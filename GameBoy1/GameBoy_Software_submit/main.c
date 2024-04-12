#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/time.h> 
#include <math.h>

#include "game_boy.h"
#include "usbkeyboard.h"
#include "usb_HID_keys.h"

#define CART_HEADER_ADDR 0x0100

// Joypad keys (configure here)
#define JOYPAD_RIGHT    KEY_D
#define JOYPAD_LEFT     KEY_A
#define JOYPAD_UP       KEY_W
#define JOYPAD_DOWN     KEY_S
#define JOYPAD_A        KEY_J
#define JOYPAD_B        KEY_K
#define JOYPAD_SELECT   KEY_O
#define JOYPAD_START    KEY_I

// DE1-SoC H2F AXI bus address
#define H2F_AXI_BASE    0xC0000000
#define H2F_AXI_SPAN    0x04000000
#define SDRAM_OFFSET    0x02000000

// FUNCTION DECLARATIONS

uint8_t update_joypad_status(uint8_t key);
void send_joypad_status(uint8_t reg);
char parse_printable_key(int key, bool mod, bool caps);
void read_cart();
void read_cart_header(FILE* ptr);
void save_RAM_to_SAV_file();
void read_SAV_file();

// TYPEDEFs

// Cartridge Header Information
typedef struct {
    uint8_t begin[4];           // 0x0100-0x0103: cart begin code
    uint8_t N_logo[48];		    // 0x0104-0x0133: scrolling Nintendo graphic (MUST NOT MODIFY)
    uint8_t game_title[15];	    // 0x0134-0x0142: title of the game in upper case ASCII
    uint8_t color_gb;			// 0x0143: 0x80 if color GB; else 0x00
    uint8_t licensee_new[2];	// 0x0144-0x0145: (new) licensee code (normally both 0x00 if address 0x014B != 0x33)
    uint8_t SGB_flag;			// 0x0146: GB/SGB indicator (0x00 = GB; 0x03 = SGB)
    uint8_t type;				// 0x0147: cartridge type
    uint8_t ROM_size;			// 0x0148: ROM size
    uint8_t RAM_size;			// 0x0149: RAM size
    uint8_t dest_code;		    // 0x014A: destination code (0x00 = Japanese; 0x01 = Non-Japanese)
    uint8_t licensee_old;		// 0x014B: (old) licensee code (0x33 = check addresses 0x0144-0x0145; 0x79 = Accolade; 0xA4 = Konami)
    uint8_t mask_ROM;			// 0x014C: mask ROM version number (usually 0x00)
    uint8_t comp_check;		    // 0x014D: complement check (PROGRAM WON'T RUN IF INCORRECT)
    uint8_t checksum[2];		// 0x014E-0x014F: checksum (GB ignores this value)
} cart_header;

// GLOBAL VARIABLES

int GB_fd;  // ioctl file descriptor

int mmap_fd;    // /dev/mem file id
void *h2f_virtual_base;  // H2F AXI bus virtual address
volatile uint8_t * sdram_ptr = NULL;

struct libusb_device_handle* keyboard;
uint8_t endpoint_address;

uint8_t joypad_reg; // bit 7-4: START, SELECT, B, A
                    // bit 3-0: DOWN, UP, LEFT, RIGHT

// Cartridge information
cart_header cart_info;
uint8_t *cart_data; // pointer to cart data start address
uint8_t *save_data; // pointer to save data start address
int ROM_size;       // in bytes
int RAM_size;       // in bytes
uint16_t ROM_bank;  // number of ROM banks
uint8_t MBC_num;    // MBC number
uint8_t RAM_bank;   // number of RAM banks
char ROM_FILE[200];
char *ROM_name;
char SAV_FILE[200];

// MAIN PROGRAM
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("ERROR: no ROM file was specified. \n");
        exit(1);
    }
    strcpy(ROM_FILE, argv[1]);   
    char tmp[200];
    strcpy(tmp, ROM_FILE);
    ROM_name = strtok(tmp, ".");
    strcpy(SAV_FILE, ROM_name);
    strcat(SAV_FILE, ".sav");
        
    // check if joypad keys are valid (cannot be ESC or modifiers or SPACE)
    uint8_t joypad_keys[8] = {
        JOYPAD_UP, JOYPAD_DOWN, JOYPAD_LEFT, JOYPAD_RIGHT,
        JOYPAD_A, JOYPAD_B, JOYPAD_START, JOYPAD_SELECT};

    for (uint8_t i = 0; i < 8; i++)
    {
        if (joypad_keys[i] == KEY_ESC || joypad_keys[i] == KEY_SPACE ||
            joypad_keys[i] == KEY_LEFTCTRL || joypad_keys[i] == KEY_RIGHTCTRL ||
            joypad_keys[i] == KEY_LEFTSHIFT || joypad_keys[i] == KEY_RIGHTSHIFT ||
            joypad_keys[i] == KEY_LEFTALT || joypad_keys[i] == KEY_RIGHTALT ||
            joypad_keys[i] == KEY_LEFTMETA || joypad_keys[i] == KEY_RIGHTMETA)
        {
            printf("Not a valid joypad key! Please reconfigure! \n");
            exit(1);
        }
    }    

    static const char filename[] = "/dev/game_boy";
    if ((GB_fd = open(filename, O_RDWR)) == -1) 
    {
        fprintf(stderr, "could not open %s\n", filename);
        return -1;
    }

    // LOAD CARTRIDGE ROM AND SAV RAM TO DE1-SoC SDRAM

    // Declare volatile pointers to I/O registers (volatile 	
    // means that IO load and store instructions will be used 	
    // to access these pointer locations,  

    // === get FPGA addresses ==================
    // Open /dev/mem
    if((mmap_fd = open("/dev/mem", (O_RDWR | O_SYNC ))) == -1)
    {
        printf("ERROR: could not open \"/dev/mem\"...\n");
        return(1);
    }

    // ===========================================
    // get virtual address for
    // AXI bus address
    h2f_virtual_base = mmap(NULL, H2F_AXI_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, mmap_fd, H2F_AXI_BASE); 	
    if(h2f_virtual_base == MAP_FAILED) 
    {
        printf("ERROR: mmap3() failed...\n");
        close(mmap_fd);
        return(1);
    }

    printf("*************************************************\n");
    sdram_ptr = (uint8_t *) (h2f_virtual_base); 
    read_cart();
    printf("*************************************************\n");

    sdram_ptr = (uint8_t *) (h2f_virtual_base + SDRAM_OFFSET);
    if (RAM_size != 0)
    {
        for (int i = 0; i < RAM_size; i++)
        {
            *(sdram_ptr + i) = 0;         // clear RAM
        }
        read_SAV_file();
        printf("*************************************************\n");
    }
    
    // MBC info
    sdram_ptr = (uint8_t *) (h2f_virtual_base + SDRAM_OFFSET);
    *(sdram_ptr - 5) = MBC_num;          // MBC number          
    *(sdram_ptr - 4) = RAM_bank;         // Number of banks
    *(sdram_ptr - 3) = ROM_bank & 0xFF;  // Lower byte
    *(sdram_ptr - 2) = ROM_bank >> 8;    // MSB
    *(sdram_ptr - 1) = 1;                // load complete

    // JOYPAD INPUT CONTROL

    struct usb_keyboard_packet packet;
    int transferred;
    char keystate[20];
    bool shift;
    bool cap_state = 0;
    bool double_speed = 0;

    /* Open the keyboard */
    if ((keyboard = openkeyboard(&endpoint_address)) == NULL) {
        fprintf(stderr, "Did not find a keyboard\n");
        exit(1);
    }

    /* Look for and handle keypresses */
    for (;;)
    {
        libusb_interrupt_transfer(keyboard, endpoint_address,
            (uint8_t*)& packet, sizeof(packet),
            &transferred, 0);
        if (transferred == sizeof(packet))
        {
            sprintf(keystate, "%02x %02x %02x %02x %02x %02x %02x", packet.modifiers, packet.keycode[0],
                packet.keycode[1], packet.keycode[2], packet.keycode[3],
                packet.keycode[4], packet.keycode[5]);
            //printf("%s\n", keystate);

            shift = packet.modifiers == USB_LSHIFT || packet.modifiers == USB_RSHIFT;

            // will execute the last pressed key
            if (packet.keycode[0] == KEY_ESC)   /* ESC pressed? */
            {
                if (RAM_size != 0)
                {
                    *(sdram_ptr - 1) = 0;
                    save_RAM_to_SAV_file();
                    printf("*************************************************\n");
                }
                break;
            }
            else if (packet.keycode[0] == KEY_SPACE)
            {
                double_speed = !double_speed;
                *(sdram_ptr - 6) = double_speed;
                if (double_speed)
                    printf("Double speed: ON \n");
                else
                    printf("Double speed: ON \n");
            }
            else if (packet.keycode[0] == KEY_CAPSLOCK || packet.keycode[1] == KEY_CAPSLOCK ||
                packet.keycode[2] == KEY_CAPSLOCK || packet.keycode[3] == KEY_CAPSLOCK ||
                packet.keycode[4] == KEY_CAPSLOCK || packet.keycode[5] == KEY_CAPSLOCK)
            {
                cap_state = !cap_state;
                if (cap_state)
                    printf("CAPS on \n");
                else
                    printf("CAPS off \n");
            }
            else if (packet.keycode[5])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[5], shift, cap_state);
                printf("Key5 pressed: %c \n", input_key);

                uint8_t reg = 0;
                for (uint8_t i = 0; i <= 5; i++)
                {
                    reg += update_joypad_status(packet.keycode[i]);
                }

                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[4])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[4], shift, cap_state);
                printf("Key4 pressed: %c \n", input_key);

                uint8_t reg = 0;
                for (uint8_t i = 0; i <= 4; i++)
                {
                    reg += update_joypad_status(packet.keycode[i]);
                }

                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[3])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[3], shift, cap_state);
                printf("Key3 pressed: %c \n", input_key);

                uint8_t reg = 0;
                for (uint8_t i = 0; i <= 3; i++)
                {
                    reg += update_joypad_status(packet.keycode[i]);
                }

                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[2])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[2], shift, cap_state);
                printf("Key2 pressed: %c \n", input_key);

                uint8_t reg = 0;
                for (uint8_t i = 0; i <= 2; i++)
                {
                    reg += update_joypad_status(packet.keycode[i]);
                }

                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[1])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[1], shift, cap_state);
                printf("Key1 pressed: %c \n", input_key);

                uint8_t reg = 0;
                for (uint8_t i = 0; i <= 1; i++)
                {
                    reg += update_joypad_status(packet.keycode[i]);
                }

                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[0])
            {
                // convert usb keycodes to ASCII
                char input_key = parse_printable_key(packet.keycode[0], shift, cap_state);
                printf("Key0 pressed: %c \n", input_key);

                uint8_t reg = update_joypad_status(packet.keycode[0]);
                if (reg)
                {
                    joypad_reg = reg;
                    send_joypad_status(joypad_reg);
                }
            }
            else if (packet.keycode[0] == KEY_NONE)
            {
                joypad_reg = 0;
                send_joypad_status(joypad_reg);
            }
        }
    }

    return 0;
}

// FUNCTION DEFINITIONS

uint8_t update_joypad_status(uint8_t key)
{
    uint8_t reg;
    switch (key)
    {
        case JOYPAD_RIGHT:
            reg = (1 << 0); break;
        case JOYPAD_LEFT:
            reg = (1 << 1); break;
        case JOYPAD_UP:
            reg = (1 << 2); break;
        case JOYPAD_DOWN:
            reg = (1 << 3); break;
        case JOYPAD_A:
            reg = (1 << 4); break;
        case JOYPAD_B:
            reg = (1 << 5); break;
        case JOYPAD_SELECT:
            reg = (1 << 6); break;
        case JOYPAD_START:
            reg = (1 << 7); break;
        default: 
            reg = 0;
    }
    return reg;
}

void send_joypad_status(uint8_t reg)
{
    uint8_t byte = reg;
    printf("Joypad register is: %.2X \n", byte);
    if (ioctl(GB_fd, GAME_BOY_SEND_JOYPAD_STATUS, &byte))
    {
        perror("ioctl(GAME_BOY_SEND_JOYPAD_STATUS) failed");
        return;
    }
}

char parse_printable_key(int key, bool mod, bool caps)
{
    if (key == KEY_BACKSPACE)
    {
        return 8;
    }
    if (key == KEY_ENTER || key == KEY_KPENTER)
    {
        return '\n';
    }
    switch (key)
    {
    case KEY_A:
        return (mod ^ caps) ? 'A' : 'a';
    case KEY_B:
        return (mod ^ caps) ? 'B' : 'b';
    case KEY_C:
        return (mod ^ caps) ? 'C' : 'c';
    case KEY_D:
        return (mod ^ caps) ? 'D' : 'd';
    case KEY_E:
        return (mod ^ caps) ? 'E' : 'e';
    case KEY_F:
        return (mod ^ caps) ? 'F' : 'f';
    case KEY_G:
        return (mod ^ caps) ? 'G' : 'g';
    case KEY_H:
        return (mod ^ caps) ? 'H' : 'h';
    case KEY_I:
        return (mod ^ caps) ? 'I' : 'i';
    case KEY_J:
        return (mod ^ caps) ? 'J' : 'j';
    case KEY_K:
        return (mod ^ caps) ? 'K' : 'k';
    case KEY_L:
        return (mod ^ caps) ? 'L' : 'l';
    case KEY_M:
        return (mod ^ caps) ? 'M' : 'm';
    case KEY_N:
        return (mod ^ caps) ? 'N' : 'n';
    case KEY_O:
        return (mod ^ caps) ? 'O' : 'o';
    case KEY_P:
        return (mod ^ caps) ? 'P' : 'p';
    case KEY_Q:
        return (mod ^ caps) ? 'Q' : 'q';
    case KEY_R:
        return (mod ^ caps) ? 'R' : 'r';
    case KEY_S:
        return (mod ^ caps) ? 'S' : 's';
    case KEY_T:
        return (mod ^ caps) ? 'T' : 't';
    case KEY_U:
        return (mod ^ caps) ? 'U' : 'u';
    case KEY_V:
        return (mod ^ caps) ? 'V' : 'v';
    case KEY_W:
        return (mod ^ caps) ? 'W' : 'w';
    case KEY_X:
        return (mod ^ caps) ? 'X' : 'x';
    case KEY_Y:
        return (mod ^ caps) ? 'Y' : 'y';
    case KEY_Z:
        return (mod ^ caps) ? 'Z' : 'z';
    case KEY_1:
        return (mod) ? '!' : '1';
    case KEY_2:
        return (mod) ? '@' : '2';
    case KEY_3:
        return (mod) ? '#' : '3';
    case KEY_4:
        return (mod) ? '$' : '4';
    case KEY_5:
        return (mod) ? '%' : '5';
    case KEY_6:
        return (mod) ? '^' : '6';
    case KEY_7:
        return (mod) ? '&' : '7';
    case KEY_8:
        return (mod) ? '*' : '8';
    case KEY_9:
        return (mod) ? '(' : '9';
    case KEY_0:
        return (mod) ? ')' : '0';
    case KEY_TAB:
        return 9;
    case KEY_SPACE:
        return ' ';
    case KEY_MINUS:
        return (mod) ? '_' : '-';
    case KEY_EQUAL:
        return (mod) ? '+' : '=';
    case KEY_LEFTBRACE:
        return (mod) ? '{' : '[';
    case KEY_RIGHTBRACE:
        return (mod) ? '}' : ']';
    case KEY_BACKSLASH:
        return (mod) ? '|' : '\\';
    case KEY_SEMICOLON:
        return (mod) ? ':' : ';';
    case KEY_APOSTROPHE:
        return (mod) ? '"' : '\'';
    case KEY_GRAVE:
        return (mod) ? '~' : '`';
    case KEY_COMMA:
        return (mod) ? '<' : ',';
    case KEY_DOT:
        return (mod) ? '>' : '.';
    case KEY_SLASH:
        return (mod) ? '?' : '/';
    case KEY_KPSLASH:
        return '/';
    case KEY_KPASTERISK:
        return '*';
    case KEY_KPMINUS:
        return '-';
    case KEY_KPPLUS:
        return '+';
    case KEY_KP1:
        return '1';
    case KEY_KP2:
        return '2';
    case KEY_KP3:
        return '3';
    case KEY_KP4:
        return '4';
    case KEY_KP5:
        return '5';
    case KEY_KP6:
        return '6';
    case KEY_KP7:
        return '7';
    case KEY_KP8:
        return '8';
    case KEY_KP9:
        return '9';
    case KEY_KP0:
        return '0';
    case KEY_KPDOT:
        return '.';
    default:
        return ' ';
    }
}

// read cartridge contents
void read_cart()
{
    FILE* cart_ptr;
    cart_ptr = fopen(ROM_FILE, "rb");

    if (cart_ptr == NULL)
    {
        printf("Unable to open the ROM file \"%s\"!\n", ROM_FILE);
        exit(1);
    }
    else
    {
        printf("ROM file \"%s\" opened successfully! \n\n", ROM_FILE);

        printf("Cartridge information: \n");
        read_cart_header(cart_ptr);

        cart_data = (uint8_t *)malloc(ROM_size);

        fseek(cart_ptr, 0, SEEK_SET);
        for (int i = 0; i < ROM_size; i++)
        {
            fread(cart_data + i, 1, 1, cart_ptr);
            //printf("Address %.4X: %.2X \n", i, *(cart_data + i));
            //printf("Address of cart_data[%d] is: %p \n", i, (void *)(cart_data+i));
        }
        fclose(cart_ptr);

        printf("Loading %d bytes of ROM into SDRAM...", ROM_size);
        for (int i = 0; i < ROM_size; i++)
        {
            *(sdram_ptr + i) = *(cart_data + i); 
            //printf("SDRAM %.4X: %.2X \n", i, *(sdram_ptr+i));
        }
        printf("complete! \n");
    }
}

// get cartridge information (e.g. MBC type, ROM size, RAM size, etc.)
void read_cart_header(FILE * ptr)
{
    fseek(ptr, CART_HEADER_ADDR, SEEK_SET);
    fread(&cart_info, 1, 0x14F - CART_HEADER_ADDR + 0x01, ptr);

    printf("- Game title: %s \n", cart_info.game_title);

    if (cart_info.color_gb == 0x80)
        printf("- Console: Game Boy Color \n");
    else
        printf("- Console: Game Boy \n");

    if (cart_info.SGB_flag == 0x03)
        printf("- Super Game Boy functions supported \n");

    char cart_str[26];
    switch (cart_info.type)
    {
        case 0x00:
            strcpy(cart_str, "ROM ONLY");
            MBC_num = 0;
            break;
        case 0x01:
            strcpy(cart_str, "ROM+MBC1");
            MBC_num = 1;
            break;
        case 0x02:
            strcpy(cart_str, "ROM+MBC1+RAM");
            MBC_num = 1;
            break;
        case 0x03:
            strcpy(cart_str, "ROM+MBC1+RAM+BATT");
            MBC_num = 1;
            break;
        case 0x05:
            strcpy(cart_str, "ROM+MBC2");
            MBC_num = 2;
            break;
        case 0x06:
            strcpy(cart_str, "ROM+MBC2+BATTERY");
            MBC_num = 2;
            break;
        case 0x08:
            strcpy(cart_str, "ROM+RAM");
            MBC_num = 1;
            break;
        case 0x09:
            strcpy(cart_str, "ROM+RAM+BATTERY");
            MBC_num = 1;
            break;
        case 0x0B:
            strcpy(cart_str, "ROM+MMM01");
            break;
        case 0x0C:
            strcpy(cart_str, "ROM+MMM01+SRAM");
            break;
        case 0x0D:
            strcpy(cart_str, "ROM+MMM01+SRAM+BATT");
            break;
        case 0x0F:
            strcpy(cart_str, "ROM+MBC3+TIMER+BATT");
            MBC_num = 3;
            break;
        case 0x10:
            strcpy(cart_str, "ROM+MBC3+TIMER+RAM+BATT");
            MBC_num = 3;
            break;
        case 0x11:
            strcpy(cart_str, "ROM+MBC3");
            MBC_num = 3;
            break;
        case 0x12:
            strcpy(cart_str, "ROM+MBC3+RAM");
            MBC_num = 3;
            break;
        case 0x13:
            strcpy(cart_str, "ROM+MBC3+RAM+BATT");
            MBC_num = 3;
            break;
        case 0x19:
            strcpy(cart_str, "ROM+MBC5");
            MBC_num = 5;
            break;
        case 0x1A:
            strcpy(cart_str, "ROM+MBC5+RAM");
            MBC_num = 5;
            break;
        case 0x1B:
            strcpy(cart_str, "ROM+MBC5+RAM+BATT");
            MBC_num = 5;
            break;
        case 0x1C:
            strcpy(cart_str, "ROM+MBC5+RUMBLE");
            MBC_num = 5;
            break;
        case 0x1D:
            strcpy(cart_str, "ROM+MBC5+RUMBLE+SRAM");
            MBC_num = 5;
            break;
        case 0x1E:
            strcpy(cart_str, "ROM+MBC5+RUMBLE+SRAM+BATT");
            MBC_num = 5;
            break;
        case 0x1F:
            strcpy(cart_str, "Pocket Camera");
            break;
        case 0xFD:
            strcpy(cart_str, "Bandai TAMA5");
            break;
        case 0xFE:
            strcpy(cart_str, "Hudson HuC-3");
            break;
        case 0xFF:
            strcpy(cart_str, "Hudson HuC-1");
            break;
        default:
            strcpy(cart_str, "Invalid cartridge type");
            exit(1);
    }
    printf("- Cartridge type: %s \n", cart_str);

    switch (cart_info.ROM_size)
    {
        case 0x00:
            ROM_bank = 2;  // 32kB   
            break;
        case 0x01:
            ROM_bank = 4;  // 64kB   
            break;
        case 0x02:
            ROM_bank = 8;  // 128kB   
            break;
        case 0x03:
            ROM_bank = 16;  // 256kB  
            break;
        case 0x04:
            ROM_bank = 32;  // 512kB  
            break;
        case 0x05:
            ROM_bank = 64;  // 1MB  
            break;
        case 0x06:
            ROM_bank = 128;  // 2MB   
            break;
        case 0x07:
            ROM_bank = 256;  // 4MB   
            break;
        case 0x08:
            ROM_bank = 512;  // 8MB   
            break;
        case 0x52:
            ROM_bank = 72;  // 1.1MB   
            break;
        case 0x53:
            ROM_bank = 80;  // 1.2MB  
            break;
        case 0x54:
            ROM_bank = 96;  // 1.5MB 
            break;
        default:
            printf("Invalid ROM size \n");
            exit(1);
    }
    ROM_size = ROM_bank * 16 * 1024;
    printf("- ROM size: %d bytes (%d banks) \n", ROM_size, ROM_bank);

    switch (cart_info.RAM_size)
    {
        case 0x00:
            RAM_bank = 0;
            RAM_size = 0;
            break;
        case 0x01:
            RAM_bank = 1;
            RAM_size = 2 * 1024;        // 2kB
            break;
        case 0x02:
            RAM_bank = 1;
            RAM_size = 8 * 1024;        // 8kB
            break;
        case 0x03:
            RAM_bank = 4;
            RAM_size = 4 * 8 * 1024;    // 32kB
            break;
        case 0x04:
            RAM_bank = 16;
            RAM_size = 16 * 8 * 1024;   // 128kB
            break;
        default:
            printf("Invalid RAM size \n");
            exit(1);
    }
    printf("- RAM size: %d bytes (%d banks) \n", RAM_size, RAM_bank);
}

// saves RAM contents (in SDRAM) to a SAV file
void save_RAM_to_SAV_file()
{
    FILE* save_ptr;
    save_ptr = fopen(SAV_FILE, "wb");

    if (save_ptr == NULL)
    {
        printf("Unable to open the SAV file \"%s\"! \n", SAV_FILE);
        exit(1);
    }
    else
    {
        printf("SAV file \"%s\" opened successfully! \n\n", SAV_FILE);

        sdram_ptr = (uint8_t *) (h2f_virtual_base + SDRAM_OFFSET);

        save_data = (uint8_t *)malloc(RAM_size);

        printf("Saving game data... \n");
        for (int i = 0; i < RAM_size; i++)
        {
            *(save_data + i) = *(sdram_ptr + i);
        }

        printf("Writing to file: %s \n", SAV_FILE);
        fwrite(save_data, 1, RAM_size, save_ptr);
        fclose(save_ptr);
    }
}

void read_SAV_file()
{
    FILE* save_ptr;
    save_ptr = fopen(SAV_FILE, "rb");

    if (save_ptr == NULL)
    {
        printf("No SAV file was loaded \n");
    }
    else
    {
        printf("SAV file \"%s\" opened successfully! \n\n", SAV_FILE);

        save_data = (uint8_t *)malloc(RAM_size);

        fseek(save_ptr, 0, SEEK_SET);
        for (int i = 0; i < RAM_size; i++)
        {
            fread(save_data + i, 1, 1, save_ptr);
            //printf("Address %.4X: %.2X \n", i, *(save_data + i));
            //printf("Address of save_data[%d] is: %p \n", i, (void *)(save_data+i));
        }
        fclose(save_ptr);

        printf("Loading %d bytes of RAM into SDRAM...", RAM_size);
        for (int i = 0; i < RAM_size; i++)
        {
            *(sdram_ptr + i) = *(save_data + i); 
            //printf("SDRAM %.4X: %.2X \n", i, *(sdram_ptr+i));
        }
        printf("complete! \n");
    }
}

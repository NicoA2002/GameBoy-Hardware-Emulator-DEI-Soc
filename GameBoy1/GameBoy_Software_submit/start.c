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
#include "controller.h"

#define CART_HEADER_ADDR 0x0100

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

struct libusb_device_handle* controller;

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

// MAIN PROGRAM
int main(int argc, char *argv[])
{
    // HANDLE COMMAND LINE ARGS
    int tempfilearg = 0;

    unsigned char double_speed = 0;
    for (int i = 1; i<argc; i++){
        if (strcmp(argv[i], "-d") == 0) {
            double_speed = 1;
        } else {tempfilearg = i;}
    }

    if (tempfilearg == 0){
        printf("Usage: %s <ROM file> [-d] \n", argv[0]);
        exit(1);
    }

    strcpy(ROM_FILE, argv[tempfilearg]);   
    char tmp[200];
    strcpy(tmp, ROM_FILE);
    ROM_name = strtok(tmp, ".");

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
    
    // MBC info
    sdram_ptr = (uint8_t *) (h2f_virtual_base + SDRAM_OFFSET);
    *(sdram_ptr - 5) = MBC_num;          // MBC number          
    *(sdram_ptr - 4) = RAM_bank;         // Number of banks
    *(sdram_ptr - 3) = ROM_bank & 0xFF;  // Lower byte
    *(sdram_ptr - 2) = ROM_bank >> 8;    // MSB
    *(sdram_ptr - 1) = 1;                // load complete

    /* Double Speed Control */
    *(sdram_ptr - 6) = double_speed;
    if (double_speed)
        printf("Double speed: ON \n");
    else
        printf("Double speed: OFF \n");

    // JOYPAD INPUT CONTROL
    unsigned char packet[8];
    int transferred;
    unsigned char pressed;
    unsigned char last_pressed = 0;

    /* Open the controller */
    if ((controller = opencontroller()) == NULL) {
        fprintf(stderr, "Did not find a controller, check Vendor/Product ID in controller.h\n");
        exit(1);
    }
    
    volatile uint8_t *lcdc_ptr = (h2f_virtual_base) + 0xFF40;

    /* Handle NES Controller Inputs by sending only new values */
    printf("READY!");
    for (;;)
    {
        //try to find LCDC
        fprintf(stderr, "LCDC Bit6: 0x%x\n", (*lcdc_ptr) & 0x40);
        fprintf(stderr, "LCDC Bit4: 0x%x\n", (*lcdc_ptr) & 0x10);
        fprintf(stderr, "LCDC Bit3: 0x%x\n\n", (*lcdc_ptr) & 0x08);

        libusb_interrupt_transfer(controller, ENDPT_ADDR_IN,
            (unsigned char *)& packet, sizeof(packet),
            &transferred, 500);

           
        if (transferred > 0 && !EMPTY_INTERR(packet)) {			
			/* --- Start/Select --- */
			PROCESS(packet[6], SELECT, pressed);
			PROCESS(packet[6], START, pressed);

			/* --- A/B --- */
			PROCESS(packet[5], A, pressed);
			PROCESS(packet[5], B, pressed);

			/* --- D_Pad --- */
			PROCESS(packet[4], DOWN, pressed);
			PROCESS(packet[3], RIGHT, pressed);
			EMPTY_PROCESS(packet[4], UP, pressed);
			EMPTY_PROCESS(packet[3], LEFT, pressed);

            // bytes are swapped, and not recognizing a header file change
            pressed = ((pressed & 0x0F) << 4) | ((pressed & 0xF0) >> 4);
			/* Effectively debounces by introducing a delay after input was recieved */
			usleep(100 * 1000);
		} else if (transferred > 0){    
            pressed = 0x00;        
		}
        if (last_pressed != pressed) send_joypad_status(pressed);
        last_pressed = pressed;
    }

    libusb_close(controller);
    return 0;
}

// FUNCTION DEFINITIONS
void send_joypad_status(uint8_t reg)
{
    uint8_t byte = reg;
    printf("Joypad register is: %.2X \n", byte);
    if (ioctl(GB_fd, GAME_BOY_WRITE_JOYPAD, &byte))
    {
        perror("ioctl(GAME_BOY_WRITE_JOYPAD) failed");
        return;
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

    // MBCs not supported in this version of hardware
    if (MBC_num != 0)
    {
        printf("Memory Bank Controllers not yet implemented!\n");
        exit(1);
    }

}



`timescale 1ns / 1ns

//Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

/* WARNING: DOES NOT HAVE INTERRUPTS OR ANY EXTERNAL OUTPUTS IMPLEMENTED */

`define OAM_BASE_ADDR 16'hFE00
`define OAM_END_ADDR 16'hFEA0

`define BG_MAP_1_BASE_ADDR 16'h9800
`define BG_MAP_1_END_ADDR 16'h9BFF

`define TILE_BASE 16'h8000
`define MAX_LY 8'd155

`define NO_BOOT 0

`define PPU_ADDR_INC(x) PPU_ADDR <= PPU_ADDR + x

typedef enum bit [1:0] {PPU_H_BLANK, PPU_V_BLANK, PPU_SCAN, PPU_DRAW} PPU_STATES_t;
typedef enum bit [2:0] {BG_TILE_NO_STORE, BG_ROW_1_LOAD, BG_ROW_2_LOAD, BG_READY, BG_PAUSE} BG_DRAW_STATES_t;
typedef enum bit [2:0] {SP_SEARCH, SP_ROW_1_LOAD, SP_ROW_2_LOAD, SP_READY, SP_RUN_BG, SP_TILE_LOAD} SP_DRAW_STATES_t;
typedef enum bit [2:0] {MIX_LOAD, MIX_START, MIX_PUSH} MIX_STATES_t;

module PPU3
(
    input logic clk,
    input logic rst,
    
    /* System access for PPU internal registers */
    input logic [15:0] ADDR,
    input logic WR,
    input logic RD,
    input logic [7:0] MMIO_DATA_out,
    output logic [7:0] MMIO_DATA_in,
    
    /* Interrupts */
    output logic IRQ_PPU_V_BLANK,
    output logic IRQ_LCDC,
    
    output logic [1:0] PPU_MODE,
    
    /* VRAM access for PPU */
    output logic PPU_RD,
    output logic [15:0] PPU_ADDR,
    input logic [7:0] PPU_DATA_in,
    
    output logic [1:0] PX_OUT,
    output logic PX_valid, 
    output logic [7:0] DEBUG_FLAG
);

/* Extensions */
logic [15:0] BIG_DATA_in, BIG_LY, BIG_X;

/* Scanline tracking */
logic [7:0] LY, x_pos;  // x-pos in range [0, 159]
logic [8:0] cycles;
logic [15:0] tile_c;
logic [3:0] pixels_pushed;

/* Sprite OAM Scan vars */
logic [15:0] curr_off;
logic [3:0] sp_loaded;
logic sp_in_range;
logic sp_found;
logic [15:0] offset_jump;

logic [7:0] sp_y_buff [9:0];
logic [7:0] sp_x_buff [9:0];
logic [7:0] sp_off_buff [9:0]; 		// stores start of sprite entries in OAM (entry + 2 => for tile no.)

/* BG fetching vars */
logic bg_fifo_go;
logic bg_fifo_load;
logic [2:0] bg_fetch_mode;
logic [7:0] bg_tile_row [1:0];

/* SP fetching vars */
logic sp_fifo_go;
logic sp_fifo_load;
logic [7:0] curr_sp_flag;
logic [7:0] sp_real_x;		// used to account for the 16 offset
logic [3:0] sp_ind;
logic [2:0] sp_fetch_mode;
logic [7:0] sp_tile_row [1:0];
logic unsigned [7:0] sp_mask;

/* Pixel mixing */
logic ready_load;
logic [1:0] bg_out;
logic [1:0] sp_out;
logic [2:0] px_mix_mode;

/* Dealayed Data Input */
logic [7:0] PREV_DATA_in;
logic mem_update;

/* Assigns */
assign BIG_DATA_in = {8'b0,PREV_DATA_in};
assign BIG_LY = {13'b0, LY[2:0]};
assign BIG_X = {8'b0,x_pos};

assign sp_in_range = ((LY + 16 >= PREV_DATA_in) &&
							(LY + 16 < PREV_DATA_in + (8 << LCDC[2])));
assign curr_off = PPU_ADDR - `OAM_BASE_ADDR;

assign sp_real_x = sp_x_buff[sp_ind] - 8;

PPU_SHIFT_REG bg_fifo(.clk(clk), .rst(rst), .data(bg_tile_row), .go(bg_fifo_go), .load(bg_fifo_load), .q(bg_out));
PPU_SHIFT_REG sp_fifo(.clk(clk), .rst(rst), .data(sp_tile_row), .go(sp_fifo_go), .load(sp_fifo_load), .q(sp_out));

/* External registers */
logic [7:0] LCDC, STAT, SCX, SCY, LYC, DMA, BGP, OBP0, OBP1, WX, WY; // Register alias

logic [7:0] FF40;
assign LCDC = FF40;

logic [7:0] FF41;
assign STAT = FF41;

logic [7:0] FF42;
assign SCY = FF42;

logic [7:0] FF43;
assign SCX = FF43;

logic [7:0] FF44;

logic [7:0] FF45;
assign LYC = FF45;

logic [7:0] FF46;
assign DMA = FF46;

logic [7:0] FF47;
assign BGP = FF47;

logic [7:0] FF48; 
assign OBP0 = {FF48[7:2], 2'b00}; // Last 2 bits are not used

logic [7:0] FF49;
assign OBP1 = {FF49[7:2], 2'b00};

logic [7:0] FF4A;
assign WY = FF4A;

logic [7:0] FF4B;
assign WX = FF4B;

/*
 *  Interrupt Assigns
*/
assign IRQ_PPU_V_BLANK = PPU_MODE == PPU_V_BLANK;
assign IRQ_LCDC = (STAT[2] && STAT[6]) || (STAT[3] & ~|STAT[1:0]) || (STAT[4] & ~STAT[1] & STAT[0]) || (STAT[5] & STAT[1] & ~STAT[0]);  


/* Register Assignment
 * 
 * 	if a register memory address is being indexed it gets updated here 
 *  -- As a warning the following may introduce timing oddities compared to other group
 */
always_ff @(posedge clk)
begin
    if (rst)
    begin
        FF40 <= `NO_BOOT ? 8'h91 : 0;
        FF41 <= 0;
        FF42 <= 0;
        FF43 <= 0;
        FF45 <= 0;
        FF46 <= 0;
        FF47 <= `NO_BOOT ? 8'hFC : 0;
        FF48 <= `NO_BOOT ? 8'hFF : 0;
        FF49 <= `NO_BOOT ? 8'hFF : 0;
        FF4A <= 0; 
        FF4B <= 0;  
    end
    else
    begin
        FF40 <= (WR && (ADDR == 16'hFF40)) ? MMIO_DATA_out : FF40;
	    FF41 <= (WR && (ADDR == 16'hFF41)) ? {MMIO_DATA_out[7:3], FF41[2:0]} : {FF41[7:3], LYC == LY, PPU_MODE};
	    FF42 <= (WR && (ADDR == 16'hFF42)) ? MMIO_DATA_out : FF42;
	    FF43 <= (WR && (ADDR == 16'hFF43)) ? MMIO_DATA_out : FF43;
	    FF45 <= (WR && (ADDR == 16'hFF45)) ? MMIO_DATA_out : FF45;
	    FF46 <= (WR && (ADDR == 16'hFF46)) ? MMIO_DATA_out : FF46;
	    FF47 <= (WR && (ADDR == 16'hFF47)) ? MMIO_DATA_out : FF47;
	    FF48 <= (WR && (ADDR == 16'hFF48)) ? MMIO_DATA_out : FF48;
	    FF49 <= (WR && (ADDR == 16'hFF49)) ? MMIO_DATA_out : FF49;
	    FF4A <= (WR && (ADDR == 16'hFF4A)) ? MMIO_DATA_out : FF4A;
	    FF4B <= (WR && (ADDR == 16'hFF4B)) ? MMIO_DATA_out : FF4B;
    end
end

/* -- State Switching machine -- */
always_ff @(posedge clk) begin
	cycles <= cycles + 1;

	if (PPU_DATA_in != PREV_DATA_in) PREV_DATA_in <= PPU_DATA_in;

	if ((LY >= 8 && LY < 16) && (x_pos >= 8 && x_pos < 16) && cycles == 95) DEBUG_FLAG <= 3;
	else if ((LY >= 16 && LY < 24) && (x_pos >= 24 && x_pos < 32) && cycles == 127) DEBUG_FLAG <= 4;
	else DEBUG_FLAG <= 0;

    if (rst) begin
			x_pos <= 0;
			cycles <= 0;
			LY <= 0;
			PPU_ADDR <= `OAM_BASE_ADDR;
			PPU_MODE <= PPU_SCAN;
    end else if (LCDC[7]) begin
		/* -- Following block happens on a per scanline basis (456 cycles per line) -- */
        case (PPU_MODE)
            PPU_SCAN: begin
	    		if (cycles == 79) begin
					PPU_MODE <= PPU_DRAW;
					ready_load <= 1;
					pixels_pushed <= 1;
					tile_c <= BIG_LY >> 3;
					x_pos <= 0;
					
					bg_fetch_mode <= BG_PAUSE;
					sp_fetch_mode <= SP_SEARCH;
		    	end
				if (LY >= 144) PPU_MODE <= PPU_V_BLANK; 
			end
		    PPU_DRAW: 
		    	if (x_pos > 160) begin
		    		PPU_MODE <= PPU_H_BLANK;
		    		PX_valid <= 0;
		    	end
		    PPU_H_BLANK: begin
		    	if (cycles == 454) DEBUG_FLAG <= 2;			// DEBUG_FLAG
		    	if (cycles >= 455) begin					// we reached the end of the scanline
					LY <= LY + 1;

					for (int i = 0; i < 10; i++) begin
			            sp_x_buff[0] = 8'd0;
			            sp_y_buff[0] = 8'd0;
			            sp_off_buff[i] = 8'd0;
			        end
					x_pos <= 0;
					sp_loaded <= 0;
					cycles <= 0;
					PPU_MODE <= PPU_SCAN;
					PPU_ADDR <= `OAM_BASE_ADDR;
					DEBUG_FLAG <= 0;
				end
			end
		    PPU_V_BLANK: begin
				if (cycles >= 455) begin		// we reached the end of the scanline
					LY <= LY + 1;
					cycles <= 0;
					if (LY >= `MAX_LY) begin
						LY <= 0;
						PPU_MODE <= PPU_SCAN;
					end
				end
			end
        endcase
    end
end   

/* 
 * If we detect a memory request we return back the current
 * state of the register
 */ 
always_comb
begin
    case (ADDR)
        16'hFF40: MMIO_DATA_in = FF40;
        16'hFF41: MMIO_DATA_in = {1'b1, FF41[6:0]};
        16'hFF42: MMIO_DATA_in = FF42;
        16'hFF43: MMIO_DATA_in = FF43;
        16'hFF44: MMIO_DATA_in = FF44;
        16'hFF45: MMIO_DATA_in = FF45;
        16'hFF46: MMIO_DATA_in = FF46;
        16'hFF47: MMIO_DATA_in = FF47;
        16'hFF48: MMIO_DATA_in = FF48;
        16'hFF49: MMIO_DATA_in = FF49;
        16'hFF4A: MMIO_DATA_in = FF4A;
        16'hFF4B: MMIO_DATA_in = FF4B;
        default : MMIO_DATA_in = 8'hFF;
    endcase
end

/* -- OAM Scan State Machine -- */
always_ff @(posedge clk) begin
	if (rst) begin
		sp_loaded <= 0;
	end if (PPU_MODE == PPU_SCAN) begin
		if (offset_jump != 0) begin
			if (offset_jump == 1) begin
				sp_loaded <= sp_loaded + 1;
				sp_y_buff[sp_loaded] <= PREV_DATA_in;
				sp_off_buff[sp_loaded] <= curr_off[7:0];
			end else if (offset_jump == 3) sp_x_buff[sp_loaded - 1] <= PREV_DATA_in;

			`PPU_ADDR_INC(offset_jump);
		end
		else if (cycles != 79 && cycles[0]) `PPU_ADDR_INC(4);
	end
end 

always_ff @(posedge clk or negedge clk) begin
	if (rst || PPU_MODE == PPU_H_BLANK) begin
		offset_jump <= 0;
		sp_found <= 0;
	end

	if (clk) offset_jump <= 0;
	if (clk == 0) begin
		if (!cycles[0])	begin								// forces alternating clock cycles
			if (sp_in_range && sp_loaded < 10) begin
				offset_jump <= 1;							// jumps to x-byte
				sp_found <= 1;
			end
		end else begin
			if (sp_found) begin
				offset_jump <= 3;
				sp_found <= 0;
			end
		end
	end
end

/*
 *
 * We'll need to implement
 *  Proper pixel mixing			o 
 *  Interrupts					o 
 * 	LCDC flags 
 * 	Alternate mode support
 * 	Tall sprites
 *  SCX and SCY
 * 	X masking					o
 *  Y masking 					o
 * 		(handled by scanlines but tested anyways)
 *
 */

/* BG Draw Machine */
always_ff @(posedge clk) begin
	if (rst) begin
		pixels_pushed <= 1;
		tile_c <= 1;
	end
	if (PPU_MODE == PPU_DRAW) begin
		case (bg_fetch_mode)
			BG_TILE_NO_STORE: begin
				bg_fetch_mode <= BG_ROW_1_LOAD;
				PPU_ADDR <= `TILE_BASE + (BIG_LY << 1) + (BIG_DATA_in << 4);	// tile_base + (16 * tile_no) + 2 * (LY % 8)
			end
			BG_ROW_1_LOAD: begin
				bg_tile_row[0] <= PREV_DATA_in;
				bg_fetch_mode <= BG_ROW_2_LOAD;
				`PPU_ADDR_INC(1);
			end
			BG_ROW_2_LOAD: begin
				bg_tile_row[1] <= PREV_DATA_in;
				bg_fetch_mode <= BG_READY;
			end
			default: begin
			end
		endcase
	end
end

/* SP Draw Machine 
	
 *	State machine iterates through detected sprites for a PPU_scanline,
 *	loads the rows into the sp_fifo and switches the bg drawing on
*/
always_ff @(posedge clk) begin
	if (rst) begin
		sp_ind <= 0;
	end
	if (PPU_MODE == PPU_DRAW) begin
		case (sp_fetch_mode)
			SP_SEARCH: begin
				if (sp_x_buff[sp_ind] >= 8 &&
						((sp_real_x >= x_pos && sp_real_x < x_pos + 8) || 
						  sp_real_x + 8 > x_pos && sp_real_x + 8 <= x_pos + 8)) begin			// end of sprite in tile
					PPU_ADDR <= `OAM_BASE_ADDR + {8'b0, sp_off_buff[sp_ind]} + 2;			// points to tile no. of sprite
					sp_fetch_mode <= SP_TILE_LOAD;	
					
					if (sp_real_x > x_pos && sp_real_x < x_pos + 8) sp_mask <= 8'hFF >> (x_pos + 6 - sp_real_x);
					else if (sp_real_x + 8 > x_pos && sp_real_x + 8 < x_pos + 8) sp_mask <= 8'hFF << (x_pos - sp_real_x);
					else sp_mask <= 8'hFF;

				end else sp_ind <= sp_ind + 1;

				if (sp_ind == 9) begin
					sp_fetch_mode <= SP_RUN_BG;
					DEBUG_FLAG <= 1;
					sp_tile_row[0] <= 0;
					sp_tile_row[1] <= 0;
				end
			end
			SP_TILE_LOAD: begin
				PPU_ADDR <= `TILE_BASE + (BIG_LY << 1) + (BIG_DATA_in << 4);					// load in tile data
				sp_fetch_mode <= SP_ROW_1_LOAD;
			end
			SP_ROW_1_LOAD: begin
				sp_tile_row[0] <= PREV_DATA_in & sp_mask;
				sp_fetch_mode <= SP_ROW_2_LOAD;
				DEBUG_FLAG <= 5;
				`PPU_ADDR_INC(1);
			end
			SP_ROW_2_LOAD: begin
				sp_tile_row[1] <= PREV_DATA_in & sp_mask;
				PPU_ADDR <= `OAM_BASE_ADDR + {8'b0, sp_off_buff[sp_ind]} + 3;	// grabs sprite flags
				sp_fetch_mode <= SP_RUN_BG;
				DEBUG_FLAG <= 1;
			end
			SP_RUN_BG: begin
				sp_ind <= 0;
				curr_sp_flag <= PREV_DATA_in;
				bg_fetch_mode <= BG_TILE_NO_STORE;
				PPU_ADDR <= `BG_MAP_1_BASE_ADDR + tile_c;
				sp_fetch_mode <= SP_READY;
				DEBUG_FLAG <= 0;
			end
			SP_READY: begin
				//check to see if new sprite should be rendered
			end
			default: begin
			end
		endcase
	end
end

assign PX_OUT = (sp_out == 2'h0 || (bg_out != 2'h0 && curr_sp_flag[7])) ? bg_out : sp_out;

/* Pixel Mixing & Output Machine */ 
always_ff @(posedge clk) begin
	if (rst) begin
		ready_load <= 1;
	end else if (PPU_MODE == PPU_DRAW) begin
		case (px_mix_mode)
			MIX_LOAD: begin
					if (!ready_load) begin
						pixels_pushed <= pixels_pushed - 1;
						PX_valid <= 1;
					end

					if (pixels_pushed == 1) begin
						PX_valid <= 0;
						if ((sp_fetch_mode == SP_READY) && (bg_fetch_mode == BG_READY)) begin
							// load both buffers into fifos
							bg_fifo_load <= 1;
							sp_fifo_load <= 1;
							
							// make sure we stop pushing for a sec
							bg_fifo_go <= 0;
							sp_fifo_go <= 0;

							px_mix_mode <= MIX_START;

							PX_valid <= 0;
							tile_c <= tile_c + 1;
							x_pos <= x_pos + 8;
						end
					end

					if (pixels_pushed == 0) begin
						pixels_pushed <= 1;
						ready_load <= 1;
						PX_valid <= 0;
					end
				end
				MIX_START: begin
					bg_fifo_load <= 0;
					sp_fifo_load <= 0;
						
					bg_fifo_go <= 1;
					sp_fifo_go <= 1;

					if (x_pos <= 160) PX_valid <= 1;

					pixels_pushed <= 8; 
					ready_load <= 0;
 
					bg_fetch_mode <= BG_PAUSE;
					sp_fetch_mode <= SP_SEARCH;
					px_mix_mode <= MIX_LOAD;
				end
				default: begin
				end
		endcase 
	end
end
  
endmodule
    
module PPU_SHIFT_REG
(
    input clk,
    input rst,
    input logic [7:0] data [1:0],
    input logic go,
    input logic load,
    output logic [1:0] q
);

logic [7:0] shift_reg [0:1];

always_ff @(posedge clk)
begin
    if (rst)
    begin
        shift_reg[0] <= 0;
        shift_reg[1] <= 0;
    end
    else if (load)
    begin
        shift_reg[0] <= data[0];
        shift_reg[1] <= data[1];
    end
    else
    begin
        if (go)
        begin
            shift_reg[0][7:1] <= shift_reg[0][6:0];
            shift_reg[0][0] <= 0;
            shift_reg[1][7:1] <= shift_reg[1][6:0];
            shift_reg[1][0] <= 0;
        end
    end
end

assign q = {shift_reg[1][7], shift_reg[0][7]};
        
endmodule
    

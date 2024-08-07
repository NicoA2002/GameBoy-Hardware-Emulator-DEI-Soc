// Authors: Nicolas Alarcon, Claire Cizdziel, Donovan Sproule

`define MEM_CYCLE

`define OAM_BASE_ADDR 16'hFE00
`define OAM_END_ADDR 16'hFEA0

`define BG_MAP_1_BASE_ADDR 16'h9800
`define BG_MAP_2_BASE_ADDR 16'h9C00

`define BG_MAP_1_END_ADDR 16'h9BFF

`define MAX_LY 8'd155

`define NO_BOOT 0

`define PPU_ADDR_INC(x) `PPU_ADDR_SET(PPU_ADDR + x)
`ifdef MEM_CYCLE
`define PPU_ADDR_SET(x) PPU_ADDR <= x; mem_config <= MEM_REQ;
`else
`define PPU_ADDR_SET(x) PPU_ADDR <= x;
`endif

/* Macros that set STAT flags */
`define PPU_MODE_SET(x) PPU_MODE <= x; FF41[1:0] <= x
`define LY_UPDATE(x) LY <= x; FF41[2] <= (x == LYC); FF45 <= {7'b0, (x == LYC)}
`define WXC_UPDATE(x) if (LY >= WY && ((real_wx >= SCX) && (real_wx <= (168 + SCX)))) WXC <= x

typedef enum bit [1:0] {PPU_H_BLANK, PPU_V_BLANK, PPU_SCAN, PPU_DRAW} PPU_STATES_t;
typedef enum bit [2:0] {BG_TILE_NO_STORE, BG_ROW_1_LOAD, BG_ROW_2_LOAD, BG_READY, BG_PAUSE} BG_DRAW_STATES_t;
typedef enum bit [2:0] {SP_SEARCH, SP_ROW_1_LOAD, SP_ROW_2_LOAD, SP_READY, SP_RUN_BG, SP_TILE_LOAD} SP_DRAW_STATES_t;
typedef enum bit [2:0] {MIX_LOAD, MIX_START, MIX_PUSH} MIX_STATES_t;
typedef enum bit [2:0] {MEM_EMPTY, MEM_REQ, MEM_LOAD, MEM_NO_REQ} MEM_STATES_t;
typedef enum bit [1:0] {W_NO_EDGE, W_BG_RUN, W_MASK_RUN} W_STATES_t;

/* Doesn't track clock cycles but instead measures progressions in the form of 'dots'. Any instruction that processes
 * data and progresses the PPU iterates a dot, most of the exceptions being stall clock cycles where we make a memory 
 * request and must halt until we can use the data
 */

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
    output logic PX_valid 
);

/* Extensions */
logic [15:0] BIG_DATA_in, BIG_LY_SCY_MOD, BIG_X;
logic signed [15:0] S_BIG_DATA_in;

/* Scanline tracking */
logic [7:0] LY, x_pos;  			// x-pos in range [0, 159]
logic [8:0] dots;
logic [3:0] pixels_pushed;
logic [15:0] x_tile_off;
logic [15:0] y_tile_off;

/* Sprite OAM Scan vars */
logic [15:0] curr_off;
logic [3:0] sp_loaded;
logic sp_in_range;
logic sp_found;
logic tts;							// tall tile selector
logic [15:0] offset_jump;

logic [7:0] sp_y_buff [9:0];
logic [7:0] sp_x_buff [9:0];
logic [7:0] sp_off_buff [9:0]; 		// stores start of sprite entries in OAM (entry + 2 => for tile no.)

/* BG fetching vars */
logic bg_fifo_go;
logic bg_fifo_load;
logic [2:0] bg_fetch_mode;
logic [7:0] bg_tile_row [1:0];
logic [15:0] bg_map_sel;

/* SP fetching vars */
logic sp_fifo_go;
logic sp_fifo_load;
logic [15:0] alt_data_in_sel;
logic [15:0] alt_tile_base;
logic [7:0] curr_sp_flag;
logic [7:0] sp_real_x;				// used to account for the 16 offset
logic [3:0] sp_ind;
logic [2:0] sp_fetch_mode;
logic [7:0] sp_tile_row [1:0];

/* Window */
logic [7:0] WXC;
logic [7:0] real_wx;
logic [15:0] x_w_off;
logic [15:0] y_w_off;
logic [1:0] w_check;
logic [7:0] w_mask;
logic [15:0] w_map_sel;

/* Pixel Masking */
logic unsigned [7:0] gen_mask;
logic unsigned [7:0] sp_mask;

/* Pixel mixing */
logic ready_load;
logic flush_buff;
logic [1:0] bg_out;
logic [1:0] sp_out;
logic [2:0] px_mix_mode;

/* Dealayed Data Input */
`ifdef MEM_CYCLE
logic [2:0] mem_config;
`endif

/* Frame Reset */
logic frame_rst;

/* Assigns */
assign BIG_DATA_in = {8'b0, PPU_DATA_in};
assign S_BIG_DATA_in = {8'b0, PPU_DATA_in};
assign BIG_LY_SCY_MOD = {13'b0, LY[2:0] + SCY[2:0]};
assign BIG_X = {8'b0,x_pos};

assign sp_in_range = ((LY + SCY + 16 >= PPU_DATA_in) &&
							(LY + SCY + 16 < PPU_DATA_in + (8 << LCDC[2])));
assign curr_off = PPU_ADDR - `OAM_BASE_ADDR;
assign x_tile_off = (((BIG_X >> 3) + ({8'b0, SCX} >> 3)) & 16'h3FFF);
assign y_tile_off = (((({8'h0, LY} + {8'h0, SCY}) & 16'hFF) >> 3) << 5) & 16'h3FFF;

assign x_w_off = ((({8'b0, x_pos - real_wx} >> 3)) & 16'h3FFF);
assign y_w_off = ((({8'h0, WXC}) >> 3) << 5) & 16'h3FFF;

assign sp_real_x = sp_x_buff[sp_ind] - 8;
assign real_wx = WX - 7;

assign w_map_sel = (LCDC[6]) ? `BG_MAP_2_BASE_ADDR : `BG_MAP_1_BASE_ADDR;
assign bg_map_sel = (LCDC[3]) ? `BG_MAP_2_BASE_ADDR : `BG_MAP_1_BASE_ADDR;

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
assign FF44 = LY;

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


/* STAT Interrupts */
logic IRQ_STAT, IRQ_STAT_NEXT; // The Internal IRQ signal, IRQ LCDC Triggered on the rising edge of this

always_comb begin
	IRQ_STAT_NEXT = (FF41[6] && LY == LYC) ||
	                (FF41[3] && PPU_MODE == PPU_H_BLANK) ||
	                (FF41[5] && PPU_MODE == PPU_SCAN) ||
	                ((FF41[4] || FF41[5]) && PPU_MODE == PPU_V_BLANK);
	IRQ_STAT_NEXT = IRQ_STAT_NEXT & LCDC[7];
end

assign IRQ_LCDC = IRQ_STAT_NEXT && !IRQ_STAT;

/*
 *  Pixel Assigns
*/
assign flush_buff = (PPU_MODE == PPU_DRAW) && 
			!(ready_load & (pixels_pushed == 4'hA)) && 
			(pixels_pushed > 0 & pixels_pushed <= 8);

assign PX_OUT = (sp_out == 2'h0 || (bg_out != 2'h0 && curr_sp_flag[7])) ? bg_out : sp_out;
assign PX_valid = (flush_buff && (x_pos <= 160 || (x_pos <= 168 && SCX != 0)));

assign alt_tile_base = (LCDC[4]) ? 16'h8000 : 16'h9000;
assign alt_data_in_sel = (LCDC[4]) ? BIG_DATA_in : S_BIG_DATA_in;

/* 
 * If we detect a memory request we return back the current
 * state of the register
 */ 
always_latch
begin
	if (RD) begin
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
end

always_ff @(posedge clk) begin

	/* Register Assignment
	* 
	* 	if a register memory address is being indexed it gets updated here 
	*  -- As a warning the following may introduce timing oddities compared to other group
	*/

	if (rst)
    begin
    	IRQ_STAT <= 0;
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
    	IRQ_STAT <= IRQ_STAT_NEXT;
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

	/* -- Memory Loading machine -- */
`ifdef MEM_CYCLE
	if (mem_config != MEM_NO_REQ) mem_config <= mem_config + 1;
`endif
	
	frame_rst <= 0;
	/* -- State Switching machine -- */
    if (rst || frame_rst) begin
			x_pos <= 0;
			dots <= 0;
			`LY_UPDATE(0);
			WXC <= 0;
			`PPU_ADDR_SET(`OAM_BASE_ADDR);
			`PPU_MODE_SET(PPU_SCAN);
			PPU_RD <= 1;
`ifdef  MEM_CYCLE
	end else if (LCDC[7] && mem_config == MEM_NO_REQ) begin
`else
	end else if (LCDC[7]) begin
`endif
    	dots <= dots + 1;
		/* -- Following block happens on a per scanline basis (456 dots per line) -- */
        case (PPU_MODE)
            PPU_SCAN: begin
	    		if (dots == 79) begin
					`PPU_MODE_SET(PPU_DRAW);
					ready_load <= 1;
					pixels_pushed <= 4'hA;
					x_pos <= 0;
					
					bg_fetch_mode <= BG_PAUSE;
					sp_fetch_mode <= SP_SEARCH;
		    	end
				if (LY >= 144) begin 
					`PPU_MODE_SET(PPU_V_BLANK);
					PPU_RD <= 0;
				end 
			end
		    PPU_DRAW: begin
		    	if ((x_pos > 160 && SCX == 0) || x_pos > 168) begin
		    		`PPU_MODE_SET(PPU_H_BLANK);
		    		PPU_RD <= 0;
		    	end
		    end
		    PPU_H_BLANK: begin
		    	if (dots >= 455) begin					// we reached the end of the scanline
					`LY_UPDATE(LY + 1);
					`WXC_UPDATE(WXC + 1);
					for (int i = 0; i < 10; i++) begin
			            sp_x_buff[0] <= 8'd0;
			            sp_y_buff[0] <= 8'd0;
			            sp_off_buff[i] <= 8'd0;
			        end
					x_pos <= 0;
					sp_loaded <= 0;
					dots <= 0;
					`PPU_MODE_SET(PPU_SCAN);
					PPU_RD <= 1;
					`PPU_ADDR_SET(`OAM_BASE_ADDR);
				end else begin
					`PPU_ADDR_SET(0);
				end
			end
		    PPU_V_BLANK: begin
				if (dots >= 455) begin		// we reached the end of the scanline
					`LY_UPDATE(LY + 1);
					`WXC_UPDATE(WXC + 1);
					dots <= 0;
					if (LY >= `MAX_LY) begin	// we are ready to render the next frame
						frame_rst <= 1;
					end
				end else begin
					`PPU_ADDR_SET(0);
				end
			end
        endcase
	end

	/* -- OAM Scan State Machine -- */
	if (rst || frame_rst || PPU_MODE == PPU_H_BLANK) begin
		sp_loaded <= 0;
		sp_found <= 0;
`ifdef MEM_CYCLE
	end else if (mem_config == MEM_NO_REQ) begin
`else
	end else begin
`endif
		if (PPU_MODE == PPU_SCAN) begin
			if (!dots[0]) begin									// forces alternating clock dots
				if (sp_in_range && sp_loaded < 10) begin
					sp_loaded <= sp_loaded + 1;
					sp_y_buff[sp_loaded] <= PPU_DATA_in;
					sp_off_buff[sp_loaded] <= curr_off[7:0];
					sp_found <= 1;
				end 
				`PPU_ADDR_INC(1);	
			end else begin
				if (sp_found) begin
					sp_x_buff[sp_loaded - 1] <= PPU_DATA_in;
				end 
				`PPU_ADDR_INC(3);							// jumps to next sprite in OAM
				sp_found <= 0;
			end
		end
	end

`ifdef MEM_CYCLE
	if (PPU_MODE == PPU_DRAW && px_mix_mode == MIX_LOAD)
		if (!ready_load && pixels_pushed > 0) pixels_pushed <= pixels_pushed - 1;
`endif

	/* BG/Window Sprite Draw Machine 
	*	State machine iterates through detected sprites for a PPU_scanline,
	*	loads the rows into the sp_fifo and switches the bg drawing on
	*/
	if (rst || frame_rst) begin
		pixels_pushed <= 4'hA;
		sp_ind <= 0;
		ready_load <= 1;
`ifdef MEM_CYCLE
	end else if (mem_config == MEM_NO_REQ) begin
`else
	end else begin
`endif
		if (PPU_MODE == PPU_DRAW) begin
			/* Background Fetch Machine */
			case (bg_fetch_mode)
				BG_TILE_NO_STORE: begin
					bg_fetch_mode <= BG_ROW_1_LOAD;
					
					`PPU_ADDR_SET(alt_tile_base + (BIG_LY_SCY_MOD << 1) + (alt_data_in_sel << 4));		// tile_base + 2 * (LY + SCY % 8) + (16 * tile_no) 

					if (LCDC[5]) begin
						if (LY >= WY && (x_pos + SCX >= real_wx)) begin
							`PPU_ADDR_SET(alt_tile_base + ({13'h0, WXC[2:0]} << 1) + (alt_data_in_sel << 4));		// tile_base + (16 * tile_no) + 2 * (LY + SCY % 8)
						end
					end
					
					if (x_pos == 0) gen_mask <= 8'hFF >> SCX[2:0];
					else if (x_pos == 160) gen_mask <= ~(8'hFF << SCX[2:0]);
					else gen_mask <= 8'hFF;

					if (w_check == W_BG_RUN) w_mask <= 8'hFF << (8 - (real_wx - x_pos - SCX));
					if (w_check == W_MASK_RUN) w_mask <= 8'hFF >> (real_wx - x_pos - SCX);
				end
				BG_ROW_1_LOAD: begin
					if (LCDC[0]) begin
						bg_tile_row[0] <= PPU_DATA_in & gen_mask;
						if (w_check == W_BG_RUN) bg_tile_row[0] <= PPU_DATA_in & w_mask;
						if (w_check == W_MASK_RUN) bg_tile_row[0] <= bg_tile_row[0] | (PPU_DATA_in & w_mask);
					end else bg_tile_row[0] <= 8'h0;

					bg_fetch_mode <= BG_ROW_2_LOAD;
					`PPU_ADDR_INC(1);
				end
				BG_ROW_2_LOAD: begin
					if (LCDC[0]) begin
						bg_tile_row[1] <= PPU_DATA_in & gen_mask;
						if (w_check == W_BG_RUN) bg_tile_row[1] <= PPU_DATA_in & w_mask;
						if (w_check == W_MASK_RUN) bg_tile_row[1] <= bg_tile_row[1] | (PPU_DATA_in & w_mask);
					end else bg_tile_row[1] <= 8'h0;

					if (w_check == W_BG_RUN) begin
						bg_fetch_mode <= BG_TILE_NO_STORE;
						`PPU_ADDR_SET(w_map_sel + {x_w_off[15:3], 3'h0} + y_w_off);
						w_check <= W_MASK_RUN;
					end else begin
						bg_fetch_mode <= BG_READY;
					end
				end
				default: begin
				end
			endcase

			/* Sprite Fetch Machine */
			case (sp_fetch_mode)
				SP_SEARCH: begin
					if (sp_x_buff[sp_ind] >= 8 &&
							((sp_real_x >= x_pos && sp_real_x < x_pos + 8) || 
							  sp_real_x + 8 > x_pos && sp_real_x + 8 <= x_pos + 8) && 
							  	LCDC[1]) begin			// end of sprite in tile

						`PPU_ADDR_SET(`OAM_BASE_ADDR + {8'b0, sp_off_buff[sp_ind]} + 2);
						sp_fetch_mode <= SP_TILE_LOAD;	
						
						if (x_pos == 0) gen_mask <= 8'hFF >> SCX[2:0];
						else if (x_pos == 160) gen_mask <= ~(8'hFF << SCX[2:0]);
						else gen_mask <= 8'hFF;

						if (sp_real_x > x_pos && sp_real_x < x_pos + 8) sp_mask <= 8'hFF >> (x_pos + 6 - sp_real_x);
						else if (sp_real_x + 8 > x_pos && sp_real_x + 8 < x_pos + 8) sp_mask <= 8'hFF << (x_pos - sp_real_x);
						else sp_mask <= 8'hFF;

						tts <= 1;
						/* For tall sprites */
						if (LCDC[2]) begin
							if (LY + 16 < sp_y_buff[sp_ind] + 16) tts <= 0;
							else tts <= 1;
						end

					end else sp_ind <= sp_ind + 1;

					if (sp_ind == 9) begin
						sp_fetch_mode <= SP_RUN_BG;
						sp_tile_row[0] <= 0;
						sp_tile_row[1] <= 0;
					end
				end
				SP_TILE_LOAD: begin
					sp_mask <= sp_mask & gen_mask;
					`PPU_ADDR_SET(16'h8000 + (BIG_LY_SCY_MOD << 1) + ({BIG_DATA_in[15:1], tts} << 4));
					sp_fetch_mode <= SP_ROW_1_LOAD;
				end
				SP_ROW_1_LOAD: begin
					sp_tile_row[0] <= PPU_DATA_in & sp_mask;
					sp_fetch_mode <= SP_ROW_2_LOAD;
					`PPU_ADDR_INC(1);
				end
				SP_ROW_2_LOAD: begin
					sp_tile_row[1] <= PPU_DATA_in & sp_mask;
					`PPU_ADDR_SET(`OAM_BASE_ADDR + {8'b0, sp_off_buff[sp_ind]} + 3);
					sp_fetch_mode <= SP_RUN_BG;
				end
				SP_RUN_BG: begin
					sp_ind <= 0;
					curr_sp_flag <= PPU_DATA_in;
					bg_fetch_mode <= BG_TILE_NO_STORE;
					if (LY >= WY && ((x_pos + SCX >= real_wx) || (x_pos + SCX + 8 > real_wx)) && LCDC[5]) begin
						if ((x_pos + SCX + 8 > real_wx) && (x_pos + SCX < real_wx)) begin											// In the middle of a tile
							`PPU_ADDR_SET(bg_map_sel + x_tile_off + y_tile_off);
							w_check <= W_BG_RUN; 
						end else begin
							`PPU_ADDR_SET(w_map_sel + x_w_off + y_w_off);
							w_check <= W_NO_EDGE;
						end
					end else begin
						`PPU_ADDR_SET(bg_map_sel + x_tile_off + y_tile_off);
						w_check <= W_NO_EDGE;
					end
					sp_fetch_mode <= SP_READY;
				end
				SP_READY: begin
					// Purposefully ignores multiple sprites existing overlapping. This is because I don't want to overwrite data
				end
				default: begin
				end
			endcase

			/* Pixel Mixing & Output Machine */ 
			case (px_mix_mode)
				MIX_LOAD: begin
`ifndef MEM_CYCLE
					if (!ready_load && pixels_pushed > 0) begin
						pixels_pushed <= pixels_pushed - 1;
					end
`endif					

					if (pixels_pushed == 4'hA) begin
						if ((sp_fetch_mode == SP_READY) && (bg_fetch_mode == BG_READY)) begin
							// load both buffers into fifos
							bg_fifo_load <= 1;
							sp_fifo_load <= 1;
							
							// make sure we stop pushing for a sec
							bg_fifo_go <= 0;
							sp_fifo_go <= 0;

							px_mix_mode <= MIX_START;

							x_pos <= x_pos + 8;
						end
					end

					if (pixels_pushed == 0) begin
						pixels_pushed <= 4'hA;
						ready_load <= 1;
					end
				end
				MIX_START: begin
					bg_fifo_load <= 0;
					sp_fifo_load <= 0;
						
					bg_fifo_go <= 1;
					sp_fifo_go <= 1;


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

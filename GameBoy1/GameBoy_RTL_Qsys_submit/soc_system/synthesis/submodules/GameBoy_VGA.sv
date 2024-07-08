/*
 * Avalon memory-mapped peripheral that generates VGA
 *
 * Original By Stephen A. Edwards
 * Columbia University
 * Modified By Nicolas Alarcon, Donovan Sproule, Claire Cizdziel
 * Columbia University
 * 640 x 480 @ 60 Hz: 25MHz
 *
 * New Resolution: 480x432: modify timing, framebuffer size, pixel scaling
 */

module GameBoy_VGA
(
	input		logic				clk,
	input logic GameBoy_clk, // the 2^22 Hz GameBoy clk for framebuffer
	input		logic				reset,
	input logic GameBoy_reset, // Reset synced to GameBoy clk
	
	input logic clk_vga, // 25 MHz
	
	/* Avalon Slave */
	input logic [7:0]  writedata,
	input logic 	   write,
    input 		   chipselect,
    input logic [20:0]  address,

	/* VGA Conduit */
	output 	logic [7:0] 	VGA_R, VGA_G, VGA_B,
	output 	logic 	   	VGA_CLK, VGA_HS, VGA_VS,
									VGA_BLANK_n,
	output 	logic 	   	VGA_SYNC_n,

	/* GameBoy Pixel Conduit */
	input logic [1:0] LD,
	input logic PX_VALID
	
);

// VGA signals
logic [15:0] LX; //LX
logic [15:0] LY; //LY

logic [7:0]		bg_r, bg_g, bg_b;

logic [1:0] 	GB_PIXEL;

// Instantiations
vga_counters counters(.*);

/* The Framebuffer for gameboy */
logic [14:0] frame_buffer_cnt;
logic frame_buffer_switch;

always_ff @(posedge GameBoy_clk or posedge GameBoy_reset) begin
    if (GameBoy_reset) begin
        frame_buffer_cnt <= 0;
        frame_buffer_switch <= 0;
    end else if (PX_VALID) begin
		//size of frame buffer: (480*432)/3 = 207360
        if (frame_buffer_cnt == (207359)) begin
            frame_buffer_cnt <= 0;
		end else begin frame_buffer_cnt <= frame_buffer_cnt + 1; //move through buffer
		end
    end
end

logic [15:0] READ_LX, READ_LY;

assign READ_LX = LX > 80 ? LX - 80 : 0;
assign READ_LY = LY > 24 ? LY - 24 : 0;

logic [7:0] GB_LX, GB_LY;
logic [2:0] GB_COL_CNT, GB_ROW_CNT;

parameter LINE_SCALE = 3; //repeat each pixel 3 times 
always_ff @(posedge clk_vga)
begin
	if (LX < 80 || LX >= 560) //outside screen x
	begin
		GB_LX <= 0;
		GB_COL_CNT <= 0;
	end
	else begin
		GB_COL_CNT <= GB_COL_CNT + 1; 
	end

	if (GB_COL_CNT == LINE_SCALE) 
	begin
		GB_COL_CNT <= 0; 
		GB_LX <= GB_LX + 1; 
	end
	
    if (LY <= 24 || LY >= 456) //outside screen y
    begin
        GB_LY <= 0;
        GB_ROW_CNT <= 0;
    end 
	else if (LX == 1) begin 
        GB_ROW_CNT <= GB_ROW_CNT + 1;
    end
    
    if (GB_ROW_CNT == LINE_SCALE) begin 
        GB_ROW_CNT <= 0;
        GB_LY <= GB_LY + 1;
    end
end
	

Quartus_dual_port_dual_clk_ram LCD_FRAME_BUFFER0(
	.write_clk(~GameBoy_clk),
	.read_clk(~clk_vga), .data(LD),
	.we(PX_VALID), .write_addr(frame_buffer_cnt),
	.read_addr({7'b0, GB_LX} + {2'b0, GB_LY, 5'b0} + {GB_LY, 7'b0}),
	.q(GB_PIXEL)
);


always_ff @(posedge clk)
begin
	if (reset) 
	begin
		bg_r <= 8'd192;
		bg_g <= 8'd156;
		bg_b <= 8'd14;
	end 
	else if (chipselect && write)
	begin
		bg_r <= 8'h80;
	end
end

always_comb 
begin
   {VGA_R, VGA_G, VGA_B} = {8'h00, 8'h00, 8'h00};
   if (VGA_BLANK_n)
   begin
		if (LX >= 80 && LX <= 560 && LY >= 24 && LY <= 456)
		begin
			unique case (GB_PIXEL)
				2'b11:
				begin
				    VGA_R = 51;
				    VGA_G = 44;
				    VGA_B = 80;
				end
				2'b10:
				begin
				    VGA_R = 70;
				    VGA_G = 135;
				    VGA_B = 143;
				end
				2'b01:
				begin
				    VGA_R = 148;
				    VGA_G = 227;
				    VGA_B = 68;
				end
				2'b00:
				begin
				    VGA_R = 226;
				    VGA_G = 243;
				    VGA_B = 228;
				end
			endcase
			// Retro
			if (GB_ROW_CNT == 0 || GB_COL_CNT == 0)
			begin
				VGA_R = 51;
				VGA_G = 44;
				VGA_B = 80;
			end
		end
		else {VGA_R, VGA_G, VGA_B} = {bg_r, bg_g, bg_b};
	end
end

endmodule

//VGA Clock Settings
module vga_counters
(
	input 	logic				clk_vga, reset,
    output 	logic [15:0]  		LX, // LX[15:0] is pixel column
	output 	logic [15:0]  		LY, // LY[9:0] is pixel row
	output 	logic				VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n
);
//logic [15:0] LX, LY, hcount_next, vcount_next;
	/*
	* 640 X 480 VGA timing for a 50 MHz clock: one pixel every other cycle
	* 
	* LX 1599 0             1279       1599 0
	*             _______________              ________
	* ___________|    Video      |____________|  Video
	* 
	* 
	* |SYNC| BP |<-- HACTIVE -->|FP|SYNC| BP |<-- HACTIVE
	*       _______________________      _____________
	* |____|       VGA_HS          |____|
	*/
	// Parameters for LX
	parameter HACTIVE      = 11'd 1280,
				HFRONT_PORCH = 11'd 32,
				HSYNC        = 11'd 192,
				HBACK_PORCH  = 11'd 96,   
				HTOTAL       = HACTIVE + HFRONT_PORCH + HSYNC +
								HBACK_PORCH; // 1600
	
	// Parameters for LY
	parameter VACTIVE      = 10'd 480,
				VFRONT_PORCH = 10'd 10,
				VSYNC        = 10'd 2,
				VBACK_PORCH  = 10'd 33,
				VTOTAL       = VACTIVE + VFRONT_PORCH + VSYNC +
								VBACK_PORCH; // 525
	
	logic endOfLine;
   
	always_ff @(posedge clk_vga or posedge reset)
		if (reset)          LX <= 0;
		else if (endOfLine) LX <= 0;
		else  	         LX <= LX + 11'd 1;

	assign endOfLine = LX == HTOTAL - 1;
		
	logic endOfField;
	
	always_ff @(posedge clk_vga or posedge reset)
		if (reset)          LY <= 0;
		else if (endOfLine)
		if (endOfField)   LY <= 0;
		else              LY <= LY + 10'd 1;

	assign endOfField = LY == VTOTAL - 1;

	assign VGA_HS = !( (LX[10:8] == 3'b101) &
				!(LX[7:5] == 3'b111));
	assign VGA_VS = !( LY[9:1] == (VACTIVE + VFRONT_PORCH) / 2);

	assign VGA_SYNC_n = 1'b0; 

	assign VGA_BLANK_n = !( LX[10] & (LX[9] | LX[8]) ) &
				!( LY[9] | (LY[8:5] == 4'b1111) );

	assign VGA_CLK = clk_vga; // should be 25 MHz clock

endmodule


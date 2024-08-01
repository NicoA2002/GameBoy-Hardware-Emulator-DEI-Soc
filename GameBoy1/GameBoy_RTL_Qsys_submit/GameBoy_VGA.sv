/*
 * Avalon memory-mapped peripheral that generates VGA
 *
 * Original By Stephen A. Edwards
 * Columbia University
 * Modified By Nicolas Alarcon
 * Columbia University
 * 1280 x 1024 @ 60 Hz
 */

module GameBoy_VGA
(
	input logic			clk, //only used for resetting background 67.1 MHz
	input logic GameBoy_clk, // the 2^22 Hz GameBoy clk for framebuffer, from Cartridge
	input logic			reset, //only used for resetting background
	input logic GameBoy_reset, // Reset synced to GameBoy clk
	
	input logic clk_vga, // 108 MHz
	
	/* Avalon Slave from lab3*/
	input logic [7:0]   writedata,
	input logic 	    write,
    input 		        chipselect,
    input logic [20:0]  address,

	/* VGA Conduit */
	output logic [7:0] 	VGA_R, VGA_G, VGA_B,
	output logic 	   	VGA_CLK, VGA_HS, VGA_VS,
						VGA_BLANK_n,
	output logic 	   	VGA_SYNC_n,

	/* GameBoy Pixel Conduit */
	input logic [1:0] LD,
	input logic       PX_VALID);

// VGA signals
logic [15:0] LX;
logic [15:0] LY;

logic [7:0]	bg_r, bg_g, bg_b;

logic [1:0] GB_PIXEL;

// Instantiations
vga_counters counters(.*);

/* The Framebuffer for gameboy */
logic [14:0] frame_buffer_cnt;
logic frame_buffer_switch;

always_ff @(posedge GameBoy_clk or posedge GameBoy_reset)
begin
    if (GameBoy_reset) begin
        frame_buffer_cnt <= 0;
        frame_buffer_switch <= 0;
    end else if (PX_VALID) frame_buffer_cnt <= (frame_buffer_cnt == 23039) ? 0: frame_buffer_cnt + 1
end

// 
logic [7:0] GB_LX, GB_LY; //frame buffer addressing
logic [2:0] GB_COL_CNT, GB_ROW_CNT;

/* Output Scaling Machine */
always_ff @(posedge clk_vga)
begin
	//in X window and read from same address
	if (LX < 160 || LX >= 1120) begin
		GB_LX <= 0;
		GB_COL_CNT <= 0;
	end else begin
		GB_COL_CNT <= GB_COL_CNT + 1;
	end

	// increment X framebuffer address
	if (GB_COL_CNT == 5)
	begin
		GB_COL_CNT <= 0;
		GB_LX <= GB_LX + 1;
	end
	
	//in Y window and read from same address
	if (LY <= 80 || LY >= 944) begin
		GB_LY <= 0;
		GB_ROW_CNT <= 0;
	end else if (LX == 1) begin
		GB_ROW_CNT <= GB_ROW_CNT + 1;
	end
	
	//increment framebuffer Y address
	if (GB_ROW_CNT == 6)
	begin
		GB_ROW_CNT <= 0;
		GB_LY <= GB_LY + 1;
	end
end
	
/*
Runs at GameBoy clock Speed and read out at VGA clock speed

2^22 Hz/(108MHz) = 606.815... 

But does not produce a noticeable jitter, 2^22 used to produce an accurate in game clock

GB_LX runs from 0-159
GB_LY runs from 0-143

Indexing finds pixel at spot
*/
Quartus_dual_port_dual_clk_ram LCD_FRAME_BUFFER0(
	.write_clk(~GameBoy_clk), 
	.read_clk(~clk_vga), 
	.data(LD), 
	.we(PX_VALID), 
	.write_addr(frame_buffer_cnt), 
	.read_addr({7'b0, GB_LX} + {2'b0, GB_LY, 5'b0} + {GB_LY, 7'b0}), 
	.q(GB_PIXEL)
);


always_ff @(posedge clk)
begin
	if (reset) 
	begin //pantone 292!
		bg_r <= 8'd105;
		bg_g <= 8'd179;
		bg_b <= 8'd231;
	end 
	else if (chipselect && write)
	begin
		bg_r <= 8'h80;
	end
end

// WISH GB Color Palette by Kerrie Lake 
// GBPixel -> RGB Decoder
always_comb 
begin
   {VGA_R, VGA_G, VGA_B} = {8'h00, 8'h00, 8'h00};
   if (VGA_BLANK_n)
   begin
		if (LX >= 160 && LX <= 1120 && LY >= 80 && LY <= 944) //within screen window
		begin
			unique case (GB_PIXEL)
				2'b11:
				begin
				    VGA_R = 98;
				    VGA_G = 46;
				    VGA_B = 76;
				end
				2'b10:
				begin
				    VGA_R = 117;
				    VGA_G = 80;
				    VGA_B = 232;
				end
				2'b01:
				begin
				    VGA_R = 96;
				    VGA_G = 143;
				    VGA_B = 207;
				end
				2'b00:
				begin
				    VGA_R = 139;
				    VGA_G = 229;
				    VGA_B = 255;
				end
			endcase
			// Lines Between Pixels
			if (GB_ROW_CNT == 0 || GB_COL_CNT == 0)
			begin
				VGA_R = 98;
				VGA_G = 46;
				VGA_B = 76;
			end
		end
		else {VGA_R, VGA_G, VGA_B} = {bg_r, bg_g, bg_b};
	end
end

endmodule

module vga_counters
(
	input 	logic				clk_vga, reset,
    output 	logic [15:0]  		LX,
	output 	logic [15:0]  		LY,
	output 	logic				VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n
);

logic [15:0] hcount, vcount;
	/*
	* 1280 X 1024 VGA timing for a 108 MHz clock: one pixel every cycle, from tinyvga.com
	*
	* HCOUNT 1687 0             1279       1687 0
	*             _______________              ________
	* ___________|    Video      |____________|  Video
	*
	*
	* |SYNC| BP |<-- HACTIVE -->|FP|HACTIVESYNC| BP |<-- HACTIVE
	*       _______________________      _____________
	* |____|       VGA_HS          |____|
	*/
	// Parameters for hcount
	parameter 		HACTIVE      = 1280,
					HFRONT_PORCH = 48,
					HSYNC        = 112,
					HBACK_PORCH  = 248,
					HTOTAL       = HACTIVE + HFRONT_PORCH + HSYNC + HBACK_PORCH;	// 1688

	// Parameters for vcount
	parameter		VACTIVE      = 1024,
					VFRONT_PORCH = 1,
					VSYNC        = 3,
					VBACK_PORCH  = 38,
					VTOTAL       = VACTIVE + VFRONT_PORCH + VSYNC + VBACK_PORCH;	// 1066

	logic endOfLine  = hcount == HTOTAL - 1;
	logic endOfField = vcount == VTOTAL - 1;
	
	always_ff @(posedge clk_vga or posedge reset)
		if (reset)          hcount <= 0;
		else if (endOfLine) hcount <= 0;
		else  	         hcount <= hcount + 1;

	always_ff @(posedge clk_vga or posedge reset)
		if (reset)          vcount <= 0;
		else if (endOfLine)
			if (endOfField)   vcount <= 0;
			else              vcount <= vcount + 1;
	
	// Horizontal and Vertical Sync -> From Graph
	assign VGA_HS = !((hcount >= HACTIVE + HFRONT_PORCH) && (hcount < HACTIVE + HFRONT_PORCH + HSYNC));
	assign VGA_VS = !((vcount >= VACTIVE + VFRONT_PORCH) && (vcount < VACTIVE + VFRONT_PORCH + VSYNC));

	assign VGA_SYNC_n = 1'b0;	// For putting sync on the green signal; unused
	
	// Horizontal Active and Vertical Active
	assign VGA_BLANK_n = (hcount < HACTIVE)  && (vcount < VACTIVE);

	assign VGA_CLK = clk_vga;	// 108 MHz clock: rising edge sensitive
	
	//assign module outputs
	assign LX = hcount;
	assign LY = vcount;

endmodule



module Sistema_Epy (
	clk_clk,
	clk_sdram_clk,
	reset_reset_n,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	uart_rxd,
	uart_txd,
	vga_external_interface_CLK,
	vga_external_interface_HS,
	vga_external_interface_VS,
	vga_external_interface_BLANK,
	vga_external_interface_SYNC,
	vga_external_interface_R,
	vga_external_interface_G,
	vga_external_interface_B);	

	input		clk_clk;
	output		clk_sdram_clk;
	input		reset_reset_n;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[15:0]	sdram_wire_dq;
	output	[1:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	input		uart_rxd;
	output		uart_txd;
	output		vga_external_interface_CLK;
	output		vga_external_interface_HS;
	output		vga_external_interface_VS;
	output		vga_external_interface_BLANK;
	output		vga_external_interface_SYNC;
	output	[7:0]	vga_external_interface_R;
	output	[7:0]	vga_external_interface_G;
	output	[7:0]	vga_external_interface_B;
endmodule

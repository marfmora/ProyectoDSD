	Sistema_Epy u0 (
		.clk_clk                      (<connected-to-clk_clk>),                      //                    clk.clk
		.clk_sdram_clk                (<connected-to-clk_sdram_clk>),                //              clk_sdram.clk
		.reset_reset_n                (<connected-to-reset_reset_n>),                //                  reset.reset_n
		.sdram_wire_addr              (<connected-to-sdram_wire_addr>),              //             sdram_wire.addr
		.sdram_wire_ba                (<connected-to-sdram_wire_ba>),                //                       .ba
		.sdram_wire_cas_n             (<connected-to-sdram_wire_cas_n>),             //                       .cas_n
		.sdram_wire_cke               (<connected-to-sdram_wire_cke>),               //                       .cke
		.sdram_wire_cs_n              (<connected-to-sdram_wire_cs_n>),              //                       .cs_n
		.sdram_wire_dq                (<connected-to-sdram_wire_dq>),                //                       .dq
		.sdram_wire_dqm               (<connected-to-sdram_wire_dqm>),               //                       .dqm
		.sdram_wire_ras_n             (<connected-to-sdram_wire_ras_n>),             //                       .ras_n
		.sdram_wire_we_n              (<connected-to-sdram_wire_we_n>),              //                       .we_n
		.uart_rxd                     (<connected-to-uart_rxd>),                     //                   uart.rxd
		.uart_txd                     (<connected-to-uart_txd>),                     //                       .txd
		.vga_external_interface_CLK   (<connected-to-vga_external_interface_CLK>),   // vga_external_interface.CLK
		.vga_external_interface_HS    (<connected-to-vga_external_interface_HS>),    //                       .HS
		.vga_external_interface_VS    (<connected-to-vga_external_interface_VS>),    //                       .VS
		.vga_external_interface_BLANK (<connected-to-vga_external_interface_BLANK>), //                       .BLANK
		.vga_external_interface_SYNC  (<connected-to-vga_external_interface_SYNC>),  //                       .SYNC
		.vga_external_interface_R     (<connected-to-vga_external_interface_R>),     //                       .R
		.vga_external_interface_G     (<connected-to-vga_external_interface_G>),     //                       .G
		.vga_external_interface_B     (<connected-to-vga_external_interface_B>)      //                       .B
	);


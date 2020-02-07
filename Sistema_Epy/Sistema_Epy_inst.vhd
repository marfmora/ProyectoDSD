	component Sistema_Epy is
		port (
			clk_clk                      : in    std_logic                     := 'X';             -- clk
			clk_sdram_clk                : out   std_logic;                                        -- clk
			reset_reset_n                : in    std_logic                     := 'X';             -- reset_n
			sdram_wire_addr              : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n             : out   std_logic;                                        -- cas_n
			sdram_wire_cke               : out   std_logic;                                        -- cke
			sdram_wire_cs_n              : out   std_logic;                                        -- cs_n
			sdram_wire_dq                : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm               : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_wire_ras_n             : out   std_logic;                                        -- ras_n
			sdram_wire_we_n              : out   std_logic;                                        -- we_n
			uart_rxd                     : in    std_logic                     := 'X';             -- rxd
			uart_txd                     : out   std_logic;                                        -- txd
			vga_external_interface_CLK   : out   std_logic;                                        -- CLK
			vga_external_interface_HS    : out   std_logic;                                        -- HS
			vga_external_interface_VS    : out   std_logic;                                        -- VS
			vga_external_interface_BLANK : out   std_logic;                                        -- BLANK
			vga_external_interface_SYNC  : out   std_logic;                                        -- SYNC
			vga_external_interface_R     : out   std_logic_vector(7 downto 0);                     -- R
			vga_external_interface_G     : out   std_logic_vector(7 downto 0);                     -- G
			vga_external_interface_B     : out   std_logic_vector(7 downto 0)                      -- B
		);
	end component Sistema_Epy;

	u0 : component Sistema_Epy
		port map (
			clk_clk                      => CONNECTED_TO_clk_clk,                      --                    clk.clk
			clk_sdram_clk                => CONNECTED_TO_clk_sdram_clk,                --              clk_sdram.clk
			reset_reset_n                => CONNECTED_TO_reset_reset_n,                --                  reset.reset_n
			sdram_wire_addr              => CONNECTED_TO_sdram_wire_addr,              --             sdram_wire.addr
			sdram_wire_ba                => CONNECTED_TO_sdram_wire_ba,                --                       .ba
			sdram_wire_cas_n             => CONNECTED_TO_sdram_wire_cas_n,             --                       .cas_n
			sdram_wire_cke               => CONNECTED_TO_sdram_wire_cke,               --                       .cke
			sdram_wire_cs_n              => CONNECTED_TO_sdram_wire_cs_n,              --                       .cs_n
			sdram_wire_dq                => CONNECTED_TO_sdram_wire_dq,                --                       .dq
			sdram_wire_dqm               => CONNECTED_TO_sdram_wire_dqm,               --                       .dqm
			sdram_wire_ras_n             => CONNECTED_TO_sdram_wire_ras_n,             --                       .ras_n
			sdram_wire_we_n              => CONNECTED_TO_sdram_wire_we_n,              --                       .we_n
			uart_rxd                     => CONNECTED_TO_uart_rxd,                     --                   uart.rxd
			uart_txd                     => CONNECTED_TO_uart_txd,                     --                       .txd
			vga_external_interface_CLK   => CONNECTED_TO_vga_external_interface_CLK,   -- vga_external_interface.CLK
			vga_external_interface_HS    => CONNECTED_TO_vga_external_interface_HS,    --                       .HS
			vga_external_interface_VS    => CONNECTED_TO_vga_external_interface_VS,    --                       .VS
			vga_external_interface_BLANK => CONNECTED_TO_vga_external_interface_BLANK, --                       .BLANK
			vga_external_interface_SYNC  => CONNECTED_TO_vga_external_interface_SYNC,  --                       .SYNC
			vga_external_interface_R     => CONNECTED_TO_vga_external_interface_R,     --                       .R
			vga_external_interface_G     => CONNECTED_TO_vga_external_interface_G,     --                       .G
			vga_external_interface_B     => CONNECTED_TO_vga_external_interface_B      --                       .B
		);


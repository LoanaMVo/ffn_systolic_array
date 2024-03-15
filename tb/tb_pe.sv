`timescale 1ns/100ps;

module pe_test;
	parameter MAC_WIDTH = 8+1;
	parameter ACC_WIDTH = MAC_WIDTH*4+1;
	parameter PE_NUM = 4;
	parameter INPUT_DATA_WIDTH = MAC_DATA_WIDTH*8+1;

	reg start;

	reg clk;
	reg rstn;
	reg acc_en;
	reg done_o;

	reg [MAC_WIDTH-1:0] data_a_00_i;
	reg [MAC_WIDTH-1:0] data_a_01_i;
	reg [MAC_WIDTH-1:0] data_a_10_i;
	reg [MAC_WIDTH-1:0] data_a_11_i;

	reg [MAC_WIDTH-1:0] data_zero;
	
	reg [MAC_WIDTH-1:0] data_b_00_i;
	reg [MAC_WIDTH-1:0] data_b_01_i;
	reg [MAC_WIDTH-1:0] data_b_10_i;
	reg [MAC_WIDTH-1:0] data_b_11_i; 	

	reg [MAC_WIDTH*4-1:0] data_a_i;
	reg [MAC_WIDTH*4-1:0] data_b_i;

	reg [ACC_WIDTH-1:0] acc_0_o; 
	reg [ACC_WIDTH-1:0] acc_1_o; 
	reg [ACC_WIDTH-1:0] acc_2_o; 
	reg [ACC_WIDTH-1:0] acc_3_o;

	//wire [ACC_WIDTH-1:0] acc_o;
	parameter PERIOD = 10;

	always #(PERIOD/2) clk=~clk;

	reg acc_0_o;
	reg acc_1_o;
	reg acc_2_o;
	reg acc_3_o;

	process_element #(
		PE_NUM,
		MAC_WIDTH,
		ACC_WIDTH
	) dut (
	    clk,
	    rstn,
		data_a_0_r,
    	data_a_1_r,
		data_b_0_r,   
		data_b_1_r`,  
	    acc_en,
		acc_0_o,
		acc_1_o,
		acc_2_o,
		acc_3_o,
		done_o
	);
	
	initial begin
		$dumpfile("pe_test.vcd");
		$dumpvars(0,pe_test);
		start = 0;
		clk = 1'b0;
		done = 	1'b0;	
		data_a_i = 'd0;
		data_b_i = 'd0;
	
		rstn = 1'b1;
		#10 rstn = 1'b0;
		#10 rstn = 1'b1;
		// begin test
		acc_en = 'd1;
		data_a_00_i = 'd1;
        data_a_01_i = 'd1;
        data_a_10_i = 'd1;
        data_a_11_i = 'd1;

        data_b_00_i = 'd1;
	    data_b_01_i = 'd1;
	    data_b_10_i = 'd1;
	    data_b_11_i = 'd1;

		data_a_0_i = {data_a_10_i, data_a_00_i};
		data_a_1_i = {data_a_11_i, data_a_01_i, data_zero};

		data_b_0_i = {data_b_10_i, data_b_00_i};
		data_b_1_i = {data_b_11_i, data_b_01_i, data_zero};

		start_test = 1;
	end
	
	always @(posedge clk) begin
		if (start) begin
			data_a_0_r <= data_a_0_i[INPUT_DATA_WIDTH - 1 -: MAC_WIDTH];
			data_a_1_r <= data_a_1_i[INPUT_DATA_WIDTH - 1 -: MAC_WIDTH];

			data_b_0_r <= data_a_0_i[INPUT_DATA_WIDTH - 1 -: MAC_WIDTH];
			data_b_1_r <= data_a_1_i[INPUT_DATA_WIDTH - 1 -: MAC_WIDTH];
			
			data_a_0_i << MAC_WIDTH;
			data_a_1_i << MAC_WIDTH;
			data_b_0_i << MAC_WIDTH;
			data_b_1_i << MAC_WIDTH;
		end
	end
	
	$finsh;

endmodule // main

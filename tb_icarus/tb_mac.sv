`timescale 1ns/100ps;

module test;
	parameter INPUT_WIDTH = 8+1;
	parameter ACC_WIDTH = 16+1;
	reg clk;
	reg rstn;
	reg [INPUT_WIDTH-1:0] data_a_i;
	reg [INPUT_WIDTH-1:0] data_b_i;
	reg acc_en;
	wire [INPUT_WIDTH-1:0] data_a_o;
	wire [INPUT_WIDTH-1:0] data_b_o;
	wire [ACC_WIDTH-1:0] acc_o;
	parameter PERIOD = 10;

	always #(PERIOD/2) clk=~clk;

	mac #(
		INPUT_WIDTH, ACC_WIDTH
	) dut (
		clk,
		rstn,
		acc_en,
		data_a_i,
		data_b_i,
		data_a_o,
		data_b_o,
		acc_o
	);

	initial begin
		$dumpfile("test.vcd");
		$dumpvars(0,test);
		clk = 0;
		data_a_i = 'd0;
		data_b_i = 'd0;

		rstn = 1'b1;
		#10 rstn = 1'b0;
		#10 rstn = 1'b1;
		acc_en = 'd1;
	
		data_a_i = -'d2;
		data_b_i = 'd2;
		#10;
	    data_a_i = 'd1;
		data_b_i = 'd2;
		#10;
		data_a_i = 'd2;
		data_b_i = -'d3;
		#10;
		data_a_i = 'd3;
		data_b_i = 'd1;
		#10;
		acc_en = 1'b0;
		#20
		$finish;
	end
	

endmodule // main

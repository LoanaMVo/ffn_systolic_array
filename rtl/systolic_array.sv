/* 
 * SYSTOLIC ARRAY
 * Author: Loana Vo
 * Data: Febuary 2024
 * ---------------------------------------------
 *	pe0	 pe1  pe2  pe3
 *  pe4  pe5  pe6  pe7
 *  pe8  pe9  pe10 pe11
 *  pe12 pe13 pe14 p15
 * ---------------------------------------------
 *  Notes:
 *  - systolic array takes in 32 bit signed input.
 *  - fixed point prescision.
 *  - performs clocked matrix multiplication.
 */

module systolic_array #(
	//PE_SIZE = 4,
	DATA_WIDTH = 16,
	ACC_WIDTH = 64,
	PE_NUM = 16
	)(
	input logic clk,
	input logic rstn,
	// data input
	input logic signed [DATA_WIDTH-1:0] data_a_0_i,
	input logic signed [DATA_WIDTH-1:0] data_a_1_i,
	input logic signed [DATA_WIDTH-1:0] data_a_2_i,
	input logic signed [DATA_WIDTH-1:0] data_a_3_i,

	input logic signed [DATA_WIDTH-1:0] data_b_0_i,
	input logic signed [DATA_WIDTH-1:0] data_b_1_i,
	input logic signed [DATA_WIDTH-1:0] data_b_2_i,
	input logic signed [DATA_WIDTH-1:0] data_b_3_i,
	// weights
	input logic signed [DATA_WIDTH*PE_NUM-1:0] weight_i;

	// accumulator enable
	input  logic acc_en,
	// accumulator output
	output logic signed [ACC_WIDTH-1:0] acc_0_o,
	output logic signed [ACC_WIDTH-1:0] acc_1_o,
	output logic signed [ACC_WIDTH-1:0] acc_2_o,
	output logic signed [ACC_WIDTH-1:0] acc_3_o,
	output logic signed [ACC_WIDTH-1:0] acc_4_o,
	output logic signed [ACC_WIDTH-1:0] acc_5_o,
	output logic signed [ACC_WIDTH-1:0] acc_6_o,
	output logic signed [ACC_WIDTH-1:0] acc_7_o,
	output logic signed [ACC_WIDTH-1:0] acc_8_o,
	output logic signed [ACC_WIDTH-1:0] acc_9_o,
	output logic signed [ACC_WIDTH-1:0] acc_10_o,
	output logic signed [ACC_WIDTH-1:0] acc_11_o,
	output logic signed [ACC_WIDTH-1:0] acc_12_o,
	output logic signed [ACC_WIDTH-1:0] acc_13_o,
	output logic signed [ACC_WIDTH-1:0] acc_14_o,
	output logic signed [ACC_WIDTH-1:0] acc_15_o,

	output logic signed [DATA_WIDTH*PE_NUM-1:0] data_a_o,
	output logic signed [DATA_WIDTH*PE_NUM-1:0] data_b_o
	);

	// accumulator output	
	logic signed [ACC_WIDTH-1:0] acc_0_r;
	logic signed [ACC_WIDTH-1:0] acc_1_r; 
	logic signed [ACC_WIDTH-1:0] acc_2_r; 
	logic signed [ACC_WIDTH-1:0] acc_3_r; 
	logic signed [ACC_WIDTH-1:0] acc_4_r;
	logic signed [ACC_WIDTH-1:0] acc_5_r; 
	logic signed [ACC_WIDTH-1:0] acc_6_r; 
	logic signed [ACC_WIDTH-1:0] acc_7_r;
	logic signed [ACC_WIDTH-1:0] acc_8_r;
	logic signed [ACC_WIDTH-1:0] acc_9_r;
	logic signed [ACC_WIDTH-1:0] acc_10_r; 
	logic signed [ACC_WIDTH-1:0] acc_11_r; 
	logic signed [ACC_WIDTH-1:0] acc_12_r; 
	logic signed [ACC_WIDTH-1:0] acc_13_r;
	logic signed [ACC_WIDTH-1:0] acc_14_r; 
	logic signed [ACC_WIDTH-1:0] acc_15_r; 
	//process element outputs
	logic signed [DATA_WIDTH-1:0] data_a_pe0;
	logic signed [DATA_WIDTH-1:0] data_a_pe1;
	logic signed [DATA_WIDTH-1:0] data_a_pe2;
	logic signed [DATA_WIDTH-1:0] data_a_pe3;
	logic signed [DATA_WIDTH-1:0] data_a_pe4;
	logic signed [DATA_WIDTH-1:0] data_a_pe5;
	logic signed [DATA_WIDTH-1:0] data_a_pe6;
	logic signed [DATA_WIDTH-1:0] data_a_pe7;
	logic signed [DATA_WIDTH-1:0] data_a_pe8;
	logic signed [DATA_WIDTH-1:0] data_a_pe9;
	logic signed [DATA_WIDTH-1:0] data_a_pe10;
	logic signed [DATA_WIDTH-1:0] data_a_pe11;
	logic signed [DATA_WIDTH-1:0] data_a_pe12;
	logic signed [DATA_WIDTH-1:0] data_a_pe13;
	logic signed [DATA_WIDTH-1:0] data_a_pe14;
	logic signed [DATA_WIDTH-1:0] data_a_pe15;

	logic signed [DATA_WIDTH-1:0] data_b_pe0;
	logic signed [DATA_WIDTH-1:0] data_b_pe1;
	logic signed [DATA_WIDTH-1:0] data_b_pe2;
	logic signed [DATA_WIDTH-1:0] data_b_pe3;
	logic signed [DATA_WIDTH-1:0] data_b_pe4;
	logic signed [DATA_WIDTH-1:0] data_b_pe5;
	logic signed [DATA_WIDTH-1:0] data_b_pe6;
	logic signed [DATA_WIDTH-1:0] data_b_pe7;
	logic signed [DATA_WIDTH-1:0] data_b_pe8;
	logic signed [DATA_WIDTH-1:0] data_b_pe9;
	logic signed [DATA_WIDTH-1:0] data_b_pe10;
	logic signed [DATA_WIDTH-1:0] data_b_pe11;
	logic signed [DATA_WIDTH-1:0] data_b_pe12;
	logic signed [DATA_WIDTH-1:0] data_b_pe13;
	logic signed [DATA_WIDTH-1:0] data_b_pe14;
	logic signed [DATA_WIDTH-1:0] data_b_pe15;

	// FSM states
	// 1 - load weights
	// 2 - compute value of each neuron

	// process element arrangment
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_0 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_0_i),
		.data_b_i(data_b_0_i),
		.data_a_o(data_a_pe0),
		.data_b_o(data_b_pe0),
		.acc_o(acc_0_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_1 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe0),
		.data_b_i(data_b_1_i),
		.data_a_o(data_a_pe1),
		.data_b_o(data_b_pe1),
		.acc_o(acc_1_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_2 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe1),
		.data_b_i(data_b_2_i),
		.data_a_o(data_a_pe2),
		.data_b_o(data_b_pe2),
		.acc_o(acc_2_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_3 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe2),
		.data_b_i(data_b_3_i),
		.data_a_o(data_a_pe3),
		.data_b_o(data_b_pe3),
		.acc_o(acc_3_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_4 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_1_i),
		.data_b_i(data_b_pe0),
		.data_a_o(data_a_pe4),
		.data_b_o(data_b_pe4),
		.acc_o(acc_4_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_5 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe4),
		.data_b_i(data_b_pe1),
		.data_a_o(data_a_pe5),
		.data_b_o(data_b_pe5),
		.acc_o(acc_5_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_6 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe5),
		.data_b_i(data_b_pe2),
		.data_a_o(data_a_pe6),
		.data_b_o(data_b_pe6),
		.acc_o(acc_6_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_7 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe6),
		.data_b_i(data_b_pe3),
		.data_a_o(data_a_pe7),
		.data_b_o(data_b_pe7),
		.acc_o(acc_7_r)
	);
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_8 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_2_i),
		.data_b_i(data_b_pe4),
		.data_a_o(data_a_pe8),
		.data_b_o(data_b_pe8),
		.acc_o(acc_8_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_9 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe8),
		.data_b_i(data_b_pe5),
		.data_a_o(data_a_pe9),
		.data_b_o(data_b_pe9),
		.acc_o(acc_9_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_10 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe9),
		.data_b_i(data_b_pe6),
		.data_a_o(data_a_pe10),
		.data_b_o(data_b_pe10),
		.acc_o(acc_10_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_11 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe10),
		.data_b_i(data_b_pe7),
		.data_a_o(data_a_pe11),
		.data_b_o(data_b_pe11),
		.acc_o(acc_11_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_12 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_3_i),
		.data_b_i(data_b_pe8),
		.data_a_o(data_a_pe12),
		.data_b_o(data_b_pe12),
		.acc_o(acc_12_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_13 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe12),
		.data_b_i(data_b_pe9),
		.data_a_o(data_a_pe13),
		.data_b_o(data_b_pe13),
		.acc_o(acc_13_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_14 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe13),
		.data_b_i(data_b_pe10),
		.data_a_o(data_a_pe14),
		.data_b_o(data_b_pe14),
		.acc_o(acc_14_r)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_15 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe14),
		.data_b_i(data_b_pe11),
		.data_a_o(data_a_pe15),
		.data_b_o(data_b_pe15),
		.acc_o(acc_15_r)
	);

	assign acc_0_o  = acc_0_r;
	assign acc_1_o  = acc_1_r;
	assign acc_2_o  = acc_2_r;
	assign acc_3_o  = acc_3_r;
	assign acc_4_o  = acc_4_r;
	assign acc_5_o  = acc_5_r;
	assign acc_6_o  = acc_6_r;
	assign acc_7_o  = acc_7_r;
	assign acc_8_o  = acc_8_r;
	assign acc_9_o  = acc_9_r;
	assign acc_10_o = acc_10_r;
	assign acc_11_o = acc_11_r;
	assign acc_12_o = acc_12_r;
	assign acc_13_o = acc_13_r;
	assign acc_14_o = acc_14_r;
	assign acc_15_o = acc_15_r;

	assign data_a_o = {data_a_pe0, data_a_pe1, data_a_pe2, data_a_pe3, data_a_pe4, data_a_pe5, data_a_pe6, data_a_pe7,
		   			   data_a_pe8, data_a_pe9, data_a_pe10, data_a_pe11, data_a_pe12, data_a_pe13, data_a_pe14, data_a_pe15};

	assign data_b_o = {data_b_pe0, data_b_pe1, data_b_pe2, data_b_pe3, data_b_pe4, data_b_pe5, data_b_pe6, data_b_pe7, 
 		   			   data_b_pe8, data_b_pe9, data_b_pe10, data_b_pe11, data_b_pe12, data_b_pe13, data_b_pe14, data_b_pe15};

endmodule // systolic_array


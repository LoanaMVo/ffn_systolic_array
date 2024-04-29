/* SYSTOLIC ARRAY
 * Author: Loana Vo
 * Data: Febuary 2024
 * ---------------------------------------------
 *	pe0	 pe1  pe2  pe3
 *  pe4  pe5  pe6  pe7
 *  pe8  pe9  pe10 pe11
 *  pe12 pe13 pe14 p15
 * ---------------------------------------------
 *  Notes:
 *  - systolic array takes in n bit signed input.
 *  - fixed point precision.
 *  - performs clocked matrix multiplication.
 */

module systolic_array #(
	DATA_WIDTH = 16,
	ACC_WIDTH = 64,
	PE_NUM = 16,
    NEURON_NUM = 4,
    WEIGHT_WIDTH = DATA_WIDTH*PE_NUM
	)(
	input logic clk,
	input logic rstn,
	// accumulator enable
	input  logic acc_en,
    // weight load enable
    input logic load_en,
	// data input
	input logic signed [DATA_WIDTH-1:0] data_0_i,
	input logic signed [DATA_WIDTH-1:0] data_1_i,
	input logic signed [DATA_WIDTH-1:0] data_2_i,
	input logic signed [DATA_WIDTH-1:0] data_3_i,
	// weights
	input logic signed [WEIGHT_WIDTH-1:0] weight_i,
	// accumulator output
	output logic signed [ACC_WIDTH*NEURON_NUM-1:0] acc_o
	);

	// process element outputs
	logic signed [DATA_WIDTH-1:0] data_pe0;
	logic signed [DATA_WIDTH-1:0] data_pe1;
	logic signed [DATA_WIDTH-1:0] data_pe2;
	logic signed [DATA_WIDTH-1:0] data_pe3;
	logic signed [DATA_WIDTH-1:0] data_pe4;
	logic signed [DATA_WIDTH-1:0] data_pe5;
	logic signed [DATA_WIDTH-1:0] data_pe6;
	logic signed [DATA_WIDTH-1:0] data_pe7;
	logic signed [DATA_WIDTH-1:0] data_pe8;
	logic signed [DATA_WIDTH-1:0] data_pe9;
	logic signed [DATA_WIDTH-1:0] data_pe10;
	logic signed [DATA_WIDTH-1:0] data_pe11;
	logic signed [DATA_WIDTH-1:0] data_pe12;
	logic signed [DATA_WIDTH-1:0] data_pe13;
	logic signed [DATA_WIDTH-1:0] data_pe14;
	logic signed [DATA_WIDTH-1:0] data_pe15;

    // intermediat accumulator result output
   	logic signed [ACC_WIDTH-1:0] acc_res_pe0;
	logic signed [ACC_WIDTH-1:0] acc_res_pe1;
	logic signed [ACC_WIDTH-1:0] acc_res_pe2;
	logic signed [ACC_WIDTH-1:0] acc_res_pe3;
	logic signed [ACC_WIDTH-1:0] acc_res_pe4;
	logic signed [ACC_WIDTH-1:0] acc_res_pe5;
	logic signed [ACC_WIDTH-1:0] acc_res_pe6;
	logic signed [ACC_WIDTH-1:0] acc_res_pe7;
	logic signed [ACC_WIDTH-1:0] acc_res_pe8;
	logic signed [ACC_WIDTH-1:0] acc_res_pe9;
	logic signed [ACC_WIDTH-1:0] acc_res_pe10;
	logic signed [ACC_WIDTH-1:0] acc_res_pe11;
	logic signed [ACC_WIDTH-1:0] acc_res_pe12;
	logic signed [ACC_WIDTH-1:0] acc_res_pe13;
	logic signed [ACC_WIDTH-1:0] acc_res_pe14;
	logic signed [ACC_WIDTH-1:0] acc_res_pe15;
	// process element arrangment
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_0 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_0_i),
        .acc_i(1'b0),
		.weight_i(weight_i[WEIGHT_WIDTH*16-1-:DATA_WIDTH]),
		.data_o(data_pe0),
		.acc_o(acc_res_pe0)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_1 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_1_i),
        .acc_i(acc_res_pe0),
		.weight_i(weight_i[WEIGHT_WIDTH*15-1-:DATA_WIDTH]),
		.data_o(data_pe1),
		.acc_o(acc_res_pe1)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_2 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_2_i),
        .acc_i(acc_res_pe1),
		.weight_i(weight_i[WEIGHT_WIDTH*14-1-:DATA_WIDTH]),
		.data_o(data_pe2),
		.acc_o(acc_res_pe2)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_3 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_3_i),
        .acc_i(acc_res_pe2),
		.weight_i(weight_i[WEIGHT_WIDTH*13-1-:DATA_WIDTH]),
		.data_o(data_pe3),
		.acc_o(acc_res_pe3) 
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_4 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe0),
        .acc_i(1'b0),
		.weight_i(weight_i[WEIGHT_WIDTH*12-1-:DATA_WIDTH]),
		.data_o(data_pe4),
		.acc_o(acc_res_pe4)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_5 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe1),
        .acc_i(acc_res_pe4),
		.weight_i(weight_i[WEIGHT_WIDTH*11-1-:DATA_WIDTH]),
		.data_o(data_pe5),
		.acc_o(acc_res_pe5)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_6 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe2),
        .acc_i(acc_res_pe5),
		.weight_i(weight_i[WEIGHT_WIDTH*10-1-:DATA_WIDTH]),
		.data_o(data_pe6),
		.acc_o(acc_res_pe6)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_7 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe3),
        .acc_i(acc_res_pe6),
		.weight_i(weight_i[WEIGHT_WIDTH*9-1-:DATA_WIDTH]),
		.data_o(data_pe7),
		.acc_o(acc_res_pe7)
	);
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_8 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe4),
        .acc_i(1'b0),
		.weight_i(weight_i[WEIGHT_WIDTH*8-1-:DATA_WIDTH]),
		.data_o(data_pe8),
		.acc_o(acc_res_pe8)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_9 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe5),
        .acc_i(acc_res_pe8),
		.weight_i(weight_i[WEIGHT_WIDTH*7-1-:DATA_WIDTH]),
		.data_o(data_pe9),
		.acc_o(acc_res_pe9)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_10 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe6),
        .acc_i(acc_res_pe9),
		.weight_i(weight_i[WEIGHT_WIDTH*6-1-:DATA_WIDTH]),
		.data_o(data_pe10),
		.acc_o(acc_res_pe10)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_11 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe7),
        .acc_i(acc_res_pe10),
		.weight_i(weight_i[WEIGHT_WIDTH*5-1-:DATA_WIDTH]),
		.data_o(data_pe11),
		.acc_o(acc_res_pe11) 
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_12 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe8),
        .acc_i(1'b0),
		.weight_i(weight_i[WEIGHT_WIDTH*4-1-:DATA_WIDTH]),
		.data_o(data_pe12),
		.acc_o(acc_res_pe12)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_13 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe9),
        .acc_i(acc_res_pe12),
		.weight_i(weight_i[WEIGHT_WIDTH*3-1-:DATA_WIDTH]),
		.data_o(data_pe13),
		.acc_o(acc_res_pe13)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_14 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe10),
        .acc_i(acc_res_pe13),
		.weight_i(weight_i[WEIGHT_WIDTH*2-1-:DATA_WIDTH]),
		.data_o(data_pe14),
		.acc_o(acc_res_pe14)
	);

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH), .WEIGHT_WIDTH(WEIGHT_WIDTH)) pe_15 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_pe11),
        .acc_i(acc_res_pe14),
		.weight_i(weight_i[WEIGHT_WIDTH*1-1-:DATA_WIDTH]),
		.data_o(data_pe15),
		.acc_o(acc_res_pe15)
	);

    assign acc_o = {acc_res_pe3, acc_res_pe7, acc_res_pe11, acc_res_pe15};

endmodule // systolic_array 


/* SYSTOLIC ARRAY - WEIGHT STATIONARY
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

/* verilator lint_off UNUSEDSIGNAL */
module systolic_array_os #(
    DATA_WIDTH = 16,
    ACC_WIDTH = 64
    )(
    input logic clk,
    input logic rstn,
    // accumulator enable
    input  logic acc_en,
    // data input
    input logic signed [DATA_WIDTH-1:0] data_0_i,
    input logic signed [DATA_WIDTH-1:0] data_1_i,
    input logic signed [DATA_WIDTH-1:0] data_2_i,
    input logic signed [DATA_WIDTH-1:0] data_3_i,
    input logic signed [DATA_WIDTH-1:0] weight_0_i,
    input logic signed [DATA_WIDTH-1:0] weight_1_i,
    input logic signed [DATA_WIDTH-1:0] weight_2_i,
    input logic signed [DATA_WIDTH-1:0] weight_3_i,
    // accumulator output
     // intermediat accumulator result output
    output logic signed [ACC_WIDTH-1:0] acc_res_pe0_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe1_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe2_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe3_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe4_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe5_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe6_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe7_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe8_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe9_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe10_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe11_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe12_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe13_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe14_o,
    output logic signed [ACC_WIDTH-1:0] acc_res_pe15_o   
    );

    // process element inputs/outputs
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

    // weight inputs/outputs
    logic signed [DATA_WIDTH-1:0] weight_pe0;
    logic signed [DATA_WIDTH-1:0] weight_pe1;
    logic signed [DATA_WIDTH-1:0] weight_pe2;
    logic signed [DATA_WIDTH-1:0] weight_pe3;
    logic signed [DATA_WIDTH-1:0] weight_pe4;
    logic signed [DATA_WIDTH-1:0] weight_pe5;
    logic signed [DATA_WIDTH-1:0] weight_pe6;
    logic signed [DATA_WIDTH-1:0] weight_pe7;
    logic signed [DATA_WIDTH-1:0] weight_pe8;
    logic signed [DATA_WIDTH-1:0] weight_pe9;
    logic signed [DATA_WIDTH-1:0] weight_pe10;
    logic signed [DATA_WIDTH-1:0] weight_pe11;
    logic signed [DATA_WIDTH-1:0] weight_pe12;
    logic signed [DATA_WIDTH-1:0] weight_pe13;
    logic signed [DATA_WIDTH-1:0] weight_pe14;
    logic signed [DATA_WIDTH-1:0] weight_pe15;

    // process element arrangment
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_0 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_0_i),
        .weight_i(weight_0_i),
        .data_o(data_pe0),
        .weight_o(weight_pe0),
        .acc_o(acc_res_pe0_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_1 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe0),
        .weight_i(weight_1_i),
        .data_o(data_pe1),
        .weight_o(weight_pe1),
        .acc_o(acc_res_pe1_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_2 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe1),
        .weight_i(weight_2_i),
        .data_o(data_pe2),
        .weight_o(weight_pe2),
        .acc_o(acc_res_pe2_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_3 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe2),
        .weight_i(weight_3_i),
        .data_o(data_pe3),
        .weight_o(weight_pe3),
        .acc_o(acc_res_pe3_o) 
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_4 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_1_i),
        .weight_i(weight_pe0),
        .data_o(data_pe4),
        .weight_o(weight_pe4),
        .acc_o(acc_res_pe4_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_5 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe4),
        .weight_i(weight_pe1),
        .data_o(data_pe5),
        .weight_o(weight_pe5),
        .acc_o(acc_res_pe5_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_6 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe5),
        .weight_i(weight_pe2),
        .data_o(data_pe6),
        .weight_o(weight_pe6),
        .acc_o(acc_res_pe6_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_7 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe6),
        .weight_i(weight_pe3),
        .data_o(data_pe7),
        .weight_o(weight_pe7),
        .acc_o(acc_res_pe7_o)
    );
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_8 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_2_i),
        .weight_i(weight_pe4),
        .data_o(data_pe8),
        .weight_o(weight_pe8),
        .acc_o(acc_res_pe8_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_9 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe8),
        .weight_i(weight_pe5),
        .data_o(data_pe9),
        .weight_o(weight_pe9),
        .acc_o(acc_res_pe9_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_10 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe9),
        .weight_i(weight_pe6),
        .data_o(data_pe10),
        .weight_o(weight_pe10),
        .acc_o(acc_res_pe10_o)
    );
    
    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_11 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe10),
        .weight_i(weight_pe7),
        .data_o(data_pe11),
        .weight_o(weight_pe11),
        .acc_o(acc_res_pe11_o) 
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_12 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_3_i),
        .weight_i(weight_pe8),
        .data_o(data_pe12),
        .weight_o(weight_pe12),
        .acc_o(acc_res_pe12_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_13 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe12),
        .weight_i(weight_pe9),
        .data_o(data_pe13),
        .weight_o(weight_pe13),
        .acc_o(acc_res_pe13_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_14 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe13),
        .weight_i(weight_pe10),
        .data_o(data_pe14),
        .weight_o(weight_pe14),
        .acc_o(acc_res_pe14_o)
    );

    pe_os #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_15 (
        .clk(clk),
        .rstn(rstn),
        .acc_en(acc_en),
        .data_i(data_pe14),
        .weight_i(weight_pe11),
        .data_o(data_pe15),
        .weight_o(weight_pe15),
        .acc_o(acc_res_pe15_o)
    );

endmodule // systolic_array 



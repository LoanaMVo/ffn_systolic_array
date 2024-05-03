// Sigmoid Activation Function
// McMaster Universiry, 4OJ4 Individual Research Course
// Author: Loana Vo
// Date: 2024
module sigmoid #(
    parameter DATA_WIDTH = 16,
    parameter FRAC_BITS = 8
)(
    input  logic signed  [DATA_WIDTH-1:0] z_i,
    output logic         [DATA_WIDTH-1:0] y_o
);

    localparam MAX_INT = 3; // 2^3 = 8, abs max range
    localparam MAX_INDEX = FRAC_BITS + MAX_INT; //
    logic [11-1:0] y_int;
    logic [11-1:0] y_neg;
    logic [11-1:0] case_i; 
    logic gt_8_pos;
    logic gt_8_neg;
    
    // assuming 2's complement, flip bits if negative sign
    // LUT reads positive values only
    /* verilator lint_off UNUSEDSIGNAL */ 
    logic [FRAC_BITS+MAX_INT:0] two_comp_convert_r;
    /* verilator lint_on UNUSEDSIGNAL*/
    assign  two_comp_convert_r = ~{1'b1, z_i[MAX_INDEX-1:0]} + 1'b1; // using an adder...rethink

    assign case_i = z_i[DATA_WIDTH-1] ? two_comp_convert_r[MAX_INDEX-1:0] : z_i[MAX_INDEX-1:0];

    sigmoid_lut #(.DATA_WIDTH(MAX_INDEX)) lut (
        .case_i(case_i),
        .y_int(y_int)
    );

    assign gt_8_pos = (| z_i[DATA_WIDTH-2:MAX_INDEX]);
    assign gt_8_neg = ((&z_i[DATA_WIDTH-1:MAX_INDEX]) & (|z_i[MAX_INDEX-1 -: MAX_INT]));

    assign y_neg = 11'b001_0000_0000 - y_int;

    assign y_o = z_i[DATA_WIDTH-1] ?                     // check MSB sign
            ( gt_8_neg ? {5'b0, y_neg} : 16'b0)  // if negative, detect is abs(z_i) >= 8 note: in 2's complement form
          : ( gt_8_pos ? {8'b1, 8'b0}  : {5'b0, y_int} ); // if positive, detect if z_i >= 8

endmodule // sigmoid

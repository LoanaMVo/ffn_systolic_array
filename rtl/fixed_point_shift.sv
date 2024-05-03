module fixed_point_shift #(
    parameter DATA_WIDTH,
    parameter FRAC_BITS
    )(
    input logic  [DATA_WIDTH-1:0] data_i,
    output logic [DATA_WIDTH-1:0] data_shifted_o
    );
    
    assign data_shifted_o = data_i << FRAC_BITS;

endmodule

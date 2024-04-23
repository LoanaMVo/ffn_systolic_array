/* Compute e^-x using Taylor Series Expansion
 * Fixed-point format: Q(INT_BITS).FRAC_BITS
 * Author: Loana Vo
 */
 module exp_e #(
    parameter DATA_WIDTH = 32,
    parameter INT_BITS = 16
)(
    input  logic signed [DATA_WIDTH-1:0] x_i,
    output logic signed [DATA_WIDTH-1:0] y_o
);
    localparam TERMS = 4;
    //logic signed [DATA_WIDTH-1:0] sum;
    //logic signed [DATA_WIDTH-1:0] term;

    logic signed [31:0] factorial[TERMS+1];
    logic signed [31:0] power;
    logic signed [31:0] term;
    logic signed [31:0] term_fixed;
    logic signed [DATA_WIDTH-1:0] result;

    /* verilator lint_off UNUSEDSIGNAL */
    logic sign_bit;
    logic [15-1:0] frac_bit;
    logic [16-1:0] int_bit;
    /* verilator lint_on UNUSEDSIGNAL */

    // Taylor Series Expansion of e^x
    // y(x) = 1 + x + 1/2!(x^2) + 1/3!(x^3) + ... + 1/n!(x^n) 
    always_comb begin
    result = 0;
    // Precalculate factorials
    factorial[0] = 1;
    for (int i = 1; i <= TERMS; i++) begin
        factorial[i] = factorial[i-1] * i;
    end

    // Calculate each term in the Taylor series and sum them up
    for (int i = 0; i < TERMS; i++) begin
        power = 1;
        for (int k = 0; k < i; k++) begin
            power *= x_i; // Calculate power of x
        end

        term = power / factorial[i]; // Calculate term of the series

        // Convert the term to fixed-point representation
        // add 1 for signed bit
        term_fixed = term << (DATA_WIDTH - INT_BITS + 1);

        result += term_fixed; // Sum up the terms
    end

    assign sign_bit = result[DATA_WIDTH-1];
    assign int_bit  = result[DATA_WIDTH-2:DATA_WIDTH-2-15];
    assign frac_bit = result[14:0];
    end
    
    assign y_o = result;

endmodule

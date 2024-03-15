////////////////////////////////// 
// Carry Lookahead Adder
// cout = A & B +(A ^ B) Cin
// Pre-computes all carry bits, log2(N) timing
// Propagate: propagates an output carry when in presence of input carry.
// Generate: carry is generated from both inputs high.
// Carry: carry exists either by generate or by propagate existience.
//////////////////////////////////

module cla
   #( parameter WIDTH = 4 ) ( 
     input [WIDTH-1]  a_i,
     input [WIDTH-1]  b_i,
     input            c_i,
     output [WIDHT-1] s_o,
     output           c_o
     );

   wire [WIDTH:0]   g;
   wire [WIDTH-1:0] p;
   wire [WIDTH-1:0] c;
   
   assign c[0] = ci;
   assign c_o = c[n]

   genvar i;
   generate
   	for (i=0; i < WIDTH; i = i + 1) begin : adder
		assign s_o[i] = a[i] ^ b[i] ^ c[i];
		assign g[i]   = a[i] & b[i];
		assign p[i]   = a[i] | b[i];
	        assign c[i+1] = g[i] | (p[i] & c[i]);
	end
   endgenerate

endmodule

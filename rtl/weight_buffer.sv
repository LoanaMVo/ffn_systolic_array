// WEIGHT BUFFER
// McMaster Universiry, 4OJ4 Individual Research Course
// Author: Loana Vo
// Date: 2024
// Memory buffer of n x m size
// n = MEM_DEPTH
// m = MEM_LEN
// each element is 16-bits width
module weight_buffer#(
    DATA_WIDTH = 16,
    MEM_LEN = 16,  // length of memory array
    MEM_DEPTH = 16 // depth of memory array
)(
    input  logic                 clk,
    input  logic                 rstn,
    input  logic                 wr_en,
    input  logic                 rd_en,
    input  logic [4-1:0]         wr_addr,
    input  logic [4-1:0]         rd_addr,
    input  logic [MEM_WIDTH-1:0] wr_data_i,
    output logic [MEM_WIDTH-1:0] rd_data_o
    );
    // width of each memory element
    localparam MEM_WIDTH = DATA_WIDTH*MEM_LEN;
    // memory registers

    logic [MEM_WIDTH-1:0] mem_r [MEM_DEPTH];
    
    always_ff @(posedge clk, negedge rstn) begin
        if(~rstn) begin
            mem_r <= '{default: '0};
        end 
        else if (wr_en) begin
            mem_r[wr_addr] <= wr_data_i;
        end else if (rd_en) begin
            rd_data_o <= mem_r[rd_addr];
            //rd_data_o <= rd_data_int;
        end
    end

endmodule // weight_buffer

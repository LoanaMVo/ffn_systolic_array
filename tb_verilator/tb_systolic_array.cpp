#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsystolic_array.h"
#include "Vsystolic_array___024root.h"

#define MAX_SIM_TIME 50
/*
	input logic clk,
	input logic rstn,
	// data input
	input logic signed [DATA_WIDTH-1:0] data_a_0_i,
	input logic signed [DATA_WIDTH-1:0] data_a_1_i,
	input logic signed [DATA_WIDTH-1:0] data_b_0_i,
	input logic signed [DATA_WIDTH-1:0] data_b_1_i,
	// accumulator enable
	input  logic acc_en,
	// accumulator output
	output logic signed [ACC_WIDTH-1:0] acc_0_o,
	output logic signed [ACC_WIDTH-1:0] acc_1_o,
	output logic signed [ACC_WIDTH-1:0] acc_2_o,
	output logic signed [ACC_WIDTH-1:0] acc_3_o,
	output logic [DATA_WIDTH*2-1:0] pe_a_o,
	output logic [DATA_WIDTH*2-1:0] pe_b_o,
	// done
	output logic done_o
*/

vluint64_t sim_time = 0;
int start_load = 0;
int counter = 0;
int cc = 0;
int data_a_0 [10] = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};
int data_a_1 [10] = {0 ,1, 2, 0, 0, 0, 0, 0, 0, 0};
int data_b_0 [10] = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};
int data_b_1 [10] = {0, 1, 2, 0, 0, 0, 0, 0, 0, 0};

int main(int argc, char** argv, char** env) {
    Vsystolic_array *dut = new Vsystolic_array;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("systolic_array_test.vcd");
	dut->rstn = 1;
    while (sim_time < MAX_SIM_TIME) {
    	if(sim_time > 1 && sim_time < 5){
    	    dut->rstn = 0;
    	} else if (sim_time > 5){
			start_load = 1;
			dut->acc_en=1;
		} else {
    	    dut->rstn = 1;
		}

		if ((start_load && cc > 1) && counter < 12){
			dut->data_a_0_i = data_a_0[counter];
			dut->data_a_1_i = data_a_1[counter];
			dut->data_b_0_i = data_b_0[counter];
			dut->data_b_1_i = data_b_1[counter];
			counter++;
			cc = 0;
		}

        dut->clk ^= 1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
		cc++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

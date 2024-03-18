#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsystolic_array.h"
#include "Vsystolic_array___024root.h"

#define MAX_SIM_TIME 50

vluint64_t sim_time = 0;
int start_load = 0;
int counter = 0;
int cc = 0;

int array_a [4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
int array_b [4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

int data_a_0 [11] = {array_a[0][0], array_a[0][1], array_a[0][2], array_a[0][3], 0, 0, 0, 0, 0, 0, 0};
int data_a_1 [11] = {0, array_a[1][0], array_a[1][1], array_a[1][2], array_a[1][3], 0, 0, 0, 0, 0, 0};
int data_a_2 [11] = {0, 0, array_a[2][0], array_a[2][1], array_a[2][2], array_a[2][3], 0, 0, 0, 0, 0};
int data_a_3 [11] = {0, 0, 0, array_a[3][0], array_a[3][1], array_a[3][2], array_a[3][3], 0, 0, 0, 0};


int data_b_0 [11] = {array_b[0][0], array_b[1][0], array_b[2][0], array_b[3][0], 0, 0, 0, 0, 0, 0, 0};
int data_b_1 [11] = {0, array_b[0][1], array_b[1][1], array_b[2][1], array_b[3][1], 0, 0, 0, 0, 0, 0};
int data_b_2 [11] = {0, 0,  array_b[0][2], array_b[1][2], array_b[2][2], array_b[3][2], 0, 0, 0, 0, 0};
int data_b_3 [11] = {0, 0, 0, array_b[0][3], array_b[1][3], array_b[2][3], array_b[3][3], 0, 0, 0, 0};


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

		if (start_load && cc > 1){
			dut->data_a_0_i = data_a_0[counter];
			dut->data_a_1_i = data_a_1[counter];
			dut->data_a_2_i = data_a_2[counter];
			dut->data_a_3_i = data_a_3[counter];

			dut->data_b_0_i = data_b_0[counter];
			dut->data_b_1_i = data_b_1[counter];
			dut->data_b_2_i = data_b_2[counter];
			dut->data_b_3_i = data_b_3[counter];
			counter++;
			cc = 0;
		} else if (cc > 2){
			dut->acc_en = 0;
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

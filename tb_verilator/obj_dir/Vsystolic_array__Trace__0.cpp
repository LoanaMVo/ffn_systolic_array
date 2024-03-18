// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystolic_array__Syms.h"


void Vsystolic_array___024root__trace_chg_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsystolic_array___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_chg_0\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsystolic_array___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsystolic_array___024root__trace_chg_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+1,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+2,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+3,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+4,(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+5,(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+6,(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+7,(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+8,(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+9,(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+10,(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+11,(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+12,(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+13,(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+14,(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+15,(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r),16);
        bufp->chgSData(oldp+16,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+17,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+18,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+19,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+20,(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+21,(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+22,(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+23,(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+24,(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+25,(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+26,(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+27,(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+28,(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+29,(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+30,(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+31,(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgQData(oldp+32,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+34,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+36,(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+38,(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+40,(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+42,(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+44,(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+46,(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+48,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+50,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+52,(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+54,(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+56,(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+58,(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+60,(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+62,(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r),64);
    }
    bufp->chgBit(oldp+64,(vlSelf->clk));
    bufp->chgBit(oldp+65,(vlSelf->rstn));
    bufp->chgSData(oldp+66,(vlSelf->data_a_0_i),16);
    bufp->chgSData(oldp+67,(vlSelf->data_a_1_i),16);
    bufp->chgSData(oldp+68,(vlSelf->data_a_2_i),16);
    bufp->chgSData(oldp+69,(vlSelf->data_a_3_i),16);
    bufp->chgSData(oldp+70,(vlSelf->data_b_0_i),16);
    bufp->chgSData(oldp+71,(vlSelf->data_b_1_i),16);
    bufp->chgSData(oldp+72,(vlSelf->data_b_2_i),16);
    bufp->chgSData(oldp+73,(vlSelf->data_b_3_i),16);
    bufp->chgBit(oldp+74,(vlSelf->acc_en));
    bufp->chgQData(oldp+75,(vlSelf->acc_0_o),64);
    bufp->chgQData(oldp+77,(vlSelf->acc_1_o),64);
    bufp->chgQData(oldp+79,(vlSelf->acc_2_o),64);
    bufp->chgQData(oldp+81,(vlSelf->acc_3_o),64);
    bufp->chgQData(oldp+83,(vlSelf->acc_4_o),64);
    bufp->chgQData(oldp+85,(vlSelf->acc_5_o),64);
    bufp->chgQData(oldp+87,(vlSelf->acc_6_o),64);
    bufp->chgQData(oldp+89,(vlSelf->acc_7_o),64);
    bufp->chgQData(oldp+91,(vlSelf->acc_8_o),64);
    bufp->chgQData(oldp+93,(vlSelf->acc_9_o),64);
    bufp->chgQData(oldp+95,(vlSelf->acc_10_o),64);
    bufp->chgQData(oldp+97,(vlSelf->acc_11_o),64);
    bufp->chgQData(oldp+99,(vlSelf->acc_12_o),64);
    bufp->chgQData(oldp+101,(vlSelf->acc_13_o),64);
    bufp->chgQData(oldp+103,(vlSelf->acc_14_o),64);
    bufp->chgQData(oldp+105,(vlSelf->acc_15_o),64);
    bufp->chgWData(oldp+107,(vlSelf->data_a_o),256);
    bufp->chgWData(oldp+115,(vlSelf->data_b_o),256);
}

void Vsystolic_array___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_cleanup\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}

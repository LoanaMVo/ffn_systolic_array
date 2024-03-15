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
        bufp->chgSData(oldp+4,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+5,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+6,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgSData(oldp+7,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r),16);
        bufp->chgQData(oldp+8,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+10,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+12,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r),64);
        bufp->chgQData(oldp+14,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r),64);
    }
    bufp->chgBit(oldp+16,(vlSelf->clk));
    bufp->chgBit(oldp+17,(vlSelf->rstn));
    bufp->chgSData(oldp+18,(vlSelf->data_a_0_i),16);
    bufp->chgSData(oldp+19,(vlSelf->data_a_1_i),16);
    bufp->chgSData(oldp+20,(vlSelf->data_b_0_i),16);
    bufp->chgSData(oldp+21,(vlSelf->data_b_1_i),16);
    bufp->chgBit(oldp+22,(vlSelf->acc_en));
    bufp->chgQData(oldp+23,(vlSelf->acc_0_o),64);
    bufp->chgQData(oldp+25,(vlSelf->acc_1_o),64);
    bufp->chgQData(oldp+27,(vlSelf->acc_2_o),64);
    bufp->chgQData(oldp+29,(vlSelf->acc_3_o),64);
    bufp->chgIData(oldp+31,(vlSelf->pe_a_o),32);
    bufp->chgIData(oldp+32,(vlSelf->pe_b_o),32);
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

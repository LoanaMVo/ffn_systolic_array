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
        bufp->chgBit(oldp+0,(vlSelf->systolic_array__DOT__done_r));
        bufp->chgBit(oldp+1,(vlSelf->systolic_array__DOT__cnt_r));
        bufp->chgWData(oldp+2,(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r),69);
        bufp->chgWData(oldp+5,(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r),69);
        bufp->chgWData(oldp+8,(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r),69);
        bufp->chgWData(oldp+11,(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r),69);
    }
    bufp->chgBit(oldp+14,(vlSelf->clk));
    bufp->chgBit(oldp+15,(vlSelf->rstn));
    bufp->chgIData(oldp+16,(vlSelf->data_a_0_i),17);
    bufp->chgIData(oldp+17,(vlSelf->data_a_1_i),17);
    bufp->chgIData(oldp+18,(vlSelf->data_b_0_i),17);
    bufp->chgIData(oldp+19,(vlSelf->data_b_1_i),17);
    bufp->chgBit(oldp+20,(vlSelf->acc_en));
    bufp->chgWData(oldp+21,(vlSelf->acc_0_o),69);
    bufp->chgWData(oldp+24,(vlSelf->acc_1_o),69);
    bufp->chgWData(oldp+27,(vlSelf->acc_2_o),69);
    bufp->chgWData(oldp+30,(vlSelf->acc_3_o),69);
    bufp->chgQData(oldp+33,(vlSelf->pe_a_o),34);
    bufp->chgQData(oldp+35,(vlSelf->pe_b_o),34);
    bufp->chgBit(oldp+37,(vlSelf->done_o));
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

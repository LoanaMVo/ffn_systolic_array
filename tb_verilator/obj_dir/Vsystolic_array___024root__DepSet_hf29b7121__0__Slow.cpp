// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array___024root.h"

VL_ATTR_COLD void Vsystolic_array___024root___eval_static(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsystolic_array___024root___eval_initial(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rstn__0 = vlSelf->rstn;
}

VL_ATTR_COLD void Vsystolic_array___024root___eval_final(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__stl(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsystolic_array___024root___eval_phase__stl(Vsystolic_array___024root* vlSelf);

VL_ATTR_COLD void Vsystolic_array___024root___eval_settle(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../rtl/systolic_array.sv", 17, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsystolic_array___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__stl(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsystolic_array___024root___stl_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->acc_0_o = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_1_o = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_2_o = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_3_o = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_4_o = vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_5_o = vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_6_o = vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_7_o = vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_8_o = vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_9_o = vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_10_o = vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_11_o = vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_12_o = vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_13_o = vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_14_o = vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_15_o = vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r;
    vlSelf->data_a_o[0U] = (((IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r) 
                             << 0x10U) | (IData)(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r));
    vlSelf->data_a_o[1U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r) 
                                              << 0x10U));
    vlSelf->data_a_o[2U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r) 
                                              << 0x10U));
    vlSelf->data_a_o[3U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r) 
                                              << 0x10U));
    vlSelf->data_a_o[4U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r) 
                                              << 0x10U));
    vlSelf->data_a_o[5U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r) 
                                >> 0x10U)) | ((IData)(
                                                      (((QData)((IData)(
                                                                        (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r) 
                                                                          << 0x10U) 
                                                                         | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r)))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r) 
                                                                           << 0x10U) 
                                                                          | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r)))))) 
                                              << 0x10U));
    vlSelf->data_a_o[6U] = (((IData)((((QData)((IData)(
                                                       (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r) 
                                                         << 0x10U) 
                                                        | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r)))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r) 
                                                                     << 0x10U) 
                                                                    | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r)))))) 
                             >> 0x10U) | ((IData)((
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r) 
                                                                       << 0x10U) 
                                                                      | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r)))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r) 
                                                                        << 0x10U) 
                                                                       | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r))))) 
                                                   >> 0x20U)) 
                                          << 0x10U));
    vlSelf->data_a_o[7U] = (((IData)(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r) 
                             << 0x10U) | ((IData)((
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r) 
                                                                       << 0x10U) 
                                                                      | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r)))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r) 
                                                                        << 0x10U) 
                                                                       | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r))))) 
                                                   >> 0x20U)) 
                                          >> 0x10U));
    vlSelf->data_b_o[0U] = (((IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r) 
                             << 0x10U) | (IData)(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r));
    vlSelf->data_b_o[1U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r) 
                                              << 0x10U));
    vlSelf->data_b_o[2U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r) 
                                              << 0x10U));
    vlSelf->data_b_o[3U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r) 
                                              << 0x10U));
    vlSelf->data_b_o[4U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r) 
                                >> 0x10U)) | ((IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r) 
                                              << 0x10U));
    vlSelf->data_b_o[5U] = (((0xffffU & (IData)(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r)) 
                             | ((IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r) 
                                >> 0x10U)) | ((IData)(
                                                      (((QData)((IData)(
                                                                        (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r) 
                                                                          << 0x10U) 
                                                                         | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r)))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r) 
                                                                           << 0x10U) 
                                                                          | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r)))))) 
                                              << 0x10U));
    vlSelf->data_b_o[6U] = (((IData)((((QData)((IData)(
                                                       (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r) 
                                                         << 0x10U) 
                                                        | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r)))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r) 
                                                                     << 0x10U) 
                                                                    | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r)))))) 
                             >> 0x10U) | ((IData)((
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r) 
                                                                       << 0x10U) 
                                                                      | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r)))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r) 
                                                                        << 0x10U) 
                                                                       | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r))))) 
                                                   >> 0x20U)) 
                                          << 0x10U));
    vlSelf->data_b_o[7U] = (((IData)(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r) 
                             << 0x10U) | ((IData)((
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r) 
                                                                       << 0x10U) 
                                                                      | (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r)))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r) 
                                                                        << 0x10U) 
                                                                       | (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r))))) 
                                                   >> 0x20U)) 
                                          >> 0x10U));
}

VL_ATTR_COLD void Vsystolic_array___024root___eval_stl(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsystolic_array___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vsystolic_array___024root___eval_triggers__stl(Vsystolic_array___024root* vlSelf);

VL_ATTR_COLD bool Vsystolic_array___024root___eval_phase__stl(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsystolic_array___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__act(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rstn)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__nba(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rstn)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsystolic_array___024root___ctor_var_reset(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rstn = VL_RAND_RESET_I(1);
    vlSelf->data_a_0_i = VL_RAND_RESET_I(16);
    vlSelf->data_a_1_i = VL_RAND_RESET_I(16);
    vlSelf->data_a_2_i = VL_RAND_RESET_I(16);
    vlSelf->data_a_3_i = VL_RAND_RESET_I(16);
    vlSelf->data_b_0_i = VL_RAND_RESET_I(16);
    vlSelf->data_b_1_i = VL_RAND_RESET_I(16);
    vlSelf->data_b_2_i = VL_RAND_RESET_I(16);
    vlSelf->data_b_3_i = VL_RAND_RESET_I(16);
    vlSelf->acc_en = VL_RAND_RESET_I(1);
    vlSelf->acc_0_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_1_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_2_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_3_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_4_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_5_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_6_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_7_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_8_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_9_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_10_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_11_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_12_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_13_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_14_o = VL_RAND_RESET_Q(64);
    vlSelf->acc_15_o = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(256, vlSelf->data_a_o);
    VL_RAND_RESET_W(256, vlSelf->data_b_o);
    vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__weight = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r = VL_RAND_RESET_Q(64);
    vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r = VL_RAND_RESET_I(16);
    vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rstn__0 = VL_RAND_RESET_I(1);
}

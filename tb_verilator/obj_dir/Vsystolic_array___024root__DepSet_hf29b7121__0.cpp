// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array___024root.h"

VL_INLINE_OPT void Vsystolic_array___024root___ico_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->pe_a_o = (((QData)((IData)(vlSelf->data_a_0_i)) 
                       << 0x11U) | (QData)((IData)(vlSelf->data_a_1_i)));
    vlSelf->pe_b_o = (((QData)((IData)(vlSelf->data_b_0_i)) 
                       << 0x11U) | (QData)((IData)(vlSelf->data_b_1_i)));
}

void Vsystolic_array___024root___eval_ico(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsystolic_array___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vsystolic_array___024root___eval_triggers__ico(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__ico(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsystolic_array___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsystolic_array___024root___eval_act(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___nba_sequent__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_37;
    // Body
    vlSelf->systolic_array__DOT__cnt_r = ((IData)(vlSelf->rstn) 
                                          && (1U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelf->systolic_array__DOT__cnt_r))));
    if ((1U & (~ (IData)(vlSelf->rstn)))) {
        vlSelf->systolic_array__DOT__done_r = 0U;
    }
    if (vlSelf->rstn) {
        if (vlSelf->acc_en) {
            VL_EXTENDS_WI(69,17, __Vtemp_4, vlSelf->data_a_1_i);
            __Vtemp_5[0U] = __Vtemp_4[0U];
            __Vtemp_5[1U] = __Vtemp_4[1U];
            __Vtemp_5[2U] = (0x1fU & __Vtemp_4[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_7, vlSelf->data_b_1_i);
            __Vtemp_8[0U] = __Vtemp_7[0U];
            __Vtemp_8[1U] = __Vtemp_7[1U];
            __Vtemp_8[2U] = (0x1fU & __Vtemp_7[2U]);
            VL_MULS_WWW(69, __Vtemp_9, __Vtemp_5, __Vtemp_8);
            VL_ADD_W(3, __Vtemp_10, vlSelf->acc_3_o, __Vtemp_9);
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[0U] 
                = __Vtemp_10[0U];
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[1U] 
                = __Vtemp_10[1U];
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[2U] 
                = (0x1fU & __Vtemp_10[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_13, vlSelf->data_a_1_i);
            __Vtemp_14[0U] = __Vtemp_13[0U];
            __Vtemp_14[1U] = __Vtemp_13[1U];
            __Vtemp_14[2U] = (0x1fU & __Vtemp_13[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_16, vlSelf->data_b_0_i);
            __Vtemp_17[0U] = __Vtemp_16[0U];
            __Vtemp_17[1U] = __Vtemp_16[1U];
            __Vtemp_17[2U] = (0x1fU & __Vtemp_16[2U]);
            VL_MULS_WWW(69, __Vtemp_18, __Vtemp_14, __Vtemp_17);
            VL_ADD_W(3, __Vtemp_19, vlSelf->acc_2_o, __Vtemp_18);
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[0U] 
                = __Vtemp_19[0U];
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[1U] 
                = __Vtemp_19[1U];
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[2U] 
                = (0x1fU & __Vtemp_19[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_22, vlSelf->data_a_0_i);
            __Vtemp_23[0U] = __Vtemp_22[0U];
            __Vtemp_23[1U] = __Vtemp_22[1U];
            __Vtemp_23[2U] = (0x1fU & __Vtemp_22[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_25, vlSelf->data_b_1_i);
            __Vtemp_26[0U] = __Vtemp_25[0U];
            __Vtemp_26[1U] = __Vtemp_25[1U];
            __Vtemp_26[2U] = (0x1fU & __Vtemp_25[2U]);
            VL_MULS_WWW(69, __Vtemp_27, __Vtemp_23, __Vtemp_26);
            VL_ADD_W(3, __Vtemp_28, vlSelf->acc_1_o, __Vtemp_27);
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[0U] 
                = __Vtemp_28[0U];
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[1U] 
                = __Vtemp_28[1U];
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[2U] 
                = (0x1fU & __Vtemp_28[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_31, vlSelf->data_a_0_i);
            __Vtemp_32[0U] = __Vtemp_31[0U];
            __Vtemp_32[1U] = __Vtemp_31[1U];
            __Vtemp_32[2U] = (0x1fU & __Vtemp_31[2U]);
            VL_EXTENDS_WI(69,17, __Vtemp_34, vlSelf->data_b_0_i);
            __Vtemp_35[0U] = __Vtemp_34[0U];
            __Vtemp_35[1U] = __Vtemp_34[1U];
            __Vtemp_35[2U] = (0x1fU & __Vtemp_34[2U]);
            VL_MULS_WWW(69, __Vtemp_36, __Vtemp_32, __Vtemp_35);
            VL_ADD_W(3, __Vtemp_37, vlSelf->acc_0_o, __Vtemp_36);
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[0U] 
                = __Vtemp_37[0U];
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[1U] 
                = __Vtemp_37[1U];
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[2U] 
                = (0x1fU & __Vtemp_37[2U]);
        }
    } else {
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[0U] = 0U;
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[1U] = 0U;
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[2U] = 0U;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[0U] = 0U;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[1U] = 0U;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[2U] = 0U;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[0U] = 0U;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[1U] = 0U;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[2U] = 0U;
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[0U] = 0U;
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[1U] = 0U;
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[2U] = 0U;
    }
    vlSelf->done_o = vlSelf->systolic_array__DOT__done_r;
    vlSelf->acc_3_o[0U] = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[0U];
    vlSelf->acc_3_o[1U] = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[1U];
    vlSelf->acc_3_o[2U] = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r[2U];
    vlSelf->acc_2_o[0U] = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[0U];
    vlSelf->acc_2_o[1U] = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[1U];
    vlSelf->acc_2_o[2U] = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r[2U];
    vlSelf->acc_1_o[0U] = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[0U];
    vlSelf->acc_1_o[1U] = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[1U];
    vlSelf->acc_1_o[2U] = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r[2U];
    vlSelf->acc_0_o[0U] = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[0U];
    vlSelf->acc_0_o[1U] = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[1U];
    vlSelf->acc_0_o[2U] = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r[2U];
}

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsystolic_array___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vsystolic_array___024root___eval_triggers__act(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__act(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsystolic_array___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsystolic_array___024root___eval_phase__nba(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsystolic_array___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__ico(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__nba(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__act(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 8, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsystolic_array___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsystolic_array___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/systolic_array.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsystolic_array___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsystolic_array___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
    if (VL_UNLIKELY((vlSelf->data_a_0_i & 0xfffe0000U))) {
        Verilated::overWidthError("data_a_0_i");}
    if (VL_UNLIKELY((vlSelf->data_a_1_i & 0xfffe0000U))) {
        Verilated::overWidthError("data_a_1_i");}
    if (VL_UNLIKELY((vlSelf->data_b_0_i & 0xfffe0000U))) {
        Verilated::overWidthError("data_b_0_i");}
    if (VL_UNLIKELY((vlSelf->data_b_1_i & 0xfffe0000U))) {
        Verilated::overWidthError("data_b_1_i");}
    if (VL_UNLIKELY((vlSelf->acc_en & 0xfeU))) {
        Verilated::overWidthError("acc_en");}
}
#endif  // VL_DEBUG

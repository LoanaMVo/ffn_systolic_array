// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array___024root.h"

void Vsystolic_array___024root___eval_act(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rstn) {
        if (vlSelf->acc_en) {
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_0_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_a_0_i)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_b_0_i))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_4_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_a_1_i)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_1_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_b_1_i))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_8_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_a_2_i)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_5_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_2_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_b_2_i))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_12_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_a_3_i)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_9_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_6_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_3_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->data_b_3_i))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_13_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_10_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_7_o + VL_MULS_QQQ(64, 
                                                 VL_MULS_QQQ(64, 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r)), 
                                                             VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r))), 
                                                 VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_14_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_11_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r 
                = (vlSelf->acc_15_o + VL_MULS_QQQ(64, 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r)), 
                                                              VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r))), 
                                                  VL_EXTENDS_QI(64,16, (IData)(vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__weight))));
            vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r;
            vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r;
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->data_b_0_i;
            vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->data_a_0_i;
            vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->data_b_1_i;
            vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->data_a_1_i;
            vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->data_b_2_i;
            vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->data_a_2_i;
            vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r 
                = vlSelf->data_a_3_i;
            vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r 
                = vlSelf->data_b_3_i;
        }
    } else {
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r = 0ULL;
        vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r = 0U;
        vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r = 0U;
        vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r = 0U;
    }
    vlSelf->acc_0_o = vlSelf->systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_4_o = vlSelf->systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_1_o = vlSelf->systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_8_o = vlSelf->systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_5_o = vlSelf->systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_2_o = vlSelf->systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_12_o = vlSelf->systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_9_o = vlSelf->systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_6_o = vlSelf->systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_3_o = vlSelf->systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_13_o = vlSelf->systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_10_o = vlSelf->systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_7_o = vlSelf->systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_14_o = vlSelf->systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r;
    vlSelf->acc_11_o = vlSelf->systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r;
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

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsystolic_array___024root___nba_sequent__TOP__0(vlSelf);
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
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../rtl/systolic_array.sv", 17, "", "NBA region did not converge.");
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
                VL_FATAL_MT("../rtl/../rtl/systolic_array.sv", 17, "", "Active region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->acc_en & 0xfeU))) {
        Verilated::overWidthError("acc_en");}
}
#endif  // VL_DEBUG

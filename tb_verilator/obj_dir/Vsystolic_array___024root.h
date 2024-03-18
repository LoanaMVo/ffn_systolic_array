// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_
#define VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_  // guard

#include "verilated.h"


class Vsystolic_array__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rstn,0,0);
        VL_IN8(acc_en,0,0);
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rstn__0;
        CData/*0:0*/ __VactContinue;
        VL_IN16(data_a_0_i,15,0);
        VL_IN16(data_a_1_i,15,0);
        VL_IN16(data_a_2_i,15,0);
        VL_IN16(data_a_3_i,15,0);
        VL_IN16(data_b_0_i,15,0);
        VL_IN16(data_b_1_i,15,0);
        VL_IN16(data_b_2_i,15,0);
        VL_IN16(data_b_3_i,15,0);
        SData/*15:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_4__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_4__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_5__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_5__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_6__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_6__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_7__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_7__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_8__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_8__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_9__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_9__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_10__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_10__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_11__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_11__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_12__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_12__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_13__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_13__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_14__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_14__DOT__mac_inst__DOT__data_b_r;
        SData/*15:0*/ systolic_array__DOT__pe_15__DOT__mac_inst__DOT__weight;
        SData/*15:0*/ systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_a_r;
        SData/*15:0*/ systolic_array__DOT__pe_15__DOT__mac_inst__DOT__data_b_r;
        VL_OUTW(data_a_o,255,0,8);
    };
    struct {
        VL_OUTW(data_b_o,255,0,8);
        IData/*31:0*/ __VactIterCount;
        VL_OUT64(acc_0_o,63,0);
        VL_OUT64(acc_1_o,63,0);
        VL_OUT64(acc_2_o,63,0);
        VL_OUT64(acc_3_o,63,0);
        VL_OUT64(acc_4_o,63,0);
        VL_OUT64(acc_5_o,63,0);
        VL_OUT64(acc_6_o,63,0);
        VL_OUT64(acc_7_o,63,0);
        VL_OUT64(acc_8_o,63,0);
        VL_OUT64(acc_9_o,63,0);
        VL_OUT64(acc_10_o,63,0);
        VL_OUT64(acc_11_o,63,0);
        VL_OUT64(acc_12_o,63,0);
        VL_OUT64(acc_13_o,63,0);
        VL_OUT64(acc_14_o,63,0);
        VL_OUT64(acc_15_o,63,0);
        QData/*63:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_4__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_5__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_6__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_7__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_8__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_9__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_10__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_11__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_12__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_13__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_14__DOT__mac_inst__DOT__acc_r;
        QData/*63:0*/ systolic_array__DOT__pe_15__DOT__mac_inst__DOT__acc_r;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsystolic_array__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array___024root(Vsystolic_array__Syms* symsp, const char* v__name);
    ~Vsystolic_array___024root();
    VL_UNCOPYABLE(Vsystolic_array___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

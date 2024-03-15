// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsystolic_array__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsystolic_array::Vsystolic_array(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsystolic_array__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rstn{vlSymsp->TOP.rstn}
    , acc_en{vlSymsp->TOP.acc_en}
    , data_a_0_i{vlSymsp->TOP.data_a_0_i}
    , data_a_1_i{vlSymsp->TOP.data_a_1_i}
    , data_b_0_i{vlSymsp->TOP.data_b_0_i}
    , data_b_1_i{vlSymsp->TOP.data_b_1_i}
    , pe_a_o{vlSymsp->TOP.pe_a_o}
    , pe_b_o{vlSymsp->TOP.pe_b_o}
    , acc_0_o{vlSymsp->TOP.acc_0_o}
    , acc_1_o{vlSymsp->TOP.acc_1_o}
    , acc_2_o{vlSymsp->TOP.acc_2_o}
    , acc_3_o{vlSymsp->TOP.acc_3_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsystolic_array::Vsystolic_array(const char* _vcname__)
    : Vsystolic_array(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsystolic_array::~Vsystolic_array() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
void Vsystolic_array___024root___eval_static(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_initial(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_settle(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf);

void Vsystolic_array::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystolic_array::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsystolic_array___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsystolic_array___024root___eval_static(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_initial(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsystolic_array___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsystolic_array::eventsPending() { return false; }

uint64_t Vsystolic_array::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsystolic_array::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsystolic_array___024root___eval_final(Vsystolic_array___024root* vlSelf);

VL_ATTR_COLD void Vsystolic_array::final() {
    Vsystolic_array___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsystolic_array::hierName() const { return vlSymsp->name(); }
const char* Vsystolic_array::modelName() const { return "Vsystolic_array"; }
unsigned Vsystolic_array::threads() const { return 1; }
void Vsystolic_array::prepareClone() const { contextp()->prepareClone(); }
void Vsystolic_array::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsystolic_array::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsystolic_array___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsystolic_array___024root__trace_init_top(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_decl_types(tracep);
    Vsystolic_array___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_register(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsystolic_array::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsystolic_array::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsystolic_array___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSYSTOLIC_ARRAY_H_
#define VERILATED_VSYSTOLIC_ARRAY_H_  // guard

#include "verilated.h"

class Vsystolic_array__Syms;
class Vsystolic_array___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vsystolic_array__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rstn,0,0);
    VL_IN8(&acc_en,0,0);
    VL_IN16(&data_a_0_i,15,0);
    VL_IN16(&data_a_1_i,15,0);
    VL_IN16(&data_a_2_i,15,0);
    VL_IN16(&data_a_3_i,15,0);
    VL_IN16(&data_b_0_i,15,0);
    VL_IN16(&data_b_1_i,15,0);
    VL_IN16(&data_b_2_i,15,0);
    VL_IN16(&data_b_3_i,15,0);
    VL_OUTW(&data_a_o,255,0,8);
    VL_OUTW(&data_b_o,255,0,8);
    VL_OUT64(&acc_0_o,63,0);
    VL_OUT64(&acc_1_o,63,0);
    VL_OUT64(&acc_2_o,63,0);
    VL_OUT64(&acc_3_o,63,0);
    VL_OUT64(&acc_4_o,63,0);
    VL_OUT64(&acc_5_o,63,0);
    VL_OUT64(&acc_6_o,63,0);
    VL_OUT64(&acc_7_o,63,0);
    VL_OUT64(&acc_8_o,63,0);
    VL_OUT64(&acc_9_o,63,0);
    VL_OUT64(&acc_10_o,63,0);
    VL_OUT64(&acc_11_o,63,0);
    VL_OUT64(&acc_12_o,63,0);
    VL_OUT64(&acc_13_o,63,0);
    VL_OUT64(&acc_14_o,63,0);
    VL_OUT64(&acc_15_o,63,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vsystolic_array___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vsystolic_array(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vsystolic_array(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vsystolic_array();
  private:
    VL_UNCOPYABLE(Vsystolic_array);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard

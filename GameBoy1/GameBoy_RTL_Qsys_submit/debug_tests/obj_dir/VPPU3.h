// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VPPU3_H_
#define _VPPU3_H_  // guard

#include "verilated.h"

//==========

class VPPU3__Syms;
class VPPU3_VerilatedVcd;


//----------

VL_MODULE(VPPU3) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(WR,0,0);
    VL_IN8(RD,0,0);
    VL_IN8(MMIO_DATA_out,7,0);
    VL_OUT8(MMIO_DATA_in,7,0);
    VL_OUT8(IRQ_V_BLANK,0,0);
    VL_OUT8(IRQ_LCDC,0,0);
    VL_OUT8(PPU_MODE,1,0);
    VL_OUT8(PPU_RD,0,0);
    VL_IN8(PPU_DATA_in,7,0);
    VL_OUT8(PX_OUT,1,0);
    VL_OUT8(PX_valid,0,0);
    VL_IN16(ADDR,15,0);
    VL_OUT16(PPU_ADDR,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ PPU3__DOT__LY;
    CData/*7:0*/ PPU3__DOT__x_pos;
    CData/*3:0*/ PPU3__DOT__sprites_loaded;
    CData/*0:0*/ PPU3__DOT__sprite_found;
    CData/*0:0*/ PPU3__DOT__sprite_shift_go;
    CData/*0:0*/ PPU3__DOT__sprite_shift_load;
    CData/*0:0*/ PPU3__DOT__bg_shift_go;
    CData/*0:0*/ PPU3__DOT__bg_shift_load;
    CData/*7:0*/ PPU3__DOT__FF40;
    CData/*7:0*/ PPU3__DOT__FF41;
    CData/*7:0*/ PPU3__DOT__FF42;
    CData/*7:0*/ PPU3__DOT__FF43;
    CData/*7:0*/ PPU3__DOT__FF44;
    CData/*7:0*/ PPU3__DOT__FF45;
    CData/*7:0*/ PPU3__DOT__FF46;
    CData/*7:0*/ PPU3__DOT__FF47;
    CData/*7:0*/ PPU3__DOT__FF48;
    CData/*7:0*/ PPU3__DOT__FF49;
    CData/*7:0*/ PPU3__DOT__FF4A;
    CData/*7:0*/ PPU3__DOT__FF4B;
    SData/*15:0*/ PPU3__DOT__current_offset;
    SData/*8:0*/ PPU3__DOT__cycles;
    CData/*7:0*/ PPU3__DOT__sprite_y_buff[10];
    CData/*7:0*/ PPU3__DOT__sprite_x_buff[10];
    CData/*7:0*/ PPU3__DOT__sprite_offset_buff[10];
    CData/*7:0*/ PPU3__DOT__sprite_tile_row[2];
    CData/*7:0*/ PPU3__DOT__bg_tile_row[2];
    CData/*7:0*/ PPU3__DOT__sprite_fifo__DOT__shift_reg[2];
    CData/*7:0*/ PPU3__DOT__bg_fifo__DOT__shift_reg[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ PPU3__DOT____Vlvbound1;
    CData/*7:0*/ PPU3__DOT____Vlvbound2;
    CData/*7:0*/ PPU3__DOT____Vlvbound3;
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vm_traceActivity;
    CData/*7:0*/ PPU3__DOT____Vcellinp__sprite_fifo__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__bg_fifo__data[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VPPU3__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VPPU3);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VPPU3(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VPPU3();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VPPU3__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VPPU3__Syms* symsp, bool first);
  private:
    static QData _change_request(VPPU3__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VPPU3__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VPPU3__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VPPU3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VPPU3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VPPU3__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VPPU3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard

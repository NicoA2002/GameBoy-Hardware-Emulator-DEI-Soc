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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*7:0*/ PPU3__DOT__FF40;
        CData/*7:0*/ PPU3__DOT__FF40_NEXT;
        CData/*7:0*/ PPU3__DOT__FF41;
        CData/*7:0*/ PPU3__DOT__FF41_NEXT;
        CData/*7:0*/ PPU3__DOT__FF42;
        CData/*7:0*/ PPU3__DOT__FF42_NEXT;
        CData/*7:0*/ PPU3__DOT__FF43;
        CData/*7:0*/ PPU3__DOT__FF43_NEXT;
        CData/*7:0*/ PPU3__DOT__FF45;
        CData/*7:0*/ PPU3__DOT__FF45_NEXT;
        CData/*7:0*/ PPU3__DOT__FF46;
        CData/*7:0*/ PPU3__DOT__FF46_NEXT;
        CData/*7:0*/ PPU3__DOT__FF47;
        CData/*7:0*/ PPU3__DOT__FF47_NEXT;
        CData/*7:0*/ PPU3__DOT__FF48;
        CData/*7:0*/ PPU3__DOT__FF48_NEXT;
        CData/*7:0*/ PPU3__DOT__FF49;
        CData/*7:0*/ PPU3__DOT__FF49_NEXT;
        CData/*7:0*/ PPU3__DOT__FF4A;
        CData/*7:0*/ PPU3__DOT__FF4A_NEXT;
        CData/*7:0*/ PPU3__DOT__FF4B;
        CData/*7:0*/ PPU3__DOT__FF4B_NEXT;
        CData/*7:0*/ PPU3__DOT__LX;
        CData/*7:0*/ PPU3__DOT__LX_NEXT;
        CData/*7:0*/ PPU3__DOT__LY;
        CData/*7:0*/ PPU3__DOT__LY_NEXT;
        CData/*0:0*/ PPU3__DOT__OAM_SEARCH_GO;
        CData/*0:0*/ PPU3__DOT__BGWD_RENDER_GO;
        CData/*0:0*/ PPU3__DOT__SHIFT_REG_GO;
        CData/*7:0*/ PPU3__DOT__SP_MAP;
        CData/*2:0*/ PPU3__DOT__SCX_CNT;
        CData/*2:0*/ PPU3__DOT__SCX_CNT_NEXT;
        CData/*3:0*/ PPU3__DOT__sp_table_cnt;
        CData/*0:0*/ PPU3__DOT__sp_found;
        CData/*0:0*/ PPU3__DOT__isHitSP;
        CData/*3:0*/ PPU3__DOT__sp_to_fetch;
        CData/*0:0*/ PPU3__DOT__SP_RENDER_GO;
        CData/*3:0*/ PPU3__DOT__SP_NEXT_SLOT;
        CData/*3:0*/ PPU3__DOT__SP_NEXT_SLOT_NEXT;
        CData/*2:0*/ PPU3__DOT__SP_CNT;
        CData/*7:0*/ PPU3__DOT__SP_FLAG;
        CData/*0:0*/ PPU3__DOT__isHitWD;
        CData/*2:0*/ PPU3__DOT__BGWD_CNT;
        CData/*7:0*/ PPU3__DOT__BGWD_MAP;
        CData/*7:0*/ PPU3__DOT__BGWD_TILE_DATA0;
        CData/*7:0*/ PPU3__DOT__BGWD_TILE_DATA1;
        CData/*0:0*/ PPU3__DOT__isFetchWD;
        CData/*0:0*/ PPU3__DOT__isFetchWD_NEXT;
        CData/*0:0*/ PPU3__DOT__FIRST_FETCH_WD_DONE;
        CData/*0:0*/ PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_SEL;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT;
        CData/*1:0*/ PPU3__DOT__BGWD_SHIFT_REG_LOAD;
        CData/*1:0*/ PPU3__DOT__BGWD_PX_MAP;
        CData/*1:0*/ PPU3__DOT__BGWD_PX_DATA;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_A_VALID;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_B_VALID;
        CData/*0:0*/ PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT;
        CData/*2:0*/ PPU3__DOT__RENDER_CNT;
        CData/*2:0*/ PPU3__DOT__RENDER_CNT_NEXT;
        CData/*0:0*/ PPU3__DOT__IRQ_STAT;
        CData/*0:0*/ PPU3__DOT__IRQ_STAT_NEXT;
        SData/*15:0*/ PPU3__DOT__PPU_CNT;
    };
    struct {
        SData/*15:0*/ PPU3__DOT__PPU_CNT_NEXT;
        SData/*9:0*/ PPU3__DOT__sp_not_used;
        SData/*9:0*/ PPU3__DOT__sp_not_used_next;
        SData/*9:0*/ PPU3__DOT__SP_SHIFT_REG_LOAD;
        SData/*8:0*/ PPU3__DOT__SP_TILE_DATA0;
        SData/*8:0*/ PPU3__DOT__SP_TILE_DATA1;
        IData/*31:0*/ PPU3__DOT__PPU_STATE;
        IData/*31:0*/ PPU3__DOT__PPU_STATE_NEXT;
        CData/*5:0*/ PPU3__DOT__sp_name_table[10];
        CData/*7:0*/ PPU3__DOT__sp_name_table_x[10];
        CData/*7:0*/ PPU3__DOT__sp_y_table[10];
        CData/*7:0*/ PPU3__DOT__sp_x_table[10];
        CData/*1:0*/ PPU3__DOT__SP_PX_MAP[10];
        CData/*1:0*/ PPU3__DOT__SP_PRIPN[10];
        CData/*1:0*/ PPU3__DOT__SP_PRIPN_NEXT[10];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[2];
        CData/*7:0*/ PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[2];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*1:0*/ PPU3__DOT____Vlvbound2;
    CData/*1:0*/ PPU3__DOT____Vlvbound3;
    CData/*0:0*/ PPU3__DOT____Vlvbound4;
    CData/*0:0*/ PPU3__DOT____Vlvbound5;
    CData/*1:0*/ PPU3__DOT____Vlvbound6;
    CData/*7:0*/ PPU3__DOT____Vlvbound9;
    CData/*5:0*/ PPU3__DOT____Vlvbound10;
    CData/*7:0*/ PPU3__DOT____Vlvbound11;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[2];
    CData/*7:0*/ PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[2];
    
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
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPPU3.h for the primary calling header

#ifndef VERILATED_VPPU3___024ROOT_H_
#define VERILATED_VPPU3___024ROOT_H_  // guard

#include "verilated.h"

class VPPU3__Syms;

class VPPU3___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
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
    CData/*7:0*/ PPU3__DOT____Vlvbound_ha2b8a78f__0;
    CData/*7:0*/ PPU3__DOT____Vlvbound_he36bfb9b__0;
    CData/*7:0*/ PPU3__DOT____Vlvbound_hf25d2aed__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN16(ADDR,15,0);
    VL_OUT16(PPU_ADDR,15,0);
    SData/*15:0*/ PPU3__DOT__current_offset;
    SData/*8:0*/ PPU3__DOT__cycles;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 10> PPU3__DOT__sprite_y_buff;
    VlUnpacked<CData/*7:0*/, 10> PPU3__DOT__sprite_x_buff;
    VlUnpacked<CData/*7:0*/, 10> PPU3__DOT__sprite_offset_buff;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT__sprite_tile_row;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT____Vcellinp__sprite_fifo__data;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT__bg_tile_row;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT____Vcellinp__bg_fifo__data;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT__sprite_fifo__DOT__shift_reg;
    VlUnpacked<CData/*7:0*/, 2> PPU3__DOT__bg_fifo__DOT__shift_reg;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPPU3__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPPU3___024root(VPPU3__Syms* symsp, const char* v__name);
    ~VPPU3___024root();
    VL_UNCOPYABLE(VPPU3___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPPU3__Syms.h"


//======================

void VPPU3::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VPPU3::traceInit, &VPPU3::traceFull, &VPPU3::traceChg, this);
}
void VPPU3::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VPPU3* t = (VPPU3*)userthis;
    VPPU3__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VPPU3::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VPPU3* t = (VPPU3*)userthis;
    VPPU3__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VPPU3::traceInitThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VPPU3::traceFullThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VPPU3::traceInitThis__1(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+465,"clk", false,-1);
        vcdp->declBit(c+473,"rst", false,-1);
        vcdp->declBus(c+481,"ADDR", false,-1, 15,0);
        vcdp->declBit(c+489,"WR", false,-1);
        vcdp->declBit(c+497,"RD", false,-1);
        vcdp->declBus(c+505,"MMIO_DATA_out", false,-1, 7,0);
        vcdp->declBus(c+513,"MMIO_DATA_in", false,-1, 7,0);
        vcdp->declBit(c+521,"IRQ_V_BLANK", false,-1);
        vcdp->declBit(c+529,"IRQ_LCDC", false,-1);
        vcdp->declBus(c+537,"PPU_MODE", false,-1, 1,0);
        vcdp->declBit(c+545,"PPU_RD", false,-1);
        vcdp->declBus(c+553,"PPU_ADDR", false,-1, 15,0);
        vcdp->declBus(c+561,"PPU_DATA_in", false,-1, 7,0);
        vcdp->declBus(c+569,"PX_OUT", false,-1, 1,0);
        vcdp->declBit(c+577,"PX_valid", false,-1);
        vcdp->declBit(c+465,"PPU3 clk", false,-1);
        vcdp->declBit(c+473,"PPU3 rst", false,-1);
        vcdp->declBus(c+481,"PPU3 ADDR", false,-1, 15,0);
        vcdp->declBit(c+489,"PPU3 WR", false,-1);
        vcdp->declBit(c+497,"PPU3 RD", false,-1);
        vcdp->declBus(c+505,"PPU3 MMIO_DATA_out", false,-1, 7,0);
        vcdp->declBus(c+513,"PPU3 MMIO_DATA_in", false,-1, 7,0);
        vcdp->declBit(c+521,"PPU3 IRQ_V_BLANK", false,-1);
        vcdp->declBit(c+529,"PPU3 IRQ_LCDC", false,-1);
        vcdp->declBus(c+537,"PPU3 PPU_MODE", false,-1, 1,0);
        vcdp->declBit(c+545,"PPU3 PPU_RD", false,-1);
        vcdp->declBus(c+553,"PPU3 PPU_ADDR", false,-1, 15,0);
        vcdp->declBus(c+561,"PPU3 PPU_DATA_in", false,-1, 7,0);
        vcdp->declBus(c+569,"PPU3 PX_OUT", false,-1, 1,0);
        vcdp->declBit(c+577,"PPU3 PX_valid", false,-1);
        vcdp->declBit(c+585,"PPU3 sprite_in_range", false,-1);
        vcdp->declBus(c+33,"PPU3 LY", false,-1, 7,0);
        vcdp->declBus(c+41,"PPU3 x_pos", false,-1, 7,0);
        vcdp->declBus(c+593,"PPU3 current_offset", false,-1, 15,0);
        vcdp->declBus(c+49,"PPU3 sprites_loaded", false,-1, 3,0);
        vcdp->declBit(c+57,"PPU3 sprite_found", false,-1);
        vcdp->declBus(c+65,"PPU3 cycles", false,-1, 8,0);
        {int i; for (i=0; i<10; i++) {
                vcdp->declBus(c+73+i*1,"PPU3 sprite_y_buff", true,(i+0), 7,0);}}
        {int i; for (i=0; i<10; i++) {
                vcdp->declBus(c+153+i*1,"PPU3 sprite_x_buff", true,(i+0), 7,0);}}
        {int i; for (i=0; i<10; i++) {
                vcdp->declBus(c+233+i*1,"PPU3 sprite_offset_buff", true,(i+0), 7,0);}}
        vcdp->declBit(c+601,"PPU3 sprite_shift_go", false,-1);
        vcdp->declBit(c+609,"PPU3 sprite_shift_load", false,-1);
        vcdp->declBus(c+313,"PPU3 sprite_shift_output", false,-1, 1,0);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+617+i*1,"PPU3 sprite_tile_row", true,(i+0), 7,0);}}
        vcdp->declBit(c+633,"PPU3 bg_shift_go", false,-1);
        vcdp->declBit(c+641,"PPU3 bg_shift_load", false,-1);
        vcdp->declBus(c+321,"PPU3 bg_shift_output", false,-1, 1,0);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+649+i*1,"PPU3 bg_tile_row", true,(i+0), 7,0);}}
        vcdp->declBus(c+329,"PPU3 LCDC", false,-1, 7,0);
        vcdp->declBus(c+337,"PPU3 STAT", false,-1, 7,0);
        vcdp->declBus(c+345,"PPU3 SCX", false,-1, 7,0);
        vcdp->declBus(c+353,"PPU3 SCY", false,-1, 7,0);
        vcdp->declBus(c+361,"PPU3 LYC", false,-1, 7,0);
        vcdp->declBus(c+369,"PPU3 DMA", false,-1, 7,0);
        vcdp->declBus(c+377,"PPU3 BGP", false,-1, 7,0);
        vcdp->declBus(c+385,"PPU3 OBP0", false,-1, 7,0);
        vcdp->declBus(c+393,"PPU3 OBP1", false,-1, 7,0);
        vcdp->declBus(c+401,"PPU3 WX", false,-1, 7,0);
        vcdp->declBus(c+409,"PPU3 WY", false,-1, 7,0);
        vcdp->declBus(c+329,"PPU3 FF40", false,-1, 7,0);
        vcdp->declBus(c+337,"PPU3 FF41", false,-1, 7,0);
        vcdp->declBus(c+353,"PPU3 FF42", false,-1, 7,0);
        vcdp->declBus(c+345,"PPU3 FF43", false,-1, 7,0);
        vcdp->declBus(c+665,"PPU3 FF44", false,-1, 7,0);
        vcdp->declBus(c+361,"PPU3 FF45", false,-1, 7,0);
        vcdp->declBus(c+369,"PPU3 FF46", false,-1, 7,0);
        vcdp->declBus(c+377,"PPU3 FF47", false,-1, 7,0);
        vcdp->declBus(c+417,"PPU3 FF48", false,-1, 7,0);
        vcdp->declBus(c+425,"PPU3 FF49", false,-1, 7,0);
        vcdp->declBus(c+409,"PPU3 FF4A", false,-1, 7,0);
        vcdp->declBus(c+401,"PPU3 FF4B", false,-1, 7,0);
        vcdp->declBit(c+465,"PPU3 sprite_fifo clk", false,-1);
        vcdp->declBit(c+473,"PPU3 sprite_fifo rst", false,-1);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+1+i*1,"PPU3 sprite_fifo data", true,(i+0), 7,0);}}
        vcdp->declBit(c+601,"PPU3 sprite_fifo go", false,-1);
        vcdp->declBit(c+609,"PPU3 sprite_fifo load", false,-1);
        vcdp->declBus(c+313,"PPU3 sprite_fifo q", false,-1, 1,0);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+433+i*1,"PPU3 sprite_fifo shift_reg", true,(i+0), 7,0);}}
        vcdp->declBit(c+465,"PPU3 bg_fifo clk", false,-1);
        vcdp->declBit(c+473,"PPU3 bg_fifo rst", false,-1);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+17+i*1,"PPU3 bg_fifo data", true,(i+0), 7,0);}}
        vcdp->declBit(c+633,"PPU3 bg_fifo go", false,-1);
        vcdp->declBit(c+641,"PPU3 bg_fifo load", false,-1);
        vcdp->declBus(c+321,"PPU3 bg_fifo q", false,-1, 1,0);
        {int i; for (i=0; i<2; i++) {
                vcdp->declBus(c+449+i*1,"PPU3 bg_fifo shift_reg", true,(i+0), 7,0);}}
    }
}

void VPPU3::traceFullThis__1(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[0]),8);
        vcdp->fullBus(c+2,(vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[1]),8);
        vcdp->fullBus(c+17,(vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[0]),8);
        vcdp->fullBus(c+18,(vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[1]),8);
        vcdp->fullBus(c+33,(vlTOPp->PPU3__DOT__LY),8);
        vcdp->fullBus(c+41,(vlTOPp->PPU3__DOT__x_pos),8);
        vcdp->fullBus(c+49,(vlTOPp->PPU3__DOT__sprites_loaded),4);
        vcdp->fullBit(c+57,(vlTOPp->PPU3__DOT__sprite_found));
        vcdp->fullBus(c+65,(vlTOPp->PPU3__DOT__cycles),9);
        vcdp->fullBus(c+73,(vlTOPp->PPU3__DOT__sprite_y_buff[0]),8);
        vcdp->fullBus(c+74,(vlTOPp->PPU3__DOT__sprite_y_buff[1]),8);
        vcdp->fullBus(c+75,(vlTOPp->PPU3__DOT__sprite_y_buff[2]),8);
        vcdp->fullBus(c+76,(vlTOPp->PPU3__DOT__sprite_y_buff[3]),8);
        vcdp->fullBus(c+77,(vlTOPp->PPU3__DOT__sprite_y_buff[4]),8);
        vcdp->fullBus(c+78,(vlTOPp->PPU3__DOT__sprite_y_buff[5]),8);
        vcdp->fullBus(c+79,(vlTOPp->PPU3__DOT__sprite_y_buff[6]),8);
        vcdp->fullBus(c+80,(vlTOPp->PPU3__DOT__sprite_y_buff[7]),8);
        vcdp->fullBus(c+81,(vlTOPp->PPU3__DOT__sprite_y_buff[8]),8);
        vcdp->fullBus(c+82,(vlTOPp->PPU3__DOT__sprite_y_buff[9]),8);
        vcdp->fullBus(c+153,(vlTOPp->PPU3__DOT__sprite_x_buff[0]),8);
        vcdp->fullBus(c+154,(vlTOPp->PPU3__DOT__sprite_x_buff[1]),8);
        vcdp->fullBus(c+155,(vlTOPp->PPU3__DOT__sprite_x_buff[2]),8);
        vcdp->fullBus(c+156,(vlTOPp->PPU3__DOT__sprite_x_buff[3]),8);
        vcdp->fullBus(c+157,(vlTOPp->PPU3__DOT__sprite_x_buff[4]),8);
        vcdp->fullBus(c+158,(vlTOPp->PPU3__DOT__sprite_x_buff[5]),8);
        vcdp->fullBus(c+159,(vlTOPp->PPU3__DOT__sprite_x_buff[6]),8);
        vcdp->fullBus(c+160,(vlTOPp->PPU3__DOT__sprite_x_buff[7]),8);
        vcdp->fullBus(c+161,(vlTOPp->PPU3__DOT__sprite_x_buff[8]),8);
        vcdp->fullBus(c+162,(vlTOPp->PPU3__DOT__sprite_x_buff[9]),8);
        vcdp->fullBus(c+233,(vlTOPp->PPU3__DOT__sprite_offset_buff[0]),8);
        vcdp->fullBus(c+234,(vlTOPp->PPU3__DOT__sprite_offset_buff[1]),8);
        vcdp->fullBus(c+235,(vlTOPp->PPU3__DOT__sprite_offset_buff[2]),8);
        vcdp->fullBus(c+236,(vlTOPp->PPU3__DOT__sprite_offset_buff[3]),8);
        vcdp->fullBus(c+237,(vlTOPp->PPU3__DOT__sprite_offset_buff[4]),8);
        vcdp->fullBus(c+238,(vlTOPp->PPU3__DOT__sprite_offset_buff[5]),8);
        vcdp->fullBus(c+239,(vlTOPp->PPU3__DOT__sprite_offset_buff[6]),8);
        vcdp->fullBus(c+240,(vlTOPp->PPU3__DOT__sprite_offset_buff[7]),8);
        vcdp->fullBus(c+241,(vlTOPp->PPU3__DOT__sprite_offset_buff[8]),8);
        vcdp->fullBus(c+242,(vlTOPp->PPU3__DOT__sprite_offset_buff[9]),8);
        vcdp->fullBus(c+313,(((2U & (vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                     [1U] >> 6U)) | 
                              (1U & (vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                     [0U] >> 7U)))),2);
        vcdp->fullBus(c+321,(((2U & (vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                                     [1U] >> 6U)) | 
                              (1U & (vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                                     [0U] >> 7U)))),2);
        vcdp->fullBus(c+329,(vlTOPp->PPU3__DOT__FF40),8);
        vcdp->fullBus(c+337,(vlTOPp->PPU3__DOT__FF41),8);
        vcdp->fullBus(c+345,(vlTOPp->PPU3__DOT__FF43),8);
        vcdp->fullBus(c+353,(vlTOPp->PPU3__DOT__FF42),8);
        vcdp->fullBus(c+361,(vlTOPp->PPU3__DOT__FF45),8);
        vcdp->fullBus(c+369,(vlTOPp->PPU3__DOT__FF46),8);
        vcdp->fullBus(c+377,(vlTOPp->PPU3__DOT__FF47),8);
        vcdp->fullBus(c+385,((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48))),8);
        vcdp->fullBus(c+393,((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF49))),8);
        vcdp->fullBus(c+401,(vlTOPp->PPU3__DOT__FF4B),8);
        vcdp->fullBus(c+409,(vlTOPp->PPU3__DOT__FF4A),8);
        vcdp->fullBus(c+417,(vlTOPp->PPU3__DOT__FF48),8);
        vcdp->fullBus(c+425,(vlTOPp->PPU3__DOT__FF49),8);
        vcdp->fullBus(c+433,(vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0]),8);
        vcdp->fullBus(c+434,(vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1]),8);
        vcdp->fullBus(c+449,(vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0]),8);
        vcdp->fullBus(c+450,(vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1]),8);
        vcdp->fullBit(c+465,(vlTOPp->clk));
        vcdp->fullBit(c+473,(vlTOPp->rst));
        vcdp->fullBus(c+481,(vlTOPp->ADDR),16);
        vcdp->fullBit(c+489,(vlTOPp->WR));
        vcdp->fullBit(c+497,(vlTOPp->RD));
        vcdp->fullBus(c+505,(vlTOPp->MMIO_DATA_out),8);
        vcdp->fullBus(c+513,(vlTOPp->MMIO_DATA_in),8);
        vcdp->fullBit(c+521,(vlTOPp->IRQ_V_BLANK));
        vcdp->fullBit(c+529,(vlTOPp->IRQ_LCDC));
        vcdp->fullBus(c+537,(vlTOPp->PPU_MODE),2);
        vcdp->fullBit(c+545,(vlTOPp->PPU_RD));
        vcdp->fullBus(c+553,(vlTOPp->PPU_ADDR),16);
        vcdp->fullBus(c+561,(vlTOPp->PPU_DATA_in),8);
        vcdp->fullBus(c+569,(vlTOPp->PX_OUT),2);
        vcdp->fullBit(c+577,(vlTOPp->PX_valid));
        vcdp->fullBit(c+585,(((((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                               >= (IData)(vlTOPp->PPU_DATA_in)) 
                              & (((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                 < ((IData)(vlTOPp->PPU_DATA_in) 
                                    + ((IData)(8U) 
                                       << (1U & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                 >> 2U))))))));
        vcdp->fullBus(c+593,((0xffffU & ((IData)(vlTOPp->PPU_ADDR) 
                                         - (IData)(0xfe00U)))),16);
        vcdp->fullBit(c+601,(vlTOPp->PPU3__DOT__sprite_shift_go));
        vcdp->fullBit(c+609,(vlTOPp->PPU3__DOT__sprite_shift_load));
        vcdp->fullBus(c+617,(vlTOPp->PPU3__DOT__sprite_tile_row[0]),8);
        vcdp->fullBus(c+618,(vlTOPp->PPU3__DOT__sprite_tile_row[1]),8);
        vcdp->fullBit(c+633,(vlTOPp->PPU3__DOT__bg_shift_go));
        vcdp->fullBit(c+641,(vlTOPp->PPU3__DOT__bg_shift_load));
        vcdp->fullBus(c+649,(vlTOPp->PPU3__DOT__bg_tile_row[0]),8);
        vcdp->fullBus(c+650,(vlTOPp->PPU3__DOT__bg_tile_row[1]),8);
        vcdp->fullBus(c+665,(vlTOPp->PPU3__DOT__FF44),8);
    }
}

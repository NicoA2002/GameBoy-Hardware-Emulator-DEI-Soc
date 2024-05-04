// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPPU3__Syms.h"


VL_ATTR_COLD void VPPU3___024root__trace_init_sub__TOP__0(VPPU3___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+59,"clk", false,-1);
    tracep->declBit(c+60,"rst", false,-1);
    tracep->declBus(c+61,"ADDR", false,-1, 15,0);
    tracep->declBit(c+62,"WR", false,-1);
    tracep->declBit(c+63,"RD", false,-1);
    tracep->declBus(c+64,"MMIO_DATA_out", false,-1, 7,0);
    tracep->declBus(c+65,"MMIO_DATA_in", false,-1, 7,0);
    tracep->declBit(c+66,"IRQ_V_BLANK", false,-1);
    tracep->declBit(c+67,"IRQ_LCDC", false,-1);
    tracep->declBus(c+68,"PPU_MODE", false,-1, 1,0);
    tracep->declBit(c+69,"PPU_RD", false,-1);
    tracep->declBus(c+70,"PPU_ADDR", false,-1, 15,0);
    tracep->declBus(c+71,"PPU_DATA_in", false,-1, 7,0);
    tracep->declBus(c+72,"PX_OUT", false,-1, 1,0);
    tracep->declBit(c+73,"PX_valid", false,-1);
    tracep->pushNamePrefix("PPU3 ");
    tracep->declBit(c+59,"clk", false,-1);
    tracep->declBit(c+60,"rst", false,-1);
    tracep->declBus(c+61,"ADDR", false,-1, 15,0);
    tracep->declBit(c+62,"WR", false,-1);
    tracep->declBit(c+63,"RD", false,-1);
    tracep->declBus(c+64,"MMIO_DATA_out", false,-1, 7,0);
    tracep->declBus(c+65,"MMIO_DATA_in", false,-1, 7,0);
    tracep->declBit(c+66,"IRQ_V_BLANK", false,-1);
    tracep->declBit(c+67,"IRQ_LCDC", false,-1);
    tracep->declBus(c+68,"PPU_MODE", false,-1, 1,0);
    tracep->declBit(c+69,"PPU_RD", false,-1);
    tracep->declBus(c+70,"PPU_ADDR", false,-1, 15,0);
    tracep->declBus(c+71,"PPU_DATA_in", false,-1, 7,0);
    tracep->declBus(c+72,"PX_OUT", false,-1, 1,0);
    tracep->declBit(c+73,"PX_valid", false,-1);
    tracep->declBit(c+74,"sprite_in_range", false,-1);
    tracep->declBus(c+5,"LY", false,-1, 7,0);
    tracep->declBus(c+6,"x_pos", false,-1, 7,0);
    tracep->declBus(c+75,"current_offset", false,-1, 15,0);
    tracep->declBus(c+7,"sprites_loaded", false,-1, 3,0);
    tracep->declBit(c+8,"sprite_found", false,-1);
    tracep->declBus(c+9,"cycles", false,-1, 8,0);
    for (int i = 0; i < 10; ++i) {
        tracep->declBus(c+10+i*1,"sprite_y_buff", true,(i+0), 7,0);
    }
    for (int i = 0; i < 10; ++i) {
        tracep->declBus(c+20+i*1,"sprite_x_buff", true,(i+0), 7,0);
    }
    for (int i = 0; i < 10; ++i) {
        tracep->declBus(c+30+i*1,"sprite_offset_buff", true,(i+0), 7,0);
    }
    tracep->declBit(c+76,"sprite_shift_go", false,-1);
    tracep->declBit(c+77,"sprite_shift_load", false,-1);
    tracep->declBus(c+40,"sprite_shift_output", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+78+i*1,"sprite_tile_row", true,(i+0), 7,0);
    }
    tracep->declBit(c+80,"bg_shift_go", false,-1);
    tracep->declBit(c+81,"bg_shift_load", false,-1);
    tracep->declBus(c+41,"bg_shift_output", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+82+i*1,"bg_tile_row", true,(i+0), 7,0);
    }
    tracep->declBus(c+42,"LCDC", false,-1, 7,0);
    tracep->declBus(c+43,"STAT", false,-1, 7,0);
    tracep->declBus(c+44,"SCX", false,-1, 7,0);
    tracep->declBus(c+45,"SCY", false,-1, 7,0);
    tracep->declBus(c+46,"LYC", false,-1, 7,0);
    tracep->declBus(c+47,"DMA", false,-1, 7,0);
    tracep->declBus(c+48,"BGP", false,-1, 7,0);
    tracep->declBus(c+49,"OBP0", false,-1, 7,0);
    tracep->declBus(c+50,"OBP1", false,-1, 7,0);
    tracep->declBus(c+51,"WX", false,-1, 7,0);
    tracep->declBus(c+52,"WY", false,-1, 7,0);
    tracep->declBus(c+42,"FF40", false,-1, 7,0);
    tracep->declBus(c+43,"FF41", false,-1, 7,0);
    tracep->declBus(c+45,"FF42", false,-1, 7,0);
    tracep->declBus(c+44,"FF43", false,-1, 7,0);
    tracep->declBus(c+84,"FF44", false,-1, 7,0);
    tracep->declBus(c+46,"FF45", false,-1, 7,0);
    tracep->declBus(c+47,"FF46", false,-1, 7,0);
    tracep->declBus(c+48,"FF47", false,-1, 7,0);
    tracep->declBus(c+53,"FF48", false,-1, 7,0);
    tracep->declBus(c+54,"FF49", false,-1, 7,0);
    tracep->declBus(c+52,"FF4A", false,-1, 7,0);
    tracep->declBus(c+51,"FF4B", false,-1, 7,0);
    tracep->pushNamePrefix("bg_fifo ");
    tracep->declBit(c+59,"clk", false,-1);
    tracep->declBit(c+60,"rst", false,-1);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBit(c+80,"go", false,-1);
    tracep->declBit(c+81,"load", false,-1);
    tracep->declBus(c+41,"q", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+55+i*1,"shift_reg", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sprite_fifo ");
    tracep->declBit(c+59,"clk", false,-1);
    tracep->declBit(c+60,"rst", false,-1);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBit(c+76,"go", false,-1);
    tracep->declBit(c+77,"load", false,-1);
    tracep->declBus(c+40,"q", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+57+i*1,"shift_reg", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VPPU3___024root__trace_init_top(VPPU3___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_init_top\n"); );
    // Body
    VPPU3___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VPPU3___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPPU3___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VPPU3___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VPPU3___024root__trace_register(VPPU3___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VPPU3___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VPPU3___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VPPU3___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VPPU3___024root__trace_full_sub_0(VPPU3___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VPPU3___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_full_top_0\n"); );
    // Init
    VPPU3___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPPU3___024root*>(voidSelf);
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VPPU3___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VPPU3___024root__trace_full_sub_0(VPPU3___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[0]),8);
    bufp->fullCData(oldp+2,(vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[1]),8);
    bufp->fullCData(oldp+3,(vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[0]),8);
    bufp->fullCData(oldp+4,(vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[1]),8);
    bufp->fullCData(oldp+5,(vlSelf->PPU3__DOT__LY),8);
    bufp->fullCData(oldp+6,(vlSelf->PPU3__DOT__x_pos),8);
    bufp->fullCData(oldp+7,(vlSelf->PPU3__DOT__sprites_loaded),4);
    bufp->fullBit(oldp+8,(vlSelf->PPU3__DOT__sprite_found));
    bufp->fullSData(oldp+9,(vlSelf->PPU3__DOT__cycles),9);
    bufp->fullCData(oldp+10,(vlSelf->PPU3__DOT__sprite_y_buff[0]),8);
    bufp->fullCData(oldp+11,(vlSelf->PPU3__DOT__sprite_y_buff[1]),8);
    bufp->fullCData(oldp+12,(vlSelf->PPU3__DOT__sprite_y_buff[2]),8);
    bufp->fullCData(oldp+13,(vlSelf->PPU3__DOT__sprite_y_buff[3]),8);
    bufp->fullCData(oldp+14,(vlSelf->PPU3__DOT__sprite_y_buff[4]),8);
    bufp->fullCData(oldp+15,(vlSelf->PPU3__DOT__sprite_y_buff[5]),8);
    bufp->fullCData(oldp+16,(vlSelf->PPU3__DOT__sprite_y_buff[6]),8);
    bufp->fullCData(oldp+17,(vlSelf->PPU3__DOT__sprite_y_buff[7]),8);
    bufp->fullCData(oldp+18,(vlSelf->PPU3__DOT__sprite_y_buff[8]),8);
    bufp->fullCData(oldp+19,(vlSelf->PPU3__DOT__sprite_y_buff[9]),8);
    bufp->fullCData(oldp+20,(vlSelf->PPU3__DOT__sprite_x_buff[0]),8);
    bufp->fullCData(oldp+21,(vlSelf->PPU3__DOT__sprite_x_buff[1]),8);
    bufp->fullCData(oldp+22,(vlSelf->PPU3__DOT__sprite_x_buff[2]),8);
    bufp->fullCData(oldp+23,(vlSelf->PPU3__DOT__sprite_x_buff[3]),8);
    bufp->fullCData(oldp+24,(vlSelf->PPU3__DOT__sprite_x_buff[4]),8);
    bufp->fullCData(oldp+25,(vlSelf->PPU3__DOT__sprite_x_buff[5]),8);
    bufp->fullCData(oldp+26,(vlSelf->PPU3__DOT__sprite_x_buff[6]),8);
    bufp->fullCData(oldp+27,(vlSelf->PPU3__DOT__sprite_x_buff[7]),8);
    bufp->fullCData(oldp+28,(vlSelf->PPU3__DOT__sprite_x_buff[8]),8);
    bufp->fullCData(oldp+29,(vlSelf->PPU3__DOT__sprite_x_buff[9]),8);
    bufp->fullCData(oldp+30,(vlSelf->PPU3__DOT__sprite_offset_buff[0]),8);
    bufp->fullCData(oldp+31,(vlSelf->PPU3__DOT__sprite_offset_buff[1]),8);
    bufp->fullCData(oldp+32,(vlSelf->PPU3__DOT__sprite_offset_buff[2]),8);
    bufp->fullCData(oldp+33,(vlSelf->PPU3__DOT__sprite_offset_buff[3]),8);
    bufp->fullCData(oldp+34,(vlSelf->PPU3__DOT__sprite_offset_buff[4]),8);
    bufp->fullCData(oldp+35,(vlSelf->PPU3__DOT__sprite_offset_buff[5]),8);
    bufp->fullCData(oldp+36,(vlSelf->PPU3__DOT__sprite_offset_buff[6]),8);
    bufp->fullCData(oldp+37,(vlSelf->PPU3__DOT__sprite_offset_buff[7]),8);
    bufp->fullCData(oldp+38,(vlSelf->PPU3__DOT__sprite_offset_buff[8]),8);
    bufp->fullCData(oldp+39,(vlSelf->PPU3__DOT__sprite_offset_buff[9]),8);
    bufp->fullCData(oldp+40,(((2U & (vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                     [1U] >> 6U)) | 
                              (1U & (vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                     [0U] >> 7U)))),2);
    bufp->fullCData(oldp+41,(((2U & (vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                                     [1U] >> 6U)) | 
                              (1U & (vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                                     [0U] >> 7U)))),2);
    bufp->fullCData(oldp+42,(vlSelf->PPU3__DOT__FF40),8);
    bufp->fullCData(oldp+43,(vlSelf->PPU3__DOT__FF41),8);
    bufp->fullCData(oldp+44,(vlSelf->PPU3__DOT__FF43),8);
    bufp->fullCData(oldp+45,(vlSelf->PPU3__DOT__FF42),8);
    bufp->fullCData(oldp+46,(vlSelf->PPU3__DOT__FF45),8);
    bufp->fullCData(oldp+47,(vlSelf->PPU3__DOT__FF46),8);
    bufp->fullCData(oldp+48,(vlSelf->PPU3__DOT__FF47),8);
    bufp->fullCData(oldp+49,((0xfcU & (IData)(vlSelf->PPU3__DOT__FF48))),8);
    bufp->fullCData(oldp+50,((0xfcU & (IData)(vlSelf->PPU3__DOT__FF49))),8);
    bufp->fullCData(oldp+51,(vlSelf->PPU3__DOT__FF4B),8);
    bufp->fullCData(oldp+52,(vlSelf->PPU3__DOT__FF4A),8);
    bufp->fullCData(oldp+53,(vlSelf->PPU3__DOT__FF48),8);
    bufp->fullCData(oldp+54,(vlSelf->PPU3__DOT__FF49),8);
    bufp->fullCData(oldp+55,(vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0]),8);
    bufp->fullCData(oldp+56,(vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1]),8);
    bufp->fullCData(oldp+57,(vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0]),8);
    bufp->fullCData(oldp+58,(vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1]),8);
    bufp->fullBit(oldp+59,(vlSelf->clk));
    bufp->fullBit(oldp+60,(vlSelf->rst));
    bufp->fullSData(oldp+61,(vlSelf->ADDR),16);
    bufp->fullBit(oldp+62,(vlSelf->WR));
    bufp->fullBit(oldp+63,(vlSelf->RD));
    bufp->fullCData(oldp+64,(vlSelf->MMIO_DATA_out),8);
    bufp->fullCData(oldp+65,(vlSelf->MMIO_DATA_in),8);
    bufp->fullBit(oldp+66,(vlSelf->IRQ_V_BLANK));
    bufp->fullBit(oldp+67,(vlSelf->IRQ_LCDC));
    bufp->fullCData(oldp+68,(vlSelf->PPU_MODE),2);
    bufp->fullBit(oldp+69,(vlSelf->PPU_RD));
    bufp->fullSData(oldp+70,(vlSelf->PPU_ADDR),16);
    bufp->fullCData(oldp+71,(vlSelf->PPU_DATA_in),8);
    bufp->fullCData(oldp+72,(vlSelf->PX_OUT),2);
    bufp->fullBit(oldp+73,(vlSelf->PX_valid));
    bufp->fullBit(oldp+74,(((((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                             >= (IData)(vlSelf->PPU_DATA_in)) 
                            & (((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                               < ((IData)(vlSelf->PPU_DATA_in) 
                                  + ((IData)(8U) << 
                                     (1U & ((IData)(vlSelf->PPU3__DOT__FF40) 
                                            >> 2U))))))));
    bufp->fullSData(oldp+75,((0xffffU & ((IData)(vlSelf->PPU_ADDR) 
                                         - (IData)(0xfe00U)))),16);
    bufp->fullBit(oldp+76,(vlSelf->PPU3__DOT__sprite_shift_go));
    bufp->fullBit(oldp+77,(vlSelf->PPU3__DOT__sprite_shift_load));
    bufp->fullCData(oldp+78,(vlSelf->PPU3__DOT__sprite_tile_row[0]),8);
    bufp->fullCData(oldp+79,(vlSelf->PPU3__DOT__sprite_tile_row[1]),8);
    bufp->fullBit(oldp+80,(vlSelf->PPU3__DOT__bg_shift_go));
    bufp->fullBit(oldp+81,(vlSelf->PPU3__DOT__bg_shift_load));
    bufp->fullCData(oldp+82,(vlSelf->PPU3__DOT__bg_tile_row[0]),8);
    bufp->fullCData(oldp+83,(vlSelf->PPU3__DOT__bg_tile_row[1]),8);
    bufp->fullCData(oldp+84,(vlSelf->PPU3__DOT__FF44),8);
}

#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VPPU3.h"
#include "VPPU3__Syms.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Valu *dut = new VPPU3;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("VPPU.vcd");

    //need to feed in initial mem stuff
    /*
        VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(WR,0,0);
    VL_IN8(RD,0,0);
    VL_IN8(MMIO_DATA_out,7,0);
    VL_OUT8(MMIO_DATA_in,7,0); out
    VL_OUT8(IRQ_V_BLANK,0,0); out
    VL_OUT8(IRQ_LCDC,0,0); out
    VL_OUT8(PPU_MODE,1,0);
    VL_OUT8(PPU_RD,0,0);
    VL_IN8(PPU_DATA_in,7,0);
    VL_OUT8(PX_OUT,1,0);
    VL_OUT8(PX_valid,0,0);
    VL_IN16(ADDR,15,0);
    VL_OUT16(PPU_ADDR,15,0);    
    */


    while (sim_time < MAX_SIM_TIME) {
        //initial reset
        dut->rst = (sim_time==1) ? 1 : 0;


        dut->clk ^= 1;
        dut->eval();

        if (sim_time>)


        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}


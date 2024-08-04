// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VPPU3__Syms.h"
#include "VPPU3.h"
#include "VPPU3___024root.h"

// FUNCTIONS
VPPU3__Syms::~VPPU3__Syms()
{
}

VPPU3__Syms::VPPU3__Syms(VerilatedContext* contextp, const char* namep, VPPU3* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

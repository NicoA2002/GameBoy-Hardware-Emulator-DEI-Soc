// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VPPU3__SYMS_H_
#define _VPPU3__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VPPU3.h"

// SYMS CLASS
class VPPU3__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VPPU3*                         TOPp;
    
    // CREATORS
    VPPU3__Syms(VPPU3* topp, const char* namep);
    ~VPPU3__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#ifndef __erfc_hpp
#define __erfc_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_erfc();
extern void TerminateModule_erfc();
extern _mexLocalFunctionTable _local_function_table_erfc;

extern mwArray erfc(mwArray x = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxErfc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

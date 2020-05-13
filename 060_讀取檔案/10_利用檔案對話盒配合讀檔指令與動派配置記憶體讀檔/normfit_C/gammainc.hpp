//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#ifndef __gammainc_hpp
#define __gammainc_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_gammainc();
extern void TerminateModule_gammainc();
extern _mexLocalFunctionTable _local_function_table_gammainc;

extern mwArray gammainc(mwArray x = mwArray::DIN, mwArray a = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxGammainc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

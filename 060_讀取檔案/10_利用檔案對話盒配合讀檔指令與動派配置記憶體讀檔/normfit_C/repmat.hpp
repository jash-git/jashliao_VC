//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#ifndef __repmat_hpp
#define __repmat_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_repmat();
extern void TerminateModule_repmat();
extern _mexLocalFunctionTable _local_function_table_repmat;

extern mwArray repmat(mwArray A = mwArray::DIN,
                      mwArray M = mwArray::DIN,
                      mwArray N = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxRepmat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

//
// MATLAB Compiler: 3.0
// Date: Fri Oct 29 14:44:58 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "Cpp" "-h"
// "addmatrix" 
//
#ifndef __addmatrix_hpp
#define __addmatrix_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_addmatrix();
extern void TerminateModule_addmatrix();
extern _mexLocalFunctionTable _local_function_table_addmatrix;

extern mwArray addmatrix(mwArray * prod,
                         mwArray x = mwArray::DIN,
                         mwArray y = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxAddmatrix(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

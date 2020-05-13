//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#ifndef __normfit_hpp
#define __normfit_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_normfit();
extern void TerminateModule_normfit();
extern _mexLocalFunctionTable _local_function_table_normfit;

extern mwArray Nnormfit(int nargout,
                        mwArray * sigmahat,
                        mwArray * muci,
                        mwArray * sigmaci,
                        mwArray x = mwArray::DIN,
                        mwArray alpha = mwArray::DIN);
extern mwArray normfit(mwArray * sigmahat,
                       mwArray * muci,
                       mwArray * sigmaci,
                       mwArray x = mwArray::DIN,
                       mwArray alpha = mwArray::DIN);
extern void Vnormfit(mwArray x = mwArray::DIN, mwArray alpha = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxNormfit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#ifndef __gammaln_mex_interface_hpp
#define __gammaln_mex_interface_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_gammaln_mex_interface();
extern void TerminateModule_gammaln_mex_interface();
extern _mexLocalFunctionTable _local_function_table_gammaln;

extern mwArray Ngammaln(int nargout,
                        mwVarargout varargout,
                        mwVarargin varargin = mwVarargin::DIN);
extern mwArray gammaln(mwVarargout varargout,
                       mwVarargin varargin = mwVarargin::DIN);
extern void Vgammaln(mwVarargin varargin = mwVarargin::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxGammaln(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif

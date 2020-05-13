//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betaln.hpp"
#include "gammaln_mex_interface.hpp"
#include "libmatlbm.hpp"

void InitializeModule_betaln() {
}

void TerminateModule_betaln() {
}

static mwArray Mbetaln(int nargout_, mwArray z, mwArray w);

_mexLocalFunctionTable _local_function_table_betaln
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betaln" contains the normal interface for the "betaln"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betaln.m" (lines
// 1-21). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betaln(mwArray z, mwArray w) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mbetaln(nargout, z, w);
    return y;
}

//
// The function "mlxBetaln" contains the feval interface for the "betaln"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betaln.m" (lines
// 1-21). The feval function calls the implementation version of betaln through
// this function. This function processes any input arguments and passes them
// to the implementation version of the function, appearing above.
//
void mlxBetaln(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[2];
        mwArray mplhs[1];
        int i;
        mclCppUndefineArrays(1, mplhs);
        if (nlhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betaln Line: 1 Column: 1"
                  " The function \"betaln\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betaln Line: 1 Column: "
                  "1 The function \"betaln\" was called with mor"
                  "e than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetaln(nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetaln" is the implementation version of the "betaln"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betaln.m" (lines
// 1-21). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = betaln(z,w)
//
static mwArray Mbetaln(int nargout_, mwArray z, mwArray w) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betaln;
    mwArray y = mwArray::UNDEFINED;
    //
    // %BETALN Logarithm of beta function.
    // %   Y = BETALN(Z,W) computes the natural logarithm of the beta
    // %   function for corresponding elements of Z and W.   The arrays Z and
    // %   W must be the same size (or either can be scalar).  BETALN is
    // %   defined as:
    // %
    // %       BETALN = LOG(BETA(Z,W)) 
    // %
    // %   and is obtained without computing BETA(Z,W). Since the beta
    // %   function can range over very large or very small values, its
    // %   logarithm is sometimes more useful.
    // %
    // %   See also BETAINC, BETA.
    // 
    // %   Reference: Abramowitz & Stegun, sec. 6.2.
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.8 $  $Date: 2002/04/09 00:29:46 $
    // 
    // y = gammaln(z)+gammaln(w)-gammaln(z+w);
    //
    y
      = Ngammaln(0, mwValueVarargout(), mwVarargin(mwVa(z, "z")))
        + Ngammaln(0, mwValueVarargout(), mwVarargin(mwVa(w, "w")))
        - Ngammaln(
            0, mwValueVarargout(), mwVarargin(mwVa(z, "z") + mwVa(w, "w")));
    mwValidateOutput(y, 1, nargout_, "y", "betaln");
    return y;
}

//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "chi2inv.hpp"
#include "distchck.hpp"
#include "gaminv.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[29] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 't',
                               'w', 'o', ' ', 'i', 'n', 'p', 'u', 't', ' ', 'a',
                               'r', 'g', 'u', 'm', 'e', 'n', 't', 's', '.' };
static mwArray _mxarray0_ = mclInitializeString(29, _array1_);
static mwArray _mxarray2_ = mclInitializeDouble(2.0);
static mwArray _mxarray3_ = mclInitializeDouble(0.0);

static mxChar _array5_[47] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'n',
                               'o', 'n', '-', 's', 'c', 'a', 'l', 'a', 'r', ' ',
                               'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', ' ',
                               't', 'o', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'i',
                               'n', ' ', 's', 'i', 'z', 'e', '.' };
static mwArray _mxarray4_ = mclInitializeString(47, _array5_);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray6_ = mclInitializeDouble(_ieee_nan_);

void InitializeModule_chi2inv() {
}

void TerminateModule_chi2inv() {
}

static mwArray Mchi2inv(int nargout_, mwArray p, mwArray v);

_mexLocalFunctionTable _local_function_table_chi2inv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "chi2inv" contains the normal interface for the "chi2inv"
// M-function from file "c:\matlab6p5\toolbox\stats\chi2inv.m" (lines 1-37).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray chi2inv(mwArray p, mwArray v) {
    int nargout = 1;
    mwArray x = mwArray::UNDEFINED;
    x = Mchi2inv(nargout, p, v);
    return x;
}

//
// The function "mlxChi2inv" contains the feval interface for the "chi2inv"
// M-function from file "c:\matlab6p5\toolbox\stats\chi2inv.m" (lines 1-37).
// The feval function calls the implementation version of chi2inv through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxChi2inv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: chi2inv Line: 1 Column: "
                  "1 The function \"chi2inv\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: chi2inv Line: 1 Column: "
                  "1 The function \"chi2inv\" was called with mor"
                  "e than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mchi2inv(nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mchi2inv" is the implementation version of the "chi2inv"
// M-function from file "c:\matlab6p5\toolbox\stats\chi2inv.m" (lines 1-37). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function x = chi2inv(p,v);
//
static mwArray Mchi2inv(int nargout_, mwArray p, mwArray v) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_chi2inv;
    int nargin_ = nargin(2, mwVarargin(p, v));
    mwArray x = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %CHI2INV Inverse of the chi-square cumulative distribution function (cdf).
    // %   X = CHI2INV(P,V)  returns the inverse of the chi-square cdf with V  
    // %   degrees of freedom at the values in P. The chi-square cdf with V 
    // %   degrees of freedom, is the gamma cdf with parameters V/2 and 2.   
    // %
    // %   The size of X is the common size of P and V. A scalar input
    // %   functions as a constant matrix of the same size as the other input.   
    // 
    // %   References:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 26.4.
    // %      [2] E. Kreyszig, "Introductory Mathematical Statistics",
    // %      John Wiley, 1970, section 10.2 (page 144)
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.10 $  $Date: 2002/01/17 21:30:15 $
    // 
    // if nargin < 2, 
    //
    if (nargin_ < 2) {
        //
        // error('Requires two input arguments.');
        //
        error(mwVarargin(_mxarray0_));
    //
    // end
    //
    }
    //
    // 
    // [errorcode p v] = distchck(2,p,v);
    //
    errorcode
    = distchck(
        mwVarargout(p, v), _mxarray2_, mwVarargin(mwVa(p, "p"), mwVa(v, "v")));
    //
    // 
    // if errorcode > 0
    //
    if (mclGtBool(mwVv(errorcode, "errorcode"), _mxarray3_)) {
        //
        // error('Requires non-scalar arguments to match in size.');
        //
        error(mwVarargin(_mxarray4_));
    //
    // end
    //
    }
    //
    // 
    // % Call the gamma inverse function. 
    // x = gaminv(p,v/2,2);
    //
    x = gaminv(mwVa(p, "p"), mwVa(v, "v") / _mxarray2_, _mxarray2_);
    //
    // 
    // % Return NaN if the degrees of freedom is not positive.
    // k = (v <= 0);
    //
    k = mwVa(v, "v") <= _mxarray3_;
    //
    // if any(k(:))
    //
    if (tobool(any(mclArrayRef(mwVv(k, "k"), colon())))) {
        //
        // x(k) = NaN;
        //
        mclArrayAssign(&x, _mxarray6_, mwVv(k, "k"));
    //
    // end
    //
    }
    mwValidateOutput(x, 1, nargout_, "x", "chi2inv");
    return x;
}

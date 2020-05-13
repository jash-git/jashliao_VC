//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betapdf.hpp"
#include "betaln.hpp"
#include "distchck.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[31] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's',
                               ' ', 't', 'h', 'r', 'e', 'e', ' ', 'i',
                               'n', 'p', 'u', 't', ' ', 'a', 'r', 'g',
                               'u', 'm', 'e', 'n', 't', 's', '.' };
static mwArray _mxarray0_ = mclInitializeString(31, _array1_);
static mwArray _mxarray2_ = mclInitializeDouble(3.0);
static mwArray _mxarray3_ = mclInitializeDouble(0.0);

static mxChar _array5_[47] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'n',
                               'o', 'n', '-', 's', 'c', 'a', 'l', 'a', 'r', ' ',
                               'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', ' ',
                               't', 'o', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'i',
                               'n', ' ', 's', 'i', 'z', 'e', '.' };
static mwArray _mxarray4_ = mclInitializeString(47, _array5_);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray6_ = mclInitializeDouble(_ieee_nan_);
static mwArray _mxarray7_ = mclInitializeDouble(1.0);
static double _ieee_plusinf_ = mclGetInf();
static mwArray _mxarray8_ = mclInitializeDouble(_ieee_plusinf_);

void InitializeModule_betapdf() {
}

void TerminateModule_betapdf() {
}

static mwArray Mbetapdf(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_betapdf
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betapdf" contains the normal interface for the "betapdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betapdf.m" (lines 1-51).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betapdf(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mbetapdf(nargout, x, a, b);
    return y;
}

//
// The function "mlxBetapdf" contains the feval interface for the "betapdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betapdf.m" (lines 1-51).
// The feval function calls the implementation version of betapdf through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxBetapdf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[3];
        mwArray mplhs[1];
        int i;
        mclCppUndefineArrays(1, mplhs);
        if (nlhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betapdf Line: 1 Column: "
                  "1 The function \"betapdf\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betapdf Line: 1 Column: "
                  "1 The function \"betapdf\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetapdf(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetapdf" is the implementation version of the "betapdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betapdf.m" (lines 1-51). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = betapdf(x,a,b)
//
static mwArray Mbetapdf(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betapdf;
    int nargin_ = nargin(3, mwVarargin(x, a, b));
    mwArray y = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray k2 = mwArray::UNDEFINED;
    mwArray tmp = mwArray::UNDEFINED;
    mwArray k1 = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %BETAPDF Beta probability density function.
    // %   Y = BETAPDF(X,A,B) returns the beta probability density 
    // %   function with parameters A and B at the values in X.
    // %
    // %   The size of Y is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // 
    // %   References:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 26.1.33.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // % $Revision: 2.11 $  $Date: 2002/01/17 21:29:59 $
    // 
    // if nargin < 3, 
    //
    if (nargin_ < 3) {
        //
        // error('Requires three input arguments.');
        //
        error(mwVarargin(_mxarray0_));
    //
    // end
    //
    }
    //
    // 
    // [errorcode x a b] = distchck(3,x,a,b);
    //
    errorcode
    = distchck(
        mwVarargout(x, a, b),
        _mxarray2_,
        mwVarargin(mwVa(x, "x"), mwVa(a, "a"), mwVa(b, "b")));
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
    // % Initialize Y to zero.
    // y = zeros(size(x));
    //
    y = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // 
    // % Return NaN for parameter values outside their respective limits.
    // k1 = find(a <= 0 | b <= 0);
    //
    k1 = find(mwVa(a, "a") <= _mxarray3_ | mwVa(b, "b") <= _mxarray3_);
    //
    // if any(k1)
    //
    if (tobool(any(mwVv(k1, "k1")))) {
        //
        // tmp = NaN;
        //
        tmp = _mxarray6_;
        //
        // y(k1) = tmp(ones(size(k1))); 
        //
        mclArrayAssign(
          &y,
          mclArrayRef(
            mwVv(tmp, "tmp"),
            ones(mwVarargin(size(mwValueVarargout(), mwVv(k1, "k1"))))),
          mwVv(k1, "k1"));
    //
    // end
    //
    }
    //
    // 
    // % Return Inf for x = 0 and a < 1 or x = 1 and b < 1.
    // % Required for non-IEEE machines.
    // k2 = find((x == 0 & a < 1) | (x == 1 & b < 1));
    //
    k2
      = find(
          mwVa(x, "x") == _mxarray3_ & mwVa(a, "a") < _mxarray7_
          | mwVa(x, "x") == _mxarray7_ & mwVa(b, "b") < _mxarray7_);
    //
    // if any(k2)
    //
    if (tobool(any(mwVv(k2, "k2")))) {
        //
        // tmp = Inf;
        //
        tmp = _mxarray8_;
        //
        // y(k2) = tmp(ones(size(k2))); 
        //
        mclArrayAssign(
          &y,
          mclArrayRef(
            mwVv(tmp, "tmp"),
            ones(mwVarargin(size(mwValueVarargout(), mwVv(k2, "k2"))))),
          mwVv(k2, "k2"));
    //
    // end
    //
    }
    //
    // 
    // % Return the beta density function for valid parameters.
    // k = find(~(a <= 0 | b <= 0 | x <= 0 | x >= 1));
    //
    k
      = find(
          ~ (mwVa(a, "a") <= _mxarray3_ | mwVa(b, "b") <= _mxarray3_
             | mwVa(x, "x") <= _mxarray3_
             | mwVa(x, "x") >= _mxarray7_));
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // %    y(k) = x(k) .^ (a(k) - 1) .* (1 - x(k)) .^ (b(k) - 1) ./ beta(a(k),b(k));
        // tmp(k) = (a(k) - 1).*log(x(k)) + (b(k) - 1).*log((1 - x(k))) - betaln(a(k),b(k));
        //
        mclArrayAssign(
          &tmp,
          times(
            mclArrayRef(mwVa(a, "a"), mwVv(k, "k")) - _mxarray7_,
            log(mclArrayRef(mwVa(x, "x"), mwVv(k, "k"))))
          + times(
              mclArrayRef(mwVa(b, "b"), mwVv(k, "k")) - _mxarray7_,
              log(_mxarray7_ - mclArrayRef(mwVa(x, "x"), mwVv(k, "k"))))
          - betaln(
              mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
              mclArrayRef(mwVa(b, "b"), mwVv(k, "k"))),
          mwVv(k, "k"));
        //
        // y(k) = exp(tmp(k));
        //
        mclArrayAssign(
          &y, exp(mclArrayRef(mwVv(tmp, "tmp"), mwVv(k, "k"))), mwVv(k, "k"));
    //
    // end
    //
    }
    mwValidateOutput(y, 1, nargout_, "y", "betapdf");
    return y;
}

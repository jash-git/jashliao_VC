//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betacdf.hpp"
#include "betainc.hpp"
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

void InitializeModule_betacdf() {
}

void TerminateModule_betacdf() {
}

static mwArray Mbetacdf(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_betacdf
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betacdf" contains the normal interface for the "betacdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betacdf.m" (lines 1-51).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betacdf(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray p = mwArray::UNDEFINED;
    p = Mbetacdf(nargout, x, a, b);
    return p;
}

//
// The function "mlxBetacdf" contains the feval interface for the "betacdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betacdf.m" (lines 1-51).
// The feval function calls the implementation version of betacdf through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxBetacdf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: betacdf Line: 1 Column: "
                  "1 The function \"betacdf\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betacdf Line: 1 Column: "
                  "1 The function \"betacdf\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetacdf(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetacdf" is the implementation version of the "betacdf"
// M-function from file "c:\matlab6p5\toolbox\stats\betacdf.m" (lines 1-51). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function p = betacdf(x,a,b);
//
static mwArray Mbetacdf(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betacdf;
    int nargin_ = nargin(3, mwVarargin(x, a, b));
    mwArray p = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray k2 = mwArray::UNDEFINED;
    mwArray tmp = mwArray::UNDEFINED;
    mwArray k1 = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %BETACDF Beta cumulative distribution function.
    // %   P = BETACDF(X,A,B) returns the beta cumulative distribution
    // %   function with parameters A and B at the values in X.
    // %
    // %   The size of P is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   BETAINC does the computational work.
    // 
    // %   Reference:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 26.5.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.9 $  $Date: 2002/01/17 21:29:55 $
    // 
    // if nargin<3, 
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
    // % Initialize P to 0.
    // p = zeros(size(x));
    //
    p = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // 
    // k1 = find(a<=0 | b<=0);
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
        // p(k1) = tmp(ones(size(k1))); 
        //
        mclArrayAssign(
          &p,
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
    // % If is X >= 1 the cdf of X is 1. 
    // k2 = find(x >= 1);
    //
    k2 = find(mwVa(x, "x") >= _mxarray7_);
    //
    // if any(k2)
    //
    if (tobool(any(mwVv(k2, "k2")))) {
        //
        // p(k2) = ones(size(k2));
        //
        mclArrayAssign(
          &p,
          ones(mwVarargin(size(mwValueVarargout(), mwVv(k2, "k2")))),
          mwVv(k2, "k2"));
    //
    // end
    //
    }
    //
    // 
    // k = find(x > 0 & x < 1 & a > 0 & b > 0);
    //
    k
      = find(
          mwVa(x, "x") > _mxarray3_ & mwVa(x, "x") < _mxarray7_
          & mwVa(a, "a") > _mxarray3_
          & mwVa(b, "b") > _mxarray3_);
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // p(k) = betainc(x(k),a(k),b(k));
        //
        mclArrayAssign(
          &p,
          betainc(
            mclArrayRef(mwVa(x, "x"), mwVv(k, "k")),
            mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
            mclArrayRef(mwVa(b, "b"), mwVv(k, "k"))),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // % Make sure that round-off errors never make P greater than 1.
    // k = find(p > 1);
    //
    k = find(mwVv(p, "p") > _mxarray7_);
    //
    // p(k) = ones(size(k));
    //
    mclArrayAssign(
      &p,
      ones(mwVarargin(size(mwValueVarargout(), mwVv(k, "k")))),
      mwVv(k, "k"));
    mwValidateOutput(p, 1, nargout_, "p", "betacdf");
    return p;
}

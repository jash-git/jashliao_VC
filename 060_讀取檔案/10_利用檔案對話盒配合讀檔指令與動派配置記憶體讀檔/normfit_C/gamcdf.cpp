//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "gamcdf.hpp"
#include "distchck.hpp"
#include "gammainc.hpp"
#include "libmatlbm.hpp"
#include "realmax.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.0);

static mxChar _array2_[38] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'a',
                               't', ' ', 'l', 'e', 'a', 's', 't', ' ', 't', 'w',
                               'o', ' ', 'i', 'n', 'p', 'u', 't', ' ', 'a', 'r',
                               'g', 'u', 'm', 'e', 'n', 't', 's', '.' };
static mwArray _mxarray1_ = mclInitializeString(38, _array2_);
static mwArray _mxarray3_ = mclInitializeDouble(3.0);
static mwArray _mxarray4_ = mclInitializeDouble(0.0);

static mxChar _array6_[47] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'n',
                               'o', 'n', '-', 's', 'c', 'a', 'l', 'a', 'r', ' ',
                               'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', ' ',
                               't', 'o', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'i',
                               'n', ' ', 's', 'i', 'z', 'e', '.' };
static mwArray _mxarray5_ = mclInitializeString(47, _array6_);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray7_ = mclInitializeDouble(_ieee_nan_);
static mwArray _mxarray8_ = mclInitializeDouble(1.7976931348623157e+308);

void InitializeModule_gamcdf() {
}

void TerminateModule_gamcdf() {
}

static mwArray Mgamcdf(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_gamcdf
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "gamcdf" contains the normal interface for the "gamcdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gamcdf.m" (lines 1-54).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray gamcdf(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray p = mwArray::UNDEFINED;
    p = Mgamcdf(nargout, x, a, b);
    return p;
}

//
// The function "mlxGamcdf" contains the feval interface for the "gamcdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gamcdf.m" (lines 1-54). The
// feval function calls the implementation version of gamcdf through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxGamcdf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: gamcdf Line: 1 Column: 1"
                  " The function \"gamcdf\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gamcdf Line: 1 Column: "
                  "1 The function \"gamcdf\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mgamcdf(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mgamcdf" is the implementation version of the "gamcdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gamcdf.m" (lines 1-54). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function p = gamcdf(x,a,b)
//
static mwArray Mgamcdf(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_gamcdf;
    int nargin_ = nargin(3, mwVarargin(x, a, b));
    mwArray p = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %GAMCDF Gamma cumulative distribution function.
    // %   P = GAMCDF(X,A,B) returns the gamma cumulative distribution
    // %   function with parameters A and B at the values in X.
    // %
    // %   The size of P is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   Some references refer to the gamma distribution with a single
    // %   parameter. This corresponds to the default of B = 1. 
    // %
    // %   GAMMAINC does computational work.
    // 
    // %   References:
    // %      [1]  L. Devroye, "Non-Uniform Random Variate Generation", 
    // %      Springer-Verlag, 1986. p. 401.
    // %      [2]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 26.1.32.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.12 $  $Date: 2002/01/17 21:30:39 $
    // 
    // if nargin < 3, 
    //
    if (nargin_ < 3) {
        //
        // b = 1; 
        //
        b = _mxarray0_;
    //
    // end
    //
    }
    //
    // 
    // if nargin < 2, 
    //
    if (nargin_ < 2) {
        //
        // error('Requires at least two input arguments.'); 
        //
        error(mwVarargin(_mxarray1_));
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
        _mxarray3_,
        mwVarargin(mwVa(x, "x"), mwVa(a, "a"), mwVa(b, "b")));
    //
    // 
    // if errorcode > 0
    //
    if (mclGtBool(mwVv(errorcode, "errorcode"), _mxarray4_)) {
        //
        // error('Requires non-scalar arguments to match in size.');
        //
        error(mwVarargin(_mxarray5_));
    //
    // end
    //
    }
    //
    // 
    // % Initialize P to zero.
    // p = zeros(size(x));
    //
    p = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // 
    // %   Return NaN if the arguments are outside their respective limits.
    // p(a <= 0 | b <= 0) = NaN;
    //
    mclArrayAssign(
      &p, _mxarray7_, mwVa(a, "a") <= _mxarray4_ | mwVa(b, "b") <= _mxarray4_);
    //
    // 
    // k = find(x > 0 & ~(a <= 0 | b <= 0));
    //
    k
      = find(
          mwVa(x, "x") > _mxarray4_
          & ~ (mwVa(a, "a") <= _mxarray4_ | mwVa(b, "b") <= _mxarray4_));
    //
    // if any(k), 
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // p(k) = gammainc(x(k) ./ b(k),a(k));
        //
        mclArrayAssign(
          &p,
          gammainc(
            rdivide(
              mclArrayRef(mwVa(x, "x"), mwVv(k, "k")),
              mclArrayRef(mwVa(b, "b"), mwVv(k, "k"))),
            mclArrayRef(mwVa(a, "a"), mwVv(k, "k"))),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // % Make sure that round-off errors never make P greater than 1.
    // p(p > 1) = 1;
    //
    mclArrayAssign(&p, _mxarray0_, mwVv(p, "p") > _mxarray0_);
    //
    // 
    // % If we have NaN or Inf, fix if possible
    // k = ~isfinite(p);
    //
    k = ~ isfinite(mwVv(p, "p"));
    //
    // if (any(k)), p(x>=sqrt(realmax)) = 1; end
    //
    if (tobool(any(mwVv(k, "k")))) {
        mclArrayAssign(&p, _mxarray0_, mwVa(x, "x") >= sqrt(_mxarray8_));
    }
    mwValidateOutput(p, 1, nargout_, "p", "gamcdf");
    return p;
}

//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "gampdf.hpp"
#include "distchck.hpp"
#include "gammaln_mex_interface.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.0);

static mxChar _array2_[37] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'a',
                               't', ' ', 'l', 'e', 'a', 's', 't', ' ', 't', 'w',
                               'o', ' ', 'i', 'n', 'p', 'u', 't', ' ', 'a', 'r',
                               'g', 'u', 'm', 'e', 'n', 't', 's' };
static mwArray _mxarray1_ = mclInitializeString(37, _array2_);
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
static double _ieee_plusinf_ = mclGetInf();
static mwArray _mxarray8_ = mclInitializeDouble(_ieee_plusinf_);

void InitializeModule_gampdf() {
}

void TerminateModule_gampdf() {
}

static mwArray Mgampdf(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_gampdf
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "gampdf" contains the normal interface for the "gampdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gampdf.m" (lines 1-49).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray gampdf(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mgampdf(nargout, x, a, b);
    return y;
}

//
// The function "mlxGampdf" contains the feval interface for the "gampdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gampdf.m" (lines 1-49). The
// feval function calls the implementation version of gampdf through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxGampdf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: gampdf Line: 1 Column: 1"
                  " The function \"gampdf\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gampdf Line: 1 Column: "
                  "1 The function \"gampdf\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mgampdf(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mgampdf" is the implementation version of the "gampdf"
// M-function from file "c:\matlab6p5\toolbox\stats\gampdf.m" (lines 1-49). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = gampdf(x,a,b)
//
static mwArray Mgampdf(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_gampdf;
    int nargin_ = nargin(3, mwVarargin(x, a, b));
    mwArray y = mwArray::UNDEFINED;
    mwArray k2 = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %GAMPDF Gamma probability density function.
    // %   Y = GAMPDF(X,A,B) returns the gamma probability density function 
    // %   with parameters A and B, at the values in X.
    // %
    // %   The size of Y is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   Some references refer to the gamma distribution with a single
    // %   parameter. This corresponds to the default of B = 1.
    // 
    // %   References:
    // %      [1]  L. Devroye, "Non-Uniform Random Variate Generation", 
    // %      Springer-Verlag, 1986, pages 401-402.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.10 $  $Date: 2002/01/17 21:30:41 $
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
        // error('Requires at least two input arguments'); 
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
    // % Initialize Y to zero.
    // y = zeros(size(x));
    //
    y = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // 
    // %   Return NaN if the arguments are outside their respective limits.
    // y(a <= 0 | b <= 0) = NaN;     
    //
    mclArrayAssign(
      &y, _mxarray7_, mwVa(a, "a") <= _mxarray4_ | mwVa(b, "b") <= _mxarray4_);
    //
    // 
    // k=find(x > 0 & ~(a <= 0 | b <= 0));
    //
    k
      = find(
          mwVa(x, "x") > _mxarray4_
          & ~ (mwVa(a, "a") <= _mxarray4_ | mwVa(b, "b") <= _mxarray4_));
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // y(k) = (a(k) - 1) .* log(x(k)) - (x(k) ./ b(k)) - gammaln(a(k)) - a(k) .* log(b(k));
        //
        mclArrayAssign(
          &y,
          times(
            mclArrayRef(mwVa(a, "a"), mwVv(k, "k")) - _mxarray0_,
            log(mclArrayRef(mwVa(x, "x"), mwVv(k, "k"))))
          - rdivide(
              mclArrayRef(mwVa(x, "x"), mwVv(k, "k")),
              mclArrayRef(mwVa(b, "b"), mwVv(k, "k")))
          - Ngammaln(
              0,
              mwValueVarargout(),
              mwVarargin(mclArrayRef(mwVa(a, "a"), mwVv(k, "k"))))
          - times(
              mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
              log(mclArrayRef(mwVa(b, "b"), mwVv(k, "k")))),
          mwVv(k, "k"));
        //
        // y(k) = exp(y(k));
        //
        mclArrayAssign(
          &y, exp(mclArrayRef(mwVv(y, "y"), mwVv(k, "k"))), mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // y(x == 0 & a < 1) = Inf;
    //
    mclArrayAssign(
      &y, _mxarray8_, mwVa(x, "x") == _mxarray4_ & mwVa(a, "a") < _mxarray0_);
    //
    // k2 = find(x == 0 & a == 1);
    //
    k2 = find(mwVa(x, "x") == _mxarray4_ & mwVa(a, "a") == _mxarray0_);
    //
    // if any(k2)
    //
    if (tobool(any(mwVv(k2, "k2")))) {
        //
        // y(k2) = (1./b(k2));
        //
        mclArrayAssign(
          &y,
          rdivide(_mxarray0_, mclArrayRef(mwVa(b, "b"), mwVv(k2, "k2"))),
          mwVv(k2, "k2"));
    //
    // end
    //
    }
    mwValidateOutput(y, 1, nargout_, "y", "gampdf");
    return y;
}

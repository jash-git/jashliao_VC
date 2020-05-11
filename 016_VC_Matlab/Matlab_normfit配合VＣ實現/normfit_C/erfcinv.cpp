//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "erfcinv.hpp"
#include "erfc.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[15] = { 'Y', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'r', 'e', 'a', 'l', '.' };
static mwArray _mxarray0_ = mclInitializeString(15, _array1_);

static double _array3_[6] = { .01370600482778535, -.3051415712357203,
                              1.524304069216834, -3.057303267970988,
                              2.710410832036097, -.8862269264526915 };
static mwArray _mxarray2_ = mclInitializeDoubleVector(1, 6, _array3_);

static double _array5_[5] = { -.05319931523264068, .6311946752267222,
                              -2.432796560310728, 4.175081992982483,
                              -3.32017038822143 };
static mwArray _mxarray4_ = mclInitializeDoubleVector(1, 5, _array5_);

static double _array7_[6] = { .005504751339936943, .2279687217114118,
                              1.697592457770869, 1.80293316878195,
                              -3.093354679843504, -2.077595676404383 };
static mwArray _mxarray6_ = mclInitializeDoubleVector(1, 6, _array7_);

static double _array9_[4] = { .007784695709041462, .3224671290700398,
                              2.445134137142996, 3.754408661907416 };
static mwArray _mxarray8_ = mclInitializeDoubleVector(1, 4, _array9_);
static mwArray _mxarray10_ = mclInitializeDouble(.0485);
static mwArray _mxarray11_ = mclInitializeDouble(1.9515);
static mwArray _mxarray12_ = mclInitializeDouble(1.0);
static mwArray _mxarray13_ = mclInitializeDouble(0.0);
static mwArray _mxarray14_ = mclInitializeDouble(-2.0);
static mwArray _mxarray15_ = mclInitializeDouble(2.0);
static mwArray _mxarray16_ = mclInitializeDouble(3.141592653589793);
static double _ieee_plusinf_ = mclGetInf();
static mwArray _mxarray17_ = mclInitializeDouble(_ieee_plusinf_);
static double _ieee_minusinf_ = mclGetMinusInf();
static mwArray _mxarray18_ = mclInitializeDouble(_ieee_minusinf_);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray19_ = mclInitializeDouble(_ieee_nan_);

void InitializeModule_erfcinv() {
}

void TerminateModule_erfcinv() {
}

static mwArray Merfcinv(int nargout_, mwArray y);

_mexLocalFunctionTable _local_function_table_erfcinv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "erfcinv" contains the normal interface for the "erfcinv"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcinv.m" (lines
// 1-80). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray erfcinv(mwArray y) {
    int nargout = 1;
    mwArray x = mwArray::UNDEFINED;
    x = Merfcinv(nargout, y);
    return x;
}

//
// The function "mlxErfcinv" contains the feval interface for the "erfcinv"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcinv.m" (lines
// 1-80). The feval function calls the implementation version of erfcinv
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxErfcinv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[1];
        mwArray mplhs[1];
        int i;
        mclCppUndefineArrays(1, mplhs);
        if (nlhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: erfcinv Line: 1 Column: "
                  "1 The function \"erfcinv\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: erfcinv Line: 1 Column: "
                  "1 The function \"erfcinv\" was called with mor"
                  "e than the declared number of inputs (1).")));
        }
        for (i = 0; i < 1 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 1; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Merfcinv(nlhs, mprhs[0]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Merfcinv" is the implementation version of the "erfcinv"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcinv.m" (lines
// 1-80). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function x = erfcinv(y)
//
static mwArray Merfcinv(int nargout_, mwArray y) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_erfcinv;
    mwArray x = mwArray::UNDEFINED;
    mwArray u = mwArray::UNDEFINED;
    mwArray r = mwArray::UNDEFINED;
    mwArray q = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray yhigh = mwArray::UNDEFINED;
    mwArray ylow = mwArray::UNDEFINED;
    mwArray d = mwArray::UNDEFINED;
    mwArray c = mwArray::UNDEFINED;
    mwArray b = mwArray::UNDEFINED;
    mwArray a = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %ERFCINV Inverse complementary error function.
    // %   X = ERFCINV(Y) is the inverse of the complementary error function
    // %   for each element of Y.  It satisfies y = erfc(x) 
    // %   for 2 >= y >= 0 and -Inf <= x <= Inf.
    // %
    // %   See also ERF, ERFC, ERFCX, ERFINV.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 1.4 $  $Date: 2002/04/09 00:29:47 $
    // 
    // %   Original algorithm for norminv from Peter J. Acklam, jacklam@math.uio.no.
    // 
    // if ~isreal(y), error('Y must be real.'); end
    //
    if (mclNotBool(isreal(mwVa(y, "y")))) {
        error(mwVarargin(_mxarray0_));
    }
    //
    // x = zeros(size(y));
    //
    x = zeros(mwVarargin(size(mwValueVarargout(), mwVa(y, "y"))));
    //
    // 
    // % Coefficients in rational approximations.
    // a = [  1.370600482778535e-02 -3.051415712357203e-01 ...
    //
    a = _mxarray2_;
    //
    // 1.524304069216834e+00 -3.057303267970988e+00  ...
    // 2.710410832036097e+00 -8.862269264526915e-01 ];
    // b = [ -5.319931523264068e-02  6.311946752267222e-01 ...
    //
    b = _mxarray4_;
    //
    // -2.432796560310728e+00  4.175081992982483e+00 ...
    // -3.320170388221430e+00 ];
    // c = [  5.504751339936943e-03  2.279687217114118e-01 ...
    //
    c = _mxarray6_;
    //
    // 1.697592457770869e+00  1.802933168781950e+00 ...
    // -3.093354679843504e+00 -2.077595676404383e+00 ];
    // d = [  7.784695709041462e-03  3.224671290700398e-01 ...
    //
    d = _mxarray8_;
    //
    // 2.445134137142996e+00  3.754408661907416e+00 ];
    // 
    // % Define break-points.
    // ylow  = 0.0485;
    //
    ylow = _mxarray10_;
    //
    // yhigh = 1.9515;
    //
    yhigh = _mxarray11_;
    //
    // 
    // % Rational approximation for central region
    // k = ylow <= y & y <= yhigh;
    //
    k
      = mwVv(ylow, "ylow") <= mwVa(y, "y")
        & mwVa(y, "y") <= mwVv(yhigh, "yhigh");
    //
    // if any(k(:))
    //
    if (tobool(any(mclArrayRef(mwVv(k, "k"), colon())))) {
        //
        // q = y(k)-1;
        //
        q = mclArrayRef(mwVa(y, "y"), mwVv(k, "k")) - _mxarray12_;
        //
        // r = q.*q;
        //
        r = times(mwVv(q, "q"), mwVv(q, "q"));
        //
        // x(k) = (((((a(1)*r+a(2)).*r+a(3)).*r+a(4)).*r+a(5)).*r+a(6)).*q ./ ...
        //
        mclArrayAssign(
          &x,
          rdivide(
            times(
              times(
                times(
                  times(
                    times(
                      mclIntArrayRef(mwVv(a, "a"), 1) * mwVv(r, "r")
                      + mclIntArrayRef(mwVv(a, "a"), 2),
                      mwVv(r, "r"))
                    + mclIntArrayRef(mwVv(a, "a"), 3),
                    mwVv(r, "r"))
                  + mclIntArrayRef(mwVv(a, "a"), 4),
                  mwVv(r, "r"))
                + mclIntArrayRef(mwVv(a, "a"), 5),
                mwVv(r, "r"))
              + mclIntArrayRef(mwVv(a, "a"), 6),
              mwVv(q, "q")),
            times(
              times(
                times(
                  times(
                    mclIntArrayRef(mwVv(b, "b"), 1) * mwVv(r, "r")
                    + mclIntArrayRef(mwVv(b, "b"), 2),
                    mwVv(r, "r"))
                  + mclIntArrayRef(mwVv(b, "b"), 3),
                  mwVv(r, "r"))
                + mclIntArrayRef(mwVv(b, "b"), 4),
                mwVv(r, "r"))
              + mclIntArrayRef(mwVv(b, "b"), 5),
              mwVv(r, "r"))
            + _mxarray12_),
          mwVv(k, "k"));
    //
    // (((((b(1)*r+b(2)).*r+b(3)).*r+b(4)).*r+b(5)).*r+1);
    // end
    //
    }
    //
    // 
    // % Rational approximation for lower region
    // k = 0 < y & y < ylow;
    //
    k = _mxarray13_ < mwVa(y, "y") & mwVa(y, "y") < mwVv(ylow, "ylow");
    //
    // if any(k(:))
    //
    if (tobool(any(mclArrayRef(mwVv(k, "k"), colon())))) {
        //
        // q  = sqrt(-2*log(y(k)/2));
        //
        q
          = sqrt(
              _mxarray14_
              * log(mclArrayRef(mwVa(y, "y"), mwVv(k, "k")) / _mxarray15_));
        //
        // x(k) = (((((c(1)*q+c(2)).*q+c(3)).*q+c(4)).*q+c(5)).*q+c(6)) ./ ...
        //
        mclArrayAssign(
          &x,
          rdivide(
            times(
              times(
                times(
                  times(
                    mclIntArrayRef(mwVv(c, "c"), 1) * mwVv(q, "q")
                    + mclIntArrayRef(mwVv(c, "c"), 2),
                    mwVv(q, "q"))
                  + mclIntArrayRef(mwVv(c, "c"), 3),
                  mwVv(q, "q"))
                + mclIntArrayRef(mwVv(c, "c"), 4),
                mwVv(q, "q"))
              + mclIntArrayRef(mwVv(c, "c"), 5),
              mwVv(q, "q"))
            + mclIntArrayRef(mwVv(c, "c"), 6),
            times(
              times(
                times(
                  mclIntArrayRef(mwVv(d, "d"), 1) * mwVv(q, "q")
                  + mclIntArrayRef(mwVv(d, "d"), 2),
                  mwVv(q, "q"))
                + mclIntArrayRef(mwVv(d, "d"), 3),
                mwVv(q, "q"))
              + mclIntArrayRef(mwVv(d, "d"), 4),
              mwVv(q, "q"))
            + _mxarray12_),
          mwVv(k, "k"));
    //
    // ((((d(1)*q+d(2)).*q+d(3)).*q+d(4)).*q+1);
    // end
    //
    }
    //
    // 
    // % Rational approximation for upper region
    // k = yhigh < y & y < 2;
    //
    k = mwVv(yhigh, "yhigh") < mwVa(y, "y") & mwVa(y, "y") < _mxarray15_;
    //
    // if any(k(:))
    //
    if (tobool(any(mclArrayRef(mwVv(k, "k"), colon())))) {
        //
        // q  = sqrt(-2*log(1-y(k)/2));
        //
        q
          = sqrt(
              _mxarray14_
              * log(
                  _mxarray12_
                  - mclArrayRef(mwVa(y, "y"), mwVv(k, "k")) / _mxarray15_));
        //
        // x(k) = -(((((c(1)*q+c(2)).*q+c(3)).*q+c(4)).*q+c(5)).*q+c(6)) ./ ...
        //
        mclArrayAssign(
          &x,
          rdivide(
            - (times(
                 times(
                   times(
                     times(
                       mclIntArrayRef(mwVv(c, "c"), 1) * mwVv(q, "q")
                       + mclIntArrayRef(mwVv(c, "c"), 2),
                       mwVv(q, "q"))
                     + mclIntArrayRef(mwVv(c, "c"), 3),
                     mwVv(q, "q"))
                   + mclIntArrayRef(mwVv(c, "c"), 4),
                   mwVv(q, "q"))
                 + mclIntArrayRef(mwVv(c, "c"), 5),
                 mwVv(q, "q"))
               + mclIntArrayRef(mwVv(c, "c"), 6)),
            times(
              times(
                times(
                  mclIntArrayRef(mwVv(d, "d"), 1) * mwVv(q, "q")
                  + mclIntArrayRef(mwVv(d, "d"), 2),
                  mwVv(q, "q"))
                + mclIntArrayRef(mwVv(d, "d"), 3),
                mwVv(q, "q"))
              + mclIntArrayRef(mwVv(d, "d"), 4),
              mwVv(q, "q"))
            + _mxarray12_),
          mwVv(k, "k"));
    //
    // ((((d(1)*q+d(2)).*q+d(3)).*q+d(4)).*q+1);
    // end
    //
    }
    //
    // 
    // % The relative error of the approximation has absolute value less
    // % than 1.13e-9.  One iteration of Halley's rational method (third
    // % order) gives full machine precision.
    // 
    // % Newton's method: new x = x - f/f'
    // % Halley's method: new x = x - 1/(f'/f - (f"/f')/2)
    // % This function: f = erfc(x) - y, f' = -2/sqrt(pi)*exp(-x^2), f" = -2*x*f'
    // 
    // % Newton's correction
    // u = (erfc(x) - y) ./ (-2/sqrt(pi) * exp(-x.^2));
    //
    u
      = rdivide(
          erfc(mwVv(x, "x")) - mwVa(y, "y"),
          _mxarray14_ / sqrt(_mxarray16_)
          * exp(- power(mwVv(x, "x"), _mxarray15_)));
    //
    // 
    // % Halley's step
    // x = x - u./(1+x.*u);
    //
    x
      = mwVv(x, "x")
        - rdivide(
            mwVv(u, "u"), _mxarray12_ + times(mwVv(x, "x"), mwVv(u, "u")));
    //
    // 
    // % Exceptional cases
    // 
    // x(y == 0) = Inf;
    //
    mclArrayAssign(&x, _mxarray17_, mwVa(y, "y") == _mxarray13_);
    //
    // x(y == 2) = -Inf;
    //
    mclArrayAssign(&x, _mxarray18_, mwVa(y, "y") == _mxarray15_);
    //
    // x(y < 0) = NaN;
    //
    mclArrayAssign(&x, _mxarray19_, mwVa(y, "y") < _mxarray13_);
    //
    // x(y > 2) = NaN;
    //
    mclArrayAssign(&x, _mxarray19_, mwVa(y, "y") > _mxarray15_);
    //
    // x(isnan(y)) = NaN;
    //
    mclArrayAssign(&x, _mxarray19_, isnan(mwVa(y, "y")));
    mwValidateOutput(x, 1, nargout_, "x", "erfcinv");
    return x;
}

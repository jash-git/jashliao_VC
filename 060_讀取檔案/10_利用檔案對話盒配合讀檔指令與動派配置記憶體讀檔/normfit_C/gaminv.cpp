//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "gaminv.hpp"
#include "distchck.hpp"
#include "gamcdf.hpp"
#include "gampdf.hpp"
#include "libmatlbm.hpp"
#include "norminv.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.0);
static mwArray _mxarray1_ = mclInitializeDouble(3.0);
static mwArray _mxarray2_ = mclInitializeDouble(0.0);

static mxChar _array4_[47] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'n',
                               'o', 'n', '-', 's', 'c', 'a', 'l', 'a', 'r', ' ',
                               'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', ' ',
                               't', 'o', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'i',
                               'n', ' ', 's', 'i', 'z', 'e', '.' };
static mwArray _mxarray3_ = mclInitializeString(47, _array4_);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray5_ = mclInitializeDouble(_ieee_nan_);
static double _ieee_plusinf_ = mclGetInf();
static mwArray _mxarray6_ = mclInitializeDouble(_ieee_plusinf_);
static mwArray _mxarray7_ = mclInitializeDouble(100.0);
static mwArray _mxarray8_ = mclInitializeDouble(2.0);
static mwArray _mxarray9_ = mclInitializeDouble(.5);
static mwArray _mxarray10_ = mclInitializeDouble(-2.0);
static mwArray _mxarray11_ = mclInitializeDouble(2.220446049250313e-16);
static mwArray _mxarray12_ = mclInitializeDouble(10.0);

static mxChar _array14_[37] = { 0x005c, 'n', 'W', 'a', 'r', 'n', 'i',
                                'n', 'g', ':', ' ', 'G', 'A', 'M', 'I',
                                'N', 'V', ' ', 'd', 'i', 'd', ' ', 'n',
                                'o', 't', ' ', 'c', 'o', 'n', 'v', 'e',
                                'r', 'g', 'e', '.', 0x005c, 'n' };
static mwArray _mxarray13_ = mclInitializeString(37, _array14_);

static mxChar _array16_[20] = { 'T', 'h', 'e', ' ', 'l', 'a', 's',
                                't', ' ', 's', 't', 'e', 'p', ' ',
                                'w', 'a', 's', ':', ' ', ' ' };
static mwArray _mxarray15_ = mclInitializeString(20, _array16_);

static mxChar _array18_[6] = { '%', '1', '3', '.', '8', 'f' };
static mwArray _mxarray17_ = mclInitializeString(6, _array18_);

void InitializeModule_gaminv() {
}

void TerminateModule_gaminv() {
}

static mwArray Mgaminv(int nargout_, mwArray p, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_gaminv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "gaminv" contains the normal interface for the "gaminv"
// M-function from file "c:\matlab6p5\toolbox\stats\gaminv.m" (lines 1-102).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray gaminv(mwArray p, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray x = mwArray::UNDEFINED;
    x = Mgaminv(nargout, p, a, b);
    return x;
}

//
// The function "mlxGaminv" contains the feval interface for the "gaminv"
// M-function from file "c:\matlab6p5\toolbox\stats\gaminv.m" (lines 1-102).
// The feval function calls the implementation version of gaminv through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxGaminv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: gaminv Line: 1 Column: 1"
                  " The function \"gaminv\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gaminv Line: 1 Column: "
                  "1 The function \"gaminv\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mgaminv(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mgaminv" is the implementation version of the "gaminv"
// M-function from file "c:\matlab6p5\toolbox\stats\gaminv.m" (lines 1-102). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function x = gaminv(p,a,b);
//
static mwArray Mgaminv(int nargout_, mwArray p, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_gaminv;
    int nargin_ = nargin(3, mwVarargin(p, a, b));
    mwArray x = mwArray::UNDEFINED;
    mwArray outstr = mwArray::UNDEFINED;
    mwArray str = mwArray::UNDEFINED;
    mwArray ksmall = mwArray::UNDEFINED;
    mwArray xnew = mwArray::UNDEFINED;
    mwArray h = mwArray::UNDEFINED;
    mwArray xk = mwArray::UNDEFINED;
    mwArray sigma = mwArray::UNDEFINED;
    mwArray mu = mwArray::UNDEFINED;
    mwArray temp = mwArray::UNDEFINED;
    mwArray v = mwArray::UNDEFINED;
    mwArray mn = mwArray::UNDEFINED;
    mwArray pk = mwArray::UNDEFINED;
    mwArray count = mwArray::UNDEFINED;
    mwArray count_limit = mwArray::UNDEFINED;
    mwArray k1 = mwArray::UNDEFINED;
    mwArray k0 = mwArray::UNDEFINED;
    mwArray tmp = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    //
    // %GAMINV Inverse of the gamma cumulative distribution function (cdf).
    // %   X = GAMINV(P,A,B)  returns the inverse of the gamma cdf with  
    // %   parameters A and B, at the probabilities in P.
    // %
    // %   The size of X is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   GAMINV uses Newton's method to converge to the solution.
    // 
    // %   References:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 6.5.
    // 
    // %   B.A. Jones 1-12-93
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.10 $  $Date: 2002/01/17 21:30:40 $
    // 
    // if nargin<3, 
    //
    if (nargin_ < 3) {
        //
        // b=1;
        //
        b = _mxarray0_;
    //
    // end
    //
    }
    //
    // 
    // [errorcode p a b] = distchck(3,p,a,b);
    //
    errorcode
    = distchck(
        mwVarargout(p, a, b),
        _mxarray1_,
        mwVarargin(mwVa(p, "p"), mwVa(a, "a"), mwVa(b, "b")));
    //
    // 
    // if errorcode > 0
    //
    if (mclGtBool(mwVv(errorcode, "errorcode"), _mxarray2_)) {
        //
        // error('Requires non-scalar arguments to match in size.');
        //
        error(mwVarargin(_mxarray3_));
    //
    // end
    //
    }
    //
    // 
    // %   Initialize X to zero.
    // x = zeros(size(p));
    //
    x = zeros(mwVarargin(size(mwValueVarargout(), mwVa(p, "p"))));
    //
    // 
    // k = find(p<0 | p>1 | a <= 0 | b <= 0);
    //
    k
      = find(
          mwVa(p, "p") < _mxarray2_ | mwVa(p, "p") > _mxarray0_
          | mwVa(a, "a") <= _mxarray2_
          | mwVa(b, "b") <= _mxarray2_);
    //
    // if any(k),
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // tmp  = NaN;
        //
        tmp = _mxarray5_;
        //
        // x(k) = tmp(ones(size(k)));
        //
        mclArrayAssign(
          &x,
          mclArrayRef(
            mwVv(tmp, "tmp"),
            ones(mwVarargin(size(mwValueVarargout(), mwVv(k, "k"))))),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // % The inverse cdf of 0 is 0, and the inverse cdf of 1 is 1.  
    // k0 = find(p == 0 & a > 0 & b > 0);
    //
    k0
      = find(
          mwVa(p, "p") == _mxarray2_ & mwVa(a, "a") > _mxarray2_
          & mwVa(b, "b") > _mxarray2_);
    //
    // if any(k0),
    //
    if (tobool(any(mwVv(k0, "k0")))) {
        //
        // x(k0) = zeros(size(k0)); 
        //
        mclArrayAssign(
          &x,
          zeros(mwVarargin(size(mwValueVarargout(), mwVv(k0, "k0")))),
          mwVv(k0, "k0"));
    //
    // end
    //
    }
    //
    // 
    // k1 = find(p == 1 & a > 0 & b > 0);
    //
    k1
      = find(
          mwVa(p, "p") == _mxarray0_ & mwVa(a, "a") > _mxarray2_
          & mwVa(b, "b") > _mxarray2_);
    //
    // if any(k1), 
    //
    if (tobool(any(mwVv(k1, "k1")))) {
        //
        // tmp = Inf;
        //
        tmp = _mxarray6_;
        //
        // x(k1) = tmp(ones(size(k1))); 
        //
        mclArrayAssign(
          &x,
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
    // % Newton's Method
    // % Permit no more than count_limit interations.
    // count_limit = 100;
    //
    count_limit = _mxarray7_;
    //
    // count = 0;
    //
    count = _mxarray2_;
    //
    // 
    // k = find(p > 0  &  p < 1 & a > 0 & b > 0);
    //
    k
      = find(
          mwVa(p, "p") > _mxarray2_ & mwVa(p, "p") < _mxarray0_
          & mwVa(a, "a") > _mxarray2_
          & mwVa(b, "b") > _mxarray2_);
    //
    // if (~any(k(:))), return; end
    //
    if (mclNotBool(any(mclArrayRef(mwVv(k, "k"), colon())))) {
        goto return_;
    }
    //
    // pk = p(k);
    //
    pk = mclArrayRef(mwVa(p, "p"), mwVv(k, "k"));
    //
    // 
    // % Supply a starting guess for the iteration.
    // %   Use a method of moments fit to the lognormal distribution. 
    // mn = a(k) .* b(k);
    //
    mn
      = times(
          mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
          mclArrayRef(mwVa(b, "b"), mwVv(k, "k")));
    //
    // v = mn .* b(k);
    //
    v = times(mwVv(mn, "mn"), mclArrayRef(mwVa(b, "b"), mwVv(k, "k")));
    //
    // temp = log(v + mn .^ 2); 
    //
    temp = log(mwVv(v, "v") + power(mwVv(mn, "mn"), _mxarray8_));
    //
    // mu = 2 * log(mn) - 0.5 * temp;
    //
    mu = _mxarray8_ * log(mwVv(mn, "mn")) - _mxarray9_ * mwVv(temp, "temp");
    //
    // sigma = -2 * log(mn) + temp;
    //
    sigma = _mxarray10_ * log(mwVv(mn, "mn")) + mwVv(temp, "temp");
    //
    // xk = exp(norminv(pk,mu,sigma));
    //
    xk = exp(norminv(mwVv(pk, "pk"), mwVv(mu, "mu"), mwVv(sigma, "sigma")));
    //
    // 
    // h = ones(size(pk)); 
    //
    h = ones(mwVarargin(size(mwValueVarargout(), mwVv(pk, "pk"))));
    //
    // 
    // % Break out of the iteration loop for three reasons:
    // %  1) the last update is very small (compared to x)
    // %  2) the last update is very small (compared to sqrt(eps))
    // %  3) There are more than 100 iterations. This should NEVER happen. 
    // 
    // while(any(abs(h) > sqrt(eps)*abs(xk))  &  max(abs(h)) > sqrt(eps)    ...
    //
    for (;;) {
        mwArray a_
          = any(abs(mwVv(h, "h")) > sqrt(_mxarray11_) * abs(mwVv(xk, "xk")));
        if (tobool(a_)) {
            a_ = a_ & max(abs(mwVv(h, "h"))) > sqrt(_mxarray11_);
        } else {
            a_ = 0;
        }
        if (tobool(a_)
            && tobool(
                 a_
                 & mwVv(count, "count") < mwVv(count_limit, "count_limit"))) {
        } else {
            break;
        }
        //
        // & count < count_limit), 
        // 
        // count = count + 1;
        //
        count = mwVv(count, "count") + _mxarray0_;
        //
        // h = (gamcdf(xk,a(k),b(k)) - pk) ./ gampdf(xk,a(k),b(k));
        //
        h
          = rdivide(
              gamcdf(
                mwVv(xk, "xk"),
                mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
                mclArrayRef(mwVa(b, "b"), mwVv(k, "k")))
              - mwVv(pk, "pk"),
              gampdf(
                mwVv(xk, "xk"),
                mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
                mclArrayRef(mwVa(b, "b"), mwVv(k, "k"))));
        //
        // xnew = xk - h;
        //
        xnew = mwVv(xk, "xk") - mwVv(h, "h");
        //
        // % Make sure that the current guess stays greater than zero.
        // % When Newton's Method suggests steps that lead to negative guesses
        // % take a step 9/10ths of the way to zero:
        // ksmall = find(xnew < 0);
        //
        ksmall = find(mwVv(xnew, "xnew") < _mxarray2_);
        //
        // if any(ksmall),
        //
        if (tobool(any(mwVv(ksmall, "ksmall")))) {
            //
            // xnew(ksmall) = xk(ksmall) / 10;
            //
            mclArrayAssign(
              &xnew,
              mclArrayRef(mwVv(xk, "xk"), mwVv(ksmall, "ksmall")) / _mxarray12_,
              mwVv(ksmall, "ksmall"));
            //
            // h = xk-xnew;
            //
            h = mwVv(xk, "xk") - mwVv(xnew, "xnew");
        //
        // end
        //
        }
        //
        // xk = xnew;
        //
        xk = mwVv(xnew, "xnew");
    //
    // end
    //
    }
    //
    // 
    // 
    // % Store the converged value in the correct place
    // x(k) = xk;
    //
    mclArrayAssign(&x, mwVv(xk, "xk"), mwVv(k, "k"));
    //
    // 
    // if count == count_limit, 
    //
    if (mclEqBool(mwVv(count, "count"), mwVv(count_limit, "count_limit"))) {
        //
        // fprintf('\nWarning: GAMINV did not converge.\n');
        //
        ans.EqAns(Nfprintf(0, _mxarray13_, mwVarargin()));
        //
        // str = 'The last step was:  ';
        //
        str = _mxarray15_;
        //
        // outstr = sprintf([str,'%13.8f'],h);
        //
        outstr
          = sprintf(
              horzcat(mwVarargin(mwVv(str, "str"), _mxarray17_)),
              mwVarargin(mwVv(h, "h")));
        //
        // fprintf(outstr);
        //
        ans.EqAns(Nfprintf(0, mwVv(outstr, "outstr"), mwVarargin()));
    //
    // end
    //
    }
    return_:
    mwValidateOutput(x, 1, nargout_, "x", "gaminv");
    return x;
}

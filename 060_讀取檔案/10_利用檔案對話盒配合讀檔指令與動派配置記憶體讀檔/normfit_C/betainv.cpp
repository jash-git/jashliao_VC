//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betainv.hpp"
#include "betacdf.hpp"
#include "betapdf.hpp"
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
static mwArray _mxarray6_ = mclInitializeDouble(1.0);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray7_ = mclInitializeDouble(_ieee_nan_);
static mwArray _mxarray8_ = mclInitializeDouble(100.0);
static mwArray _mxarray9_ = mclInitializeDouble(2.220446049250313e-16);
static mwArray _mxarray10_ = mclInitializeDouble(10.0);

static mxChar _array12_[38] = { 0x005c, 'n', 'W', 'a', 'r', 'n', 'i',
                                'n', 'g', ':', ' ', 'B', 'E', 'T', 'A',
                                'I', 'N', 'V', ' ', 'd', 'i', 'd', ' ',
                                'n', 'o', 't', ' ', 'c', 'o', 'n', 'v',
                                'e', 'r', 'g', 'e', '.', 0x005c, 'n' };
static mwArray _mxarray11_ = mclInitializeString(38, _array12_);

static mxChar _array14_[20] = { 'T', 'h', 'e', ' ', 'l', 'a', 's',
                                't', ' ', 's', 't', 'e', 'p', ' ',
                                'w', 'a', 's', ':', ' ', ' ' };
static mwArray _mxarray13_ = mclInitializeString(20, _array14_);

static mxChar _array16_[6] = { '%', '1', '3', '.', '8', 'f' };
static mwArray _mxarray15_ = mclInitializeString(6, _array16_);

void InitializeModule_betainv() {
}

void TerminateModule_betainv() {
}

static mwArray Mbetainv(int nargout_, mwArray p, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_betainv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betainv" contains the normal interface for the "betainv"
// M-function from file "c:\matlab6p5\toolbox\stats\betainv.m" (lines 1-111).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betainv(mwArray p, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray x = mwArray::UNDEFINED;
    x = Mbetainv(nargout, p, a, b);
    return x;
}

//
// The function "mlxBetainv" contains the feval interface for the "betainv"
// M-function from file "c:\matlab6p5\toolbox\stats\betainv.m" (lines 1-111).
// The feval function calls the implementation version of betainv through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxBetainv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: betainv Line: 1 Column: "
                  "1 The function \"betainv\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betainv Line: 1 Column: "
                  "1 The function \"betainv\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetainv(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetainv" is the implementation version of the "betainv"
// M-function from file "c:\matlab6p5\toolbox\stats\betainv.m" (lines 1-111).
// It contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function x = betainv(p,a,b);
//
static mwArray Mbetainv(int nargout_, mwArray p, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betainv;
    int nargin_ = nargin(3, mwVarargin(p, a, b));
    mwArray x = mwArray::UNDEFINED;
    mwArray outstr = mwArray::UNDEFINED;
    mwArray str = mwArray::UNDEFINED;
    mwArray klarge = mwArray::UNDEFINED;
    mwArray ksmall = mwArray::UNDEFINED;
    mwArray xnew = mwArray::UNDEFINED;
    mwArray crit = mwArray::UNDEFINED;
    mwArray h = mwArray::UNDEFINED;
    mwArray xk = mwArray::UNDEFINED;
    mwArray pk = mwArray::UNDEFINED;
    mwArray count = mwArray::UNDEFINED;
    mwArray count_limit = mwArray::UNDEFINED;
    mwArray k1 = mwArray::UNDEFINED;
    mwArray k0 = mwArray::UNDEFINED;
    mwArray tmp = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %BETAINV Inverse of the beta cumulative distribution function (cdf).
    // %   X = BETAINV(P,A,B) returns the inverse of the beta cdf with 
    // %   parameters A and B at the values in P.
    // %
    // %   The size of X is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   BETAINV uses Newton's method to converge to the solution.
    // 
    // %   Reference:
    // %      [1]     M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964.
    // 
    // %   B.A. Jones 1-12-93
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.11 $  $Date: 2002/01/17 21:29:57 $
    // 
    // if nargin <  3, 
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
    // [errorcode p a b] = distchck(3,p,a,b);
    //
    errorcode
    = distchck(
        mwVarargout(p, a, b),
        _mxarray2_,
        mwVarargin(mwVa(p, "p"), mwVa(a, "a"), mwVa(b, "b")));
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
    // %   Initialize x to zero.
    // x = zeros(size(p));
    //
    x = zeros(mwVarargin(size(mwValueVarargout(), mwVa(p, "p"))));
    //
    // 
    // %   Return NaN if the arguments are outside their respective limits.
    // k = find(p < 0 | p > 1 | a <= 0 | b <= 0);
    //
    k
      = find(
          mwVa(p, "p") < _mxarray3_ | mwVa(p, "p") > _mxarray6_
          | mwVa(a, "a") <= _mxarray3_
          | mwVa(b, "b") <= _mxarray3_);
    //
    // if any(k),
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // tmp = NaN;
        //
        tmp = _mxarray7_;
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
          mwVa(p, "p") == _mxarray3_ & mwVa(a, "a") > _mxarray3_
          & mwVa(b, "b") > _mxarray3_);
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
    // k1 = find(p==1);
    //
    k1 = find(mwVa(p, "p") == _mxarray6_);
    //
    // if any(k1), 
    //
    if (tobool(any(mwVv(k1, "k1")))) {
        //
        // x(k1) = ones(size(k1)); 
        //
        mclArrayAssign(
          &x,
          ones(mwVarargin(size(mwValueVarargout(), mwVv(k1, "k1")))),
          mwVv(k1, "k1"));
    //
    // end
    //
    }
    //
    // 
    // % Newton's Method.
    // % Permit no more than count_limit interations.
    // count_limit = 100;
    //
    count_limit = _mxarray8_;
    //
    // count = 0;
    //
    count = _mxarray3_;
    //
    // 
    // k = find(p > 0 & p < 1 & a > 0 & b > 0);
    //
    k
      = find(
          mwVa(p, "p") > _mxarray3_ & mwVa(p, "p") < _mxarray6_
          & mwVa(a, "a") > _mxarray3_
          & mwVa(b, "b") > _mxarray3_);
    //
    // if isempty(k)
    //
    if (tobool(isempty(mwVv(k, "k")))) {
        //
        // return;
        //
        goto return_;
    //
    // end
    //
    }
    //
    // pk = p(k);
    //
    pk = mclArrayRef(mwVa(p, "p"), mwVv(k, "k"));
    //
    // 
    // %   Use the mean as a starting guess. 
    // xk = a(k) ./ (a(k) + b(k));
    //
    xk
      = rdivide(
          mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
          mclArrayRef(mwVa(a, "a"), mwVv(k, "k"))
          + mclArrayRef(mwVa(b, "b"), mwVv(k, "k")));
    //
    // 
    // 
    // % Move starting values away from the boundaries.
    // if xk == 0,
    //
    if (mclEqBool(mwVv(xk, "xk"), _mxarray3_)) {
        //
        // xk = sqrt(eps);
        //
        xk = sqrt(_mxarray9_);
    //
    // end
    //
    }
    //
    // if xk == 1,
    //
    if (mclEqBool(mwVv(xk, "xk"), _mxarray6_)) {
        //
        // xk = 1 - sqrt(eps);
        //
        xk = _mxarray6_ - sqrt(_mxarray9_);
    //
    // end
    //
    }
    //
    // 
    // 
    // h = ones(size(pk));
    //
    h = ones(mwVarargin(size(mwValueVarargout(), mwVv(pk, "pk"))));
    //
    // crit = sqrt(eps); 
    //
    crit = sqrt(_mxarray9_);
    //
    // 
    // % Break out of the iteration loop for the following:
    // %  1) The last update is very small (compared to x).
    // %  2) The last update is very small (compared to 100*eps).
    // %  3) There are more than 100 iterations. This should NEVER happen. 
    // 
    // while(any(abs(h) > crit * abs(xk)) & max(abs(h)) > crit    ...
    //
    for (;;) {
        mwArray a_
          = any(abs(mwVv(h, "h")) > mwVv(crit, "crit") * abs(mwVv(xk, "xk")));
        if (tobool(a_)) {
            a_ = a_ & max(abs(mwVv(h, "h"))) > mwVv(crit, "crit");
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
        // count = count+1;    
        //
        count = mwVv(count, "count") + _mxarray6_;
        //
        // h = (betacdf(xk,a(k),b(k)) - pk) ./ betapdf(xk,a(k),b(k));
        //
        h
          = rdivide(
              betacdf(
                mwVv(xk, "xk"),
                mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
                mclArrayRef(mwVa(b, "b"), mwVv(k, "k")))
              - mwVv(pk, "pk"),
              betapdf(
                mwVv(xk, "xk"),
                mclArrayRef(mwVa(a, "a"), mwVv(k, "k")),
                mclArrayRef(mwVa(b, "b"), mwVv(k, "k"))));
        //
        // xnew = xk - h;
        //
        xnew = mwVv(xk, "xk") - mwVv(h, "h");
        //
        // 
        // % Make sure that the values stay inside the bounds.
        // % Initially, Newton's Method may take big steps.
        // ksmall = find(xnew <= 0);
        //
        ksmall = find(mwVv(xnew, "xnew") <= _mxarray3_);
        //
        // klarge = find(xnew >= 1);
        //
        klarge = find(mwVv(xnew, "xnew") >= _mxarray6_);
        //
        // if any(ksmall) | any(klarge)
        //
        {
            mwArray a_ = any(mwVv(ksmall, "ksmall"));
            if (tobool(a_) || tobool(a_ | any(mwVv(klarge, "klarge")))) {
                //
                // xnew(ksmall) = xk(ksmall) /10;
                //
                mclArrayAssign(
                  &xnew,
                  mclArrayRef(mwVv(xk, "xk"), mwVv(ksmall, "ksmall"))
                  / _mxarray10_,
                  mwVv(ksmall, "ksmall"));
                //
                // xnew(klarge) = 1 - (1 - xk(klarge))/10;
                //
                mclArrayAssign(
                  &xnew,
                  _mxarray6_
                  - (_mxarray6_
                     - mclArrayRef(mwVv(xk, "xk"), mwVv(klarge, "klarge")))
                    / _mxarray10_,
                  mwVv(klarge, "klarge"));
            } else {
            }
        //
        // end
        //
        }
        //
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
    // % Return the converged value(s).
    // x(k) = xk;
    //
    mclArrayAssign(&x, mwVv(xk, "xk"), mwVv(k, "k"));
    //
    // 
    // if count==count_limit, 
    //
    if (mclEqBool(mwVv(count, "count"), mwVv(count_limit, "count_limit"))) {
        //
        // fprintf('\nWarning: BETAINV did not converge.\n');
        //
        ans.EqAns(Nfprintf(0, _mxarray11_, mwVarargin()));
        //
        // str = 'The last step was:  ';
        //
        str = _mxarray13_;
        //
        // outstr = sprintf([str,'%13.8f'],h);
        //
        outstr
          = sprintf(
              horzcat(mwVarargin(mwVv(str, "str"), _mxarray15_)),
              mwVarargin(mwVv(h, "h")));
        //
        // fprintf(outstr);
        //
        ans.EqAns(Nfprintf(0, mwVv(outstr, "outstr"), mwVarargin()));
    //
    // end
    //
    }
    //
    // 
    //
    return_:
    mwValidateOutput(x, 1, nargout_, "x", "betainv");
    return x;
}

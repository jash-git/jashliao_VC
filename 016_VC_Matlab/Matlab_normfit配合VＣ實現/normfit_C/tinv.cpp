//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "tinv.hpp"
#include "betainv.hpp"
#include "distchck.hpp"
#include "libmatlbm.hpp"
#include "norminv.hpp"

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
static mwArray _mxarray7_ = mclInitializeDouble(1.0);
static mwArray _mxarray8_ = mclInitializeDouble(3.141592653589793);
static mwArray _mxarray9_ = mclInitializeDouble(.5);
static double _ieee_plusinf_ = mclGetInf();
static mwArray _mxarray10_ = mclInitializeDouble(_ieee_plusinf_);
static mwArray _mxarray11_ = mclInitializeDouble(1000.0);
static mwArray _mxarray12_ = mclInitializeDouble(3.0);
static mwArray _mxarray13_ = mclInitializeDouble(4.0);
static mwArray _mxarray14_ = mclInitializeDouble(5.0);
static mwArray _mxarray15_ = mclInitializeDouble(16.0);
static mwArray _mxarray16_ = mclInitializeDouble(96.0);
static mwArray _mxarray17_ = mclInitializeDouble(7.0);
static mwArray _mxarray18_ = mclInitializeDouble(19.0);
static mwArray _mxarray19_ = mclInitializeDouble(17.0);
static mwArray _mxarray20_ = mclInitializeDouble(15.0);
static mwArray _mxarray21_ = mclInitializeDouble(384.0);
static mwArray _mxarray22_ = mclInitializeDouble(79.0);
static mwArray _mxarray23_ = mclInitializeDouble(9.0);
static mwArray _mxarray24_ = mclInitializeDouble(776.0);
static mwArray _mxarray25_ = mclInitializeDouble(1482.0);
static mwArray _mxarray26_ = mclInitializeDouble(1920.0);
static mwArray _mxarray27_ = mclInitializeDouble(945.0);
static mwArray _mxarray28_ = mclInitializeDouble(92160.0);

void InitializeModule_tinv() {
}

void TerminateModule_tinv() {
}

static mwArray Mtinv(int nargout_, mwArray p, mwArray v);

_mexLocalFunctionTable _local_function_table_tinv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "tinv" contains the normal interface for the "tinv" M-function
// from file "c:\matlab6p5\toolbox\stats\tinv.m" (lines 1-70). This function
// processes any input arguments and passes them to the implementation version
// of the function, appearing above.
//
mwArray tinv(mwArray p, mwArray v) {
    int nargout = 1;
    mwArray x = mwArray::UNDEFINED;
    x = Mtinv(nargout, p, v);
    return x;
}

//
// The function "mlxTinv" contains the feval interface for the "tinv"
// M-function from file "c:\matlab6p5\toolbox\stats\tinv.m" (lines 1-70). The
// feval function calls the implementation version of tinv through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxTinv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: tinv Line: 1 Column: 1"
                  " The function \"tinv\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: tinv Line: 1 Column: 1"
                  " The function \"tinv\" was called with more "
                  "than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mtinv(nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mtinv" is the implementation version of the "tinv" M-function
// from file "c:\matlab6p5\toolbox\stats\tinv.m" (lines 1-70). It contains the
// actual compiled code for that M-function. It is a static function and must
// only be called from one of the interface functions, appearing below.
//
//
// function x = tinv(p,v);
//
static mwArray Mtinv(int nargout_, mwArray p, mwArray v) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_tinv;
    int nargin_ = nargin(2, mwVarargin(p, v));
    mwArray x = mwArray::UNDEFINED;
    mwArray df = mwArray::UNDEFINED;
    mwArray xn = mwArray::UNDEFINED;
    mwArray z = mwArray::UNDEFINED;
    mwArray k1 = mwArray::UNDEFINED;
    mwArray tmp = mwArray::UNDEFINED;
    mwArray k0 = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %TINV   Inverse of Student's T cumulative distribution function (cdf).
    // %   X=TINV(P,V) returns the inverse of Student's T cdf with V degrees 
    // %   of freedom, at the values in P.
    // %
    // %   The size of X is the common size of P and V. A scalar input   
    // %   functions as a constant matrix of the same size as the other input.    
    // 
    // %   References:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 26.6.2
    // 
    // %   B.A. Jones 1-18-93
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.11 $  $Date: 2002/01/17 21:32:05 $
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
    // % Initialize Y to zero, or NaN for invalid d.f.
    // x=zeros(size(p));
    //
    x = zeros(mwVarargin(size(mwValueVarargout(), mwVa(p, "p"))));
    //
    // x(v <= 0) = NaN;
    //
    mclArrayAssign(&x, _mxarray6_, mwVa(v, "v") <= _mxarray3_);
    //
    // 
    // k = find(v == 1 & ~isnan(x));
    //
    k = find(mwVa(v, "v") == _mxarray7_ & ~ isnan(mwVv(x, "x")));
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // x(k) = tan(pi * (p(k) - 0.5));
        //
        mclArrayAssign(
          &x,
          tan(
            _mxarray8_
            * (mclArrayRef(mwVa(p, "p"), mwVv(k, "k")) - _mxarray9_)),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // % The inverse cdf of 0 is -Inf, and the inverse cdf of 1 is Inf.
    // k0 = find(p == 0 & ~isnan(x));
    //
    k0 = find(mwVa(p, "p") == _mxarray3_ & ~ isnan(mwVv(x, "x")));
    //
    // if any(k0)
    //
    if (tobool(any(mwVv(k0, "k0")))) {
        //
        // tmp   = Inf;
        //
        tmp = _mxarray10_;
        //
        // x(k0) = -tmp(ones(size(k0)));
        //
        mclArrayAssign(
          &x,
          - mclArrayRef(
              mwVv(tmp, "tmp"),
              ones(mwVarargin(size(mwValueVarargout(), mwVv(k0, "k0"))))),
          mwVv(k0, "k0"));
    //
    // end
    //
    }
    //
    // k1 = find(p ==1 & ~isnan(x));
    //
    k1 = find(mwVa(p, "p") == _mxarray7_ & ~ isnan(mwVv(x, "x")));
    //
    // if any(k1)
    //
    if (tobool(any(mwVv(k1, "k1")))) {
        //
        // tmp   = Inf;
        //
        tmp = _mxarray10_;
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
    // % For small d.f., call betainv which uses Newton's method
    // k = find(p >= 0.5 & p < 1 & ~isnan(x) & v < 1000);
    //
    k
      = find(
          mwVa(p, "p") >= _mxarray9_ & mwVa(p, "p") < _mxarray7_
          & ~ isnan(mwVv(x, "x"))
          & mwVa(v, "v") < _mxarray11_);
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // z = betainv(2*(1-p(k)),v(k)/2,0.5);
        //
        z
          = betainv(
              _mxarray2_
              * (_mxarray7_ - mclArrayRef(mwVa(p, "p"), mwVv(k, "k"))),
              mclArrayRef(mwVa(v, "v"), mwVv(k, "k")) / _mxarray2_,
              _mxarray9_);
        //
        // x(k) = sqrt(v(k) ./ z - v(k));
        //
        mclArrayAssign(
          &x,
          sqrt(
            rdivide(mclArrayRef(mwVa(v, "v"), mwVv(k, "k")), mwVv(z, "z"))
            - mclArrayRef(mwVa(v, "v"), mwVv(k, "k"))),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // k = find(p < 0.5 & p > 0 & ~isnan(x) & v < 1000);
    //
    k
      = find(
          mwVa(p, "p") < _mxarray9_ & mwVa(p, "p") > _mxarray3_
          & ~ isnan(mwVv(x, "x"))
          & mwVa(v, "v") < _mxarray11_);
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // z = betainv(2*(p(k)),v(k)/2,0.5);
        //
        z
          = betainv(
              _mxarray2_ * mclArrayRef(mwVa(p, "p"), mwVv(k, "k")),
              mclArrayRef(mwVa(v, "v"), mwVv(k, "k")) / _mxarray2_,
              _mxarray9_);
        //
        // x(k) = -sqrt(v(k) ./ z - v(k));
        //
        mclArrayAssign(
          &x,
          - sqrt(
              rdivide(mclArrayRef(mwVa(v, "v"), mwVv(k, "k")), mwVv(z, "z"))
              - mclArrayRef(mwVa(v, "v"), mwVv(k, "k"))),
          mwVv(k, "k"));
    //
    // end
    //
    }
    //
    // 
    // % For large d.f., use Abramowitz & Stegun formula 26.7.5
    // k = find(p>0 & p<1 & ~isnan(x) & v >= 1000);
    //
    k
      = find(
          mwVa(p, "p") > _mxarray3_ & mwVa(p, "p") < _mxarray7_
          & ~ isnan(mwVv(x, "x"))
          & mwVa(v, "v") >= _mxarray11_);
    //
    // if any(k)
    //
    if (tobool(any(mwVv(k, "k")))) {
        //
        // xn = norminv(p(k));
        //
        xn = norminv(mclArrayRef(mwVa(p, "p"), mwVv(k, "k")));
        //
        // df = v(k);
        //
        df = mclArrayRef(mwVa(v, "v"), mwVv(k, "k"));
        //
        // x(k) = xn + (xn.^3+xn)./(4*df) + ...
        //
        mclArrayAssign(
          &x,
          mwVv(xn, "xn")
          + rdivide(
              power(mwVv(xn, "xn"), _mxarray12_) + mwVv(xn, "xn"),
              _mxarray13_ * mwVv(df, "df"))
          + rdivide(
              _mxarray14_ * power(mwVv(xn, "xn"), _mxarray14_)
              + times(_mxarray15_, power(mwVv(xn, "xn"), _mxarray12_))
              + _mxarray12_ * mwVv(xn, "xn"),
              _mxarray16_ * power(mwVv(df, "df"), _mxarray2_))
          + rdivide(
              _mxarray12_ * power(mwVv(xn, "xn"), _mxarray17_)
              + _mxarray18_ * power(mwVv(xn, "xn"), _mxarray14_)
              + _mxarray19_ * power(mwVv(xn, "xn"), _mxarray12_)
              - _mxarray20_ * mwVv(xn, "xn"),
              _mxarray21_ * power(mwVv(df, "df"), _mxarray12_))
          + rdivide(
              _mxarray22_ * power(mwVv(xn, "xn"), _mxarray23_)
              + _mxarray24_ * power(mwVv(xn, "xn"), _mxarray17_)
              + _mxarray25_ * power(mwVv(xn, "xn"), _mxarray14_)
              - _mxarray26_ * power(mwVv(xn, "xn"), _mxarray12_)
              - _mxarray27_ * mwVv(xn, "xn"),
              _mxarray28_ * power(mwVv(df, "df"), _mxarray13_)),
          mwVv(k, "k"));
    //
    // (5*xn.^5+16.*xn.^3+3*xn)./(96*df.^2) + ...
    // (3*xn.^7+19*xn.^5+17*xn.^3-15*xn)./(384*df.^3) +...
    // (79*xn.^9+776*xn.^7+1482*xn.^5-1920*xn.^3-945*xn)./(92160*df.^4);
    // end
    //
    }
    mwValidateOutput(x, 1, nargout_, "x", "tinv");
    return x;
}

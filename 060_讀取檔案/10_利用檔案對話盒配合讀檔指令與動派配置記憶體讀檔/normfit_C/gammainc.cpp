//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "gammainc.hpp"
#include "gammaln_mex_interface.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[42] = { 'X', ' ', 'a', 'n', 'd', ' ', 'A', ' ', 'm',
                               'u', 's', 't', ' ', 'b', 'e', ' ', 't', 'h',
                               'e', ' ', 's', 'a', 'm', 'e', ' ', 's', 'i',
                               'z', 'e', ',', ' ', 'o', 'r', ' ', 's', 'c',
                               'a', 'l', 'a', 'r', 's', '.' };
static mwArray _mxarray0_ = mclInitializeString(42, _array1_);
static mwArray _mxarray2_ = mclInitializeDouble(0.0);

static mxChar _array4_[23] = { 'A', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'n', 'o', 'n', '-', 'n', 'e',
                               'g', 'a', 't', 'i', 'v', 'e', '.' };
static mwArray _mxarray3_ = mclInitializeString(23, _array4_);
static mwArray _mxarray5_ = mclInitializeDouble(1.0);
static mwArray _mxarray6_ = mclInitializeDouble(1048576.0);

static mxChar _array8_[3] = { 'i', 'n', 'f' };
static mwArray _mxarray7_ = mclInitializeString(3, _array8_);
static mwArray _mxarray9_ = mclInitializeDouble(2.220446049250313e-14);
static mwArray _mxarray10_ = mclInitializeDouble(.3333333333333333);

void InitializeModule_gammainc() {
}

void TerminateModule_gammainc() {
}

static mwArray Mgammainc(int nargout_, mwArray x, mwArray a);

_mexLocalFunctionTable _local_function_table_gammainc
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "gammainc" contains the normal interface for the "gammainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\gammainc.m" (lines
// 1-112). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray gammainc(mwArray x, mwArray a) {
    int nargout = 1;
    mwArray b = mwArray::UNDEFINED;
    b = Mgammainc(nargout, x, a);
    return b;
}

//
// The function "mlxGammainc" contains the feval interface for the "gammainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\gammainc.m" (lines
// 1-112). The feval function calls the implementation version of gammainc
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxGammainc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: gammainc Line: 1 Column: "
                  "1 The function \"gammainc\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gammainc Line: 1 Column: "
                  "1 The function \"gammainc\" was called with mor"
                  "e than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mgammainc(nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mgammainc" is the implementation version of the "gammainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\gammainc.m" (lines
// 1-112). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function b = gammainc(x,a)
//
static mwArray Mgammainc(int nargout_, mwArray x, mwArray a) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_gammainc;
    mwArray b = mwArray::UNDEFINED;
    mwArray anf = mwArray::UNDEFINED;
    mwArray ana = mwArray::UNDEFINED;
    mwArray gold = mwArray::UNDEFINED;
    mwArray g = mwArray::UNDEFINED;
    mwArray n = mwArray::UNDEFINED;
    mwArray fac = mwArray::UNDEFINED;
    mwArray b1 = mwArray::UNDEFINED;
    mwArray b0 = mwArray::UNDEFINED;
    mwArray a1 = mwArray::UNDEFINED;
    mwArray a0 = mwArray::UNDEFINED;
    mwArray del = mwArray::UNDEFINED;
    mwArray sum = mwArray::UNDEFINED;
    mwArray ap = mwArray::UNDEFINED;
    mwArray ak = mwArray::UNDEFINED;
    mwArray xk = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray amax = mwArray::UNDEFINED;
    mwArray ascalar = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %GAMMAINC Incomplete gamma function.
    // %   Y = GAMMAINC(X,A) evaluates the incomplete gamma function for
    // %   corresponding elements of X and A.  X and A must be real and the same
    // %   size (or either can be a scalar).  A must also be non-negative.
    // %   The incomplete gamma function is defined as: 
    // %
    // %    gammainc(x,a) = 1 ./ gamma(a) .*
    // %       integral from 0 to x of t^(a-1) exp(-t) dt
    // %
    // %   For any a>=0, as x approaches infinity, gammainc(x,a) approaches 1.
    // %   For small x and a, gammainc(x,a) ~= x^a, so gammainc(0,0) = 1.
    // %
    // %   See also GAMMA, GAMMALN, PSI.
    // 
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.17 $  $Date: 2002/04/09 00:29:48 $
    // 
    // % x and a must be compatible for addition.
    // 
    // try
    //
    try {
        //
        // b = zeros(size(x + a));
        //
        b
          = zeros(
              mwVarargin(
                size(mwValueVarargout(), mwVa(x, "x") + mwVa(a, "a"))));
    //
    // catch
    //
    } catch(mwException e_) {
        //
        // error('X and A must be the same size, or scalars.')
        //
        error(mwVarargin(_mxarray0_));
    //
    // end
    //
    }
    //
    // if any(a < 0)
    //
    if (tobool(any(mwVa(a, "a") < _mxarray2_))) {
        //
        // error('A must be non-negative.')
        //
        error(mwVarargin(_mxarray3_));
    //
    // end
    //
    }
    //
    // 
    // % If a is a vector, make sure x is too.
    // 
    // ascalar = (max(size(a)) == 1);
    //
    ascalar = max(size(mwValueVarargout(), mwVa(a, "a"))) == _mxarray5_;
    //
    // if ~ascalar & (max(size(x)) == 1)
    //
    {
        mwArray a_ = ~ mwVv(ascalar, "ascalar");
        if (tobool(a_)
            && tobool(
                 a_
                 & max(size(mwValueVarargout(), mwVa(x, "x")))
                   == _mxarray5_)) {
            //
            // x = x(ones(size(a)));
            //
            x
              = mclArrayRef(
                  mwVa(x, "x"),
                  ones(mwVarargin(size(mwValueVarargout(), mwVa(a, "a")))));
        } else {
        }
    //
    // end
    //
    }
    //
    // 
    // % Upper limit for series and continued fraction.
    // 
    // amax = 2^20;
    //
    amax = _mxarray6_;
    //
    // if all(a <= amax)
    //
    if (tobool(all(mwVa(a, "a") <= mwVv(amax, "amax")))) {
        //
        // 
        // % Series expansion for x < a+1
        // 
        // k = find(a ~= 0 & x ~= 0 & x < a+1);
        //
        k
          = find(
              mwVa(a, "a") != _mxarray2_ & mwVa(x, "x") != _mxarray2_
              & mwVa(x, "x") < mwVa(a, "a") + _mxarray5_);
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // xk = x(k);
            //
            xk = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            //
            // if ascalar, ak = a; else, ak = a(k); end
            //
            if (tobool(mwVv(ascalar, "ascalar"))) {
                ak = mwVa(a, "a");
            } else {
                ak = mclArrayRef(mwVa(a, "a"), mwVv(k, "k"));
            }
            //
            // ap = ak;
            //
            ap = mwVv(ak, "ak");
            //
            // sum = 1./ap;
            //
            sum = rdivide(_mxarray5_, mwVv(ap, "ap"));
            //
            // del = sum;
            //
            del = mwVv(sum, "sum");
            //
            // while norm(del,'inf') >= 100*eps*norm(sum,'inf')
            //
            while (mclGeBool(
                     norm(mwVv(del, "del"), _mxarray7_),
                     _mxarray9_ * norm(mwVv(sum, "sum"), _mxarray7_))) {
                //
                // ap = ap + 1;
                //
                ap = mwVv(ap, "ap") + _mxarray5_;
                //
                // del = xk .* del ./ ap;
                //
                del
                  = rdivide(
                      times(mwVv(xk, "xk"), mwVv(del, "del")), mwVv(ap, "ap"));
                //
                // sum = sum + del;
                //
                sum = mwVv(sum, "sum") + mwVv(del, "del");
            //
            // end
            //
            }
            //
            // b(k) = sum .* exp(-xk + ak.*log(xk) - gammaln(ak));
            //
            mclArrayAssign(
              &b,
              times(
                mwVv(sum, "sum"),
                exp(
                  - mwVv(xk, "xk") + times(mwVv(ak, "ak"), log(mwVv(xk, "xk")))
                  - Ngammaln(
                      0, mwValueVarargout(), mwVarargin(mwVv(ak, "ak"))))),
              mwVv(k, "k"));
        //
        // end
        //
        }
        //
        // 
        // % Continued fraction for x >= a+1
        // 
        // k = find(a ~= 0 & x ~= 0 & x >= a+1);
        //
        k
          = find(
              mwVa(a, "a") != _mxarray2_ & mwVa(x, "x") != _mxarray2_
              & mwVa(x, "x") >= mwVa(a, "a") + _mxarray5_);
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // xk = x(k);
            //
            xk = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            //
            // a0 = ones(size(k));
            //
            a0 = ones(mwVarargin(size(mwValueVarargout(), mwVv(k, "k"))));
            //
            // a1 = x(k);
            //
            a1 = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            //
            // b0 = zeros(size(k));
            //
            b0 = zeros(mwVarargin(size(mwValueVarargout(), mwVv(k, "k"))));
            //
            // b1 = a0;
            //
            b1 = mwVv(a0, "a0");
            //
            // if ascalar, ak = a; else, ak = a(k); end
            //
            if (tobool(mwVv(ascalar, "ascalar"))) {
                ak = mwVa(a, "a");
            } else {
                ak = mclArrayRef(mwVa(a, "a"), mwVv(k, "k"));
            }
            //
            // fac = 1;
            //
            fac = _mxarray5_;
            //
            // n = 1;
            //
            n = _mxarray5_;
            //
            // g = b1;
            //
            g = mwVv(b1, "b1");
            //
            // gold = b0;
            //
            gold = mwVv(b0, "b0");
            //
            // while norm(g-gold,'inf') >= 100*eps*norm(g,'inf');
            //
            while (mclGeBool(
                     norm(mwVv(g, "g") - mwVv(gold, "gold"), _mxarray7_),
                     _mxarray9_ * norm(mwVv(g, "g"), _mxarray7_))) {
                //
                // gold = g;
                //
                gold = mwVv(g, "g");
                //
                // ana = n - ak;
                //
                ana = mwVv(n, "n") - mwVv(ak, "ak");
                //
                // a0 = (a1 + a0 .*ana) .* fac;
                //
                a0
                  = times(
                      mwVv(a1, "a1") + times(mwVv(a0, "a0"), mwVv(ana, "ana")),
                      mwVv(fac, "fac"));
                //
                // b0 = (b1 + b0 .*ana) .* fac;
                //
                b0
                  = times(
                      mwVv(b1, "b1") + times(mwVv(b0, "b0"), mwVv(ana, "ana")),
                      mwVv(fac, "fac"));
                //
                // anf = n*fac;
                //
                anf = mwVv(n, "n") * mwVv(fac, "fac");
                //
                // a1 = xk .* a0 + anf .* a1;
                //
                a1
                  = times(mwVv(xk, "xk"), mwVv(a0, "a0"))
                    + times(mwVv(anf, "anf"), mwVv(a1, "a1"));
                //
                // b1 = xk .* b0 + anf .* b1;
                //
                b1
                  = times(mwVv(xk, "xk"), mwVv(b0, "b0"))
                    + times(mwVv(anf, "anf"), mwVv(b1, "b1"));
                //
                // fac = 1 ./ a1;
                //
                fac = rdivide(_mxarray5_, mwVv(a1, "a1"));
                //
                // g = b1 .* fac;
                //
                g = times(mwVv(b1, "b1"), mwVv(fac, "fac"));
                //
                // n = n + 1;
                //
                n = mwVv(n, "n") + _mxarray5_;
            //
            // end
            //
            }
            //
            // b(k) = 1 - exp(-xk + ak.*log(xk) - gammaln(ak)) .* g;
            //
            mclArrayAssign(
              &b,
              _mxarray5_
              - times(
                  exp(
                    - mwVv(xk, "xk")
                    + times(mwVv(ak, "ak"), log(mwVv(xk, "xk")))
                    - Ngammaln(
                        0, mwValueVarargout(), mwVarargin(mwVv(ak, "ak")))),
                  mwVv(g, "g")),
              mwVv(k, "k"));
        //
        // end
        //
        }
        //
        // 
        // k = find(x == 0);
        //
        k = find(mwVa(x, "x") == _mxarray2_);
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // b(k) = 0;
            //
            mclArrayAssign(&b, _mxarray2_, mwVv(k, "k"));
        //
        // end
        //
        }
        //
        // k = find(a == 0 & ones(size(x)));
        //
        k
          = find(
              mwVa(a, "a") == _mxarray2_
              & ones(mwVarargin(size(mwValueVarargout(), mwVa(x, "x")))));
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // b(k) = 1;
            //
            mclArrayAssign(&b, _mxarray5_, mwVv(k, "k"));
        //
        // end
        //
        }
    //
    // 
    // else
    //
    } else {
        //
        // 
        // % Approximation for a > amax.  Accurate to about 5.e-5.
        // 
        // if ascalar
        //
        if (tobool(mwVv(ascalar, "ascalar"))) {
            //
            // x = max(amax-1/3 + sqrt(amax/a).*(x-(a-1/3)),0);
            //
            x
              = max(
                  mwVv(amax, "amax") - _mxarray10_
                  + times(
                      sqrt(mwVv(amax, "amax") / mwVa(a, "a")),
                      mwVa(x, "x") - (mwVa(a, "a") - _mxarray10_)),
                  _mxarray2_);
            //
            // b = gammainc(x,amax);
            //
            b = gammainc(mwVa(x, "x"), mwVv(amax, "amax"));
        //
        // else
        //
        } else {
            //
            // k = find(a > amax);
            //
            k = find(mwVa(a, "a") > mwVv(amax, "amax"));
            //
            // x(k) = max(amax-1/3 + sqrt(amax./a(k)).*(x(k)-(a(k)-1/3)),0);
            //
            mclArrayAssign(
              &x,
              max(
                mwVv(amax, "amax") - _mxarray10_
                + times(
                    sqrt(
                      rdivide(
                        mwVv(amax, "amax"),
                        mclArrayRef(mwVa(a, "a"), mwVv(k, "k")))),
                    mclArrayRef(mwVa(x, "x"), mwVv(k, "k"))
                    - (mclArrayRef(mwVa(a, "a"), mwVv(k, "k"))
                       - _mxarray10_)),
                _mxarray2_),
              mwVv(k, "k"));
            //
            // a(k) = amax;
            //
            mclArrayAssign(&a, mwVv(amax, "amax"), mwVv(k, "k"));
            //
            // b = gammainc(x,a);
            //
            b = gammainc(mwVa(x, "x"), mwVa(a, "a"));
        //
        // end
        //
        }
    //
    // 
    // end
    //
    }
    mwValidateOutput(b, 1, nargout_, "b", "gammainc");
    return b;
}

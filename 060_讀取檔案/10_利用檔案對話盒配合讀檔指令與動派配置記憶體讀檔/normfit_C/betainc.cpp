//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betainc.hpp"
#include "betacore.hpp"
#include "erfc.hpp"
#include "gammainc.hpp"
#include "gammaln_mex_interface.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[31] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's',
                               ' ', 't', 'h', 'r', 'e', 'e', ' ', 'i',
                               'n', 'p', 'u', 't', ' ', 'a', 'r', 'g',
                               'u', 'm', 'e', 'n', 't', 's', '.' };
static mwArray _mxarray0_ = mclInitializeString(31, _array1_);

static mxChar _array3_[32] = { 'X', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'i', 'n', ' ', 't', 'h', 'e',
                               ' ', 'i', 'n', 't', 'e', 'r', 'v', 'a',
                               'l', ' ', '[', '0', ',', '1', ']', '.' };
static mwArray _mxarray2_ = mclInitializeString(32, _array3_);

static mxChar _array5_[22] = { 'Z', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'n', 'o', 'n', 'n', 'e', 'g',
                               'a', 't', 'i', 'v', 'e', '.' };
static mwArray _mxarray4_ = mclInitializeString(22, _array5_);

static mxChar _array7_[22] = { 'W', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'n', 'o', 'n', 'n', 'e', 'g',
                               'a', 't', 'i', 'v', 'e', '.' };
static mwArray _mxarray6_ = mclInitializeString(22, _array7_);
static mwArray _mxarray8_ = mclInitializeDouble(0.0);
static mwArray _mxarray9_ = mclInitializeDouble(1.0);

static mxChar _array11_[65] = { 'X', ',', ' ', 'Z', ' ', 'a', 'n', 'd', ' ',
                                'W', ' ', 'm', 'u', 's', 't', ' ', 'a', 'l',
                                'l', ' ', 't', 'h', 'e', ' ', 's', 'a', 'm',
                                'e', ' ', 's', 'i', 'z', 'e', ' ', '(', 'o',
                                'r', ' ', 'a', 'n', 'y', ' ', 'o', 'f', ' ',
                                't', 'h', 'e', 'm', ' ', 'c', 'a', 'n', ' ',
                                'b', 'e', ' ', 's', 'c', 'a', 'l', 'a', 'r',
                                ')', '.' };
static mwArray _mxarray10_ = mclInitializeString(65, _array11_);
static mwArray _mxarray12_ = mclInitializeDouble(2.0);
static mwArray _mxarray13_ = mclInitializeDouble(.3333333333333333);
static mwArray _mxarray14_ = mclInitializeDouble(.5);
static mwArray _mxarray15_ = mclInitializeDouble(-3.0);
static mwArray _mxarray16_ = mclInitializeDouble(9.0);
static mwArray _mxarray17_ = mclInitializeDouble(.8);
static mwArray _mxarray18_ = mclInitializeDouble(3.0);

void InitializeModule_betainc() {
}

void TerminateModule_betainc() {
}

static mwArray Mbetainc(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_betainc
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betainc" contains the normal interface for the "betainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betainc.m" (lines
// 1-89). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betainc(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mbetainc(nargout, x, a, b);
    return y;
}

//
// The function "mlxBetainc" contains the feval interface for the "betainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betainc.m" (lines
// 1-89). The feval function calls the implementation version of betainc
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxBetainc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: betainc Line: 1 Column: "
                  "1 The function \"betainc\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betainc Line: 1 Column: "
                  "1 The function \"betainc\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetainc(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetainc" is the implementation version of the "betainc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betainc.m" (lines
// 1-89). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = betainc(x,a,b)
//
static mwArray Mbetainc(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betainc;
    int nargin_ = nargin(3, mwVarargin(x, a, b));
    mwArray y = mwArray::UNDEFINED;
    mwArray s = mwArray::UNDEFINED;
    mwArray w2 = mwArray::UNDEFINED;
    mwArray w1 = mwArray::UNDEFINED;
    mwArray bk = mwArray::UNDEFINED;
    mwArray ak = mwArray::UNDEFINED;
    mwArray xk = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray bt = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %BETAINC Incomplete beta function.
    // %   Y = BETAINC(X,Z,W) computes the incomplete beta function for
    // %   corresponding elements of X, Z, and W.  The elements of X must be
    // %   in the closed interval [0,1].  The arguments X, Z and W must all
    // %   be the same size (or any of them can be scalar).
    // %
    // %   The incomplete beta function is defined as
    // %
    // %     I_x(z,b) = 1./BETA(z,w) .* 
    // %                 integral from 0 to x of t.^(z-1) .* (1-t).^(w-1) dt
    // %
    // %   See also BETA, BETALN.
    // 
    // %   Ref: Abramowitz & Stegun, Handbook of Mathematical Functions, sec. 26.5,
    // %   especially 26.5.8, 26.5.20 and 26.5.21.
    // 
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.16 $  $Date: 2002/04/09 00:29:45 $
    // 
    // if nargin < 3
    //
    if (nargin_ < 3) {
        //
        // error('Requires three input arguments.')
        //
        error(mwVarargin(_mxarray0_));
    //
    // elseif any(x(:) < 0 | x(:) > 1 | isnan(x(:))) | ~isreal(x)
    //
    } else {
        mwArray a_
          = any(
              mclArrayRef(mwVa(x, "x"), colon()) < _mxarray8_
              | mclArrayRef(mwVa(x, "x"), colon()) > _mxarray9_
              | isnan(mclArrayRef(mwVa(x, "x"), colon())));
        if (tobool(a_) || tobool(a_ | ~ isreal(mwVa(x, "x")))) {
            //
            // error('X must be in the interval [0,1].')
            //
            error(mwVarargin(_mxarray2_));
        //
        // elseif any(a(:) < 0 | isnan(a(:))) | ~isreal(a)
        //
        } else {
            mwArray a_0
              = any(
                  mclArrayRef(mwVa(a, "a"), colon()) < _mxarray8_
                  | isnan(mclArrayRef(mwVa(a, "a"), colon())));
            if (tobool(a_0) || tobool(a_0 | ~ isreal(mwVa(a, "a")))) {
                //
                // error('Z must be nonnegative.')
                //
                error(mwVarargin(_mxarray4_));
            //
            // elseif any(b(:) < 0 | isnan(b(:))) | ~isreal(b)
            //
            } else {
                mwArray a_1
                  = any(
                      mclArrayRef(mwVa(b, "b"), colon()) < _mxarray8_
                      | isnan(mclArrayRef(mwVa(b, "b"), colon())));
                if (tobool(a_1) || tobool(a_1 | ~ isreal(mwVa(b, "b")))) {
                    //
                    // error('W must be nonnegative.')
                    //
                    error(mwVarargin(_mxarray6_));
                } else {
                }
            }
        }
    //
    // end
    //
    }
    //
    // 
    // try
    //
    try {
        //
        // % Preallocate y (using the size rules for plus)
        // y = x + a + b; 
        //
        y = mwVa(x, "x") + mwVa(a, "a") + mwVa(b, "b");
        //
        // y(:) = 0;
        //
        mclArrayAssign(&y, _mxarray8_, colon());
    //
    // catch
    //
    } catch(mwException e_) {
        //
        // error('X, Z and W must all the same size (or any of them can be scalar).')
        //
        error(mwVarargin(_mxarray10_));
    //
    // end
    //
    }
    //
    // 
    // if ~isempty(y)
    //
    if (mclNotBool(isempty(mwVv(y, "y")))) {
        //
        // bt = exp(gammaln(a+b)-gammaln(a)-gammaln(b) + ...
        //
        bt
          = exp(
              Ngammaln(
                0, mwValueVarargout(), mwVarargin(mwVa(a, "a") + mwVa(b, "b")))
              - Ngammaln(0, mwValueVarargout(), mwVarargin(mwVa(a, "a")))
              - Ngammaln(0, mwValueVarargout(), mwVarargin(mwVa(b, "b")))
              + times(
                  mwVa(a, "a"),
                  log(mwVa(x, "x") + (mwVa(x, "x") == _mxarray8_)))
              + times(
                  mwVa(b, "b"),
                  log(
                    _mxarray9_ - mwVa(x, "x")
                    + (mwVa(x, "x") == _mxarray9_))));
        //
        // a.*log(x+(x==0)) + b.*log(1-x+(x==1)));
        // 
        // k = find(x < (a+1) ./ (a+b+2));
        //
        k
          = find(
              mwVa(x, "x")
              < rdivide(
                  mwVa(a, "a") + _mxarray9_,
                  mwVa(a, "a") + mwVa(b, "b") + _mxarray12_));
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // if length(x) == 1, xk = x; else, xk = x(k); end
            //
            if (mclLengthInt(mwVa(x, "x")) == 1) {
                xk = mwVa(x, "x");
            } else {
                xk = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            }
            //
            // if length(a) == 1, ak = a; else, ak = a(k); end
            //
            if (mclLengthInt(mwVa(a, "a")) == 1) {
                ak = mwVa(a, "a");
            } else {
                ak = mclArrayRef(mwVa(a, "a"), mwVv(k, "k"));
            }
            //
            // if length(b) == 1, bk = b; else, bk = b(k); end
            //
            if (mclLengthInt(mwVa(b, "b")) == 1) {
                bk = mwVa(b, "b");
            } else {
                bk = mclArrayRef(mwVa(b, "b"), mwVv(k, "k"));
            }
            //
            // y(k) = bt(k) .* betacore(xk,ak,bk) ./ ak;
            //
            mclArrayAssign(
              &y,
              rdivide(
                times(
                  mclArrayRef(mwVv(bt, "bt"), mwVv(k, "k")),
                  betacore(mwVv(xk, "xk"), mwVv(ak, "ak"), mwVv(bk, "bk"))),
                mwVv(ak, "ak")),
              mwVv(k, "k"));
        //
        // end
        //
        }
        //
        // 
        // k = find(x >= (a+1) ./ (a+b+2));
        //
        k
          = find(
              mwVa(x, "x")
              >= rdivide(
                   mwVa(a, "a") + _mxarray9_,
                   mwVa(a, "a") + mwVa(b, "b") + _mxarray12_));
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // if length(x) == 1, xk = x; else, xk = x(k); end
            //
            if (mclLengthInt(mwVa(x, "x")) == 1) {
                xk = mwVa(x, "x");
            } else {
                xk = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            }
            //
            // if length(a) == 1, ak = a; else, ak = a(k); end
            //
            if (mclLengthInt(mwVa(a, "a")) == 1) {
                ak = mwVa(a, "a");
            } else {
                ak = mclArrayRef(mwVa(a, "a"), mwVv(k, "k"));
            }
            //
            // if length(b) == 1, bk = b; else, bk = b(k); end
            //
            if (mclLengthInt(mwVa(b, "b")) == 1) {
                bk = mwVa(b, "b");
            } else {
                bk = mclArrayRef(mwVa(b, "b"), mwVv(k, "k"));
            }
            //
            // y(k) = 1 - bt(k) .* betacore(1-xk,bk,ak) ./ bk;
            //
            mclArrayAssign(
              &y,
              _mxarray9_
              - rdivide(
                  times(
                    mclArrayRef(mwVv(bt, "bt"), mwVv(k, "k")),
                    betacore(
                      _mxarray9_ - mwVv(xk, "xk"),
                      mwVv(bk, "bk"),
                      mwVv(ak, "ak"))),
                  mwVv(bk, "bk")),
              mwVv(k, "k"));
        //
        // end
        //
        }
        //
        // 
        // k = find(isnan(y));
        //
        k = find(isnan(mwVv(y, "y")));
        //
        // if ~isempty(k)
        //
        if (mclNotBool(isempty(mwVv(k, "k")))) {
            //
            // % Continued fraction in betacore failed, use approximations.
            // if length(x) == 1, xk = x; else, xk = x(k); end
            //
            if (mclLengthInt(mwVa(x, "x")) == 1) {
                xk = mwVa(x, "x");
            } else {
                xk = mclArrayRef(mwVa(x, "x"), mwVv(k, "k"));
            }
            //
            // if length(a) == 1, ak = a; else, ak = a(k); end
            //
            if (mclLengthInt(mwVa(a, "a")) == 1) {
                ak = mwVa(a, "a");
            } else {
                ak = mclArrayRef(mwVa(a, "a"), mwVv(k, "k"));
            }
            //
            // if length(b) == 1, bk = b; else, bk = b(k); end
            //
            if (mclLengthInt(mwVa(b, "b")) == 1) {
                bk = mwVa(b, "b");
            } else {
                bk = mclArrayRef(mwVa(b, "b"), mwVv(k, "k"));
            }
            //
            // w1 = (bk*xk).^(1/3);
            //
            w1 = power(mwVv(bk, "bk") * mwVv(xk, "xk"), _mxarray13_);
            //
            // w2 = (ak*(1-xk)).^(1/3);
            //
            w2
              = power(
                  mwVv(ak, "ak") * (_mxarray9_ - mwVv(xk, "xk")), _mxarray13_);
            //
            // y(k) = 0.5*erfc(-3/sqrt(2)*((1-1/(9*bk))*w1-(1-1/(9*ak))*w2)./ ...
            //
            mclArrayAssign(
              &y,
              _mxarray14_
              * erfc(
                  rdivide(
                    _mxarray15_ / sqrt(_mxarray12_)
                    * ((_mxarray9_
                        - _mxarray9_ / (_mxarray16_ * mwVv(bk, "bk")))
                       * mwVv(w1, "w1")
                       - (_mxarray9_
                          - _mxarray9_ / (_mxarray16_ * mwVv(ak, "ak")))
                         * mwVv(w2, "w2")),
                    sqrt(
                      power(mwVv(w1, "w1"), _mxarray12_) / mwVv(bk, "bk")
                      + power(mwVv(w2, "w2"), _mxarray12_)
                        / mwVv(ak, "ak")))),
              mwVv(k, "k"));
            //
            // sqrt(w1.^2/bk+w2.^2/ak));
            // k = find((ak+bk-1).*(1-xk) < 0.8);
            //
            k
              = find(
                  times(
                    mwVv(ak, "ak") + mwVv(bk, "bk") - _mxarray9_,
                    _mxarray9_ - mwVv(xk, "xk"))
                  < _mxarray17_);
            //
            // if ~isempty(k)
            //
            if (mclNotBool(isempty(mwVv(k, "k")))) {
                //
                // if length(x) == 1, xk = x; else, xk = xk(k); end
                //
                if (mclLengthInt(mwVa(x, "x")) == 1) {
                    xk = mwVa(x, "x");
                } else {
                    xk = mclArrayRef(mwVv(xk, "xk"), mwVv(k, "k"));
                }
                //
                // if length(a) == 1, ak = a; else, ak = ak(k); end
                //
                if (mclLengthInt(mwVa(a, "a")) == 1) {
                    ak = mwVa(a, "a");
                } else {
                    ak = mclArrayRef(mwVv(ak, "ak"), mwVv(k, "k"));
                }
                //
                // if length(b) == 1, bk = b; else, bk = bk(k); end
                //
                if (mclLengthInt(mwVa(b, "b")) == 1) {
                    bk = mwVa(b, "b");
                } else {
                    bk = mclArrayRef(mwVv(bk, "bk"), mwVv(k, "k"));
                }
                //
                // s = 0.5*((ak+bk-1)*(3-xk)-(bk-1)).*(1-xk);
                //
                s
                  = times(
                      _mxarray14_
                      * ((mwVv(ak, "ak") + mwVv(bk, "bk") - _mxarray9_)
                         * (_mxarray18_ - mwVv(xk, "xk"))
                         - (mwVv(bk, "bk") - _mxarray9_)),
                      _mxarray9_ - mwVv(xk, "xk"));
                //
                // y(k) = 1-gammainc(s,bk);
                //
                mclArrayAssign(
                  &y,
                  _mxarray9_ - gammainc(mwVv(s, "s"), mwVv(bk, "bk")),
                  mwVv(k, "k"));
            //
            // end
            //
            }
        //
        // end
        //
        }
        //
        // 
        // k = find(x == 0);
        //
        k = find(mwVa(x, "x") == _mxarray8_);
        //
        // if length(k) > 0
        //
        if (mclLengthInt(mwVv(k, "k")) > 0) {
            //
            // if length(x) == 1, y(:) = 0; else, y(k) = 0; end
            //
            if (mclLengthInt(mwVa(x, "x")) == 1) {
                mclArrayAssign(&y, _mxarray8_, colon());
            } else {
                mclArrayAssign(&y, _mxarray8_, mwVv(k, "k"));
            }
        //
        // end
        //
        }
        //
        // 
        // k = find(x == 1);
        //
        k = find(mwVa(x, "x") == _mxarray9_);
        //
        // if length(k) > 0
        //
        if (mclLengthInt(mwVv(k, "k")) > 0) {
            //
            // if length(x) == 1, y(:) = 1; else, y(k) = 1; end
            //
            if (mclLengthInt(mwVa(x, "x")) == 1) {
                mclArrayAssign(&y, _mxarray9_, colon());
            } else {
                mclArrayAssign(&y, _mxarray9_, mwVv(k, "k"));
            }
        //
        // end
        //
        }
    //
    // end
    //
    }
    mwValidateOutput(y, 1, nargout_, "y", "betainc");
    return y;
}

//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "betacore.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.0);
static mwArray _mxarray1_ = mclInitializeDouble(2.0);
static mwArray _mxarray2_ = mclInitializeDouble(2.220446049250313e-13);
static mwArray _mxarray3_ = mclInitializeDouble(1000.0);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray4_ = mclInitializeDouble(_ieee_nan_);

void InitializeModule_betacore() {
}

void TerminateModule_betacore() {
}

static mwArray Mbetacore(int nargout_, mwArray x, mwArray a, mwArray b);

_mexLocalFunctionTable _local_function_table_betacore
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "betacore" contains the normal interface for the "betacore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betacore.m" (lines
// 1-51). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray betacore(mwArray x, mwArray a, mwArray b) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mbetacore(nargout, x, a, b);
    return y;
}

//
// The function "mlxBetacore" contains the feval interface for the "betacore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betacore.m" (lines
// 1-51). The feval function calls the implementation version of betacore
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxBetacore(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: betacore Line: 1 Column: "
                  "1 The function \"betacore\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: betacore Line: 1 Column: "
                  "1 The function \"betacore\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mbetacore(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mbetacore" is the implementation version of the "betacore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\betacore.m" (lines
// 1-51). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = betacore(x, a, b)
//
static mwArray Mbetacore(int nargout_, mwArray x, mwArray a, mwArray b) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_betacore;
    mwArray y = mwArray::UNDEFINED;
    mwArray tem = mwArray::UNDEFINED;
    mwArray k = mwArray::UNDEFINED;
    mwArray m = mwArray::UNDEFINED;
    mwArray yold = mwArray::UNDEFINED;
    mwArray bp = mwArray::UNDEFINED;
    mwArray bpp = mwArray::UNDEFINED;
    mwArray ap = mwArray::UNDEFINED;
    mwArray app = mwArray::UNDEFINED;
    mwArray d = mwArray::UNDEFINED;
    mwArray bz = mwArray::UNDEFINED;
    mwArray bm = mwArray::UNDEFINED;
    mwArray am = mwArray::UNDEFINED;
    mwArray qam = mwArray::UNDEFINED;
    mwArray qap = mwArray::UNDEFINED;
    mwArray qab = mwArray::UNDEFINED;
    //
    // %BETACORE Core algorithm for the incomplete beta function.
    // %   BETACORE(x,a,b) is used twice by BETAINC(X,A,B).
    // %   Returns NaN if continued fraction does not converge.
    // %
    // %   See also BETAINC.
    // 
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.10 $  $Date: 2002/04/09 00:29:45 $
    // 
    // qab = a + b;
    //
    qab = mwVa(a, "a") + mwVa(b, "b");
    //
    // qap = a + 1;
    //
    qap = mwVa(a, "a") + _mxarray0_;
    //
    // qam = a - 1;
    //
    qam = mwVa(a, "a") - _mxarray0_;
    //
    // am = ones(size(x));
    //
    am = ones(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // bm = am;
    //
    bm = mwVv(am, "am");
    //
    // y = am;
    //
    y = mwVv(am, "am");
    //
    // bz = 1 - qab .* x ./ qap;
    //
    bz
      = _mxarray0_
        - rdivide(times(mwVv(qab, "qab"), mwVa(x, "x")), mwVv(qap, "qap"));
    //
    // d = zeros(size(x));
    //
    d = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
    //
    // app = d;
    //
    app = mwVv(d, "d");
    //
    // ap = d;
    //
    ap = mwVv(d, "d");
    //
    // bpp = d;
    //
    bpp = mwVv(d, "d");
    //
    // bp = d;
    //
    bp = mwVv(d, "d");
    //
    // yold = d;
    //
    yold = mwVv(d, "d");
    //
    // m = 1;
    //
    m = _mxarray0_;
    //
    // k = 1;
    //
    k = _mxarray0_;
    //
    // while 1
    //
    for (;;) {
        //
        // tem = 2 * m;
        //
        tem = _mxarray1_ * mwVv(m, "m");
        //
        // d = m * (b - m) .* x ./ ((qam + tem) .* (a + tem));
        //
        d
          = rdivide(
              times(
                mwVv(m, "m") * (mwVa(b, "b") - mwVv(m, "m")), mwVa(x, "x")),
              times(
                mwVv(qam, "qam") + mwVv(tem, "tem"),
                mwVa(a, "a") + mwVv(tem, "tem")));
        //
        // ap = y + d .* am;
        //
        ap = mwVv(y, "y") + times(mwVv(d, "d"), mwVv(am, "am"));
        //
        // bp = bz + d .* bm;
        //
        bp = mwVv(bz, "bz") + times(mwVv(d, "d"), mwVv(bm, "bm"));
        //
        // d = -(a + m) .* (qab + m) .* x ./ ((a + tem) .* (qap + tem));
        //
        d
          = rdivide(
              times(
                times(
                  - (mwVa(a, "a") + mwVv(m, "m")),
                  mwVv(qab, "qab") + mwVv(m, "m")),
                mwVa(x, "x")),
              times(
                mwVa(a, "a") + mwVv(tem, "tem"),
                mwVv(qap, "qap") + mwVv(tem, "tem")));
        //
        // app = ap + d .* y;
        //
        app = mwVv(ap, "ap") + times(mwVv(d, "d"), mwVv(y, "y"));
        //
        // bpp = bp + d .* bz;
        //
        bpp = mwVv(bp, "bp") + times(mwVv(d, "d"), mwVv(bz, "bz"));
        //
        // yold = y;
        //
        yold = mwVv(y, "y");
        //
        // am = ap ./ bpp;
        //
        am = rdivide(mwVv(ap, "ap"), mwVv(bpp, "bpp"));
        //
        // bm = bp ./ bpp;
        //
        bm = rdivide(mwVv(bp, "bp"), mwVv(bpp, "bpp"));
        //
        // y = app ./ bpp;
        //
        y = rdivide(mwVv(app, "app"), mwVv(bpp, "bpp"));
        //
        // if m == 1
        //
        if (mclEqBool(mwVv(m, "m"), _mxarray0_)) {
            //
            // bz = 1;
            //
            bz = _mxarray0_;
        //
        // end
        //
        }
        //
        // k = find(abs(y(:)-yold(:)) > 1000*eps*abs(y(:)));
        //
        k
          = find(
              abs(
                mclArrayRef(mwVv(y, "y"), colon())
                - mclArrayRef(mwVv(yold, "yold"), colon()))
              > _mxarray2_ * abs(mclArrayRef(mwVv(y, "y"), colon())));
        //
        // if isempty(k)
        //
        if (tobool(isempty(mwVv(k, "k")))) {
            //
            // break
            //
            break;
        //
        // end
        //
        }
        //
        // m = m + 1;
        //
        m = mwVv(m, "m") + _mxarray0_;
        //
        // if m > 1000
        //
        if (mclGtBool(mwVv(m, "m"), _mxarray3_)) {
            //
            // y(k) = NaN;
            //
            mclArrayAssign(&y, _mxarray4_, mwVv(k, "k"));
            //
            // return
            //
            goto return_;
        //
        // end
        //
        }
    //
    // end
    //
    }
    return_:
    mwValidateOutput(y, 1, nargout_, "y", "betacore");
    return y;
}

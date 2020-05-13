//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "normfit.hpp"
#include "chi2inv.hpp"
#include "libmatlbm.hpp"
#include "mean.hpp"
#include "std.hpp"
#include "tinv.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(.05);
static mwArray _mxarray1_ = mclInitializeDouble(1.0);
static mwArray _mxarray2_ = mclInitializeDouble(2.0);

void InitializeModule_normfit() {
}

void TerminateModule_normfit() {
}

static mwArray Mnormfit(mwArray * sigmahat,
                        mwArray * muci,
                        mwArray * sigmaci,
                        int nargout_,
                        mwArray x,
                        mwArray alpha);

_mexLocalFunctionTable _local_function_table_normfit
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "Nnormfit" contains the nargout interface for the "normfit"
// M-function from file "c:\matlab6p5\toolbox\stats\normfit.m" (lines 1-45).
// This interface is only produced if the M-function uses the special variable
// "nargout". The nargout interface allows the number of requested outputs to
// be specified via the nargout argument, as opposed to the normal interface
// which dynamically calculates the number of outputs based on the number of
// non-NULL inputs it receives. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
mwArray Nnormfit(int nargout,
                 mwArray * sigmahat,
                 mwArray * muci,
                 mwArray * sigmaci,
                 mwArray x,
                 mwArray alpha) {
    mwArray muhat = mwArray::UNDEFINED;
    mwArray sigmahat__ = mwArray::UNDEFINED;
    mwArray muci__ = mwArray::UNDEFINED;
    mwArray sigmaci__ = mwArray::UNDEFINED;
    muhat = Mnormfit(&sigmahat__, &muci__, &sigmaci__, nargout, x, alpha);
    if (sigmahat != NULL) {
        *sigmahat = sigmahat__;
    }
    if (muci != NULL) {
        *muci = muci__;
    }
    if (sigmaci != NULL) {
        *sigmaci = sigmaci__;
    }
    return muhat;
}

//
// The function "normfit" contains the normal interface for the "normfit"
// M-function from file "c:\matlab6p5\toolbox\stats\normfit.m" (lines 1-45).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray normfit(mwArray * sigmahat,
                mwArray * muci,
                mwArray * sigmaci,
                mwArray x,
                mwArray alpha) {
    int nargout = 1;
    mwArray muhat = mwArray::UNDEFINED;
    mwArray sigmahat__ = mwArray::UNDEFINED;
    mwArray muci__ = mwArray::UNDEFINED;
    mwArray sigmaci__ = mwArray::UNDEFINED;
    if (sigmahat != NULL) {
        ++nargout;
    }
    if (muci != NULL) {
        ++nargout;
    }
    if (sigmaci != NULL) {
        ++nargout;
    }
    muhat = Mnormfit(&sigmahat__, &muci__, &sigmaci__, nargout, x, alpha);
    if (sigmahat != NULL) {
        *sigmahat = sigmahat__;
    }
    if (muci != NULL) {
        *muci = muci__;
    }
    if (sigmaci != NULL) {
        *sigmaci = sigmaci__;
    }
    return muhat;
}

//
// The function "Vnormfit" contains the void interface for the "normfit"
// M-function from file "c:\matlab6p5\toolbox\stats\normfit.m" (lines 1-45).
// The void interface is only produced if the M-function uses the special
// variable "nargout", and has at least one output. The void interface function
// specifies zero output arguments to the implementation version of the
// function, and in the event that the implementation version still returns an
// output (which, in MATLAB, would be assigned to the "ans" variable), it
// deallocates the output. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void Vnormfit(mwArray x, mwArray alpha) {
    mwArray muhat = mwArray::UNDEFINED;
    mwArray sigmahat = mwArray::UNDEFINED;
    mwArray muci = mwArray::UNDEFINED;
    mwArray sigmaci = mwArray::UNDEFINED;
    muhat = Mnormfit(&sigmahat, &muci, &sigmaci, 0, x, alpha);
}

//
// The function "mlxNormfit" contains the feval interface for the "normfit"
// M-function from file "c:\matlab6p5\toolbox\stats\normfit.m" (lines 1-45).
// The feval function calls the implementation version of normfit through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxNormfit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[2];
        mwArray mplhs[4];
        int i;
        mclCppUndefineArrays(4, mplhs);
        if (nlhs > 4) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: normfit Line: 1 Column: "
                  "1 The function \"normfit\" was called with mor"
                  "e than the declared number of outputs (4).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: normfit Line: 1 Column: "
                  "1 The function \"normfit\" was called with mor"
                  "e than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0]
          = Mnormfit(
              &mplhs[1], &mplhs[2], &mplhs[3], nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
        for (i = 1; i < 4 && i < nlhs; ++i) {
            plhs[i] = mplhs[i].FreezeData();
        }
    }
    MW_END_MLX();
}

//
// The function "Mnormfit" is the implementation version of the "normfit"
// M-function from file "c:\matlab6p5\toolbox\stats\normfit.m" (lines 1-45). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function [muhat, sigmahat, muci, sigmaci] = normfit(x,alpha)
//
static mwArray Mnormfit(mwArray * sigmahat,
                        mwArray * muci,
                        mwArray * sigmaci,
                        int nargout_,
                        mwArray x,
                        mwArray alpha) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_normfit;
    int nargin_ = nargin(2, mwVarargin(x, alpha));
    mwArray muhat = mwArray::UNDEFINED;
    mwArray chi2crit = mwArray::UNDEFINED;
    mwArray tcrit = mwArray::UNDEFINED;
    mwArray n = mwArray::UNDEFINED;
    mwArray m = mwArray::UNDEFINED;
    //
    // %NORMFIT Parameter estimates and confidence intervals for normal data.
    // %   NORMFIT(X,ALPHA) Returns estimates of the parameters of the 
    // %   normal distribution given the data in X. 
    // %
    // %   [MUHAT,SIGMAHAT,MUCI,SIGMACI] = NORMFIT(X,ALPHA) gives the minimum
    // %   variance unbiased estimates of the parameters of the normal distribution 
    // %   and 100(1-ALPHA) percent confidence intervals given the data.
    // %   By default the optional parameter ALPHA = 0.05 corresponding
    // %   to 95% confidence intervals. 
    // %
    // %   See also NORMCDF, NORMINV, NORMPDF, NORMPLOT, NORMRND, NORMSTAT, MLE. 
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // % $Revision: 2.12 $  $Date: 2002/01/17 21:31:31 $
    // 
    // if nargin < 2 
    //
    if (nargin_ < 2) {
        //
        // alpha = 0.05;
        //
        alpha = _mxarray0_;
    //
    // end
    //
    }
    //
    // 
    // [m, n] = size(x);
    //
    size(mwVarargout(m, n), mwVa(x, "x"));
    //
    // if min(m,n) == 1
    //
    if (mclEqBool(min(mwVv(m, "m"), mwVv(n, "n")), _mxarray1_)) {
        //
        // x = x(:);
        //
        x = mclArrayRef(mwVa(x, "x"), colon());
        //
        // m = max(m,n);
        //
        m = max(mwVv(m, "m"), mwVv(n, "n"));
        //
        // n = 1;
        //
        n = _mxarray1_;
    //
    // end
    //
    }
    //
    // 
    // muhat = mean(x);
    //
    muhat = mean(mwVa(x, "x"));
    //
    // sigmahat = std(x);
    //
    *sigmahat = std(mwVa(x, "x"));
    //
    // 
    // if nargout > 2,
    //
    if (nargout_ > 2) {
        //
        // muci = zeros(2,n);
        //
        *muci = zeros(mwVarargin(_mxarray2_, mwVv(n, "n")));
        //
        // sigmaci = zeros(2,n);
        //
        *sigmaci = zeros(mwVarargin(_mxarray2_, mwVv(n, "n")));
        //
        // 
        // tcrit = tinv([alpha/2 1-alpha/2],m-1);
        //
        tcrit
          = tinv(
              horzcat(
                mwVarargin(
                  mwVa(alpha, "alpha") / _mxarray2_,
                  _mxarray1_ - mwVa(alpha, "alpha") / _mxarray2_)),
              mwVv(m, "m") - _mxarray1_);
        //
        // muci = [(muhat + tcrit(1)*sigmahat/sqrt(m));...
        //
        *muci
          = vertcat(
              mwVarargin(
                mwVv(muhat, "muhat")
                + mclIntArrayRef(mwVv(tcrit, "tcrit"), 1)
                  * mwVv(*sigmahat, "sigmahat")
                  / sqrt(mwVv(m, "m")),
                mwVv(muhat, "muhat")
                + mclIntArrayRef(mwVv(tcrit, "tcrit"), 2)
                  * mwVv(*sigmahat, "sigmahat")
                  / sqrt(mwVv(m, "m"))));
        //
        // (muhat + tcrit(2)*sigmahat/sqrt(m))];
        // 
        // chi2crit = chi2inv([alpha/2 1-alpha/2],m-1);
        //
        chi2crit
          = chi2inv(
              horzcat(
                mwVarargin(
                  mwVa(alpha, "alpha") / _mxarray2_,
                  _mxarray1_ - mwVa(alpha, "alpha") / _mxarray2_)),
              mwVv(m, "m") - _mxarray1_);
        //
        // sigmaci =  [(sigmahat*sqrt((m-1)./chi2crit(2)));
        //
        *sigmaci
          = vertcat(
              mwVarargin(
                mwVv(*sigmahat, "sigmahat")
                * sqrt(
                    rdivide(
                      mwVv(m, "m") - _mxarray1_,
                      mclIntArrayRef(mwVv(chi2crit, "chi2crit"), 2))),
                mwVv(*sigmahat, "sigmahat")
                * sqrt(
                    rdivide(
                      mwVv(m, "m") - _mxarray1_,
                      mclIntArrayRef(mwVv(chi2crit, "chi2crit"), 1)))));
    //
    // (sigmahat*sqrt((m-1)./chi2crit(1)))];
    // 
    // end
    //
    }
    mwValidateOutput(muhat, 1, nargout_, "muhat", "normfit");
    mwValidateOutput(*sigmahat, 2, nargout_, "sigmahat", "normfit");
    mwValidateOutput(*muci, 3, nargout_, "muci", "normfit");
    mwValidateOutput(*sigmaci, 4, nargout_, "sigmaci", "normfit");
    return muhat;
    //
    // 
    //
}

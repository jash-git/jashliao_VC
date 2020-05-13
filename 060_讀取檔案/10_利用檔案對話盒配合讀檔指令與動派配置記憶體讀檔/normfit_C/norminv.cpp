//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "norminv.hpp"
#include "distchck.hpp"
#include "erfcinv.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(0.0);
static mwArray _mxarray1_ = mclInitializeDouble(1.0);
static mwArray _mxarray2_ = mclInitializeDouble(3.0);

static mxChar _array4_[47] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'n',
                               'o', 'n', '-', 's', 'c', 'a', 'l', 'a', 'r', ' ',
                               'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', ' ',
                               't', 'o', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'i',
                               'n', ' ', 's', 'i', 'z', 'e', '.' };
static mwArray _mxarray3_ = mclInitializeString(47, _array4_);
static mwArray _mxarray5_ = mclInitializeDouble(2.0);

void InitializeModule_norminv() {
}

void TerminateModule_norminv() {
}

static mwArray Mnorminv(int nargout_, mwArray p, mwArray mu, mwArray sigma);

_mexLocalFunctionTable _local_function_table_norminv
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "norminv" contains the normal interface for the "norminv"
// M-function from file "c:\matlab6p5\toolbox\stats\norminv.m" (lines 1-34).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray norminv(mwArray p, mwArray mu, mwArray sigma) {
    int nargout = 1;
    mwArray z = mwArray::UNDEFINED;
    z = Mnorminv(nargout, p, mu, sigma);
    return z;
}

//
// The function "mlxNorminv" contains the feval interface for the "norminv"
// M-function from file "c:\matlab6p5\toolbox\stats\norminv.m" (lines 1-34).
// The feval function calls the implementation version of norminv through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxNorminv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: norminv Line: 1 Column: "
                  "1 The function \"norminv\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: norminv Line: 1 Column: "
                  "1 The function \"norminv\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mnorminv(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mnorminv" is the implementation version of the "norminv"
// M-function from file "c:\matlab6p5\toolbox\stats\norminv.m" (lines 1-34). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function z = norminv(p,mu,sigma)
//
static mwArray Mnorminv(int nargout_, mwArray p, mwArray mu, mwArray sigma) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_norminv;
    int nargin_ = nargin(3, mwVarargin(p, mu, sigma));
    mwArray z = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    mwArray errorcode = mwArray::UNDEFINED;
    //
    // %NORMINV Inverse of the normal cumulative distribution function (cdf).
    // %   X = NORMINV(P,MU,SIGMA) finds the inverse of the normal cdf with
    // %   mean, MU, and standard deviation, SIGMA.
    // %
    // %   The size of X is the common size of the input arguments. A scalar input  
    // %   functions as a constant matrix of the same size as the other inputs.    
    // %
    // %   Default values for MU and SIGMA are 0 and 1 respectively.
    // %
    // %   See also NORMCDF, ERF, ERFC, ERFINV, ERFCINV.
    // 
    // %   References:
    // %      [1]  M. Abramowitz and I. A. Stegun, "Handbook of Mathematical
    // %      Functions", Government Printing Office, 1964, 7.1.1 and 26.2.2
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.12 $  $Date: 2002/01/17 21:31:31 $
    // 
    // if nargin < 2, mu = 0; end
    //
    if (nargin_ < 2) {
        mu = _mxarray0_;
    }
    //
    // if nargin < 3, sigma = 1; end
    //
    if (nargin_ < 3) {
        sigma = _mxarray1_;
    }
    //
    // 
    // [errorcode p mu sigma] = distchck(3,p,mu,sigma);
    //
    errorcode
    = distchck(
        mwVarargout(p, mu, sigma),
        _mxarray2_,
        mwVarargin(mwVa(p, "p"), mwVa(mu, "mu"), mwVa(sigma, "sigma")));
    //
    // if errorcode > 0
    //
    if (mclGtBool(mwVv(errorcode, "errorcode"), _mxarray0_)) {
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
    // % It is numerically preferable to use the complementary error function
    // % and norminv(p) = -sqrt(2)*erfcinv(2*p) to produce accurate results
    // % for p near zero.
    // 
    // z = (-sqrt(2)*sigma).*erfcinv(2*p) + mu;
    //
    z
      = times(
          - sqrt(_mxarray5_) * mwVa(sigma, "sigma"),
          erfcinv(_mxarray5_ * mwVa(p, "p")))
        + mwVa(mu, "mu");
    mwValidateOutput(z, 1, nargout_, "z", "norminv");
    return z;
    //
    // 
    //
}

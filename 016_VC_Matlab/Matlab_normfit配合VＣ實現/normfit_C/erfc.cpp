//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "erfc.hpp"
#include "erfcore_mex_interface.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[15] = { 'X', ' ', 'm', 'u', 's', 't', ' ', 'b',
                               'e', ' ', 'r', 'e', 'a', 'l', '.' };
static mwArray _mxarray0_ = mclInitializeString(15, _array1_);
static mwArray _mxarray2_ = mclInitializeDouble(1.0);

void InitializeModule_erfc() {
}

void TerminateModule_erfc() {
}

static mwArray Merfc(int nargout_, mwArray x);

_mexLocalFunctionTable _local_function_table_erfc
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "erfc" contains the normal interface for the "erfc" M-function
// from file "c:\matlab6p5\toolbox\matlab\specfun\erfc.m" (lines 1-22). This
// function processes any input arguments and passes them to the implementation
// version of the function, appearing above.
//
mwArray erfc(mwArray x) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Merfc(nargout, x);
    return y;
}

//
// The function "mlxErfc" contains the feval interface for the "erfc"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfc.m" (lines
// 1-22). The feval function calls the implementation version of erfc through
// this function. This function processes any input arguments and passes them
// to the implementation version of the function, appearing above.
//
void mlxErfc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: erfc Line: 1 Column: 1"
                  " The function \"erfc\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: erfc Line: 1 Column: 1"
                  " The function \"erfc\" was called with more "
                  "than the declared number of inputs (1).")));
        }
        for (i = 0; i < 1 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 1; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Merfc(nlhs, mprhs[0]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Merfc" is the implementation version of the "erfc" M-function
// from file "c:\matlab6p5\toolbox\matlab\specfun\erfc.m" (lines 1-22). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = erfc(x)
//
static mwArray Merfc(int nargout_, mwArray x) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_erfc;
    mwArray y = mwArray::UNDEFINED;
    mwArray siz = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %ERFC  Complementary error function.
    // %   Y = ERFC(X) is the complementary error function for each element
    // %   of X.  X must be real.  The complementary error function is
    // %   defined as:
    // %
    // %     erfc(x) = 2/sqrt(pi) * integral from x to inf of exp(-t^2) dt.
    // %             = 1 - erf(x).
    // %
    // %   See also ERF, ERFCX, ERFINV.
    // 
    // %   Ref: Abramowitz & Stegun, Handbook of Mathematical Functions, sec. 7.1.
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.12 $  $Date: 2002/04/09 00:29:47 $
    // 
    // % Derived from a FORTRAN program by W. J. Cody.
    // 
    // if ~isreal(x), error('X must be real.'); end
    //
    if (mclNotBool(isreal(mwVa(x, "x")))) {
        error(mwVarargin(_mxarray0_));
    }
    //
    // siz = size(x);
    //
    siz = size(mwValueVarargout(), mwVa(x, "x"));
    //
    // x = x(:);
    //
    x = mclArrayRef(mwVa(x, "x"), colon());
    //
    // y = reshape(erfcore(x,1), siz);
    //
    y
      = reshape(
          Nerfcore(
            0, mwValueVarargout(), mwVarargin(mwVa(x, "x"), _mxarray2_)),
          mwVarargin(mwVv(siz, "siz")));
    mwValidateOutput(y, 1, nargout_, "y", "erfc");
    return y;
}

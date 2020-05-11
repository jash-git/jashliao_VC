//
// MATLAB Compiler: 3.0
// Date: Fri Oct 29 14:44:58 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "Cpp" "-h"
// "addmatrix" 
//
#include "addmatrix.hpp"
#include "libmatlbm.hpp"

void InitializeModule_addmatrix() {
}

void TerminateModule_addmatrix() {
}

static mwArray Maddmatrix(mwArray * prod, int nargout_, mwArray x, mwArray y);

_mexLocalFunctionTable _local_function_table_addmatrix
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "addmatrix" contains the normal interface for the "addmatrix"
// M-function from file "c:\matlab6p5\work\addmatrix.m" (lines 1-3). This
// function processes any input arguments and passes them to the implementation
// version of the function, appearing above.
//
mwArray addmatrix(mwArray * prod, mwArray x, mwArray y) {
    int nargout = 1;
    mwArray sum = mwArray::UNDEFINED;
    mwArray prod__ = mwArray::UNDEFINED;
    if (prod != NULL) {
        ++nargout;
    }
    sum = Maddmatrix(&prod__, nargout, x, y);
    if (prod != NULL) {
        *prod = prod__;
    }
    return sum;
}

//
// The function "mlxAddmatrix" contains the feval interface for the "addmatrix"
// M-function from file "c:\matlab6p5\work\addmatrix.m" (lines 1-3). The feval
// function calls the implementation version of addmatrix through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxAddmatrix(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[2];
        mwArray mplhs[2];
        int i;
        mclCppUndefineArrays(2, mplhs);
        if (nlhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: addmatrix Line: 1 Column: "
                  "1 The function \"addmatrix\" was called with mor"
                  "e than the declared number of outputs (2).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: addmatrix Line: 1 Column:"
                  " 1 The function \"addmatrix\" was called with m"
                  "ore than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Maddmatrix(&mplhs[1], nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
        for (i = 1; i < 2 && i < nlhs; ++i) {
            plhs[i] = mplhs[i].FreezeData();
        }
    }
    MW_END_MLX();
}

//
// The function "Maddmatrix" is the implementation version of the "addmatrix"
// M-function from file "c:\matlab6p5\work\addmatrix.m" (lines 1-3). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function [sum,prod]=addmatrix(x,y)
//
static mwArray Maddmatrix(mwArray * prod, int nargout_, mwArray x, mwArray y) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_addmatrix;
    mwArray sum = mwArray::UNDEFINED;
    //
    // sum=x+y;
    //
    sum = mwVa(x, "x") + mwVa(y, "y");
    //
    // prod=x*y;
    //
    *prod = mwVa(x, "x") * mwVa(y, "y");
    mwValidateOutput(sum, 1, nargout_, "sum", "addmatrix");
    mwValidateOutput(*prod, 2, nargout_, "prod", "addmatrix");
    return sum;
}

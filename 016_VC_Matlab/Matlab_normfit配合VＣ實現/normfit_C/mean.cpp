//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "mean.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.0);

void InitializeModule_mean() {
}

void TerminateModule_mean() {
}

static mwArray Mmean(int nargout_, mwArray x, mwArray dim);

_mexLocalFunctionTable _local_function_table_mean
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "mean" contains the normal interface for the "mean" M-function
// from file "c:\matlab6p5\toolbox\matlab\datafun\mean.m" (lines 1-30). This
// function processes any input arguments and passes them to the implementation
// version of the function, appearing above.
//
mwArray mean(mwArray x, mwArray dim) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mmean(nargout, x, dim);
    return y;
}

//
// The function "mlxMean" contains the feval interface for the "mean"
// M-function from file "c:\matlab6p5\toolbox\matlab\datafun\mean.m" (lines
// 1-30). The feval function calls the implementation version of mean through
// this function. This function processes any input arguments and passes them
// to the implementation version of the function, appearing above.
//
void mlxMean(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: mean Line: 1 Column: 1"
                  " The function \"mean\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 2) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: mean Line: 1 Column: 1"
                  " The function \"mean\" was called with more "
                  "than the declared number of inputs (2).")));
        }
        for (i = 0; i < 2 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 2; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mmean(nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mmean" is the implementation version of the "mean" M-function
// from file "c:\matlab6p5\toolbox\matlab\datafun\mean.m" (lines 1-30). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = mean(x,dim)
//
static mwArray Mmean(int nargout_, mwArray x, mwArray dim) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_mean;
    int nargin_ = nargin(2, mwVarargin(x, dim));
    mwArray y = mwArray::UNDEFINED;
    //
    // %MEAN   Average or mean value.
    // %   For vectors, MEAN(X) is the mean value of the elements in X. For
    // %   matrices, MEAN(X) is a row vector containing the mean value of
    // %   each column.  For N-D arrays, MEAN(X) is the mean value of the
    // %   elements along the first non-singleton dimension of X.
    // %
    // %   MEAN(X,DIM) takes the mean along the dimension DIM of X. 
    // %
    // %   Example: If X = [0 1 2
    // %                    3 4 5]
    // %
    // %   then mean(X,1) is [1.5 2.5 3.5] and mean(X,2) is [1
    // %                                                     4]
    // %
    // %   See also MEDIAN, STD, MIN, MAX, COV.
    // 
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.17 $  $Date: 2002/06/05 17:06:39 $
    // 
    // if nargin==1, 
    //
    if (nargin_ == 1) {
        //
        // % Determine which dimension SUM will use
        // dim = min(find(size(x)~=1));
        //
        dim = min(find(size(mwValueVarargout(), mwVa(x, "x")) != _mxarray0_));
        //
        // if isempty(dim), dim = 1; end
        //
        if (tobool(isempty(mwVa(dim, "dim")))) {
            dim = _mxarray0_;
        }
        //
        // 
        // y = sum(x)/size(x,dim);
        //
        y
          = sum(mwVa(x, "x"))
            / size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim"));
    //
    // else
    //
    } else {
        //
        // y = sum(x,dim)/size(x,dim);
        //
        y
          = sum(mwVa(x, "x"), mwVa(dim, "dim"))
            / size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim"));
    //
    // end
    //
    }
    mwValidateOutput(y, 1, nargout_, "y", "mean");
    return y;
}

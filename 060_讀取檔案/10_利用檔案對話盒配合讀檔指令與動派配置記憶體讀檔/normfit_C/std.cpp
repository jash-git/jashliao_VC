//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "std.hpp"
#include "libmatlbm.hpp"
#include "repmat.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(0.0);
static mwArray _mxarray1_ = mclInitializeDouble(1.0);
static double _ieee_nan_ = mclGetNaN();
static mwArray _mxarray2_ = mclInitializeDouble(_ieee_nan_);

void InitializeModule_std() {
}

void TerminateModule_std() {
}

static mwArray Mstd(int nargout_, mwArray x, mwArray flag, mwArray dim);

_mexLocalFunctionTable _local_function_table_std
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "std" contains the normal interface for the "std" M-function
// from file "c:\matlab6p5\toolbox\matlab\datafun\std.m" (lines 1-51). This
// function processes any input arguments and passes them to the implementation
// version of the function, appearing above.
//
mwArray std(mwArray x, mwArray flag, mwArray dim) {
    int nargout = 1;
    mwArray y = mwArray::UNDEFINED;
    y = Mstd(nargout, x, flag, dim);
    return y;
}

//
// The function "mlxStd" contains the feval interface for the "std" M-function
// from file "c:\matlab6p5\toolbox\matlab\datafun\std.m" (lines 1-51). The
// feval function calls the implementation version of std through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxStd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: std Line: 1 Column: 1 "
                  "The function \"std\" was called with more th"
                  "an the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: std Line: 1 Column: 1"
                  " The function \"std\" was called with more "
                  "than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mstd(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mstd" is the implementation version of the "std" M-function
// from file "c:\matlab6p5\toolbox\matlab\datafun\std.m" (lines 1-51). It
// contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function y = std(x,flag,dim)
//
static mwArray Mstd(int nargout_, mwArray x, mwArray flag, mwArray dim) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_std;
    int nargin_ = nargin(3, mwVarargin(x, flag, dim));
    mwArray y = mwArray::UNDEFINED;
    mwArray xc = mwArray::UNDEFINED;
    mwArray tile = mwArray::UNDEFINED;
    //
    // %STD    Standard deviation.
    // %   For vectors, STD(X) returns the standard deviation. For matrices,
    // %   STD(X) is a row vector containing the standard deviation of each
    // %   column.  For N-D arrays, STD(X) is the standard deviation of the
    // %   elements along the first non-singleton dimension of X.
    // %
    // %   STD(X) normalizes by (N-1) where N is the sequence length.  This
    // %   makes STD(X).^2 the best unbiased estimate of the variance if X
    // %   is a sample from a normal distribution.
    // %
    // %   STD(X,1) normalizes by N and produces the square root of the
    // %   second moment of the sample about its mean.  STD(X,0) is the
    // %   same as STD(X).
    // %
    // %   STD(X,FLAG,DIM) takes the standard deviation along the dimension
    // %   DIM of X.  When FLAG=0 STD normalizes by (N-1), otherwise STD
    // %   normalizes by N.
    // %
    // %   Example: If X = [4 -2 1
    // %                    9  5 7]
    // %     then std(X,0,1) is [ 3.5355 4.9497 4.2426] and std(X,0,2) is [3.0
    // %                                                                   2.0]
    // %   See also COV, MEAN, VAR, MEDIAN, CORRCOEF.
    // 
    // %   J.N. Little 4-21-85
    // %   Revised 5-9-88 JNL, 3-11-94 BAJ, 5-26-95 dlc, 5-29-96 CMT.
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.25 $  $Date: 2002/06/05 17:06:38 $
    // 
    // if nargin<2, flag = 0; end
    //
    if (nargin_ < 2) {
        flag = _mxarray0_;
    }
    //
    // if nargin<3,
    //
    if (nargin_ < 3) {
        //
        // if isempty(x), y = 0/0; return; end % Empty case without dim argument
        //
        if (tobool(isempty(mwVa(x, "x")))) {
            y = _mxarray0_ / _mxarray0_;
            goto return_;
        }
        //
        // dim = min(find(size(x)~=1));
        //
        dim = min(find(size(mwValueVarargout(), mwVa(x, "x")) != _mxarray1_));
        //
        // if isempty(dim), dim = 1; end
        //
        if (tobool(isempty(mwVa(dim, "dim")))) {
            dim = _mxarray1_;
        }
    //
    // end
    //
    }
    //
    // 
    // % Avoid divide by zero for scalar case
    // if size(x,dim)==1, y = zeros(size(x)); y(isnan(x))=NaN; return, end
    //
    if (mclEqBool(
          size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim")),
          _mxarray1_)) {
        y = zeros(mwVarargin(size(mwValueVarargout(), mwVa(x, "x"))));
        mclArrayAssign(&y, _mxarray2_, isnan(mwVa(x, "x")));
        goto return_;
    }
    //
    // 
    // tile = ones(1,max(ndims(x),dim));
    //
    tile
      = ones(
          mwVarargin(_mxarray1_, max(ndims(mwVa(x, "x")), mwVa(dim, "dim"))));
    //
    // tile(dim) = size(x,dim);
    //
    mclArrayAssign(
      &tile,
      size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim")),
      mwVa(dim, "dim"));
    //
    // 
    // xc = x - repmat(sum(x,dim)/size(x,dim),tile);  % Remove mean
    //
    xc
      = mwVa(x, "x")
        - repmat(
            sum(mwVa(x, "x"), mwVa(dim, "dim"))
            / size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim")),
            mwVv(tile, "tile"));
    //
    // if flag,
    //
    if (tobool(mwVa(flag, "flag"))) {
        //
        // y = sqrt(sum(conj(xc).*xc,dim)/size(x,dim));
        //
        y
          = sqrt(
              sum(
                times(conj(mwVv(xc, "xc")), mwVv(xc, "xc")), mwVa(dim, "dim"))
              / size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim")));
    //
    // else
    //
    } else {
        //
        // y = sqrt(sum(conj(xc).*xc,dim)/(size(x,dim)-1));
        //
        y
          = sqrt(
              sum(
                times(conj(mwVv(xc, "xc")), mwVv(xc, "xc")), mwVa(dim, "dim"))
              / (size(mwValueVarargout(), mwVa(x, "x"), mwVa(dim, "dim"))
                 - _mxarray1_));
    //
    // end
    //
    }
    //
    // 
    //
    return_:
    mwValidateOutput(y, 1, nargout_, "y", "std");
    return y;
}

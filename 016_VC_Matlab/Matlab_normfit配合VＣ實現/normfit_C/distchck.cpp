//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "distchck.hpp"
#include "cellfun_mex_interface.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(0.0);
static mwArray _mxarray1_ = mclInitializeDouble(1.0);

static mxChar _array3_[10] = { 'p', 'r', 'o', 'd', 'o',
                               'f', 's', 'i', 'z', 'e' };
static mwArray _mxarray2_ = mclInitializeString(10, _array3_);
static mwArray _mxarray4_ = mclInitializeDoubleVector(0, 0, (double *)NULL);

void InitializeModule_distchck() {
}

void TerminateModule_distchck() {
}

static mwArray Mdistchck(mwArray * varargout,
                         int nargout_,
                         mwArray nparms,
                         mwArray varargin);

_mexLocalFunctionTable _local_function_table_distchck
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "distchck" contains the normal interface for the "distchck"
// M-function from file "c:\matlab6p5\toolbox\stats\distchck.m" (lines 1-40).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray distchck(mwVarargout varargout, mwArray nparms, mwVarargin varargin) {
    int nargout = 1;
    mwArray errorcode = mwArray::UNDEFINED;
    nargout += varargout.Nargout();
    errorcode
      = Mdistchck(&varargout.GetCell(), nargout, nparms, varargin.ToArray());
    varargout.AssignOutputs();
    return errorcode;
}

//
// The function "mlxDistchck" contains the feval interface for the "distchck"
// M-function from file "c:\matlab6p5\toolbox\stats\distchck.m" (lines 1-40).
// The feval function calls the implementation version of distchck through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxDistchck(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[2];
        mwArray mplhs[2];
        int i;
        mclCppUndefineArrays(2, mplhs);
        for (i = 0; i < 1 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 1; ++i) {
            mprhs[i].MakeDIN();
        }
        mprhs[1] = mclCreateVararginCell(nrhs - 1, prhs + 1);
        mplhs[0] = Mdistchck(&mplhs[1], nlhs, mprhs[0], mprhs[1]);
        plhs[0] = mplhs[0].FreezeData();
        mclAssignVarargoutCell(1, nlhs - 1, plhs + 1, mplhs[1].FreezeData());
    }
    MW_END_MLX();
}

//
// The function "Mdistchck" is the implementation version of the "distchck"
// M-function from file "c:\matlab6p5\toolbox\stats\distchck.m" (lines 1-40).
// It contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function [errorcode,varargout] = distchck(nparms,varargin)
//
static mwArray Mdistchck(mwArray * varargout,
                         int nargout_,
                         mwArray nparms,
                         mwArray varargin) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_distchck;
    mwArray errorcode = mwArray::UNDEFINED;
    mwArray sizej = mwArray::UNDEFINED;
    mwArray size1 = mwArray::UNDEFINED;
    mwArray t = mwArray::UNDEFINED;
    mwArray sz = mwArray::UNDEFINED;
    mwArray j = mwArray::UNDEFINED;
    mwArray n = mwArray::UNDEFINED;
    mwArray isscalar = mwArray::UNDEFINED;
    //
    // %DISTCHCK Checks the argument list for the probability functions.
    // 
    // %   Copyright 1993-2002 The MathWorks, Inc. 
    // %   $Revision: 2.12 $  $Date: 2002/05/08 18:43:58 $
    // 
    // errorcode = 0;
    //
    errorcode = _mxarray0_;
    //
    // varargout = varargin;
    //
    *varargout = mwVa(varargin, "varargin");
    //
    // 
    // if nparms == 1
    //
    if (mclEqBool(mwVa(nparms, "nparms"), _mxarray1_)) {
        //
        // return;
        //
        goto return_;
    //
    // end
    //
    }
    //
    // 
    // % Get size of each input, check for scalars, copy to output
    // isscalar = (cellfun('prodofsize',varargin) == 1);
    //
    isscalar
      = Ncellfun(
          0,
          mwValueVarargout(),
          mwVarargin(_mxarray2_, mwVa(varargin, "varargin")))
        == _mxarray1_;
    //
    // 
    // % Done if all inputs are scalars.  Otherwise fetch their common size.
    // if (all(isscalar)), return; end
    //
    if (tobool(all(mwVv(isscalar, "isscalar")))) {
        goto return_;
    }
    //
    // 
    // n = nparms;
    //
    n = mwVa(nparms, "nparms");
    //
    // 
    // for j=1:n
    //
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mwVv(n, "n"));
        if (v_ > e_) {
            j = _mxarray4_;
        } else {
            //
            // sz{j} = size(varargin{j});
            // end
            //
            for (; ; ) {
                sz.cell(v_)
                = feval(
                    mwValueVarargout(),
                    mlxSize,
                    mwVarargin(mwVa(varargin, "varargin").cell(v_)));
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            j = v_;
        }
    }
    //
    // t = sz(~isscalar);
    //
    t = mclArrayRef(mwVv(sz, "sz"), ~ mwVv(isscalar, "isscalar"));
    //
    // size1 = t{1};
    //
    size1 = mwVv(t, "t").cell(_mxarray1_);
    //
    // 
    // % Scalars receive this size.  Other arrays must have the proper size.
    // for j=1:n
    //
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mwVv(n, "n"));
        if (v_ > e_) {
            j = _mxarray4_;
        } else {
            //
            // sizej = sz{j};
            // if (isscalar(j))
            // t = zeros(size1);
            // t(:) = varargin{j};
            // varargout{j} = t;
            // elseif (~isequal(sizej,size1))
            // errorcode = 1;
            // return;
            // end
            // end
            //
            for (; ; ) {
                sizej = mwVv(sz, "sz").cell(v_);
                if (tobool(mclIntArrayRef(mwVv(isscalar, "isscalar"), v_))) {
                    t = zeros(mwVarargin(mwVv(size1, "size1")));
                    mclArrayAssign(
                      &t, mwVa(varargin, "varargin").cell(v_), colon());
                    (*varargout).cell(v_) = mwVv(t, "t");
                } else if (mclNotBool(
                             isequal(
                               mwVv(sizej, "sizej"),
                               mwVarargin(mwVv(size1, "size1"))))) {
                    errorcode = _mxarray1_;
                    goto return_;
                }
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            j = v_;
        }
    }
    return_:
    mwValidateOutput(errorcode, 1, nargout_, "errorcode", "distchck");
    return errorcode;
}

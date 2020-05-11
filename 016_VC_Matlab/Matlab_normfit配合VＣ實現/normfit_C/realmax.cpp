//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "realmax.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1.9999999999999998);
static mwArray _mxarray1_ = mclInitializeDouble(1023.0);

void InitializeModule_realmax() {
}

void TerminateModule_realmax() {
}

static mwArray Mrealmax(int nargout_);

_mexLocalFunctionTable _local_function_table_realmax
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "realmax" contains the normal interface for the "realmax"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\realmax.m" (lines
// 1-19). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray realmax() {
    int nargout = 1;
    mwArray rmax = mwArray::UNDEFINED;
    rmax = Mrealmax(nargout);
    return rmax;
}

//
// The function "mlxRealmax" contains the feval interface for the "realmax"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\realmax.m" (lines
// 1-19). The feval function calls the implementation version of realmax
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxRealmax(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mplhs[1];
        mclCppUndefineArrays(1, mplhs);
        if (nlhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: realmax Line: 1 Column: "
                  "1 The function \"realmax\" was called with mor"
                  "e than the declared number of outputs (1).")));
        }
        if (nrhs > 0) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: realmax Line: 1 Column: "
                  "1 The function \"realmax\" was called with mor"
                  "e than the declared number of inputs (0).")));
        }
        mplhs[0] = Mrealmax(nlhs);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mrealmax" is the implementation version of the "realmax"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\realmax.m" (lines
// 1-19). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function rmax = realmax
//
static mwArray Mrealmax(int nargout_) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_realmax;
    mwArray rmax = mwArray::UNDEFINED;
    mwArray maxexp = mwArray::UNDEFINED;
    mwArray f = mwArray::UNDEFINED;
    //
    // %REALMAX Largest positive floating point number.
    // %   x = realmax is the largest floating point number representable
    // %   on this computer.  Anything larger overflows.
    // %
    // %   See also EPS, REALMIN.
    // 
    // %   C. Moler, 7-26-91, 6-10-92, 8-27-93.
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 5.9 $  $Date: 2002/04/08 20:21:10 $
    // 
    // % 2-eps is the largest floating point number smaller than 2.
    // f = 2-eps;
    //
    f = _mxarray0_;
    //
    // maxexp = 1023;
    //
    maxexp = _mxarray1_;
    //
    // 
    // % pow2(f,e) is f*2^e, computed by adding e to the exponent of f.
    // 
    // rmax = pow2(f,maxexp);
    //
    rmax = pow2(mwVv(f, "f"), mwVv(maxexp, "maxexp"));
    mwValidateOutput(rmax, 1, nargout_, "rmax", "realmax");
    return rmax;
}

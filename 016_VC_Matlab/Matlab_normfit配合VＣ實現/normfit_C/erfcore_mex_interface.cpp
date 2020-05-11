//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "erfcore_mex_interface.hpp"

void InitializeModule_erfcore_mex_interface() {
}

void TerminateModule_erfcore_mex_interface() {
}

static mwArray Merfcore(int nargout_, mwArray varargin);

_mexLocalFunctionTable _local_function_table_erfcore
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "Nerfcore" contains the nargout interface for the "erfcore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcore.dll"
// (lines 0-0). This interface is only produced if the M-function uses the
// special variable "nargout". The nargout interface allows the number of
// requested outputs to be specified via the nargout argument, as opposed to
// the normal interface which dynamically calculates the number of outputs
// based on the number of non-NULL inputs it receives. This function processes
// any input arguments and passes them to the implementation version of the
// function, appearing above.
//
mwArray Nerfcore(int nargout, mwVarargout varargout, mwVarargin varargin) {
    nargout += varargout.Nargout();
    varargout.GetCell() = Merfcore(nargout, varargin.ToArray());
    return varargout.AssignOutputs();
}

//
// The function "erfcore" contains the normal interface for the "erfcore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcore.dll"
// (lines 0-0). This function processes any input arguments and passes them to
// the implementation version of the function, appearing above.
//
mwArray erfcore(mwVarargout varargout, mwVarargin varargin) {
    int nargout = 0;
    nargout += varargout.Nargout();
    varargout.GetCell() = Merfcore(nargout, varargin.ToArray());
    return varargout.AssignOutputs();
}

//
// The function "Verfcore" contains the void interface for the "erfcore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcore.dll"
// (lines 0-0). The void interface is only produced if the M-function uses the
// special variable "nargout", and has at least one output. The void interface
// function specifies zero output arguments to the implementation version of
// the function, and in the event that the implementation version still returns
// an output (which, in MATLAB, would be assigned to the "ans" variable), it
// deallocates the output. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void Verfcore(mwVarargin varargin) {
    mwArray varargout = mwArray::UNDEFINED;
    varargout = Merfcore(0, varargin.ToArray());
}

//
// The function "mlxErfcore" contains the feval interface for the "erfcore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcore.dll"
// (lines 0-0). The feval function calls the implementation version of erfcore
// through this function. This function processes any input arguments and
// passes them to the implementation version of the function, appearing above.
//
void mlxErfcore(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[1];
        mwArray mplhs[1];
        mclCppUndefineArrays(1, mplhs);
        mprhs[0] = mclCreateVararginCell(nrhs, prhs);
        mplhs[0] = Merfcore(nlhs, mprhs[0]);
        mclAssignVarargoutCell(0, nlhs, plhs, mplhs[0].FreezeData());
    }
    MW_END_MLX();
}

//
// The function "Merfcore" is the implementation version of the "erfcore"
// M-function from file "c:\matlab6p5\toolbox\matlab\specfun\erfcore.dll"
// (lines 1-1). It contains the actual compiled code for that M-function. It is
// a static function and must only be called from one of the interface
// functions, appearing below.
//
static mwArray Merfcore(int nargout_, mwArray varargin) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_erfcore;
    return mclCppExecMexFile("erfcore", nargout_, varargin);
}

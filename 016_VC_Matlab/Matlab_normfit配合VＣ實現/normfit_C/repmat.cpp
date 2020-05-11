//
// MATLAB Compiler: 3.0
// Date: Tue Dec 21 11:36:40 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "CPP" "-h"
// "normfit.m" 
//
#include "repmat.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[27] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ',
                               'a', 't', ' ', 'l', 'e', 'a', 's', 't', ' ',
                               '2', ' ', 'i', 'n', 'p', 'u', 't', 's', '.' };
static mwArray _mxarray0_ = mclInitializeString(27, _array1_);
static mwArray _mxarray2_ = mclInitializeDouble(0.0);
static mwArray _mxarray3_ = mclInitializeDouble(1.0);
static mwArray _mxarray4_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
static mwArray _mxarray5_ = mclInitializeDouble(2.0);

void InitializeModule_repmat() {
}

void TerminateModule_repmat() {
}

static mwArray Mrepmat(int nargout_, mwArray A, mwArray M, mwArray N);

_mexLocalFunctionTable _local_function_table_repmat
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "repmat" contains the normal interface for the "repmat"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\repmat.m" (lines
// 1-65). This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray repmat(mwArray A, mwArray M, mwArray N) {
    int nargout = 1;
    mwArray B = mwArray::UNDEFINED;
    B = Mrepmat(nargout, A, M, N);
    return B;
}

//
// The function "mlxRepmat" contains the feval interface for the "repmat"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\repmat.m" (lines
// 1-65). The feval function calls the implementation version of repmat through
// this function. This function processes any input arguments and passes them
// to the implementation version of the function, appearing above.
//
void mlxRepmat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
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
                  "Run-time Error: File: repmat Line: 1 Column: 1"
                  " The function \"repmat\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 3) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: repmat Line: 1 Column: "
                  "1 The function \"repmat\" was called with mor"
                  "e than the declared number of inputs (3).")));
        }
        for (i = 0; i < 3 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 3; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mrepmat(nlhs, mprhs[0], mprhs[1], mprhs[2]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mrepmat" is the implementation version of the "repmat"
// M-function from file "c:\matlab6p5\toolbox\matlab\elmat\repmat.m" (lines
// 1-65). It contains the actual compiled code for that M-function. It is a
// static function and must only be called from one of the interface functions,
// appearing below.
//
//
// function B = repmat(A,M,N)
//
static mwArray Mrepmat(int nargout_, mwArray A, mwArray M, mwArray N) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_repmat;
    int nargin_ = nargin(3, mwVarargin(A, M, N));
    mwArray B = mwArray::UNDEFINED;
    mwArray subs = mwArray::UNDEFINED;
    mwArray ind = mwArray::UNDEFINED;
    mwArray i = mwArray::UNDEFINED;
    mwArray Asiz = mwArray::UNDEFINED;
    mwArray nind = mwArray::UNDEFINED;
    mwArray mind = mwArray::UNDEFINED;
    mwArray n = mwArray::UNDEFINED;
    mwArray m = mwArray::UNDEFINED;
    mwArray nelems = mwArray::UNDEFINED;
    mwArray siz = mwArray::UNDEFINED;
    mwArray ans = mwArray::UNDEFINED;
    //
    // %REPMAT Replicate and tile an array.
    // %   B = repmat(A,M,N) creates a large matrix B consisting of an M-by-N
    // %   tiling of copies of A.
    // %   
    // %   B = REPMAT(A,[M N]) accomplishes the same result as repmat(A,M,N).
    // %
    // %   B = REPMAT(A,[M N P ...]) tiles the array A to produce a
    // %   M-by-N-by-P-by-... block array.  A can be N-D.
    // %
    // %   REPMAT(A,M,N) when A is a scalar is commonly used to produce
    // %   an M-by-N matrix filled with A's value.  This can be much faster
    // %   than A*ONES(M,N) when M and/or N are large.
    // %   
    // %   Example:
    // %       repmat(magic(2),2,3)
    // %       repmat(NaN,2,3)
    // %
    // %   See also MESHGRID.
    // 
    // %   Copyright 1984-2002 The MathWorks, Inc. 
    // %   $Revision: 1.17 $  $Date: 2002/04/08 20:21:10 $
    // 
    // if nargin < 2
    //
    if (nargin_ < 2) {
        //
        // error('Requires at least 2 inputs.')
        //
        error(mwVarargin(_mxarray0_));
    //
    // elseif nargin == 2
    //
    } else if (nargin_ == 2) {
        //
        // if length(M)==1
        //
        if (mclLengthInt(mwVa(M, "M")) == 1) {
            //
            // siz = [M M];
            //
            siz = horzcat(mwVarargin(mwVa(M, "M"), mwVa(M, "M")));
        //
        // else
        //
        } else {
            //
            // siz = M;
            //
            siz = mwVa(M, "M");
        //
        // end
        //
        }
    //
    // else
    //
    } else {
        //
        // siz = [M N];
        //
        siz = horzcat(mwVarargin(mwVa(M, "M"), mwVa(N, "N")));
    //
    // end
    //
    }
    //
    // 
    // if length(A)==1
    //
    if (mclLengthInt(mwVa(A, "A")) == 1) {
        //
        // nelems = prod(siz);
        //
        nelems = prod(mwVv(siz, "siz"));
        //
        // if nelems>0
        //
        if (mclGtBool(mwVv(nelems, "nelems"), _mxarray2_)) {
            //
            // % Since B doesn't exist, the first statement creates a B with
            // % the right size and type.  Then use scalar expansion to
            // % fill the array.. Finally reshape to the specified size.
            // B(nelems) = A; 
            //
            mclArrayAssign(&B, mwVa(A, "A"), mwVv(nelems, "nelems"));
            //
            // B(:) = A;
            //
            mclArrayAssign(&B, mwVa(A, "A"), colon());
            //
            // B = reshape(B,siz);
            //
            B = reshape(mwVv(B, "B"), mwVarargin(mwVv(siz, "siz")));
        //
        // else
        //
        } else {
            //
            // B = A(ones(siz));
            //
            B = mclArrayRef(mwVa(A, "A"), ones(mwVarargin(mwVv(siz, "siz"))));
        //
        // end
        //
        }
    //
    // elseif ndims(A)==2 & length(siz)==2
    //
    } else {
        mwArray a_ = ndims(mwVa(A, "A")) == _mxarray5_;
        if (tobool(a_) && tobool(a_ & mclLengthInt(mwVv(siz, "siz")) == 2)) {
            //
            // [m,n] = size(A);
            //
            size(mwVarargout(m, n), mwVa(A, "A"));
            //
            // mind = (1:m)';
            //
            mind = ctranspose(colon(_mxarray3_, mwVv(m, "m")));
            //
            // nind = (1:n)';
            //
            nind = ctranspose(colon(_mxarray3_, mwVv(n, "n")));
            //
            // mind = mind(:,ones(1,siz(1)));
            //
            mind
              = mclArrayRef(
                  mwVv(mind, "mind"),
                  colon(),
                  ones(
                    mwVarargin(
                      _mxarray3_, mclIntArrayRef(mwVv(siz, "siz"), 1))));
            //
            // nind = nind(:,ones(1,siz(2)));
            //
            nind
              = mclArrayRef(
                  mwVv(nind, "nind"),
                  colon(),
                  ones(
                    mwVarargin(
                      _mxarray3_, mclIntArrayRef(mwVv(siz, "siz"), 2))));
            //
            // B = A(mind,nind);
            //
            B
              = mclArrayRef(
                  mwVa(A, "A"), mwVv(mind, "mind"), mwVv(nind, "nind"));
        //
        // else
        //
        } else {
            //
            // Asiz = size(A);
            //
            Asiz = size(mwValueVarargout(), mwVa(A, "A"));
            //
            // Asiz = [Asiz ones(1,length(siz)-length(Asiz))];
            //
            Asiz
              = horzcat(
                  mwVarargin(
                    mwVv(Asiz, "Asiz"),
                    ones(
                      mwVarargin(
                        _mxarray3_,
                        mclLengthInt(mwVv(siz, "siz"))
                        - mclLengthInt(mwVv(Asiz, "Asiz"))))));
            //
            // siz = [siz ones(1,length(Asiz)-length(siz))];
            //
            siz
              = horzcat(
                  mwVarargin(
                    mwVv(siz, "siz"),
                    ones(
                      mwVarargin(
                        _mxarray3_,
                        mclLengthInt(mwVv(Asiz, "Asiz"))
                        - mclLengthInt(mwVv(siz, "siz"))))));
            //
            // for i=length(Asiz):-1:1
            //
            {
                int v_ = mclForIntStart(mclLengthInt(mwVv(Asiz, "Asiz")));
                int i_ = -1;
                int e_ = mclForIntIntEnd(v_, i_, _mxarray3_);
                if (e_ == mclIntMin()) {
                    i = _mxarray4_;
                } else {
                    //
                    // ind = (1:Asiz(i))';
                    // subs{i} = ind(:,ones(1,siz(i)));
                    // end
                    //
                    for (; ; ) {
                        ind
                          = ctranspose(
                              colon(
                                _mxarray3_,
                                mclIntArrayRef(mwVv(Asiz, "Asiz"), v_)));
                        subs.cell(v_)
                        = mclArrayRef(
                            mwVv(ind, "ind"),
                            colon(),
                            ones(
                              mwVarargin(
                                _mxarray3_,
                                mclIntArrayRef(mwVv(siz, "siz"), v_))));
                        if (v_ == e_) {
                            break;
                        }
                        v_ += i_;
                    }
                    i = v_;
                }
            }
            //
            // B = A(subs{:});
            //
            B = mclArrayRef(mwVa(A, "A"), mwVv(subs, "subs").cell(colon()));
        }
    //
    // end
    //
    }
    mwValidateOutput(B, 1, nargout_, "B", "repmat");
    return B;
}

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//
#ifndef __INV_H__
#define __INV_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "batchEDSolve_types.h"

// Function Declarations
extern void invNxN(const creal_T x_data[], const int x_size[2], creal_T y_data[],
                   int y_size[2]);

#endif

//
// File trailer for inv.h
//
// [EOF]
//

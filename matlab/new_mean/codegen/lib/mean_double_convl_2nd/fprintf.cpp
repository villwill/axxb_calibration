//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fprintf.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 11-Jun-2015 01:46:04
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "fprintf.h"
#include "fileManager.h"
#include <stdio.h>

// Function Declarations
static double c_fprintf();
static double e_fprintf(double varargin_1);
static double g_fprintf(double varargin_1, double varargin_2, double varargin_3);

// Function Definitions

//
// Arguments    : void
// Return Type  : double
//
static double c_fprintf()
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[34] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o', 't',
    'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's',
    ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd', '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt);
    fflush(filestar);
  }

  return nbytesint;
}

//
// Arguments    : double varargin_1
// Return Type  : double
//
static double e_fprintf(double varargin_1)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[27] = { 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f',
    ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'i', 's', ' ',
    '%', 'f', '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }

  return nbytesint;
}

//
// Arguments    : double varargin_1
//                double varargin_2
//                double varargin_3
// Return Type  : double
//
static double g_fprintf(double varargin_1, double varargin_2, double varargin_3)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[46] = { 'V', 'a', 'l', 'u', 'e', ' ', 'o', 'f', ' ',
    't', 'h', 'e', ' ', 'c', 'o', 's', 't', ' ', 'f', 'u', 'n', 'c', 't', 'i',
    'o', 'n', ' ', 'i', 's', ' ', '%', 'f', ',', ' ', '%', 'f', ' ', 'a', 'n',
    'd', ' ', '%', 'f', ' ', '\x0a', '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt, varargin_1, varargin_2, varargin_3);
    fflush(filestar);
  }

  return nbytesint;
}

//
// Arguments    : void
// Return Type  : void
//
void b_fprintf()
{
  c_fprintf();
}

//
// Arguments    : double formatSpec
// Return Type  : void
//
void d_fprintf(double formatSpec)
{
  e_fprintf(formatSpec);
}

//
// Arguments    : double formatSpec
//                double varargin_1
//                double varargin_2
// Return Type  : void
//
void f_fprintf(double formatSpec, double varargin_1, double varargin_2)
{
  g_fprintf(formatSpec, varargin_1, varargin_2);
}

//
// File trailer for fprintf.cpp
//
// [EOF]
//

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "norm.h"
#include "eml_error.h"
#include "eml_int_forloop_overflow_check.h"
#include "sqrt.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 45, "norm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/norm.m" };

static emlrtRSInfo vc_emlrtRSI = { 14, "svd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/svd.m" };

static emlrtRSInfo wc_emlrtRSI = { 34, "svd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/svd.m" };

static emlrtRSInfo xc_emlrtRSI = { 13, "eml_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };

static emlrtRSInfo yc_emlrtRSI = { 8, "eml_lapack_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"
};

static emlrtRSInfo gd_emlrtRSI = { 373, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo hd_emlrtRSI = { 264, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo jd_emlrtRSI = { 110, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo kd_emlrtRSI = { 90, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo md_emlrtRSI = { 73, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo nd_emlrtRSI = { 19, "eml_xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };

static emlrtRSInfo od_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"
};

static emlrtRSInfo pd_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"
};

static emlrtRSInfo td_emlrtRSI = { 30, "eml_xdotc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m" };

static emlrtRSInfo ud_emlrtRSI = { 1, "xdotc",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"
};

static emlrtRSInfo vd_emlrtRSI = { 1, "xdot",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xdot.p" };

static emlrtRSInfo wd_emlrtRSI = { 1, "xdot",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"
};

static emlrtRSInfo xd_emlrtRSI = { 1, "xdotx",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"
};

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, const real_T x[16], int32_T ix0,
  real_T y[4], int32_T iy0);
static real_T b_eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[4],
  int32_T ix0);
static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[4], int32_T ix0,
  real_T y[16], int32_T iy0);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
                      iy0);
static real_T eml_xdotc(const emlrtStack *sp, int32_T n, const real_T x[16],
  int32_T ix0, const real_T y[16], int32_T iy0);
static void eml_xgesvd(const emlrtStack *sp, const real_T A[16], real_T S[4]);
static real_T eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[16],
  int32_T ix0);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, const real_T x[16], int32_T ix0,
  real_T y[4], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (a == 0.0) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

static real_T b_eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[4],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  boolean_T b_ix0;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &od_emlrtRSI;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  c_st.site = &pd_emlrtRSI;
  if (ix0 > kend) {
    b_ix0 = false;
  } else {
    b_ix0 = (kend > 2147483646);
  }

  if (b_ix0) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[4], int32_T ix0,
  real_T y[16], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (a == 0.0) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
                      iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (a == 0.0) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

static real_T eml_xdotc(const emlrtStack *sp, int32_T n, const real_T x[16],
  int32_T ix0, const real_T y[16], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  boolean_T b0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &td_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ud_emlrtRSI;
  c_st.site = &vd_emlrtRSI;
  d_st.site = &wd_emlrtRSI;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  e_st.site = &xd_emlrtRSI;
  if (1 > n) {
    b0 = false;
  } else {
    b0 = (n > 2147483646);
  }

  if (b0) {
    f_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 1; k <= n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

static void eml_xgesvd(const emlrtStack *sp, const real_T A[16], real_T S[4])
{
  real_T b_A[16];
  real_T s[4];
  real_T e[4];
  real_T work[4];
  int32_T kase;
  int32_T q;
  int32_T qs;
  boolean_T apply_transform;
  real_T ztest0;
  int32_T ixstart;
  int32_T m;
  real_T ztest;
  real_T rt;
  int32_T iter;
  real_T snorm;
  boolean_T exitg1;
  int32_T exitg4;
  boolean_T exitg3;
  real_T f;
  real_T varargin_1[5];
  real_T mtmp;
  boolean_T exitg2;
  real_T sqds;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &yc_emlrtRSI;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4);
  for (kase = 0; kase < 4; kase++) {
    s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
  }

  for (q = 0; q < 3; q++) {
    qs = q + (q << 2);
    apply_transform = false;
    c_st.site = &md_emlrtRSI;
    ztest0 = eml_xnrm2(&c_st, 4 - q, b_A, qs + 1);
    if (ztest0 > 0.0) {
      apply_transform = true;
      if (b_A[qs] < 0.0) {
        s[q] = -ztest0;
      } else {
        s[q] = ztest0;
      }

      if (muDoubleScalarAbs(s[q]) >= 1.0020841800044864E-292) {
        ztest0 = 1.0 / s[q];
        kase = (qs - q) + 4;
        for (ixstart = qs; ixstart + 1 <= kase; ixstart++) {
          b_A[ixstart] *= ztest0;
        }
      } else {
        kase = (qs - q) + 4;
        for (ixstart = qs; ixstart + 1 <= kase; ixstart++) {
          b_A[ixstart] /= s[q];
        }
      }

      b_A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (kase = q + 1; kase + 1 < 5; kase++) {
      ixstart = q + (kase << 2);
      if (apply_transform) {
        c_st.site = &kd_emlrtRSI;
        ztest0 = eml_xdotc(&c_st, 4 - q, b_A, qs + 1, b_A, ixstart + 1);
        eml_xaxpy(4 - q, -(ztest0 / b_A[q + (q << 2)]), qs + 1, b_A, ixstart + 1);
      }

      e[kase] = b_A[ixstart];
    }

    if (q + 1 <= 2) {
      c_st.site = &jd_emlrtRSI;
      ztest0 = b_eml_xnrm2(&c_st, 3 - q, e, q + 2);
      if (ztest0 == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -ztest0;
        } else {
          e[q] = ztest0;
        }

        ztest0 = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          ztest0 = 1.0 / e[q];
          for (ixstart = q + 1; ixstart + 1 < 5; ixstart++) {
            e[ixstart] *= ztest0;
          }
        } else {
          for (ixstart = q + 1; ixstart + 1 < 5; ixstart++) {
            e[ixstart] /= ztest0;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (kase = q + 1; kase + 1 < 5; kase++) {
          work[kase] = 0.0;
        }

        for (kase = q + 1; kase + 1 < 5; kase++) {
          b_eml_xaxpy(3 - q, e[kase], b_A, (q + (kase << 2)) + 2, work, q + 2);
        }

        for (kase = q + 1; kase + 1 < 5; kase++) {
          c_eml_xaxpy(3 - q, -e[kase] / e[q + 1], work, q + 2, b_A, (q + (kase <<
            2)) + 2);
        }
      }
    }
  }

  m = 2;
  s[3] = b_A[15];
  e[2] = b_A[14];
  e[3] = 0.0;
  for (q = 0; q < 4; q++) {
    ztest = e[q];
    if (s[q] != 0.0) {
      rt = muDoubleScalarAbs(s[q]);
      ztest0 = s[q] / rt;
      s[q] = rt;
      if (q + 1 < 4) {
        ztest = e[q] / ztest0;
      }
    }

    if ((q + 1 < 4) && (ztest != 0.0)) {
      rt = muDoubleScalarAbs(ztest);
      ztest0 = ztest;
      ztest = rt;
      s[q + 1] *= rt / ztest0;
    }

    e[q] = ztest;
  }

  iter = 0;
  snorm = 0.0;
  for (kase = 0; kase < 4; kase++) {
    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s[kase]),
      muDoubleScalarAbs(e[kase])));
  }

  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      c_st.site = &hd_emlrtRSI;
      c_eml_error(&c_st);
    } else {
      kase = m;
      do {
        exitg4 = 0;
        q = kase + 1;
        if (kase + 1 == 0) {
          exitg4 = 1;
        } else {
          ztest0 = muDoubleScalarAbs(e[kase]);
          if ((ztest0 <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[kase]) +
                muDoubleScalarAbs(s[kase + 1]))) || (ztest0 <=
               1.0020841800044864E-292) || ((iter > 20) && (ztest0 <=
                2.2204460492503131E-16 * snorm))) {
            e[kase] = 0.0;
            exitg4 = 1;
          } else {
            kase--;
          }
        }
      } while (exitg4 == 0);

      if (kase + 1 == m + 1) {
        kase = 4;
      } else {
        qs = m + 2;
        ixstart = m + 2;
        exitg3 = false;
        while ((!exitg3) && (ixstart >= kase + 1)) {
          qs = ixstart;
          if (ixstart == kase + 1) {
            exitg3 = true;
          } else {
            ztest0 = 0.0;
            if (ixstart < m + 2) {
              ztest0 = muDoubleScalarAbs(e[ixstart - 1]);
            }

            if (ixstart > kase + 2) {
              ztest0 += muDoubleScalarAbs(e[ixstart - 2]);
            }

            ztest = muDoubleScalarAbs(s[ixstart - 1]);
            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
                 1.0020841800044864E-292)) {
              s[ixstart - 1] = 0.0;
              exitg3 = true;
            } else {
              ixstart--;
            }
          }
        }

        if (qs == kase + 1) {
          kase = 3;
        } else if (qs == m + 2) {
          kase = 1;
        } else {
          kase = 2;
          q = qs;
        }
      }

      switch (kase) {
       case 1:
        f = e[m];
        e[m] = 0.0;
        for (ixstart = m; ixstart + 1 >= q + 1; ixstart--) {
          ztest0 = s[ixstart];
          eml_xrotg(&ztest0, &f, &ztest, &rt);
          s[ixstart] = ztest0;
          if (ixstart + 1 > q + 1) {
            f = -rt * e[ixstart - 1];
            e[ixstart - 1] *= ztest;
          }
        }
        break;

       case 2:
        f = e[q - 1];
        e[q - 1] = 0.0;
        while (q + 1 <= m + 2) {
          eml_xrotg(&s[q], &f, &ztest, &rt);
          f = -rt * e[q];
          e[q] *= ztest;
          q++;
        }
        break;

       case 3:
        varargin_1[0] = muDoubleScalarAbs(s[m + 1]);
        varargin_1[1] = muDoubleScalarAbs(s[m]);
        varargin_1[2] = muDoubleScalarAbs(e[m]);
        varargin_1[3] = muDoubleScalarAbs(s[q]);
        varargin_1[4] = muDoubleScalarAbs(e[q]);
        ixstart = 1;
        mtmp = varargin_1[0];
        if (muDoubleScalarIsNaN(varargin_1[0])) {
          kase = 2;
          exitg2 = false;
          while ((!exitg2) && (kase < 6)) {
            ixstart = kase;
            if (!muDoubleScalarIsNaN(varargin_1[kase - 1])) {
              mtmp = varargin_1[kase - 1];
              exitg2 = true;
            } else {
              kase++;
            }
          }
        }

        if (ixstart < 5) {
          while (ixstart + 1 < 6) {
            if (varargin_1[ixstart] > mtmp) {
              mtmp = varargin_1[ixstart];
            }

            ixstart++;
          }
        }

        f = s[m + 1] / mtmp;
        ztest0 = s[m] / mtmp;
        ztest = e[m] / mtmp;
        sqds = s[q] / mtmp;
        rt = ((ztest0 + f) * (ztest0 - f) + ztest * ztest) / 2.0;
        ztest0 = f * ztest;
        ztest0 *= ztest0;
        if ((rt != 0.0) || (ztest0 != 0.0)) {
          ztest = rt * rt + ztest0;
          c_st.site = &gd_emlrtRSI;
          b_sqrt(&c_st, &ztest);
          if (rt < 0.0) {
            ztest = -ztest;
          }

          ztest = ztest0 / (rt + ztest);
        } else {
          ztest = 0.0;
        }

        f = (sqds + f) * (sqds - f) + ztest;
        ztest0 = sqds * (e[q] / mtmp);
        for (ixstart = q + 1; ixstart <= m + 1; ixstart++) {
          eml_xrotg(&f, &ztest0, &ztest, &rt);
          if (ixstart > q + 1) {
            e[ixstart - 2] = f;
          }

          f = ztest * s[ixstart - 1] + rt * e[ixstart - 1];
          e[ixstart - 1] = ztest * e[ixstart - 1] - rt * s[ixstart - 1];
          ztest0 = rt * s[ixstart];
          s[ixstart] *= ztest;
          s[ixstart - 1] = f;
          eml_xrotg(&s[ixstart - 1], &ztest0, &ztest, &rt);
          f = ztest * e[ixstart - 1] + rt * s[ixstart];
          s[ixstart] = -rt * e[ixstart - 1] + ztest * s[ixstart];
          ztest0 = rt * e[ixstart];
          e[ixstart] *= ztest;
        }

        e[m] = f;
        iter++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }

        kase = q + 1;
        while ((q + 1 < 4) && (s[q] < s[kase])) {
          rt = s[q];
          s[q] = s[kase];
          s[kase] = rt;
          q = kase;
          kase++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  for (ixstart = 0; ixstart < 4; ixstart++) {
    S[ixstart] = s[ixstart];
  }
}

static real_T eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[16],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  boolean_T b_ix0;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &od_emlrtRSI;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  c_st.site = &pd_emlrtRSI;
  if (ix0 > kend) {
    b_ix0 = false;
  } else {
    b_ix0 = (kend > 2147483646);
  }

  if (b_ix0) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  *c = 0.0;
  *s = 0.0;
  drotg(a, b, c, s);
}

real_T b_norm(const emlrtStack *sp, const real_T x[16])
{
  int32_T k;
  real_T U[4];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (k = 0; k < 16; k++) {
    if (!((!muDoubleScalarIsInf(x[k])) && (!muDoubleScalarIsNaN(x[k])))) {
      b_st.site = &vc_emlrtRSI;
      b_eml_error(&b_st);
    }
  }

  b_st.site = &wc_emlrtRSI;
  eml_xgesvd(&b_st, x, U);
  return U[0];
}

real_T c_norm(const creal_T x_data[], const int32_T x_size[2])
{
  real_T y;
  int32_T j;
  int32_T i;
  boolean_T exitg1;
  real_T s;
  if ((x_size[0] == 1) || (x_size[1] == 1)) {
    y = 0.0;
    j = x_size[0] * x_size[1];
    for (i = 0; i < j; i++) {
      y += muDoubleScalarHypot(x_data[i].re, x_data[i].im);
    }
  } else {
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= x_size[1] - 1)) {
      s = 0.0;
      for (i = 0; i < x_size[0]; i++) {
        s += muDoubleScalarHypot(x_data[i + x_size[0] * j].re, x_data[i +
          x_size[0] * j].im);
      }

      if (muDoubleScalarIsNaN(s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (s > y) {
          y = s;
        }

        j++;
      }
    }
  }

  return y;
}

real_T genpnorm(const creal_T x[3])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 3; k++) {
    absxk = muDoubleScalarAbs(x[k].re);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    absxk = muDoubleScalarAbs(x[k].im);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

real_T norm(const real_T x[16])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 4)) {
    s = 0.0;
    for (i = 0; i < 4; i++) {
      s += muDoubleScalarAbs(x[i + (j << 2)]);
    }

    if (muDoubleScalarIsNaN(s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

/* End of code generation (norm.c) */

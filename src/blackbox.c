#include "astro.h"


void blackbox(double x1, double y1, int s1, int s2,
	      double epoch, double equinox,
	      double *x2, double *y2)

{
  struct s_tstate tstate;
  struct s_v6 pvec[N_TPM_STATES];
  struct s_v6 v6;

  //  double epoch = J2000;
  //  double equinox = J2000;

  // Input params are in degrees. Convert them to radians & set things up.
  double rx1=d2r(x1);
  double ry1=d2r(y1);

  v6=v6init(SPHERICAL); // v6=Spherical(lon,lat) #r=FarAway
  v6SetAlpha(v6,d2r(x1));
  v6SetDelta(v6,d2r(y1));
  v6SetR(v6,1e9);

  tpm_data(&tstate, TPM_INIT); 
  tstate.utc = utc_now(); 
  tpm_data(&tstate, TPM_ALL);

  pvec[s1]=v6;

  (void)tpm(pvec,s1,s2,epoch,equinox,&tstate);

  v6=pvec[s2];
  v6 = v6c2s(v6);
  *x2 = r2d(v6GetAlpha(v6));
  *y2 = r2d(v6GetDelta(v6));

  return;
}
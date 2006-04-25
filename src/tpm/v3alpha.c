/* file: $RCSfile: v3alpha.c,v $
** rcsid: $Id: v3alpha.c,v 1.5 2003/09/09 21:52:53 jwp Exp $
** Copyright Jeffrey W Percival
** *******************************************************************
** Space Astronomy Laboratory
** University of Wisconsin
** 1150 University Avenue
** Madison, WI 53706 USA
** *******************************************************************
** Do not use this software without attribution.
** Do not remove or alter any of the lines above.
** *******************************************************************
*/
static char *rcsid = "$Id: v3alpha.c,v 1.5 2003/09/09 21:52:53 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: v3alpha.c,v $ - return the angle in the x-y plane (right ascension)
** *******************************************************************
*/

#include "vec.h"

double
v3alpha(V3 v)
{
    double alpha;

    if (v3GetType(v) == CARTESIAN) {
	v = v3c2s(v);
    }

    alpha = v3GetAlpha(v);
    if (v3GetR(v) < 0.0) {
	alpha += M_PI;
    }

    if (alpha < 0.0) {
	alpha += ceil(alpha / (-2 * M_PI)) * (2 * M_PI);
    }
    if (alpha >= (2 * M_PI)) {
	alpha -= floor(alpha / (2 * M_PI)) * (2 * M_PI);
    }

    return(alpha);
}

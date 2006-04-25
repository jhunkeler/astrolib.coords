/* file: $RCSfile: hadec2azel.c,v $
** rcsid: $Id: hadec2azel.c,v 1.6 2003/09/03 20:19:12 jwp Exp $
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
static char *rcsid = "$Id: hadec2azel.c,v 1.6 2003/09/03 20:19:12 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: hadec2azel.c,v $
** convert a state vector from (ha,dec) to (az,el)
** *******************************************************************
*/

#include "astro.h"

V6
hadec2azel(V6 v6, double latitude)
{
    /* rotate by (90-latitude) in the plane of the meridian */
    v6 = m3v6(m3Ry((M_PI/2 - latitude)), v6);

    /* do a simple rotation about Z through 180 degrees */
    v6 = m3v6(m3Rz(M_PI), v6);

    return(v6);
}

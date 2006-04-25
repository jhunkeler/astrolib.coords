/* file: $RCSfile: fmt_j.c,v $
** rcsid: $Id: fmt_j.c,v 1.16 2003/09/09 21:18:47 jwp Exp $
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
static char *rcsid = "$Id: fmt_j.c,v 1.16 2003/09/09 21:18:47 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: fmt_j.c,v $ - format julian date
** *******************************************************************
*/

#include <stdio.h>
#include "times.h"

#define NBUF (5)
static char buf[NBUF][32];
static int nxtbuf = 0;

char *
fmt_j(double j)
{
    char *p;
    double h;
    int d;

    /* get a buffer */
    p = buf[nxtbuf++];
    nxtbuf %= NBUF;

    d = floor(j);
    h = (j - d) * 24;

    (void)sprintf(p, "%8d %s", d, fmt_h(h));

    return(p);
}

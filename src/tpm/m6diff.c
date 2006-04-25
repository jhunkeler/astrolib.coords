/* file: $RCSfile: m6diff.c,v $
** rcsid: $Id: m6diff.c,v 1.5 2003/09/09 21:52:53 jwp Exp $
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
static char *rcsid = "$Id: m6diff.c,v 1.5 2003/09/09 21:52:53 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: m6diff.c,v $ - the difference of two 6-matrices
** *******************************************************************
*/

#include "vec.h"

M6
m6diff(M6 m1, M6 m2)
{
    M6 m;

    m.m[0][0] = m3diff(m1.m[0][0], m2.m[0][0]);
    m.m[0][1] = m3diff(m1.m[0][1], m2.m[0][1]);
    m.m[1][0] = m3diff(m1.m[1][0], m2.m[1][0]);
    m.m[1][1] = m3diff(m1.m[1][1], m2.m[1][1]);

    return(m);
}

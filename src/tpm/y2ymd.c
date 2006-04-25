/* file: $RCSfile: y2ymd.c,v $
** rcsid: $Id: y2ymd.c,v 1.13 2003/09/09 21:18:47 jwp Exp $
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
static char *rcsid = "$Id: y2ymd.c,v 1.13 2003/09/09 21:18:47 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: y2ymd.c,v $ - convert a scalar year into a ymd year
** *******************************************************************
*/

#include "times.h"

YMD
y2ymd(double y)
{
    YMD ymd;
    double f;

    f = floor(y);
    ymdSetYear(ymd, (int)f);

    ymdSetMonth(ymd, 1);

    ymdSetDay(ymd, (y - f) * y2doy(ymdGetYear(ymd)));

    ymdSetHours(ymd, 0.0);
    ymdSetMinutes(ymd, 0.0);
    ymdSetSeconds(ymd, 0.0);

    return(ymd);
}

/* file: $RCSfile: dms_sum.c,v $
** rcsid: $Id: dms_sum.c,v 1.7 2003/05/15 20:09:26 jwp Exp $
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
static char *rcsid = "$Id: dms_sum.c,v 1.7 2003/05/15 20:09:26 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: dms_sum.c,v $ - sum of dms angles
** *******************************************************************
*/

#include "times.h"

DMS
dms_sum(DMS dms1, DMS dms2)
{
    dmsIncDegrees(dms1, dmsGetDegrees(dms2));
    dmsIncMinutes(dms1, dmsGetMinutes(dms2));
    dmsIncSeconds(dms1, dmsGetSeconds(dms2));

    return(dms1);
}

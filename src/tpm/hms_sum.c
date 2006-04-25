/* file: $RCSfile: hms_sum.c,v $
** rcsid: $Id: hms_sum.c,v 1.8 2003/09/09 21:18:47 jwp Exp $
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
static char *rcsid = "$Id: hms_sum.c,v 1.8 2003/09/09 21:18:47 jwp Exp $";

/*
** *******************************************************************
** $RCSfile: hms_sum.c,v $ - sum of hms times
** *******************************************************************
*/

#include "times.h"

HMS
hms_sum(HMS hms1, HMS hms2)
{
    hmsIncHours(hms1, hmsGetHours(hms2));
    hmsIncMinutes(hms1, hmsGetMinutes(hms2));
    hmsIncSeconds(hms1, hmsGetSeconds(hms2));

    return(hms1);
}

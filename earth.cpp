/***********************************************************************
 * Source File:
 *    Earth
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#include "earth.h"

void Earth::displayEarth(double angleEarth)
{
   Position pt;

   // draw the earth
   pt.setMeters(0.0, 0.0);
   drawEarth(pt, angleEarth);
}

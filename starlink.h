/***********************************************************************
 * Header File:
 *    StarLink
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Starlink : public Satellite
{
public:
   Starlink() {}
   Starlink(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawStarlink(pos, angle);
   }
};



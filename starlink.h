/***********************************************************************
 * Header File:
 *    StarLink
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Specifics for the Starlink satellite child class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "satellitePart.h"
class Starlink : public Satellite
{
public:
   Starlink() {}
   Starlink(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const {
      drawStarlink(pos, angle);
   }

   void spawnParts(list<Satellite*>& pSatellites);
};



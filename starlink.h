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
   Starlink(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawStarlink(pos, angle);
   }

   void spawnParts(list<Satellite*>& pSatellites);
};



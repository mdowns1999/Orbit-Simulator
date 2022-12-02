/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Specifics for the GPS satellite child class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "satellitePart.h"
#include "uiDraw.h"
class GPS : public Satellite
{
public:
   GPS() {}
   GPS(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const { drawGPS(pos, angle); }

   void spawnParts(list<Satellite*>& pSatellites); 
};


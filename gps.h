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
   GPS(double x, double y, double dx, double dy);
   void  draw()  const { drawGPS(pos, angle); }

   void spawnParts(list<Satellite*>& pSatellites); 
};


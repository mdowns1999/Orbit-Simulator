/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Specifics for the Hubble satellite child class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "satellitePart.h"
class Hubble : public Satellite
{
public:
   Hubble() {}
   Hubble(double x, double y, double dx, double dy);
   void  draw()  const {
      drawHubble(pos, 0.1);
   }

   void spawnParts(list<Satellite*>& pSatellites);
};



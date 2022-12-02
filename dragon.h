/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    Specifics for the dragon child class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "satellitePart.h"
class Dragon : public Satellite
{
public:
   Dragon() {}
   Dragon(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawCrewDragon(pos, angle);
   }

   void spawnParts(list<Satellite*>& pSatellites); 

};


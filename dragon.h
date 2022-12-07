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
   Dragon(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const {
      drawCrewDragon(pos, angle);
   }

   void spawnParts(list<Satellite*>& pSatellites); 

};


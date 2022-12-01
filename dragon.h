/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Dragon : public Satellite
{
public:
   Dragon() {}
   Dragon(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawCrewDragon(pos, 0.1);
   }
};


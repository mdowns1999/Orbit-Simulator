/***********************************************************************
 * Header File:
 *    Ship : A type of Satellite that the user controls
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    A type of Satellite that the user controls
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Ship : public Satellite
{
   Ship() {}
   Ship(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawShip(pos, 0.01);
   }
};


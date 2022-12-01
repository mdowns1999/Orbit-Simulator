/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Hubble : public Satellite
{
public:
   Hubble() {}
   Hubble(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawHubble(pos, 0.1);
   }
};



/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class GPS : public Satellite
{
public:
   GPS() {}
   GPS(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawGPS(pos, 0.01); }
};


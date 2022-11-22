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
      cout << "Pixel X: " << pos.getPixelsX() << endl;
      cout << "Pixel Y: " << pos.getPixelsY() << endl;
      cout << "Meter X: " << pos.getMetersX() << endl;
      cout << "Meter Y: " << pos.getMetersY() << endl;
      cout << "Meter-Pixel: " << pos.getZoom() << endl;
      drawGPS(pos, 0.01); }
};


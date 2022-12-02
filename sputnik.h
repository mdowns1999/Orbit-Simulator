/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Specifics for the Sputnik satellite child class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Sputnik : public Satellite
{
public:
   Sputnik() {}
   Sputnik(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   void  draw()  const {
      drawSputnik(pos, angle);
   }
};


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
#include "uiInteract.h" // for INTERFACE

class Ship : public Satellite
{
private:
   //Interface UI;
   bool isShip = true;


public:

   Ship() {isShip = true; }
   Ship(double x, double y) {isShip = true; pos.setMetersX(x);  pos.setMetersY(y); }
   void  drawSpaceShip(const Interface *pUI)  const {
      drawShip(pos, angle, pUI->isUp());
   }
   bool getIsShip() { return isShip; }
   void moveShip(double time, const Interface* pUI);
   void satelliteInput(const Interface * pUI);
};


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
   //bool isShip = true;
   //Type type = SHIP;
   //Status status = BROKEN;


public:

   Ship() {  }
   Ship(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y); type = SHIP;
   }
   void  drawSpaceShip(const Interface *pUI)  const {
      drawShip(pos, angle, pUI->isUp());
   }
   //bool getIsShip() { return isShip; }
   void moveShip(double time, const Interface* pUI);
   void satelliteInput(const Interface * pUI, list<Satellite*> &pSatellites);
};


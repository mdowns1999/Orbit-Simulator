/***********************************************************************
 * Header File:
 *    Ship : A type of Satellite that the user controls
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *  A type of Satellite that the user controls and uses to shoot down
 *  broken satellites.
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h" // for INTERFACE

/***********************************************************************
 * SHIP
 * This is a type of satellite that the user will control
 ************************************************************************/
class Ship : public Satellite
{
public:

   Ship() {  }
   Ship(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y); type = SHIP;}

   void  drawSpaceShip(const Interface *pUI)  const {drawShip(pos, angle, pUI->isUp()); }
   void moveShip(double time, const Interface* pUI);
   void satelliteInput(const Interface * pUI, list<Satellite*> &satellites);
};


/***********************************************************************
 * Source File:
 *    Ship
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is a ship that the user controls.
 ************************************************************************/

#include "ship.h"

void Ship::satelliteInput(const Interface * pUI)
{

 // move by a little
    //  if (pUI->isUp())
    //     pos.addPixelsY(1.0);
    //  if (pUI->isDown())
    //     pos.addPixelsY(-1.0);
    if (pUI->isLeft())
       angle -= 0.1;
    if (pUI->isRight())
       angle += 0.1;
}

void Ship::moveShip(double time, const Interface* pUI)
{
    Acceleration accel;
   
   
      //pos.addPixelsY(2.0);
    

      
      // Compute physicss
      double gravity = gravityDirection(pos.getMetersX(), pos.getMetersY());

      double height = computeHeightAboveEarth(pos.getMetersX(), pos.getMetersY());

      double gHeight = gravityHeight(height);

      accel.setDDX(accel.computeHorizontalComp(gravity, gHeight));
      accel.setDDY(accel.computeVerticalComp(gravity, gHeight));


      if (pUI->isUp()){
        accel.setDDX(accel.getDDX() + accel.computeHorizontalComp(angle, 1.5));
        accel.setDDY(accel.getDDY()  + accel.computeVerticalComp(angle, 1.5));
      }

      velocity.updateVelocity(accel, time);

      pos.setMetersX(distanceFormula(pos.getMetersX(), velocity.getDX(), accel.getDDX(), time));
      pos.setMetersY(distanceFormula(pos.getMetersY(), velocity.getDY(), accel.getDDY(), time));
   
}
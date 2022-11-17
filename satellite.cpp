/***********************************************************************
 * Source File:
 *    Satellite
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is is the parent class for all the different satellites
 ************************************************************************/
#include "satellite.h"
#include "fragment.h"



void Satellite::spawnFragments(vector<Satellite> &satellites)
{
   Fragment fragment1(pos.getMetersX()      , pos.getMetersY() + 10 );
   Fragment fragment2(pos.getMetersX() + 10 , pos.getMetersY()      );
   Fragment fragment3(pos.getMetersX()      , pos.getMetersY() - 10 );

   satellites.push_back(fragment1);
   satellites.push_back(fragment2);
   satellites.push_back(fragment3);


}


void Satellite::move(double time)
{  

   Acceleration accel;
   // Compute physics
   double gravity = gravityDirection(pos.getMetersX(), pos.getMetersY());

   double height = computeHeightAboveEarth(pos.getMetersX(), pos.getMetersY());

   double gHeight = gravityHeight(height);

   accel.setDDX(accel.computeHorizontalComp(gravity, gHeight));
   accel.setDDY(accel.computeVerticalComp(gravity, gHeight));


   velocity.updateVelocity(accel, time);
 
   pos.setMetersX(distanceFormula(pos.getMetersX(), velocity.getDX(), accel.getDDX(), time));
   pos.setMetersY(distanceFormula(pos.getMetersY(), velocity.getDY(), accel.getDDY(), time));

}

// void Satellite::input(Interface ui)
// {
    
// }
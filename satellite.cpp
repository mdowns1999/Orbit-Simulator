/***********************************************************************
 * Source File:
 *    Satellite
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 *    This is is the parent class for all the different satellites
 ************************************************************************/
#include "satellite.h"



void Satellite::destroy(vector<Satellite>& satellites, vector<Satellite>& decay)
{

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
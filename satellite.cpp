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


void Satellite::updateDecayTime()
{
   decayTime -= 1;

   if (decayTime <= 0)
   {
      //dead = true;
   }
}

void Satellite::spawnFragments(list<Satellite*>& pSatellites)
{
   //cout << "SPAWN" << endl;
   Fragment*  pFragment1 = new Fragment(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + 3000000 + random(-6000000.0, 6000000.0));
   
   Fragment*  pFragment2 = new Fragment(pos.getMetersX() + 3000000 + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));
   Fragment*  pFragment3 = new Fragment(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() - 3000000 + random(-6000000.0, 6000000.0));

   pSatellites.push_back(pFragment1);
   //cout << "Spawned" << endl;
   pSatellites.push_back(pFragment2);
   pSatellites.push_back(pFragment3);
}


void Satellite::move(double time)
{  

   Acceleration accel;
   // Compute physicss
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
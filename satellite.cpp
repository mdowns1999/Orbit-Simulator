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
#include "projectile.h"

/*********************************************
* SPAWN FRAGMENTS
* Spawn the fragments of the broken satellite
**********************************************/
void Satellite::spawnFragments(list<Satellite*>& pSatellites)
{
   Fragment*  pFragment1 = new Fragment(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + 3000000 + random(-6000000.0, 6000000.0));
   Velocity fragmentVel(velocity);
   pFragment1->setVelocity(fragmentVel);

   pSatellites.push_back(pFragment1);

}

/*********************************************
* SPAWN PROJECTILE
* Spawn the projectile of ship
**********************************************/
void Satellite::spawnProjectile(list<Satellite*>& pSatellites)
{
   //Step 1: Set Bullet to Ship Position
   Projectile* pProjectile = new Projectile(pos.getMetersX(), pos.getMetersY());

   //Step 2: Give Velocity
   Velocity projectileVel;
   projectileVel.setVelocity(angle, 50000.0);
   projectileVel.addVelocity(velocity);
   pProjectile->setVelocity(projectileVel);
   pProjectile->move(100);

   
   pSatellites.push_back(pProjectile);

}

/*********************************************
* MOVE
* Move the Satellite with the equations
**********************************************/
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
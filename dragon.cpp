/***********************************************************************
 * Source File:
 *    Dragon
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 *  A type of satellite
 ************************************************************************/

#include "dragon.h"

 /***************************************
 * NON DEFAULT CONSTRUCTOR
 * Set up the satellites position and
 * velocity.
 ****************************************/
Dragon::Dragon(double x, double y, double dx, double dy) 
{ 
   pos.setMetersX(x);  
   pos.setMetersY(y); 
   velocity.setDX(dx); 
   velocity.setDY(dy); 
}


/***************************************
* SPAWN PARTS
* Spawn the parts of the broken satellite
****************************************/
void Dragon::spawnParts(list<Satellite*>& pSatellites)
{
    DragonCenter*  pDragonCenter = new DragonCenter(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    DragonLeft*    pDragonLeft   = new DragonLeft(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    DragonRight*   pDragonRight  = new DragonRight(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

    pSatellites.push_back(pDragonCenter);
    pSatellites.push_back(pDragonLeft);
    pSatellites.push_back(pDragonRight);
}
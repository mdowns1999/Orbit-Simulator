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
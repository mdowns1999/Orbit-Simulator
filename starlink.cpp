/***********************************************************************
 * Source File:
 *    StarLink
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 * A type of satellite
 ************************************************************************/

#include "starlink.h"

/***************************************
* SPAWN PARTS
* Spawn the parts of the broken satellite
****************************************/
void Starlink::spawnParts(list<Satellite*>& pSatellites)
{
    StarlinkArray*  pStarlinkArray = new StarlinkArray(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    StarlinkBody*   pStarlinkBody  = new StarlinkBody(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

    pSatellites.push_back(pStarlinkArray);
    pSatellites.push_back(pStarlinkBody);
}
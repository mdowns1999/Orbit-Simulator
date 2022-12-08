/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 * A type of satellite
 ************************************************************************/

#include "hubble.h"

 /***************************************
 * NON DEFAULT CONSTRUCTOR
 * Set up the satellites position and
 * velocity.
 ****************************************/
Hubble::Hubble(double x, double y, double dx, double dy) 
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
void Hubble::spawnParts(list<Satellite*>& pSatellites)
{
    HubbleComputer*   pHubbleComputer  = new HubbleComputer(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    HubbleTelescope*  pHubbleTelescope = new HubbleTelescope(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    HubbleRight*      pHubbleRight     = new HubbleRight(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    HubbleLeft*       pHubbleLeft      = new HubbleLeft(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

    pSatellites.push_back(pHubbleComputer);
    pSatellites.push_back(pHubbleTelescope);
    pSatellites.push_back(pHubbleRight);
    pSatellites.push_back(pHubbleLeft);
}
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
 * SPAWN PARTS
 * Spawn the parts of the broken satellite
 ****************************************/
void Hubble::spawnParts(list<Satellite*>& pSatellites)
{
    HubbleComputer*  pHubbleComputer = new HubbleComputer(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0));
    HubbleTelescope*  pHubbleTelescope= new HubbleTelescope(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));
    HubbleRight*  pHubbleRight = new HubbleRight(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));
    HubbleLeft*  pHubbleLeft = new HubbleLeft(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));


    Velocity hubbleComputerVel(velocity);
    pHubbleComputer->setVelocity(hubbleComputerVel);  

    Velocity hubbleTelescoprVel(velocity);
    pHubbleTelescope->setVelocity(hubbleTelescoprVel);  

    Velocity hubbleRightVel(velocity);
    pHubbleRight->setVelocity(hubbleRightVel);  

    Velocity hubbleLeftVel(velocity);
    pHubbleLeft->setVelocity(hubbleLeftVel);  

    pSatellites.push_back(pHubbleComputer);
    pSatellites.push_back(pHubbleTelescope);
    pSatellites.push_back(pHubbleRight);
    pSatellites.push_back(pHubbleLeft);
}
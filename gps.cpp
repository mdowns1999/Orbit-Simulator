/***********************************************************************
 * Source File:
 *    GPS
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 * A type of satellite
 ************************************************************************/

#include "gps.h"

/***************************************
* SPAWN PARTS
* Spawn the parts of the broken satellite
****************************************/
void GPS::spawnParts(list<Satellite*>& pSatellites)
{
    GPSCenter*  pGPSCenter = new GPSCenter(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0));
    GPSRight*  pGPSRight= new GPSRight(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));
    GPSLeft*  pGPSLeft = new GPSLeft(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0));

    Velocity gpsCenterVel(velocity);
    pGPSCenter->setVelocity(gpsCenterVel);
    Velocity gpsRightVel(velocity);
    pGPSRight->setVelocity(gpsRightVel);
    Velocity gpsLeftVel(velocity);
    pGPSLeft->setVelocity(gpsLeftVel);


    pSatellites.push_back(pGPSCenter);
    pSatellites.push_back(pGPSRight);
    pSatellites.push_back(pGPSLeft);
}
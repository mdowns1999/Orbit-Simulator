/***********************************************************************
 * Header File:
 *    Game
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Where all the satellites are initiallized
 ************************************************************************/

#pragma once
#include "uiDraw.h"       // for RANDOM and DRAW*
#include "uiInteract.h"
#include "position.h"
#include "gps.h"
#include "hubble.h"
#include "sputnik.h"
#include "starlink.h"
#include "dragon.h"
#include "star.h"
#include "ship.h"
#include "physics.h"
#include <list>

class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      Ship* pShip = new Ship(-36515095.13, 42164000.0);
      Hubble* pHubble = new Hubble(0.0, -42164000.0);
      Sputnik* pSputnik = new Sputnik(-36515095.13, 21082000.0);
      Starlink* pStarlink = new Starlink(0.0, -13020000.0);
      Dragon* pDragon = new Dragon(0.0, 8000000.0);
      GPS* pGPS1 = new GPS(0.0, 26560000.0);
      GPS* pGPS2 = new GPS(23001634.72, 13280000.0);
      GPS* pGPS3 = new GPS(23001634.72, -13280000.0);
      GPS* pGPS4 = new GPS(0.0, -26560000.0);
      GPS* pGPS5 = new GPS(-23001634.72, -13280000.0);
      GPS* pGPS6 = new GPS(-23001634.72, 13280000.0);

      Velocity HubbleVel(3100.0, 0.0);
      Velocity SputnikVel(2050.0, 2684.68);
      Velocity StarlinkVel(5800.0, 0.0); 
      Velocity DragonVel(-7900.0, 0.0);
      Velocity gpsVel1(-3880.0, 0.0);
      Velocity gpsVel2(-1940.00, 3360.18);
      Velocity gpsVel3(1940.00, 3360.18);
      Velocity gpsVel4(3880.0, 0.0);
      Velocity gpsVel5(1940.00, -3360.18);
      Velocity gpsVel6(-1940.00, -3360.18);

      pHubble->setVelocity(HubbleVel);
      pSputnik->setVelocity(SputnikVel);
      pStarlink->setVelocity(StarlinkVel);
      pDragon->setVelocity(DragonVel);
      pGPS1->setVelocity(gpsVel1);
      pGPS2->setVelocity(gpsVel2);
      pGPS3->setVelocity(gpsVel3);
      pGPS4->setVelocity(gpsVel4);
      pGPS5->setVelocity(gpsVel5);
      pGPS6->setVelocity(gpsVel6);
      pSatellites.push_back(pShip);
      pSatellites.push_back(pGPS1);
      pSatellites.push_back(pGPS2);
      pSatellites.push_back(pGPS3);
      pSatellites.push_back(pGPS4);
      pSatellites.push_back(pGPS5);
      pSatellites.push_back(pGPS6);
      pSatellites.push_back(pHubble);
      pSatellites.push_back(pSputnik);
      pSatellites.push_back(pStarlink);
      //pSatellites.push_back(pDragon);
      angleEarth = 0.0;
      for (int i = 0; i < 200; i++)
      {
         Position ptStar(random(-60000000.0, 60000000.0), random(-60000000.0, 60000000.0));
         phaseStar = random(1, 224);
         Star* pStar = new Star(ptStar, phaseStar);
         pStars [i] = pStar;
         //cout << "I: " << i << endl;
      }

      //int size = sizeof(pStars) / sizeof(Star*);
      //cout << "Size: " << size << endl;
      
   }

   

   //General Game Methods
   void input(  const Interface* pUI);
   void update( const Interface* pUI);
   void display(const Interface* pUI);
   void collision();
   void destroy();

   Star star;

   //Set Positions
   Position ptUpperRight;
   Position ptEarth;
   

   //Set up a List of Satellites
   list<Satellite *> pSatellites;

   Star* pStars[200];
   

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
   int timeToBreak = 0;

   double x;
   double y;
   double dx;
   double dy;
   double height;
   double gHeight;
};


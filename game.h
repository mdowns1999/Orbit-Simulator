/***********************************************************************
 * Header File:
 *    Game
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#pragma once
#include "uiDraw.h"       // for RANDOM and DRAW*
#include "uiInteract.h"
#include "position.h"
#include "gps.h"
#include "star.h"
#include <vector>

/*************************************************************************
 * Game
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      GPS* pGPS1 = new GPS(0.0, 32164000.0);
      GPS* pGPS2 = new GPS(0.0, -32164000.0);
      Velocity vel1(-3100.0, 0.0);
      Velocity vel2(3100.0, 0.0);
      pGPS1->setVelocity(vel1);
      pGPS2->setVelocity(vel2);
      pSatellites.push_back(pGPS1);
      pSatellites.push_back(pGPS2);
      angleEarth = 0.0;
      for (int i = 0; i < 200; i++)
      {
         Position ptStar(random(-60000000.0, 60000000.0), random(-60000000.0, 60000000.0));
         //Position ptStar(0.0, 0.0);
         phaseStar = random(1, 224);
         Star* pStar = new Star(ptStar, phaseStar);
         pStars [i] = pStar;
         cout << "I: " << i << endl;
      }

      int size = sizeof(pStars) / sizeof(Star*);
      cout << "Size: " << size << endl;
      
   }

   

   //General Game Methods
   void input();
   void update();
   void display();
   void collision();

   Star star;

   //Set Positions
   Position ptUpperRight;
   Position ptEarth;
   

   //Set up a Vector of Satellites
   vector<Satellite *> pSatellites;
   //vector<Star *> pStars;
   Star* pStars[200];

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;

   double x;
   double y;
   double dx;
   double dy;
   double height;
   double gHeight;
};


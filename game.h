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
      
      //GPSpt.setMeters(0.0, 6378000.0);
      //ptGPS.setMeters(0.0, 42164000.0);

      //ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      //GPSpt.setPixelsX(1);
     // GPSpt.setPixelsY(1);
      GPSpt.setMetersX(0.0);
      GPSpt.setMetersY(35786000.0);
      //GPS gps(0.0, 35786000.0);
      gps.setPosition(GPSpt);
      //angleShip = 0.0;
      angleEarth = 0.0;
      //phaseStar = 0;
      //x = ptGPS.getMetersX();
      //y = ptGPS.getMetersY();
      //dx = -3100.0;
      //dy = 0.0;
   }

   

   //General Game Methods
   void input();
   void update();
   void display();
   void collision();


   //Position ptHubble;
   //Position ptSputnik;
   //Position ptStarlink;
   //Position ptCrewDragon;
   //Position ptShip;
   //Position ptGPS;
   //Position ptStar;
   Position ptUpperRight;
   //Position ptGPS;
   //Earth earth;
   GPS gps;
   Position GPSpt;

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


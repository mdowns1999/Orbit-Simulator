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
//#include "earth.h"
//class Game
//{
//   //Member Variables
//   
//   
//   //Constructor
//   Game();
//
//   //General Game Functions
//   //void input();
//   //void update();
//   //void display();
//   //void collision();
//};




/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      //ptGPS.setMeters(0.0, 42164000.0);

      //ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

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
   //Earth earth;

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

/***********************************************************************
 * Header File:
 *    Game
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Where all the satellites are initiallized and the game is updated. Here
 * We will also detect any collision and destroy any gragments after a 
 * certain amount of time.
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
   Game(Position ptUpperRight);

   //General Game Methods
   void input(  const Interface* pUI);
   void update( const Interface* pUI);
   void display(const Interface* pUI);
   void collision();
   void destroy();

   //Set up types
   enum Status { ALIVE, DEAD, BROKEN };
   enum Type { SHIP, SATELLITE, PART, DECAYABLE };

   //Set Positions
   Position ptUpperRight;
   Position ptEarth;

   //Set up Star Object
   Star star;
   
   //Set up a List of Satellites and Stars
   list<Satellite *> pSatellites;
   Star* pStars[200];
   
   //Variables
   unsigned char phaseStar;
   double angleEarth = 0.0;
   int timeToBreak = 0;

   //Private methods that allow Game to update Everything
private:
   void moveSatellites(const Interface* pUI);
   void updateStars();
   void updateEarthAngle();
   void breakSatellite();
   void spinBrokenSatellite();
   void updateDecayTime();
};


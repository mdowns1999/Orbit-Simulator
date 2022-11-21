/***********************************************************************
 * Source File:
 *    Game
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#include "game.h"
void Game::update()
{
   Position pt;

   angleEarth -= 0.01;

}

void Game::display()
{
   Position pt;
   Position pt2;

   // draw the earth
    //earth.displayEarth(angleEarth);

   pt.setMeters(0.0, 0.0);
   drawEarth(pt, angleEarth);

   gps.draw();
   
 

}


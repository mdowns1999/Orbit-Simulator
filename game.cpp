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
   for (auto sat : pSatellites)
   {
     sat->move(48);
   }

   angleEarth -= 0.01;
   
   for (int star = 0; star < 200; star++)
   {
      pStars[star]->updatePhase();
   }

}

void Game::display()
{
   // draw the earth
   ptEarth.setMeters(0.0, 0.0);
    

   //Draw Satellites
   for (auto sat : pSatellites)
   {
     sat->draw();
   }

   //Draw Stars
   for (int star = 0; star < 200; star++)
   {
      pStars[star]->drawStars();
   }
   //Draw Earth
   drawEarth(ptEarth, angleEarth);


  
 

}


/***********************************************************************
 * Source File:
 *    Game
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#include "game.h"
#include "cassert"

/***************************************
* INPUT
* Get User Input to move the ship
****************************************/
void Game::input(const Interface* pUI)
{
      pSatellites.front()->satelliteInput(pUI, pSatellites);
}

/***************************************
* UPDATE
* This will update all the objects of the
* Game.
****************************************/
void Game::update(const Interface* pUI)
{
   
   collision();
   destroy();

   //Move Satellites
   for (auto sat : pSatellites)
   {

      if (!sat->getIsShip())
      {
         sat->move(48);
      }
      else
      {
         sat->moveShip(48, pUI);
      }
          
   }

   //Update Angle of Earth
   angleEarth -= 0.01;
   
   //Update Stars
   for (int star = 0; star < 200; star++)
   {
      pStars[star]->updatePhase();
   }

   //Randomly break a Satellite
   if (timeToBreak > 100)
   {
      double randomPosition = random(0, pSatellites.size());

      list<Satellite*>::iterator it = pSatellites.begin();
      advance(it, randomPosition);
      if (!(*it)->getIsShip() && !(*it)->doesDecay())
      {
         (*it)->setBroken();

         timeToBreak = 0;
      }
   }
   else
   {
      timeToBreak++;
   }

   //Spin Broken Parts and Update Decay Time
   for (auto sat : pSatellites)
   {
      if (sat->isBroken())
      {
         sat->updateAngle();
      }

   }

   for (auto it = pSatellites.begin(); it != pSatellites.end(); )
   {
      if ((*it)->doesDecay())
      {
         
         if ((*it)->getDecayTime() == 0)
         {
            (*it)->setDead();
         }
         else
         {
            (*it)->updateDecayTime();
         }
      }
      ++it; 
   }
}

/***************************************
* DISPLAY
* Display everything to the user.
****************************************/
void Game::display(const Interface* pUI)
{
   // Set the Earths Position
   ptEarth.setMeters(0.0, 0.0);

   //Draw Earth
   drawEarth(ptEarth, angleEarth);
    
   //Draw Satellites
   for (auto sat : pSatellites)
   {
      if (!sat->getIsShip())
      {
         sat->draw();
      }
      else
      {
         sat->drawSpaceShip(pUI);
      }
   }

   //Draw Stars
   for (int star = 0; star < 200; star++)
   {
      pStars[star]->drawStars();
   }
}

/***************************************
* COLLISION
* This will update all the objects of the
* Game.
****************************************/
void Game::collision()
{
   for (auto sat : pSatellites)
   {
      if (computeHeightAboveEarth(sat->getPosition().getMetersX(), sat->getPosition().getMetersY()) < 0.0)
         {
            //cout << "HIT!!!!!!!!!!!!!!!!" << endl;
            sat->setDead();
         }

      //If we hit other Floating Objects
      for (auto sat2 : pSatellites)
      {
         if (sat != sat2 && computeDistance(sat->getPosition(), sat2->getPosition()) < 3000000.0)
         {
            //Set the Collided Satellites as Dead
            sat->setDead();          
            sat2->setDead();
         }
      }
   }
}

/***************************************
* DESTROY
* This will delete the pointers to the 
* satellites and the satellites themselves 
* from the list when needed.
****************************************/
void Game::destroy()
{

   for (auto it = pSatellites.begin(); it!= pSatellites.end(); )
   {
      if ((*it)->isDead())
      {
         /*Satellite* child = *it;
         delete child;*/
         if (!(*it)->doesDecay())
         {
            //cout << "SPAWN" << endl;
            (*it)->spawnFragments(pSatellites);
            (*it)->spawnParts(pSatellites);
         }
         delete* it;
         it = pSatellites.erase(it);
      }
      else
         ++it;
   }
}
      

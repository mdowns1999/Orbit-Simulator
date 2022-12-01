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


void Game::input(const Interface* pUI)
{
   // list<Satellite*>::iterator it;

   // //for (myitr = l.begin(); myitr != l.end(); ++myitr)
   // //for (it = pSatellites.begin(); it != pSatellites.begin(); ++it) {
   //    (*it)->getIsShip();

      pSatellites.front()->satelliteInput(pUI);
}
   
//}


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
      cout << randomPosition << endl;

      list<Satellite*>::iterator it = pSatellites.begin();
      advance(it, randomPosition);
      if (!(*it)->getIsShip() && !(*it)->doesDecay())
      {
         (*it)->setBroken();

         //cout << (*it)->isBroken() << endl;

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

   //for (auto it = pSatellites.begin(); it != pSatellites.end(); )
   //{
   //   if ((*it)->getDecayTime() == 0)
   //   {
   //      delete* it;
   //      it = pSatellites.erase(it);
   //   }
   //   else
   //   {
   //      ++it;
   //      if ((*it)->doesDecay())
   //      {
   //         (*it)->updateDecayTime();
   //      }
   //   }
   //}
  

}

void Game::display(const Interface* pUI)
{
   // draw the earth
   ptEarth.setMeters(0.0, 0.0);
    

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
   //Draw Earth
   drawEarth(ptEarth, angleEarth);

}

void Game::collision()
{
         //cout << "SHIP: " << pSatellites[0]->getPosition() << endl;
         //cout << "GPS 1: " << pSatellites[1]->getPosition() << endl;
         
         //cout << "DISTANCE:  " << computeDistance(pSatellites[0]->getPosition(), pSatellites[1]->getPosition()) << endl;
         //computeDistance(pSatellites[0]->getPosition(), ptEarth) < 3500000.0

         //cout << "DISTANCE: " << i << " " << computeDistance(pSatellites[i]->getPosition(), pSatellites[j]->getPosition()) << endl;
         // if (computeDistance(pSatellites[i]->getPosition(), pSatellites[j]->getPosition()) < 1000.0)
         // {
         //    cout << "HIT!!!!!!!!!!!!!!!!" << endl;
         // }

   //vector<Satellite *>::iterator i;
         
   //for (i = pSatellites.begin(); i != pSatellites.end(); i++)
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
            cout << "HIT!!!!!!!!!!!!!!!!" << endl;
            sat->setDead();
            
            sat2->setDead();

            
            //assert(false);
            
            
         }
      }
   }
}


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
            cout << "SPAWN" << endl;
            (*it)->spawnFragments(pSatellites);
         }

         delete* it;
         it = pSatellites.erase(it);
         

      }
      else
         ++it;
   }


   
}
      

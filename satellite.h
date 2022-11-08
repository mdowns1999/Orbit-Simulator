/***********************************************************************
 * Header File:
 *    Satellite : A object that floats in space
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    A object that floats in space
 ************************************************************************/
#pragma once
#include "position.h"
#include "uiInteract.h"


class Satellite
{
   // For the Unit Tests
   friend testSatellite;

private:
   //ADD VELOCITY
   Position pos;
   // ADD DIRECTION
   float angularVelocity;
   bool dead;
   float radius;

public:
   //Methods
   Satellite();
   float getRadius();
   bool isDead();
   Position getPosition();
   void kill();
   void draw();
   void destroy(Satellite satellites);
   void move(float time);
   void input(Interface ui);

};


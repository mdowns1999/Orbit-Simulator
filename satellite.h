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
#include <iostream>
#include <vector>
using namespace std;

class Satellite
{
   // For the Unit Tests
   friend class testSatellite;
   friend class DummySatellite;
   friend class StubSatellite;

private:
   //ADD VELOCITY
   Position pos;
   // ADD DIRECTION
   float angularVelocity;
   bool dead;
   float radius;

public:
   //Methods
   Satellite(){}
   float getRadius() { return radius; }
   bool isDead() { return dead; }
   Position getPosition() { return pos; }
   virtual void draw(){};
   void destroy(vector<Satellite> &satellites, vector<Satellite> &decay);
   void move(float time);
   //void input(Interface ui);

};


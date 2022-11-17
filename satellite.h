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
#include "Velocity.h"
#include "angle.h"
#include "physic.h"
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
   Velocity velocity;

public:
   //Methods
   Satellite(){}
   virtual float getRadius() { return radius; }
   virtual bool isDead() { return dead; }
   virtual Position getPosition() { return pos; }
   virtual void draw(){};
   virtual void destroy(vector<Satellite> &satellites, vector<Satellite> &decay);
   virtual void move(double time);
   //void input(Interface ui);

};


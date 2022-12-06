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
#include "physics.h"
#include <iostream>
#include <list>
using namespace std;

class Satellite
{
   // For the Unit Tests
   friend class testSatellite;
   friend class DummySatellite;
   friend class StubSatellite;

protected:
   Position pos;
   // ADD DIRECTION
   double angularVelocity;
   bool dead = false;
   bool broken = false;
   double radius;
   Velocity velocity;
   double decayTime = 0.0;
   double angle = 0.1;
   bool isShip = false;
   bool canDecay = false;

public:
   //Methods
   Satellite(){}
   Satellite(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y);}
   Satellite(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   virtual double getRadius()    { return radius; }
   virtual bool isDead()         { return dead; }
   virtual void setDead()        {  dead = true; }
   virtual bool isBroken() { return broken; }
   virtual void setBroken() { broken = true; }
   virtual Position getPosition(){ return pos; }
   virtual void setPosition(Position position) { pos = position; }
   virtual void setVelocity(Velocity vel) { velocity = vel;}
   virtual bool getIsShip()      { return isShip;}
   virtual bool doesDecay()      { return canDecay;}
   virtual bool updateAngle() { return angle+= 25; }
   virtual double getDecayTime() { return decayTime; }
   virtual void updateDecayTime() {decayTime--; }

   

   virtual void satelliteInput(const Interface* pUI, list<Satellite*> &pSatellites) {}

   virtual void draw() const {}
   virtual void drawSpaceShip(const Interface *pUI) const {}
   virtual void spawnFragments(list<Satellite*>& pSatellites);
   virtual void spawnProjectile(list<Satellite*>& pSatellites);
   virtual void spawnParts(list<Satellite*>& pSatellites) {}
   virtual void move(double time);
   virtual void moveShip(double time, const Interface* pUI){}

};


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
   double angularVelocity;
   double radius;
   Velocity velocity;
   double decayTime = 0.0;
   double angle = 0.1;
   enum Status { ALIVE, DEAD, BROKEN };
   enum Type { SHIP, SATELLITE, PART, DECAYABLE };
   Status status = ALIVE;
   Type type = SATELLITE;

public:
   // Methods
   Satellite(){}
   Satellite(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y);}
   Satellite(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   // Getters
   Status getStatus()      { return status; }
   Type getType()          { return type; }
   Position getPosition()  { return pos; }
   double getRadius()      { return radius; }
   double getDecayTime()   { return decayTime; }

   // Setters
   void setDeadStatus() { status = DEAD; }
   void setBrokenStatus() { status = BROKEN; }
   void setPosition(Position position) { pos = position; }
   void setVelocity(Velocity vel) { velocity = vel;}

   // Update
   bool updateAngle() { return angle+= 25; }
   void updateDecayTime() {decayTime--; }
   virtual void satelliteInput(const Interface* pUI, list<Satellite*> &pSatellites) {}

   // Draw
   virtual void draw() const {}
   virtual void drawSpaceShip(const Interface *pUI) const {}

   // Spawn
   virtual void spawnFragments(list<Satellite*>& pSatellites);
   virtual void spawnProjectile(list<Satellite*>& pSatellites);
   virtual void spawnParts(list<Satellite*>& pSatellites) {}

   // Mov
   virtual void move(double time);
   virtual void moveShip(double time, const Interface* pUI){}

};


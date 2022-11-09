/***********************************************************************
* Header File:
*    Test Satallite : Test the Satellite class
* Author:
*   Ben, Star, and Mike
* Summary:
*    All the unit tests for Satellite
************************************************************************/

#pragma once

#include <iostream>
#include "cassert"
#include "satellite.h"
#include <vector>
using namespace std;

class DummySatellite : public Satellite
{
public:
   DummySatellite() {}
   float getRadius() { assert(false); return 0.0; }
   bool isDead() { assert(false); return false; }
   Position getPosition() { assert(false); Position pos; return pos; }
   void draw() { assert(false); }
   void destroy(vector<DummySatellite>& satellites, vector<DummySatellite>& decay) { assert(false); }
   void move(float time) { assert(false); }
   void input(Interface ui) { assert(false); }
};

class StubSatellite : public DummySatellite
{
public:
   StubSatellite(){}
   float getRadius() { return 2.0; }
   bool isDead() { return dead; }
   Position getPosition() { Position pos; return pos; }
   void destroy(vector<StubSatellite>& satellites, vector<StubSatellite>& decay);
};





class testSatellite
{
public:
   void run()
   {
      isDeadTest_True();
      isDeadTest_False();
      getRadiusTest();
      getPositionTest();
      moveTestFallDown();
      moveTestFallUp();
      moveTestFallRight();
      moveTestFallLeft();
      destroyTest();
      inputTest();

   }


private:

    void isDeadTest_False() 
   {
        // setup
       Satellite satellite;
       satellite.dead = false;
       bool deathStatus;
       // exercise
       deathStatus = satellite.isDead();
       // verify
       assert(deathStatus == false);
   }   // teardown

   void isDeadTest_True() const
   {
        // setup
       Satellite  satellite;
       satellite.dead = true;
       bool deathStatus;
       // exercise
       deathStatus = satellite.isDead();
       // verify
       assert(deathStatus == true);
   }   // teardown

    void getRadiusTest() const
    {
      // setup
      Satellite satellite;
      satellite.radius = 2.5;
      double satelliteRadius;
      // exercise
      satelliteRadius = satellite.getRadius();
      // verify
      assert(satelliteRadius == 2.5);
    }   // teardown

    void getPositionTest() const
    {
      // setup
      Satellite satellite;
      Position position(100.0, 100.0);
      satellite.pos = position;
      Position testPos;
      // exercise
      testPos = satellite.getPosition();
      // verify
      assert(testPos.getMetersX() == 100.0);
      assert(testPos.getMetersY() == 100.0);
    }   // teardown

    void moveTestFallDown() const
    {
      // setup
      Satellite satellite;
      Position newPosition(0.0, 6378000.0);
      Velocity vel(0.0, 0.0);
      satellite.pos = newPosition;
      satellite.velocity = vel;
      double time = 48;
      // exercise
      satellite.move(time);
      // verify
      assert(satellite.pos.getMetersX() == 0.0);
      assert(satellite.pos.getMetersY() == 6377990.2);
      assert(satellite.velocity.getDX() == 0.0);
      assert(satellite.velocity.getDY() == -9.8);
    }   // teardown

    void moveTestFallUp() const
    {
       // setup
       Satellite satellite;
       Position newPosition(0.0, -6378000.0);
       Velocity vel(0.0, 0.0);
       satellite.pos = newPosition;
       satellite.velocity = vel;
       double time = 48;
       // exercise
       satellite.move(time);
       // verify
       assert(satellite.pos.getMetersX() == 0.0);
       assert(satellite.pos.getMetersY() == -6377990.2);
       assert(satellite.velocity.getDX() == 0.0);
       assert(satellite.velocity.getDY() == 9.8);
    }   // teardown

    void moveTestFallLeft() const
    {
      // setup
      Satellite satellite;
      Position newPosition(6378000.0, 0.0);
      Velocity vel(0.0, 0.0);
      satellite.pos = newPosition;
      satellite.velocity = vel;
      double time = 48;
      // exercise
      satellite.move(time);
      // verify
      assert(satellite.pos.getMetersY() == 0.0);
      assert(satellite.pos.getMetersX() == 6377990.2);
      assert(satellite.velocity.getDX() == -9.8);
      assert(satellite.velocity.getDY() == 0.0);
    }   // teardown

    void moveTestFallRight() const
    {
       // setup
       Satellite satellite;
       Position newPosition(-6378000.0, 0.0);
       Velocity vel(0.0, 0.0);
       satellite.pos = newPosition;
       satellite.velocity = vel;
       double time = 48;
       // exercise
       satellite.move(time);
       // verify
       assert(satellite.pos.getMetersY() == 0.0);
       assert(satellite.pos.getMetersX() == -6377990.2);
       assert(satellite.velocity.getDX() == 9.8);
       assert(satellite.velocity.getDY() == 0.0);
    }   // teardown


    void destroyTest() const
    {
      // setup
      Satellite satellite;
      vector<Satellite> satellites;
      satellites.push_back(satellite);
      vector<Satellite> decay;
      // exercise
      satellite.destroy(satellites, decay);
      // verify
      assert(satellites.size() == 0);
      assert(decay.size() == 3);
    }   // teardown

    void inputTest() const
    {
       // setup
       Satellite satellite;
       // exercise
       // verify
    }   // teardown

};

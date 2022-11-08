/***********************************************************************
* Header File:
*    Test Satallite : Test the Satellite class
* Author:
*   Ben, Star, and Mike
* Summary:
*    All the unit tests for Satellite
************************************************************************/

#pragma once
#include "cassert"
#include "satellite.h"



class testSatellite
{
public:
   void run()
   {

   }


private:

    void isDeadTest_False() const
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
       Satellite satellite;
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
        bool satelliteRadius;
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

    void killTest() const
    {
        // setup
        Satellite satellite;
        // exercise
        // verify
    }   // teardown

    void moveTest() const
    {
        // setup
        Satellite satellite;
        // exercise
        // verify
    }   // teardown

    void destroyTest() const
    {
        // setup
        Satellite satellite;
        // exercise
        // verify
    }   // teardown

    void inputTest() const
    {
        // setup
        Satellite satellite;
        // exercise
        // verify
    }   // teardown

};

class DummySatellite : public Satellite
{
   DummySatellite()                   { assert(false);}
   float getRadius()                  { assert(false); return 0.0; }
   bool isDead()                      { assert(false); return false; }
   Position getPosition()             { assert(false); Position pos; return pos;}
   void kill()                        { assert(false); }
   void draw()                        { assert(false); }
   void destroy(Satellite satellites) { assert(false); }
   void move(float time)              { assert(false); }
   void input(Interface ui)           { assert(false); }
};

class StubSatellite : public DummySatellite
{
   float getRadius()                  { return 2.0; }
   bool isDead()                      { return false; }
   Position getPosition()             { Position pos; return pos;}
};
///***********************************************************************
//* header file:
//*    test satallite : test the satellite class
//* author:
//*   ben, star, and mike
//* summary:
//*    all the unit tests for satellite
//************************************************************************/
//
//#pragma once
//
//#include <iostream>
//#include "cassert"
//#include "satellite.h"
//#include <vector>
//using namespace std;
//
//class dummysatellite : public satellite
//{
//public:
//   dummysatellite() {}
//   float getradius() { assert(false); return 0.0; }
//   bool isdead() { assert(false); return false; }
//   position getposition() { assert(false); position pos; return pos; }
//   void draw() { assert(false); }
//   void destroy(vector<dummysatellite>& satellites, vector<dummysatellite>& decay) { assert(false); }
//   void move(float time) { assert(false); }
//   void input(interface ui) { assert(false); }
//};
//
//class stubsatellite : public dummysatellite
//{
//public:
//   stubsatellite(){}
//   float getradius() { return 2.0; }
//   bool isdead() { return dead; }
//   position getposition() { position pos; return pos; }
//   void destroy(vector<stubsatellite>& satellites, vector<stubsatellite>& decay);
//};
//
//
//
//
//
//class testsatellite
//{
//public:
//   void run()
//   {
//      isdeadtest_true();
//      isdeadtest_false();
//      getradiustest();
//      getpositiontest();
//      movetestfalldown();
//      movetestfallup();
//      movetestfallright();
//      movetestfallleft();
//      destroytest();
//
//   }
//
//
//private:
//
//    void isdeadtest_false() 
//   {
//         setup
//       satellite satellite;
//       satellite.dead = false;
//       bool deathstatus;
//        exercise
//       deathstatus = satellite.isdead();
//        verify
//       assert(deathstatus == false);
//   }   // teardown
//
//   void isdeadtest_true() const
//   {
//         setup
//       satellite  satellite;
//       satellite.dead = true;
//       bool deathstatus;
//        exercise
//       deathstatus = satellite.isdead();
//        verify
//       assert(deathstatus == true);
//   }   // teardown
//
//    void getradiustest() const
//    {
//       setup
//      satellite satellite;
//      satellite.radius = 2.5;
//      double satelliteradius;
//       exercise
//      satelliteradius = satellite.getradius();
//       verify
//      assert(satelliteradius == 2.5);
//    }   // teardown
//
//    void getpositiontest() const
//    {
//       setup
//      satellite satellite;
//      position position(100.0, 100.0);
//      satellite.pos = position;
//      position testpos;
//       exercise
//      testpos = satellite.getposition();
//       verify
//      assert(testpos.getmetersx() == 100.0);
//      assert(testpos.getmetersy() == 100.0);
//    }   // teardown
//
//    void movetestfalldown() const
//    {
//       setup
//      satellite satellite;
//      position newposition(0.0, 6378000.0);
//      velocity vel(0.0, 0.0);
//      satellite.pos = newposition;
//      satellite.velocity = vel;
//      double time = 48;
//       exercise
//      satellite.move(time);
//       verify
//      assert(satellite.pos.getmetersx() == 0.0);
//      assert(satellite.pos.getmetersy() == 6377990.2);
//      assert(satellite.velocity.getdx() == 0.0);
//      assert(satellite.velocity.getdy() == -9.8);
//    }   // teardown
//
//    void movetestfallup() const
//    {
//        setup
//       satellite satellite;
//       position newposition(0.0, -6378000.0);
//       velocity vel(0.0, 0.0);
//       satellite.pos = newposition;
//       satellite.velocity = vel;
//       double time = 48;
//        exercise
//       satellite.move(time);
//        verify
//       assert(satellite.pos.getmetersx() == 0.0);
//       assert(satellite.pos.getmetersy() == -6377990.2);
//       assert(satellite.velocity.getdx() == 0.0);
//       assert(satellite.velocity.getdy() == 9.8);
//    }   // teardown
//
//    void movetestfallleft() const
//    {
//       setup
//      satellite satellite;
//      position newposition(6378000.0, 0.0);
//      velocity vel(0.0, 0.0);
//      satellite.pos = newposition;
//      satellite.velocity = vel;
//      double time = 48;
//       exercise
//      satellite.move(time);
//       verify
//      assert(satellite.pos.getmetersy() == 0.0);
//      assert(satellite.pos.getmetersx() == 6377990.2);
//      assert(satellite.velocity.getdx() == -9.8);
//      assert(satellite.velocity.getdy() == 0.0);
//    }   // teardown
//
//    void movetestfallright() const
//    {
//        setup
//       satellite satellite;
//       position newposition(-6378000.0, 0.0);
//       velocity vel(0.0, 0.0);
//       satellite.pos = newposition;
//       satellite.velocity = vel;
//       double time = 48;
//        exercise
//       satellite.move(time);
//        verify
//       assert(satellite.pos.getmetersy() == 0.0);
//       assert(satellite.pos.getmetersx() == -6377990.2);
//       assert(satellite.velocity.getdx() == 9.8);
//       assert(satellite.velocity.getdy() == 0.0);
//    }   // teardown
//
//
//    void destroytest() const
//    {
//       setup
//      satellite satellite;
//      vector<satellite> satellites;
//      satellites.push_back(satellite);
//      vector<satellite> decay;
//       exercise
//      satellite.destroy(satellites, decay);
//       verify
//      assert(satellites.size() == 0);
//      assert(decay.size() == 3);
//    }   // teardown
//};

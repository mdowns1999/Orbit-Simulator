/***********************************************************************
* Header File:
*    Test Angle : Test the Angle class
* Author:
*   Ben, Star, and Mike
* Summary:
*    All the unit tests for Angle
************************************************************************/

#pragma once

#include <iostream>
#include "cassert"
#include "angle.h"
using namespace std;


class testAngle
{
public:
   void run()
   {
    getRadiansTest();
    getDegreesTest();
    convertToRadiansTest();
    convertToDegreesTest();
    setRadiansTest();
    setDegreesTest();
    normalizeTestBelow();
    normalizeTestAbove();
   }


private:

   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }
   
    void getRadiansTest() const
   {
      // setup
      Angle angle;
      angle.angleRadians = 1.57079633;
      double radians;
      // exercise
      radians = angle.getRadians();
      // verify
      assert(radians == 1.57079633);
   }   // teardown

   void getDegreesTest() const
   {
      // setup
      Angle angle;
      angle.angleRadians = 1.57079633;
      double degrees;
      // exercise
      degrees = angle.getDegrees();
      // verify
      assert(closeEnough(90.0, degrees, 0.1));
   }   // teardown

  void convertToRadiansTest() const
   {
      // setup
      Angle angle;
      double radians;
      // exercise
      radians = angle.convertToRadians(90.0);
      // verify
      assert(closeEnough(1.57079633, radians, 0.1));
   }   // teardown

   void convertToDegreesTest() const
   {
      // setup
      Angle angle;
      double degrees;
      // exercise
      degrees = angle.convertToDegrees(1.57079633);
      // verify
      assert(closeEnough(90.0, degrees, 0.1));
   }   // teardown


   void setRadiansTest() const
   {
      // setup
      Angle angle;
      // exercise
      angle.setRadians(1.57079633);
      // verify
      assert(closeEnough(1.57079633, angle.angleRadians, 0.1));
   }   // teardown

   void setDegreesTest() const
   {
      // setup
      Angle angle;
      // exercise
      angle.setDegrees(90.0);
      // verify
      assert(closeEnough(1.57079633, angle.angleRadians, 0.1));
   }   // teardown

   void normalizeTestBelow()
   {
      // setup
      Angle angle;
      // exercise
      angle.setDegrees(-1.0);
      //degrees = angle.normalize(-1.0);
      // verify
      assert(closeEnough(359.0, angle.getDegrees(), 0.1));
   }   // teardown

   void normalizeTestAbove()
   {
      // setup
      Angle angle;
      // exercise
      angle.setDegrees(361.0);
      // verify
      assert(closeEnough(1.0, angle.getDegrees(), 0.1));
   }   // teardown
   
};

/***********************************************************************
* Header File:
*    Test Angle : Test the Angle class
* Author:
*   Ben, Star, and Mike
* Summary:
*    All the unit tests for Angle
************************************************************************/

#pragma once
#include "physics.h"
#include "cassert"


class testPhysics
{
public:
   void run()
   {

   }


private:

   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }


};

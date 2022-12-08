/***********************************************************************
 * Header File:
 *    Velocity
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Compute the Velocity for the Simulation
 ************************************************************************/

#pragma once
#include "Acceleration.h"

class Velocity
{
private:
   double dx;
   double dy;

public:

   // constructors
   Velocity() : dx(0.0), dy(0.0) {};
   Velocity(double newDx, double newDy) { dx = newDx; dy = newDy; } 


   
   Velocity& operator = (const Velocity& vel);

   // getters
   double getDX() const { return dx; }
   double getDY() const { return dy; }
   
   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void setVelocity(double angle, double speed);

   // calculation 
   double computeVelocity() const;
   double computeAngle()    const;
   void  addVelocity(Velocity vel);

   // update
   void updateVelocity(const Acceleration &accel, double time);
};


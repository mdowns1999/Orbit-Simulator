#pragma once
#include "Acceleration.h"

/***********************************************************************
 * Velocity: change in position divided by time
 ************************************************************************/
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

   // calculation 
   double computeVelocity() const;
   double computeAngle()    const;

   // update
   void updateVelocity(const Acceleration &accel, double time);
};


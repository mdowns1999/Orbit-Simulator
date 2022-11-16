#include "Velocity.h"
#include <cmath> // for sqrt
#define _USE_MATH_DEFINES
#include <math.h> 

/***********************************************************************
 * Velocity: change in position divided by time
 ************************************************************************/

/***********************************************************************
 * Velocity COMPUTE VELOCITY
 * Calculate total speed
 ************************************************************************/
// double Velocity::computeVelocity() const
// {
//     //
//    return sqrt((dx * dx) + (dy * dy));
// }

/***********************************************************************
 * Velocity COMPUTE ANGLE
 * Calculates the angle based on the velocity.
 ************************************************************************/
double Velocity::computeAngle() const
{
    //atan2(x, y) * 180 / M_PI;
   return atan2(dx, dy);
}

/***********************************************************************
 * Velocity UPDATE VELOCITY
 * Adds acceleration to the velocity
 ************************************************************************/
void Velocity::updateVelocity(const Acceleration &accel, double time)
{
   dx = (dx + accel.getDDX() * time);
   dy = (dy + accel.getDDY() * time);
}

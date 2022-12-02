/***********************************************************************
 * Header File:
 *    Physics
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * these are our standalone physics functions that we need for gravity and
 * the height above the earth.
 ************************************************************************/
#pragma once
#include <cmath>
#define _USE_MATH_DEFINES //PI
#include <math.h>
#include <iostream>
using namespace std;


//VARIABLES:
const double radius = 6378000.0;
const double gravity = -9.8067;


/*********************************************
* COMPUTE HEIGHT ABOVE EARTH
* Find the height of an object above the earth
**********************************************/
inline double computeHeightAboveEarth(double x, double y)
{
   return sqrt((x * x) + (y * y)) - radius;
}


/*********************************************
* GRAVITY HEIGHT
* The gravity based off of the height
**********************************************/
inline double gravityHeight(double height)
{
   return gravity * ((radius / (radius + height)) * (radius / (radius + height)));
}

/*********************************************
* GRAVITY DIRECTION
* Compute the direction of gravity
**********************************************/
inline double gravityDirection(double x, double y)
{
    return atan2(x,y);
}


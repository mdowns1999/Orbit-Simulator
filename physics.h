/***********************************************************************
 * Header File:
 *    Physics
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/
#pragma once
#include <cmath>
#define _USE_MATH_DEFINES //PI
#include <math.h>
#include <iostream>
using namespace std;


//VARIABLES:
 //const double TIME = 48;
//const double height = 35786000.0;
const double radius = 6378000.0;
const double gravity = -9.8067;
// double gHeight = 0.0;

// double x = 21082000.0;
// double y = 36515095.0;
// double dx = -2685.0;
// double dy = 1550.0;
// double ddx = 0.0;
// double ddy = 0.0;



 // 1: Height Above Earth
inline double computeHeightAboveEarth(double x, double y)
{
   return sqrt((x * x) + (y * y)) - radius;
}


// 2: Gravity Height
inline double gravityHeight(double height)
{
   return gravity * ((radius / (radius + height)) * (radius / (radius + height)));
}

inline double gravityDirection(double x, double y)
{
    return atan2(x,y);
}

// /***********************************************************************
//  * Velocity COMPUTE ANGLE
//  * Calculates the angle 
//  ************************************************************************/
// computeG(double x, double y) const
// {
//     //atan2(x, y) * 180 / M_PI;
//    return atan2(x, y);
// }
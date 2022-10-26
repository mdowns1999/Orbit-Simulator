#include <cmath>
#define _USE_MATH_DEFINES //PI
#include <math.h>
#include <iostream>
using namespace std;


//VARIABLES:
const double TIME = 48;
const double HEIGHT = 35786000.0;
const double RADIUS = 6378000.0;
const double GRAVITY = -9.8067;
double gHeight = 0.0;

double x = 21082000.0;
double y = 36515095.0;
double dx = -2685.0;
double dy = 1550.0;
double ddx = 0.0;
double ddy = 0.0;

//0 
/***********************************************************************
 * Velocity COMPUTE ANGLE
 * Calculates the angle based on the velocity.
 ************************************************************************/
double computeAngle(double x, double y)
{
   return atan2(x, y) * 180 / M_PI;
}
/***************************************************
* Changes an angle from degrees to radians.
****************************************************/
double convertToRadians(double degrees)
{
   return (degrees / 360.00) * (2.00 * M_PI);
}

// 1: Height Above Earth
double computeHeightAboveEarth(double x, double y)
{
   return sqrt((x * x) + (y * y)) - RADIUS;
}


// 2: Gravity Height
double gravityHeight()
{
   return GRAVITY * ((RADIUS / (RADIUS + HEIGHT)) * (RADIUS / (RADIUS + HEIGHT)));
}

// 3: Horizontal Component
/***********************************************
* COMPUTE HORIZONTAL COMPONENT
* Find the horizontal component of a velocity or acceleration.
* The equation is:
*     sin(a) = x / total
***********************************************/
double computeHorizontalComp(double angle, double gravityHeight)
{
   // Compute x componenent of acceleration
   // a is the radians from the degreesToRadians
   // total is the output of computeAcceleration
   return sin(angle) * gravityHeight;
}

// 4: Vertical Component
/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 ***********************************************/
double computeVerticalComp(double angle, double gravityHeight)
{
   // Compute y componenent of acceleration
   return (cos(angle) * gravityHeight);
}



// 5/6:


/***********************************************
* CONSTANT ACCELERATION
* Find the horizontal/vertical change of velocity.
* The equation is:
*   Horizontal:
*       dx = dx + ddx * t
*   Vertical:
*       dy = dy + ddy * t
***********************************************/
double ConstantAcceleration(double ds, double dds)
{
   return ds + (dds * TIME);
}




// 7/8: 
// s - X/Y
/***********************************************
* DISTANCE FORMULA
* Finding the new position.
* The equation is:
*   Horizontal:
*       x = x + dx * t + .5 * ddx * t^2
*   Vertical:
*       y = y + dy * t + .5 * ddy * t^2
***********************************************/
double distanceFormula(double s, double ds, double dds)
{
   return s + (ds * TIME) + (.5 * dds * (TIME * TIME));
}


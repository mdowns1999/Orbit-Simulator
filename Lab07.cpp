// /*************************************************************
//  * 1. Name:
//  *      Mike, Ben, and Star
//  * 2. Assignment Name:
//  *      Lab 07: Orbit Simulator
//  * 3. Assignment Description:
//  *      Simulate satellites orbiting the earth
//  * 4. What was the hardest part? Be as specific as possible.
//  *      Finding bugs with our equations so it could orbit the earth.
//  * 5. How long did it take for you to complete the assignment?
//  *      3.5 Hours
//  *****************************************************************/

#include <cassert>        // for ASSERT
#include "uiInteract.h"   // for INTERFACE
#include "uiDraw.h"       // for RANDOM and DRAW*
#include "position.h"     // for POINT
#include "test.h"
#include <cmath>
#define _USE_MATH_DEFINES //PI
#include <math.h>
using namespace std;



/***********************************************************************
 * Velocity COMPUTE ANGLE
 * Calculates the angle based on the velocity.
 ************************************************************************/
double computeAngle(double x, double y)
{
   return atan2(x, y) * 180 / M_PI;
}

/***************************************************
* CONVERT RADIANS
* Concert from Degrees to Radians
****************************************************/
double convertToRadians(double degrees)
{
   return (degrees / 360.00) * (2.00 * M_PI);
}

/***************************************************
* CONVERT HEIGHT ABOVE EARTH
* Find the Height above the earth.
****************************************************/
double computeHeightAboveEarth(double x, double y, double RADIUS)
{
   return sqrt((x * x) + (y * y)) - RADIUS;
}

/***********************************************
* GRAVITY HEIGHT
* Find the gravity at a give height.
***********************************************/
double gravityHeight(double RADIUS, double HEIGHT, double GRAVITY)
{
   return GRAVITY * ((RADIUS / (RADIUS + HEIGHT)) * (RADIUS / (RADIUS + HEIGHT)));
}

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


/***********************************************
* CONSTANT ACCELERATION
* Find the horizontal/vertical change of velocity.
* The equation is:
*   Horizontal:
*       dx = dx + ddx * t
*   Vertical:
*       dy = dy + ddy * t
***********************************************/
double ConstantAcceleration(double ds, double dds, double TIME)
{
   return ds + (dds * TIME);
}


/***********************************************
* DISTANCE FORMULA
* Finding the new position.
* The equation is:
*   Horizontal:
*       x = x + dx * t + .5 * ddx * t^2
*   Vertical:
*       y = y + dy * t + .5 * ddy * t^2
***********************************************/
double distanceFormula(double s, double ds, double dds, double TIME)
{
   return s + (ds * TIME) + (.5 * dds * (TIME * TIME));
}



/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      ptGPS.setMeters(0.0, 42164000.0);

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
      x = ptGPS.getMetersX();
      y = ptGPS.getMetersY();
      dx = -3100.0;
      dy = 0.0;
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;

   double x;
   double y;
   double dx;
   double dy;
   double height;
   double gHeight;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;


   //
   // perform all the game logic
   //
   const double TIME = 48;
   const double RADIUS = 6378000.0;
   const double GRAVITY = -9.8067;
   double ddx = 0;
   double ddy = 0;


   int angle = computeAngle(pDemo->x, pDemo->y);

   double radians = convertToRadians(angle);

   // Compute physics
   pDemo->height = computeHeightAboveEarth(pDemo->x, pDemo->y,RADIUS);
   pDemo->gHeight = gravityHeight(RADIUS, pDemo->height, GRAVITY);
   ddx = computeHorizontalComp(radians, pDemo->gHeight);
   ddy = computeVerticalComp(radians, pDemo->gHeight);
   pDemo->dx = ConstantAcceleration(pDemo->dx, ddx, TIME);
   pDemo->dy = ConstantAcceleration(pDemo->dy, ddy, TIME);
   pDemo->x = distanceFormula(pDemo->x, pDemo->dx, ddx, TIME);
   pDemo->y = distanceFormula(pDemo->y, pDemo->dy, ddy, TIME);

   // Set the New Meters
   pDemo->ptGPS.setMeters(pDemo->x, pDemo->y);

  
   // rotate the earth
   pDemo->angleEarth += 0.01;
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;

   drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);


   // draw a single star
   drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   //Run Unit Tests
   testRunner();

   // set everything into action
   //ui.run(callBack, &demo);

   return 0;
}


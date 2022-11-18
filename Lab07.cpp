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
#include "position.h"     // for 
#include "test.h"
#include <cmath>
#define _USE_MATH_DEFINES //PI
#include <math.h>
#include "game.h"
using namespace std;



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
   Game* pGame = (Game*)p;


   //
   // perform all the game logic
   //
   /*const double TIME = 48;
   const double RADIUS = 6378000.0;
   const double GRAVITY = -9.8067;*/
   double ddx = 0;
   double ddy = 0;


   //int angle = computeAngle(pDemo->x, pDemo->y);

   //double radians = convertToRadians(angle);

   // Compute physicss
   //pDemo->height = computeHeightAboveEarth(pDemo->x, pDemo->y,RADIUS);
   //pDemo->gHeight = gravityHeight(RADIUS, pDemo->height, GRAVITY);
   //ddx = computeHorizontalComp(radians, pDemo->gHeight);
   //ddy = computeVerticalComp(radians, pDemo->gHeight);
   //pDemo->dx = ConstantAcceleration(pDemo->dx, ddx, TIME);
   //pDemo->dy = ConstantAcceleration(pDemo->dy, ddy, TIME);
   //pDemo->x = distanceFormula(pDemo->x, pDemo->dx, ddx, TIME);
   //pDemo->y = distanceFormula(pDemo->y, pDemo->dy, ddy, TIME);

   // Set the New Meters
   //pDemo->ptGPS.setMeters(pDemo->x, pDemo->y);


   //// rotate the earth
   //pDemo->angleEarth += 0.01;
   //pDemo->angleShip += 0.02;
   //pDemo->phaseStar++;

   ////
   //// draw everything
   ////
   pGame->update();
   pGame->display();

   //Position pt;

   //drawGPS(pDemo->ptGPS, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);


   //// draw a single star
   //drawStar(pDemo->ptStar, pDemo->phaseStar);

   //// draw the earth
   //pt.setMeters(0.0, 0.0);
   //drawEarth(pt, pDemo->angleEarth);
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
      "Satellite Orbit",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Game game(ptUpperRight);

   //Run Unit Tests
   testRunner();

   // set everything into action
   ui.run(callBack, &game);

   return 0;
}



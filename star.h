/***********************************************************************
 * Header File:
 *    Star
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/
#pragma once
#include "uiDraw.h"
#include "position.h"
class Star
{
   //Member Variables
   char phase;
   Position position;

   Star();

   void reset(double width, double height);
   void drawStars();
};


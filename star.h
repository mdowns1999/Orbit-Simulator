/***********************************************************************
 * Header File:
 *    Star
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * The Stars that will shine in our game.
 ************************************************************************/
#pragma once
#include "uiDraw.h"
#include "position.h"
class Star
{
public:
   //Member Variables
   unsigned char phaseStar;
   Position position;

   Star(){};
   Star(Position position, char phase) { this->position = position; phaseStar = phase;};

   void reset(double width, double height);
   void drawStars() { drawStar(position, phaseStar); }
   void updatePhase() {phaseStar++;}
   
};


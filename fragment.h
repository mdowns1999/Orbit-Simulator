/***********************************************************************
 * Header File:
 *    Fragment
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Debrie that floats in space when satellites or parts break
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"

/***********************************************************************
 * Fragment
 * A child class of Satellite that will decay
 * after a short amount of time
 ************************************************************************/
class Fragment : public Satellite
{
public:
   //Methods
   Fragment() {}
   Fragment(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); decayTime = 50; type = DECAYABLE; }
   void draw() const { drawFragment(pos, 0.1); }

};


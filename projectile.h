/***********************************************************************
 * Header File:
 *    Projectile
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * The bullet that the ship fires.
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
 /***********************************************************************
  * Projectile
  * A child class of Satellite that will decay
  * after a short amount of time
  ************************************************************************/
class Projectile : public Satellite
{
public:
   //Methods
   Projectile() {}
   Projectile(double x, double y);
   void draw() const { drawProjectile(pos); }
};

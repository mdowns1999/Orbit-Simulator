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


class Projectile : public Satellite
{
private:
   bool canDecay = true;

public:
   //Methods
  Projectile() { decayTime = 6; }
  Projectile(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); decayTime = 20;}

   //Getters
   void draw() const { drawProjectile(pos); }
   bool doesDecay() { return canDecay; }
   double getDecayTime() { return decayTime;}
   void updateDecayTime() { cout << "DecayTime: " << decayTime << endl;  decayTime--;}

};

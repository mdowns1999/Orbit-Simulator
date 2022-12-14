/***********************************************************************
 * Source File:
 *    Projectile
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#include "projectile.h"

 /***************************************
 * NON DEFAULT CONSTRUCTOR
 * Set up the satellites position and
 * velocity.
 ****************************************/
Projectile::Projectile(double x, double y) 
{ 
   pos.setMetersX(x);  
   pos.setMetersY(y); 
   decayTime = 20; 
   type = DECAYABLE; 
}
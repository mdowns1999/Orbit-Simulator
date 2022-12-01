/***********************************************************************
 * Header File:
 *    Fragment
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"


class Fragment : public Satellite
{
    private:
    bool canDecay = true;
    
    public:
        //Methods
       Fragment() { decayTime = 10; }
        Fragment(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
        
        //Getters
        //virtual double getRadius() { return radius; }

        void draw() const { drawFragment(pos, 0.1); }
        bool doesDecay() { return canDecay;}

};


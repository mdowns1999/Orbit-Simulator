/***********************************************************************
 * Header File:
 *    Fragment
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Debrie that floats in space
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
       Fragment() { decayTime = 6; }
        Fragment(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); decayTime = 50;}
        
        //Getters
        void draw() const { drawFragment(pos, 0.1); }
        bool doesDecay() { return canDecay;}
        double getDecayTime() { return decayTime;}
        void updateDecayTime() {decayTime--;}

};


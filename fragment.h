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


class Fragment : public Satellite
{
    private:
    bool canDecay = true;
    
    public:
        //Methods
        Fragment() { decayTime = 6; }
        Fragment(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); decayTime = 50; type = DECAYABLE; }
        
        //Getters
        void draw() const { drawFragment(pos, 0.1); }

};


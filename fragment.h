#pragma once
#include "satellite.h";


class Fragment : public Satellite
{
    public:
        //Methods
        Fragment() { decayTime = 10; }
        Fragment(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
        
        //Getters
        virtual double getRadius() { return radius; }
        virtual Position getPosition() { return pos; }
        virtual bool isDead() { return dead; }
        virtual void draw(){}
        virtual void move(double time) {}

};


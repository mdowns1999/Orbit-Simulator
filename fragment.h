#pragma once
#include "satellite.h";


class Fragment : public Satellite
{
    public:
        //Methods
        Fragment(){}
        Fragment(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
        virtual float getRadius() { return radius; }
        virtual bool isDead() { return dead; }
        virtual Position getPosition() { return pos; }
        virtual void draw(){}
        virtual void move(double time) {}

};


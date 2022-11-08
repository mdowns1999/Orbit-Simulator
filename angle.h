#pragma once
#define _USE_MATH_DEFINES // pi and sqrt

#include <cmath> // pi and sqrt
#include <math.h> // floor
#include <iostream> // cout and cin

/***************************************************
* Angle Class
* Stores an angle in radians as an attribute, contains
* methods to change the angle between radians and
* degrees, display it in degrees, and normalizes it.
****************************************************/
class Angle
{
public:
    // for testing purposes
    friend class testAngle;

    // member attribute
    double angleRadians;

    // default constructor
    Angle();

    // update the angleRadians attribute
    void setRadians(double newAngle);
    void setDegrees(double newAngle);

    // return an angle in degrees
    double getDegrees() const;

    // return an angle in radians
    double getRadians() const;
    
};


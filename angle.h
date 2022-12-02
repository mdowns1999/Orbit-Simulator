/***********************************************************************
 * Header File:
 *    Angle
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Stores an angle in radians as an attribute, contains
 * methods to change the angle between radians and
 * degrees, display it in degrees, and normalizes it.
 ************************************************************************/


#pragma once
#include <cmath> // pi and sqrt
#define _USE_MATH_DEFINES // pi and sqrt
#include <math.h> // floor
#include <iostream> // cout and cin
class Angle
{
public:
    // for testing purposes
    friend class testAngle;

    // default constructor
    Angle(){};

    // update the angleRadians attribute
    void setRadians(double newAngle){ angleRadians = normalize(newAngle);}
    void setDegrees(double newAngle){ angleRadians = normalize(convertToRadians(newAngle));}

    // return an angle in degrees
    double getDegrees() {return convertToDegrees(angleRadians);}
    // return an angle in radians
    double getRadians() const{return angleRadians;}

private:
    // member attribute
    double angleRadians;

    double convertToRadians(double degree) { return (degree / 360.0) * (2.0 * M_PI); }
    double convertToDegrees(double radian) {return (radian / (2.0 * M_PI)) * 360.0;}
    double normalize(double angle)  const  {return angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI); }   
    
};


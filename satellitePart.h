/***********************************************************************
 * Header File:
 *    Satellite Part
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Where all the classes for parts of satellite are defined after they are 
 * destroyed.
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"

/***********************************************************************
 * DRAGON RIGHT
 * A part of a satellite
 ************************************************************************/
class DragonRight : public Satellite
{
public:
   DragonRight() {}
   DragonRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawCrewDragonRight(pos, angle); }
};

/***********************************************************************
 * DRAGON LEFT
 * A part of a satellite
 ************************************************************************/
class DragonLeft : public Satellite
{
public:
   DragonLeft() {}
   DragonLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawCrewDragonLeft(pos, angle); }
};

/***********************************************************************
 * DRAGON CENTER
 * A part of a satellite
 ************************************************************************/
class DragonCenter : public Satellite
{
public:
   DragonCenter() {}
   DragonCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawCrewDragonCenter(pos, angle); }
};

/***********************************************************************
 * GPS CENTER
 * A part of a satellite
 ************************************************************************/
class GPSCenter : public Satellite
{
public:
   GPSCenter() {}
   GPSCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSCenter(pos, angle); }
};

/***********************************************************************
 * GPS RIGHT
 * A part of a satellite
 ************************************************************************/
class GPSRight : public Satellite
{
public:
   GPSRight() {}
   GPSRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSRight(pos, angle); }
};

/***********************************************************************
 * GPS LEFT
 * A part of a satellite
 ************************************************************************/
class GPSLeft : public Satellite
{
public:
   GPSLeft() {}
   GPSLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSLeft(pos, angle); }
};

/***********************************************************************
 * STARLINK BODY
 * A part of a satellite
 ************************************************************************/
class StarlinkBody : public Satellite
{
public:
   StarlinkBody() {}
   StarlinkBody(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawStarlinkBody(pos, angle); }
};

/***********************************************************************
 * STARLINK BODY
 * A part of a satellite
 ************************************************************************/
class StarlinkArray : public Satellite
{
public:
   StarlinkArray() {}
   StarlinkArray(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawStarlinkArray(pos, angle); }
};

/***********************************************************************
 * HUBBLE COMPUTER
 * A part of a satellite
 ************************************************************************/
class HubbleComputer : public Satellite
{
public:
   HubbleComputer() {}
   HubbleComputer(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleComputer(pos, angle); }
};

/***********************************************************************
 * HUBBLE TELESCOPE
 * A part of a satellite
 ************************************************************************/
class HubbleTelescope : public Satellite
{
public:
   HubbleTelescope() {}
   HubbleTelescope(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleTelescope(pos, angle); }
};

/***********************************************************************
 * HUBBLE LEFT
 * A part of a satellite
 ************************************************************************/
class HubbleLeft : public Satellite
{
public:
   HubbleLeft() {}
   HubbleLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleLeft(pos, angle); }
};

/***********************************************************************
 * HUBBLE RIGHT
 * A part of a satellite
 ************************************************************************/
class HubbleRight : public Satellite
{
public:
   HubbleRight() {}
   HubbleRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawHubbleRight(pos, angle); }
};
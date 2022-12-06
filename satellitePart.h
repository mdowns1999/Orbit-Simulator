/***********************************************************************
 * Header File:
 *    Satellite Part
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 * Where all the classes for parts of satellite are defined
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class DragonRight : public Satellite
{
public:
   DragonRight() {}
   DragonRight(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   DragonRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawCrewDragonRight(pos, angle); }
};

class DragonLeft : public Satellite
{
public:
   DragonLeft() {}
   DragonLeft(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   DragonLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawCrewDragonLeft(pos, angle); }
};

class DragonCenter : public Satellite
{
public:
   DragonCenter() {}
   DragonCenter(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   DragonCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawCrewDragonCenter(pos, angle); }
};

class GPSCenter : public Satellite
{
public:
   GPSCenter() {}
   GPSCenter(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   GPSCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawGPSCenter(pos, angle); }
};

class GPSRight : public Satellite
{
public:
   GPSRight() {}
   GPSRight(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   GPSRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawGPSRight(pos, angle); }
};

class GPSLeft : public Satellite
{
public:
   GPSLeft() {}
   GPSLeft(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   GPSLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawGPSLeft(pos, angle); }
};


class StarlinkBody : public Satellite
{
public:
   StarlinkBody() {}
   StarlinkBody(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   StarlinkBody(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawStarlinkBody(pos, angle); }
};

class StarlinkArray : public Satellite
{
public:
   StarlinkArray() {}
   StarlinkArray(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   StarlinkArray(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawStarlinkArray(pos, angle); }
};

class HubbleComputer : public Satellite
{
public:
   HubbleComputer() {}
   HubbleComputer(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   HubbleComputer(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawHubbleComputer(pos, angle); }
};

class HubbleTelescope : public Satellite
{
public:
   HubbleTelescope() {}
   HubbleTelescope(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   HubbleTelescope(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawHubbleTelescope(pos, angle); }
};

class HubbleLeft : public Satellite
{
public:
   HubbleLeft() {}
   HubbleLeft(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   HubbleLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}

   void  draw()  const { drawHubbleLeft(pos, angle); }
};

class HubbleRight : public Satellite
{
public:
   HubbleRight() {}
   HubbleRight(double x, double y) { pos.setMetersX(x);  pos.setMetersY(y); }
   HubbleRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy);}
   void  draw()  const { drawHubbleRight(pos, angle); }
};
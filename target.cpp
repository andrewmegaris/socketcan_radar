#include "target.hpp"    


Target::Target(){}

Target::Target(int id,float range, float az, float vel, float snr):_id(id),_range(range),_azAngle(az),_velocity(vel),_snr(snr)
{

}

Target::~Target(){}

void Target::set_id(int x)
{
  _id = x;
}

void Target::set_range(float x)
{
  _range = x;
}

void Target::set_az(float x)
{
  _azAngle = x;
}

void Target::set_velocity(float x)
{
  _velocity = x;
}

void Target::set_snr(float x)
{
  _snr = x;
}

int Target::get_id()
{
  return _id;
}
 
float Target::get_range()
{
  return _range;
}

float Target::get_az()
{
  return _azAngle;
}

float Target::get_velocity()
{
  return _velocity;
}

float Target::get_snr()
{
  return _snr;
}

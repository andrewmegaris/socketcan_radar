#ifndef TARGET_H
#define TARGET_H

class Target
{
  public:
    Target();
    Target(int,float,float,float,float);
    ~Target();

    void  set_id(int);
    void  set_range(float);
    void  set_az(float);
    void  set_velocity(float);
    void  set_snr(float);

    int   get_id();
    float get_range();
    float get_az();
    float get_velocity();
    float get_snr();

  private:
    int   _id;
    float _range;
    float _azAngle;
    float _velocity;
    float _snr;

};


#endif

#ifndef RADAR_H
#define RADAR_H

const int MAX_TARGETS = 100;
const int HEADER_ID = 1;
const int FOOTER_ID = 1;
const int TARGET_RANGE_MIN = 1;
const int TARGET_RANGE_MAX = 1;

class Radar
{

  public:
    Radar();
    ~Radar();
    bool config_radar();
    bool activate();
    bool get_scan();
    Target* targetArray;
    int numTargets;

  private:

  //socketCAN stuph this may or may not stay here
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
  
};


#endif

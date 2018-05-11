#ifndef RADAR_H
#define RADAR_H

const int MAX_TARGETS = 65;
const int HEADER_ID = 1152;
const int FOOTER_ID = 1153;
const int TARGET_RANGE_MIN = 1024;
const int TARGET_RANGE_MAX = 1084;

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
    void print_scan_info();

  private:

  //socketCAN stuph this may or may not stay here
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
  
};


#endif

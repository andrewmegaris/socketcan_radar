#ifndef RADAR_H
#define RADAR_H



class Radar
{

  public:
   
     Radar(std::string,double,double,double);
    ~Radar();

    bool init();
    bool activate();
    bool get_scan();
    bool check_firmware();
    bool config_socketcan();

    int  numTargets;

    void print_scan_info();

    Target* targetArray;

  private:

    struct sockaddr_can addr;
    struct ifreq ifr;

    //pose center TBD
    struct location
    {
      double x;
      double y;
      double theta;
    };

    location pose;
    int s;
    int max_targets;
    int header_id;
    int footer_id;
    int target_frame_min;
    int target_frame_max;
    std::string radar_firmware;
  
};


#endif

#ifndef RADAR_H
#define RADAR_H

#define BUFLEN 2048

class Radar
{

  public:
   
     Radar(std::string,double,double,double);
    ~Radar();

    bool init();
    bool activate();
    bool deactivate();
    bool get_scan();
    bool enable_wide_mode();
    bool enable_long_mode();

    int  numTargets;

    void print_scan_info();

    Target* targetArray;

  private:

    bool check_firmware();
    bool config_socketcan();
    bool config_udp_socket();

    struct sockaddr_can addr;
    struct ifreq ifr;
    struct sockaddr_in myaddr, remaddr;

    //pose center TBD
    struct location
    {
      double x;
      double y;
      double theta;
    };


    location pose;
    int fd, i, slen;
    int s;
    int max_targets;
    int header_id;
    int footer_id;
    int target_raw_min;
    int target_raw_max;
    int target_tracked_min;
    int target_tracked_max;
    std::string radar_firmware;
    std::chrono::system_clock::time_point scan_time;
	


    char* server;
    char buf[BUFLEN];
};


#endif

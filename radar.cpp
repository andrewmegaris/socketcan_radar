#include <errno.h>
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "target.cpp"
#include "radar.hpp"

Radar::Radar()
{
  targetArray = new Target[MAX_TARGETS];
  numTargets  = 0;
}

Radar::~Radar()
{
  delete[] targetArray;
}

//do all the socketcan configuration here
bool Radar::config_radar()
{
  //TODO implement  checking
  bool ret = true;
  int nbytes;
  //open the socket
  s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

  //determine interface index
  strcpy(ifr.ifr_name, "can0");
  ioctl(s, SIOCGIFINDEX, &ifr);
  
  //assign interface index
  addr.can_family  = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;

  return ret;

}

//send the starting command
bool Radar::activate()
{
  //TODO implement checking
  bool ret = true;
  int nbytes;
  struct can_frame frame;

  //format frame to the start command!
  //this is standard frame format
  frame.can_id = 0x100;
  frame.can_dlc = 8;
  frame.data[0] = 0x01;
  frame.data[1] = 0x00;
  frame.data[2] = 0xff;
  frame.data[3] = 0xff;
  frame.data[4] = 0xff;
  frame.data[5] = 0xff;
  frame.data[6] = 0xff;
  frame.data[7] = 0xff;

  nbytes = write(s, &frame, sizeof(struct can_frame));
  
  return ret;
}

//TODO Add functions for switching the mode and or output type(raw detection vs target tracking..)

//look for a header ID, then parse all targets until you see footer ID
bool Radar::get_scan()
{
  //TODO implement checking
  bool ret = true;
  bool footerFound = false;
  bool headerFound = false;
  int  targetCount = 0;
  int  nbytes;

  while(footerFound == false)
  {
    //TODO check if we are doing standard can frames or extended
    //TODO add option to do both ^^ this is more of a global scope TODO
    struct can_frame frame;

    //TODO abstract frame ID
    nbytes = ::read(s, &frame, sizeof(struct can_frame));

    //make sure frame is something
    if(nbytes < 0)
    {
      perror("can raw socket read error");
      return false;
    }
    //make sure frame is a frame
    else if(nbytes < sizeof(struct can_frame))
    {
      fprintf(stderr, "read error: incomplete frame\n");
      return false;
    }
    //frame is safe to parse
    else
    {
      //can frame ID is header ID
      if(frame.can_id == HEADER_ID)
      {
        headerFound = true;
        //TODO process header frame
        //TODO get # of targets for a comparing in footer
      }
      //can frame ID is footer ID and header has been processed
      else if(frame.can_id == FOOTER_ID && headerFound)
      {
        //TODO anything useful in footer?
        footerFound = true;
        numTargets = targetCount;
      }
      //can frame ID is in the target range and header has been processed.
      else if( (frame.can_id >= TARGET_RANGE_MIN) && (frame.can_id <= TARGET_RANGE_MAX) && (headerFound) )
      {
        //processing can frame into radar target object.
        float range = (int16_t)( (frame.data[2] << 8) + frame.data[3]) / 100.0;
        float az = (int16_t)( (frame.data[6] << 8) + frame.data[7]) / 100.0 * -1;
        float vel = (int16_t)( (frame.data[4] << 8) + frame.data[5]) / 100.0;
        float snr = frame.data[1];
        int id = frame.data[0]; 
        targetArray[targetCount].set_id(id);
        targetArray[targetCount].set_range(range);
        targetArray[targetCount].set_az(az);
        targetArray[targetCount].set_velocity(vel);
        targetArray[targetCount].set_snr(snr);
        targetCount++;
      }
      //TODO we could add some check for unexpected CANIDS here.. 
    }

  }

  return ret;
}

void Radar::print_scan_info()
{
  std::cout << "Number of Targets in radar: " << numTargets << std::endl;
  for(int x = 0; x < numTargets; x++)
  {
    std::cout << "Id: " << targetArray[x].get_id() << ", ";
    std::cout << "Range: " << targetArray[x].get_range() << ", ";
    std::cout << "Velocity: " << targetArray[x].get_velocity() << std::endl;
    std::cout << "Azimuth Angle: " << targetArray[x].get_az() << ", ";
    std::cout << "SNR: " << targetArray[x].get_snr() << std::endl;
  }
}













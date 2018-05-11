#include <iostream>

#include "radar.cpp"

int main(int argc, char **argv)
{

   Radar my_radar_test;
   my_radar_test.targetArray[5].set_snr(7.7);

   std::cout << my_radar_test.targetArray[5].get_snr() << std::endl;

   return 0	;

}

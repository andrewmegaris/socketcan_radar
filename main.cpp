#include <iostream>

#include "radar.cpp"

int main(int argc, char **argv)
{

  Radar my_radar_test("k77",0.0,0.0,0.0);
  std::cout << "radar created" << std::endl;
  my_radar_test.init();
  std::cout << "radar configured" << std::endl;
  my_radar_test.activate();
  std::cout << "radar activated" << std::endl;
   
  for(int x = 0; x < 10; x++)
  {
    my_radar_test.get_scan();
    my_radar_test.print_scan_info();
  }

  return 0;
}

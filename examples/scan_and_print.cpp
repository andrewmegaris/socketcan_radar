#include <iostream>

#include "../src/radar.cpp"

int main(int argc, char **argv)
{

  Radar my_radar_test("t79_short_range",0.0,0.0,0.0);
  std::cout << "radar created" << std::endl;
  my_radar_test.init();
  std::cout << "radar configure finished" << std::endl;
  my_radar_test.activate();
  std::cout << "radar activate finished" << std::endl;
  my_radar_test.enable_wide_mode();
  for(int x = 0; x < 10; x++)
  {
    my_radar_test.get_scan();
    my_radar_test.print_scan_info();
  }
  
  my_radar_test.deactivate();

  return 0;
}

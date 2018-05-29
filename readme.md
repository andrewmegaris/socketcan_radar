# SocketCAN Radar Driver

## Info:
  programs written using the (socketCAN protocol)[https://en.wikipedia.org/wiki/SocketCAN].  The default CAN BUS used is 'can0'.  The default bitrate of the hardware  and software is 500000.   


## Radar API:

#### Radar(string fw,double x_in, double y_in, double theta_in)
- fw:   String value with the version of firmware on your radar.
- x_in: The offset in meters, on the X axis for your radar.  *see vehicle spacial reference diagram.*
- y_in: The offset in meters, on the Y axis for your radar.  *see vehicle spacial reference diagram.*
- theta_in: The angular offset in degrees for your radar. *see vehicle spacial reference diagram.*

#### ~Radar()
Releases the radar object and frees the memory allocated for the target object array.

#### init()
Calls the 'check_firmware()' and 'config_socketcan()' functions.  Returns true if initialization is successful.

#### activate()
Sends a CAN frame with the start scanning command.  This will have the radar continuously making scans.  Returns true if CAN frame was successfully written to CAN BUS.

#### deactivate()
Sends a CAN frame with the stop scanning command.  Returns true if CAN frame was successfully written to the CAN BUS.

#### get_scan()
Monitor the CAN BUS messages until a complete scan has been accumulated.  Data is stored in the radar's internal Target array.

#### print_scan_info()
Print radar's internal target array to std::cout.  *note:  These targets could be very stale depending on the last call to'get_scan()'.

#### check_firmware()
Internal function called by 'init()'.  This will match the constructor's 'fw' parameter and configure radar object accordingly.  Returns true if successful.

#### config_socketcan()
Internal function called by 'init()'.  This will configure, and bind the socket for CAN communication.  Returns true if successful.

# Build and run examples
Example applications will be compiled with the 'make' command.  Executables will be placed in the 'bin' folder.


# TODO
- make vehicle spacial reference diagram!




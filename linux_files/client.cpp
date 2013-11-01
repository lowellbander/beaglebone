// g++ libserial_client.cpp -lserial
// add request byte
#include <iostream>
#include <SerialStream.h>
#include <string>
#include <cstdlib>
int main() {
	std::string portName = "/dev/ttyACM0";
	std::cout << "Attempting to connect to port " << portName << std::endl;
	LibSerial::SerialStream port;
	port.Open(portName);
	if (!port.good()) {
		std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] " << "Error: Could not open serial port." << std::endl ;
        std::cerr << "Try using sudo." << std::endl;
        std::exit(1) ;
	}
    // Set the baud rate of the serial port.
    port.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
    if (!port.good()) {
        std::cerr << "Error: Could not set the baud rate." <<  std::endl;
        exit(1) ;
    }
    // Set the number of data bits.
    port.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
    if (!port.good()) {
        std::cerr << "Error: Could not set the character size." <<  std::endl;
        exit(1) ;
    }
    // Disable parity.
    port.SetParity(LibSerial::SerialStreamBuf::PARITY_NONE);
    if (!port.good()) {
        std::cerr << "Error: Could not disable the parity." <<  std::endl;
        exit(1) ;
    }
    // Set the number of stop bits.
    port.SetNumOfStopBits(1);
    if (!port.good()) {
        std::cerr << "Error: Could not set the number of stop bits." << std::endl;
        exit(1) ;
    }
    // Turn off hardware flow control.
    port.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE);
    if (!port.good()) {
        std::cerr << "Error: Could not use hardware flow control." << std::endl;
        exit(1) ;
    }
    std::cout << "Successfully connected to port " << portName << std::endl;

    while (port.rdbuf()->in_avail() > 0) usleep(100); // not sure what this does

    char c;
    while (true) {
    	port.get(c);
    	std::cout << "Received '" << c << "' on port " << portName << std::endl;
    }
}

// pySerial defaults to baudrate=9600

#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>

using namespace std;

int main() {
    // string port_ = "/dev/ttyACM0";
    const char* port = "/dev/ttyACM0";
    cout << "Connecting to "<< port << endl;
    ifstream myfile;
    myfile.open(port);

    if (myfile.good()) {
        cout << port << " good" << endl;    
    
    }
    else cout << port << " bad" << endl;

   // char* buff = new char[1];
   // buff[0] = 'x';
   // cout << "buff: " << buff[0] << endl;
   // myfile.read(buff,1);
   // cout << "rcvd: " << buff[0] << endl; 

    myfile.close();
    // delete buff;
}

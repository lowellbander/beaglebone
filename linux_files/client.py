import serial
from time import sleep
serConn = serial.Serial(port='/dev/ttyACM0')
print "Connected to port " + serConn.name
print "(Receiving one byte at a time)"
while True:
    serConn.write("a")
    msg = serConn.read()
    sleep(1)
    print "Received: \"" + msg + "\""
serConn.close()

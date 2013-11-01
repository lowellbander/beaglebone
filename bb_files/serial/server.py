import serial
serConn = serial.Serial(port='/dev/ttyGS0')
print "Connected to port " + serConn.name
# msg = "hello"
while True:
    msg = raw_input(">>")
    print "Writing \"" + msg + "\" to " + serConn.name
    serConn.write(msg)
serConn.close()

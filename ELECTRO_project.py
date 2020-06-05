import serial
Serial = serial.Serial('/dev/ttyUSB0', 9600,)
#value=start.ret()
def relay(value):
        while 1:
                if(value=='a'):
                        command = str.encode('1')
                        Serial.write(command)
                        break
                if(value=='b'):
                        command = str.encode('2')
                        Serial.write(command)
                        break
                if(value=='c'):
                        command = str.encode('3')
                        Serial.write(command)
                        break
                if(value=='d'):
                        command = str.encode('4')
                        Serial.write(command)
                        break
		else:
			break



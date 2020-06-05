#include <Wire.h>
int flag_realy1=0;
int flag_realy2=0;
int flag_realy3=0;
int flag_realy4=0;
int value;
// Pins used for I/O
int relay1=4;
int relay2=5;
int relay3=6;
int relay4=7;
int btnPin1 = 9;
int data1=0;
int data=0;
int Lo1=10;
int Lo2=11;
// I2C address of the MPU-6050
const int MPU_addr=0x68;
// Variables that will store sensor data
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

// Status variables, used with buttons
int precBtn1 = HIGH;

void setup(){
  // Set the pin mode of the buttons using the internal pullup resistor
  pinMode(btnPin1, INPUT_PULLUP);
  pinMode(Lo1,OUTPUT);
  pinMode(Lo2,OUTPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);

  // Start the comunication with the MPU-6050 sensor
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  // Start the serial communication
  Serial.begin(9600);
}
void loop(){
  // Read the values of the buttons
  int resultBtn1 = digitalRead(btnPin1);

  // ON btn1 pressed, start the batch and light up the yellow LED
  if (precBtn1 == HIGH && resultBtn1 == LOW)
  {
    startBatch();
  }

  // If the btn1 is pressed, reads the data from the sensor and sends it through the communication channel
  if (resultBtn1==LOW)
  {
    // Start the transmission with the MPU-6050 sensor
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
    
    // Reads the data from the sensor
    data = analogRead(A0);
    AcX=data;  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    data = analogRead(A0);    
    AcY=data;  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    data = analogRead(A0);
    AcZ=data;  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    data = analogRead(A0);
    Tmp=data;  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    data = analogRead(A0);
    GyX=data;  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    data = analogRead(A0);
    GyY=data;  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    data = analogRead(A0);
    GyZ=data;  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

    Serial.print("START");
    Serial.print(" "); Serial.print(AcX);
    Serial.print(" "); Serial.print(AcY);
    Serial.print(" "); Serial.print(AcZ);
    Serial.print(" "); Serial.print(GyX);
    Serial.print(" "); Serial.print(GyY);
    Serial.print(" "); Serial.print(GyZ);
    //
    data = analogRead(A0);
    AcX=data;  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    data = analogRead(A0);    
    AcY=data;  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    data = analogRead(A0);
    AcZ=data;  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    data = analogRead(A0);
    Tmp=data;  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    data = analogRead(A0);
    GyX=data;  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    data = analogRead(A0);
    GyY=data;  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    data = analogRead(A0);
    GyZ=data;  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

    //Serial.print("START");
    Serial.print(" "); Serial.print(AcX);
    Serial.print(" "); Serial.print(AcY);
    Serial.print(" "); Serial.print(AcZ);
    Serial.print(" "); Serial.print(GyX);
    Serial.print(" "); Serial.print(GyY);
    Serial.print(" "); Serial.print(GyZ);
    //
    data = analogRead(A0);
    AcX=data;  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    data = analogRead(A0);    
    AcY=data;  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    data = analogRead(A0);
    AcZ=data;  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    data = analogRead(A0);
    Tmp=data;  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    data = analogRead(A0);
    GyX=data;  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    data = analogRead(A0);
    GyY=data;  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    data = analogRead(A0);
    GyZ=data;  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

    //Serial.print("START");
    Serial.print(" "); Serial.print(AcX);
    Serial.print(" "); Serial.print(AcY);
    Serial.print(" "); Serial.print(AcZ);
    Serial.print(" "); Serial.print(GyX);
    Serial.print(" "); Serial.print(GyY);
    Serial.print(" "); Serial.print(GyZ);
    Serial.println(" END");
  }

  // Closes the batch when the button is released
  if (precBtn1 == LOW && resultBtn1 == HIGH)
  {
    closeBatch();
  }

  // Saves the button states
  precBtn1 = resultBtn1;
   while (Serial.available())
   {
        {
           value = Serial.read();
        }
     
     if (value == '1')
     {
        if(flag_realy1==0)
        {
        digitalWrite (relay1, LOW);
        flag_realy1=1;
        }
        if(flag_realy1==1)
        {
        digitalWrite (relay1,HIGH);
        flag_realy1=0;
        }
     }
     if (value == '2')
     {
        if(flag_realy2==0)
        {
        digitalWrite (relay2, LOW);
        flag_realy2=1;
        }
        if(flag_realy2==1)
        {
        digitalWrite (relay2,HIGH);
        flag_realy1=0;
        }
     }
     if (value == '3')
     {
        if(flag_realy3==1)
        {
        digitalWrite (relay3,HIGH);
        flag_realy3=1;
        }
        if(flag_realy3==0)
        {
        digitalWrite (relay3,LOW);
        flag_realy3=0;
        }
     }
     if (value == '4')
     {
        if(flag_realy4==1)
        {
        digitalWrite (relay4,HIGH);
        flag_realy4=1;
        }
        if(flag_realy4==0)
        {
        digitalWrite (relay4,LOW);
        flag_realy4=0;
        }
     }
   }
}

// Sends the started batch signal
void startBatch()
{
  Serial.println("STARTING BATCH");
}

// Sends the closed batch signal
void closeBatch()
{
  Serial.println("CLOSING BATCH");
}

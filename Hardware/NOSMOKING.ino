
#include "CS_MQ7.h"

#include <SoftwareSerial.h>

 

 

int Tx=4;

int Rx=5;
int sensorValue[1] = {0};
 

SoftwareSerial BTSerial(Tx, Rx);
CS_MQ7 MQ7(3, 13);  // 12 = digital Pin connected to "tog" from sensor board

                     // 13 = digital Pin connected to LED Power Indicator

int CoSensorOutput = 0; //analog Pin connected to "out" from sensor board

int CoData = 0;         //analog sensor data

 

void setup(){

  BTSerial.begin(9600);
  Serial.begin(9600);

}

 

void loop(){

  MQ7.CoPwrCycler();  
  sensorValue[0] = analogRead(CoSensorOutput);
  sendAndroidValues();

   // if(BTSerial.available()){
   //   Serial.write(BTSerial.read());
      //Serial.println(sensorValue[0]);

  //   }

      BTSerial.write(Serial.read());
      BTSerial.println(sensorValue[0]);

    delay(100);    
}

//sends the values from the sensor over serial to BT module
void sendAndroidValues()
 {
  
 Serial.print(sensorValue[0]);
 Serial.println();
 delay(100);        //added a delay to eliminate missed transmissions
}
 

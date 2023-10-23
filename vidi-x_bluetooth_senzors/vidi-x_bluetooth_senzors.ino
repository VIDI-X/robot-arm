#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

int potpin1 = 36;  // analog pin used to connect the potentiometer
int potpin2 = 34;  // analog pin used to connect the potentiometer
int potpin3 = 32;  // analog pin used to connect the potentiometer
int potpin4 = 33;  // analog pin used to connect the potentiometer

int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int val3;    // variable t o read the value from the analog pin
int val4;    // variable to read the value from the analog pin

BluetoothSerial SerialBT;


void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("VIDIXArm2"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {

  unsigned long currentMillis = millis();
  
  val1 = analogRead(potpin1);            // reads the value of the potentiometer 
  val1 = map(val1, 0, 4095, 90, 495);     // scale it to use it with the servo 
  val2 = analogRead(potpin2);            // reads the value of the potentiometer 
  val2 = map(val2, 0, 4095, 90, 495);     // scale it to use it with the servo 
  val3 = analogRead(potpin3);            // reads the value of the potentiometer
  val3 = map(val3, 0, 4095, 90, 495);    // scale it to use it with the servo 
  val4 = analogRead(potpin4);            // reads the value of the potentiometer 
  val4 = map(val4, 0, 4095, 90, 495);

  val1 = val1+100;
  val2 = val2+100;
  val3 = val3+100;
  val4 = val4+100;
  

      
      Serial.print(val1);
      Serial.print("|");
      Serial.print(val2);
      Serial.print("|");
      Serial.print(val3);
      Serial.print("|");
      Serial.println(val4);
      
      SerialBT.print(val1);
      SerialBT.print(val2);
      SerialBT.print(val3);
      SerialBT.println(val4);
      
    //} 

      delay(500);
  }

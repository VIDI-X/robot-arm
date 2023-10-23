#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

String text = "";
String command = "";
int pos;

BluetoothSerial SerialBT;

#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

int prepos1 = 370;
int prepos2 = 420;
int prepos3 = 290;
int prepos4 = 495;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("VIDIXArm1"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  pwm.setPWM(0, 0, prepos1);
  pwm.setPWM(1, 0, prepos2);
  pwm.setPWM(2, 0, prepos3);
  pwm.setPWM(3, 0, prepos4);
}

void loop() {

  if (SerialBT.available() > 0) {
    text = SerialBT.readStringUntil('|');
    Serial.println(text);
    command = text.substring(6, text.length());
    pos = command.toInt();
    Serial.println(pos);
    
    if(text.startsWith("servo1")) {
      if(pos >= prepos1) {
        for (prepos1; prepos1 <= pos; prepos1 += 1) { 
        pwm.setPWM(0, 0, prepos1);             
        delay(15); 
        }
      }
      else{
        for (prepos1; prepos1 >= pos; prepos1 -= 1) { 
        pwm.setPWM(0, 0, prepos1);             
        delay(15); 
        }
      }                       
    }
   
    if(text.startsWith("servo2")) {
      if(pos >= prepos2) {
        for (prepos2; prepos2 <= pos; prepos2 += 1) { 
        pwm.setPWM(1, 0, prepos2);             
        delay(15); 
        }
      }
      else{
        for (prepos2; prepos2 >= pos; prepos2 -= 1) { 
        pwm.setPWM(1, 0, prepos2);             
        delay(15); 
        }
      }
    }
    
    if(text.startsWith("servo3")) {
      if(pos >= prepos3) {
        for (prepos3; prepos3 <= pos; prepos3 += 1) { 
        pwm.setPWM(2, 0, prepos3);             
        delay(15); 
        }
      }
      else{
        for (prepos3; prepos3 >= pos; prepos3 -= 1) { 
        pwm.setPWM(2, 0, prepos3);             
        delay(15); 
        }
      }
    }
    
    if(text.startsWith("servo4")) {
      if(pos >= prepos4) {
        for (prepos4; prepos4 <= pos; prepos4 += 1) { 
        pwm.setPWM(3, 0, prepos4);             
        delay(15); 
        }
      }
      else{
        for (prepos4; prepos4 >= pos; prepos4 -= 1) { 
        pwm.setPWM(3, 0, prepos4);             
        delay(15); 
        }
      }
    }
    
    }
      //delay(20);
  }

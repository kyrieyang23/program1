#include <SoftwareSerial.h>
#include "roombaDefines.h"

int rxPin = 8; //yellow
int txPin = 9; //green

SoftwareSerial Roomba(rxPin, txPin);
#include "api.h"

bool button[8] = {};

// Light Sensor from Right
int light1 = 0;
int light2 = 0;
int light3 = 0;

// 0 = stop
int func = 0;
int pfunc = 0;

int wall_counter = 0;

int GuideDistance = 400;
int s = 200; // Base Speed
int dwa = 0; // delta wheel angle


void setup(){
  Roomba.begin(19200);
  Serial.begin(115200);
  pinMode(ddPin, OUTPUT);
  reconnect();
}
void reconnect() {
  func = 0;
  Serial.println("[SYSTEM] Reconnect");
  wakeUp();
  startSafe();
  setPowerLED(255, 255);
}

void safeDelay(int interval){
  for(int i=0;i<float(interval)/(20.0*3);i++){
    while (Roomba.available() > 0) Roomba.read();
    while (Serial.available() > 0) if (Serial.read() == '\n') reconnect();
    byteToArray(readSensorDataAsByte(18), button);
    light1 = readSensorDataWithSignedDec(51);
    //  light2 = readSensorDataWithSignedDec(50);
    light3 = readSensorDataWithSignedDec(49);
    setDisplayNumber(light1);

    if (button[7]) func = 0;
    else if (button[6]) func = 1;
    else if (button[5]) func = 2;
    else if (button[4]) func = 3;
//    Serial.println(String(func) + " : " + arrayToString(button) + " " + String(light1) + " " + String(light2) + " " + String(light3));
    if (pfunc != func){
      functionDidChange();
      return;
    }
  }
}

void loop() {
  
  safeDelay(60);

  functionHandle();

  pfunc = func;

}
void setFunctionValue(int newValue) 
{
  func = newValue;
  functionDidChange();
}
void functionDidChange() 
{
  if (func == 1) {
    driveWheelsPWM(200, -200);
    delay(200);
    driveWheelsPWM(200, 200);
    delay(150);
    driveWheelsPWM(-200, 200);
    delay(200);
    driveWheelsPWM(0, 0);
  } else if (func == 2) {
//    vacuum(1);
    wall_counter = 0;
  } else if (func == 3){
    driveWheelsPWM(50, -50);
    readSensorDataWithSignedDec(20);
    for(float angle=0;angle<=45*10;){
      float tempAngle = readSensorDataWithSignedDec(20);
      angle += tempAngle; // L
      Serial.println(String(tempAngle)+" "+String(angle));
//      setDisplayNumber(angle);
      delay(10);
    }
    setFunctionValue(0);
  }else{
    driveWheelsPWM(0, 0);
  }
}

void functionHandle() 
{
  if (func == 1) 
  {
    if (light3 > 100 && light3 < 1000) 
    {
      setFunctionValue(0);  // STOP
      return;
    }
    int deltaLight = light1 - GuideDistance;
    if (light1 <= 50) dwa = -150; // -104
    else dwa = deltaLight * 0.05; // 0.018
    driveWheelsPWM(s + dwa, s - dwa);
//    Serial.println("L:"+String(light1)+" S:"+String(s)+" DELTA:"+String(dwa)+" TOTAL-L:"+String(s + dwa)+" TOTAL-R:"+String(s - dwa));



  } 
  else if (func == 2) 
  {
    
//    if ( light1 < 20 ) { // (light3 > 20 && light3 < 1000) || (light1 < 20)
//      
//      wall_counter++;
//
//      driveWheelsPWM(50, 50);
//      delay(50);
//      driveWheelsPWM(0, 0);
//      delay(50);
//
//      if (wall_counter == 6) {
//        driveWheelsPWM(200, -200);
//      } else {
//        driveWheelsPWM(-200, 200);
//      }
//
//
//      delay(500);
//      driveWheelsPWM(0, 0);
//      
//      setDisplayNumber(wall_counter);
//      return;
//    }

    if(light3 >= 5) rotate90l();

    int deltaLight = light1 - GuideDistance;
    if (light1 <= 50)
    {
      driveWheelsPWM(200,200);
      safeDelay(700);
      rotate90();
    }
    else 
    {
      dwa = deltaLight * 0.05; // 0.018
    }

    if (wall_counter >= 5) driveWheelsPWM(150, 200);
    else driveWheelsPWM(s + dwa, s - dwa);
//    setDisplayNumber(wall_counter);
  }
  else if(func == 3)
  {
    
  }

}

void rotate90(){
  dwa = -150;
  driveWheelsPWM(dwa,-dwa);
  safeDelay(500);
}

void rotate90l(){
  dwa = 150;
  driveWheelsPWM(dwa,-dwa);
  safeDelay(500);
}


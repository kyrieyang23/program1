int mortorR1 = 6;
int mortorR2 = 5;
int mortorL1 = 3;
int mortorL2 = 4;
int sensorM = 8;
int sensorR = 9;
int sensorL = 10;
int time=0;
int count=0;
void setup() 
{
  pinMode(mortorR1,OUTPUT);
  pinMode(mortorR2,OUTPUT);
  pinMode(mortorL1,OUTPUT);
  pinMode(mortorL2,OUTPUT);
  pinMode(sensorM,INPUT);
  pinMode(sensorR,INPUT);
  pinMode(sensorL,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int sensorMData = digitalRead(sensorM);
  int sensorRData = digitalRead(sensorR);
  int sensorLData = digitalRead(sensorL);
  if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,245); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,250); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,80); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,255); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,250); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,245); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,255); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,80); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,250); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,250); //front
     analogWrite(mortorL2,0); //back
    }
}

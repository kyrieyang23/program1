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

void loop() {
  int sensorMData = digitalRead(sensorM);
  int sensorRData = digitalRead(sensorR);
  int sensorLData = digitalRead(sensorL);
  if((time/180) < 2)
  {
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,200); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,200); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,220); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,220); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,220); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,220); //front
     analogWrite(mortorL2,0); //back
    }
  }
  if((time/180) >= 2)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,230); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,230); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,50); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,230); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,50); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,230); //front*
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/180) >= 4)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,140); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,140); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,150); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,140); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,180); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/180) >= 5)
  {
  if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,130); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,0); //front
      analogWrite(mortorL2,80); //back
      analogWrite(mortorR1,120); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,150); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,130); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,120); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,0); //front
      analogWrite(mortorR2,80); //back
    }
  }
  if((time/180) >= 9)
  {
  if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,130); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,0); //front
      analogWrite(mortorL2,150); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,150); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,130); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,150); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,0); //front
      analogWrite(mortorR2,100); //back
    }
  }
  if((time/165) >= 10)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 )
    {
     analogWrite(mortorR1,150); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,150); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,130); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,150); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,130); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,200); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/170) >= 11)
  {
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,220); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,240); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,200); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,240); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,240); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,240); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,240); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,240); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 )
    {
     analogWrite(mortorR1,240); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,240); //front
     analogWrite(mortorL2,0); //back
    }
  }
  if((time/160) >= 13)
  {
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,180); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,50); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,180); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,200); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,160); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
  }
  if((time/175) >= 15)
  {
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,220); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,240); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,220); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,240); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,240); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,240); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,220); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,240); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,240); //front
     analogWrite(mortorL2,0); //back
    }
  }
  if((time/165) >= 18)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,200); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,180); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,200); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,150); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,180); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,0); //front
      analogWrite(mortorL2,80); //back
      analogWrite(mortorR1,80); //front*
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/190) >= 20)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,120); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,120); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0 and count == 0)
    {
     analogWrite(mortorR1,100); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,100); //front
     analogWrite(mortorL2,0); //back
     delay(300);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,0); //back
     delay(200);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,130); //back
     analogWrite(mortorL1,130); //front
     analogWrite(mortorL2,0); //back
     delay(300);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,0); //back
     delay(200);
     count = 1;
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,120); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,140); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,120); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,140); //front*
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/185) >= 22)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,200); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,200); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorR1,200); //front
      analogWrite(mortorR2,0); //back
      analogWrite(mortorL1,200); //front
      analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,200); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,180); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,240); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,50); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,180); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,200); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,50); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,240); //front*
      analogWrite(mortorR2,0); //back
    }
  }
  if((time/185) > 25)
  {
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 1 )
    {
     analogWrite(mortorR1,120); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,120); //front
     analogWrite(mortorL2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,120); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 1 and sensorRData == 1)
    {
      analogWrite(mortorL1,100); //front
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,120); //front*
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 1 and sensorRData == 0)
    {
      analogWrite(mortorL1,120); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 1 and sensorMData == 0 and sensorRData == 0)
    {
      analogWrite(mortorL1,120); //front*
      analogWrite(mortorL2,0); //back
      analogWrite(mortorR1,100); //front
      analogWrite(mortorR2,0); //back
    }
    if(sensorLData == 0 and sensorMData == 0 and sensorRData == 0)
    {
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,0); //back
     delay(200);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,130); //back
     analogWrite(mortorL1,130); //front
     analogWrite(mortorL2,0); //back
     delay(630);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,0); //back
     delay(300);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,225); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,180); //back
     delay(380);
     analogWrite(mortorR1,0); //front
     analogWrite(mortorR2,0); //back
     analogWrite(mortorL1,0); //front
     analogWrite(mortorL2,0); //back
     delay(50000);
    }
  }
  time++;
  Serial.println(time/180);
}

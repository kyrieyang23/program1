
void byteToArray(byte input,bool *Array){
  for(int i=0;i<8;i++) 
    Array[7-i] = (input>>i & 1);
}
String arrayToString(bool *Array){
  String temp = "";
  for(int i=0;i<8;i++) temp += String(Array[i]?"1":"0");
  return temp;
}

#define commandDelay 20
byte readSensorDataAsByte(int packetId){
  Roomba.write(142);
  Roomba.write(packetId);
  delay(commandDelay);
  return Roomba.read() | Roomba.read() << 8;
}

int readSensorDataWithSignedDec(int packetId){
  Roomba.write(142);
  Roomba.write(packetId);
  delay(commandDelay);
  byte raw[2];
  raw[0] = Roomba.read();
  raw[1] = Roomba.read();
  if(raw[0] & 1<<7) {
    raw[0] = ~raw[0]; // ~ = invert
    raw[1] = ~raw[1]; // ~ = invert
  }
  int a = raw[0] << 8 | raw[1];
  return a;
}

void vacuum(bool state){
  Roomba.write(138);
  int a = 0;
  if(state) a = 0b00011110;
  Roomba.write(a);
}


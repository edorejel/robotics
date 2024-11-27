/*
copy and paste the code into Tinkercad and run it, after the components and wiring have been connected
the code is for a "bare bones" remote control
the remote control is already programmed to work, once the code and components are connected, that is, the behavior of the remote control is encapsulated
and not accessible for modification
*/

#include <IRremote.h>
int IRpin=0;
IRrecv IR(IRpin);
int t=1000;


int LEDpin = 8;



void setup()
{
  
Serial.begin(9600);
pinMode(IRpin,INPUT);
IR.enableIRIn();
pinMode(0, OUTPUT);

}

void loop(){


while(IR.decode())
{
//Serial.println(IR.decodedIRData.decodedRawData,HEX);
if(IR.decodedIRData.decodedRawData==0xFF00BF00)
{
Serial.println("Power On");
digitalWrite(8, HIGH);
delay(t/10);
  Serial.println("Power Off");
digitalWrite(8, LOW);  
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFE01BF00)
{
Serial.println("Vol+");
  digitalWrite(8, HIGH);
delay(t/10);
  digitalWrite(8, LOW); 
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFD02BF00)
{
Serial.println("Func/Stop");  
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFB04BF00)
{
Serial.println("Reverse");
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFA05BF00)
{
Serial.println("Play/Pause");  
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xF906BF00)
{
Serial.println("Fast Forward");  
}
  
  
  
//close the lid
if(IR.decodedIRData.decodedRawData==0xF708BF00)
{
Serial.println("Arrow Down");  
}
  
  
if(IR.decodedIRData.decodedRawData==0xF609BF00)
{
Serial.println("Vol-");  
}

//open the lid  
if(IR.decodedIRData.decodedRawData==0xF50ABF00)
{
Serial.println("Arrow Up");  
}

  
  
  
  if(IR.decodedIRData.decodedRawData==0xF30CBF00)
{
Serial.println("0");  
}
if(IR.decodedIRData.decodedRawData==0xF20DBF00)
{
Serial.println("EQ");  
}
if(IR.decodedIRData.decodedRawData==0xF10EBF00)
{
Serial.println("ST/REPT");  
}
if(IR.decodedIRData.decodedRawData==0xEF10BF00)
{
Serial.println("1");  
}
if(IR.decodedIRData.decodedRawData==0xEE11BF00)
{
Serial.println("2");  
}
if(IR.decodedIRData.decodedRawData==0xED12BF00)
{
Serial.println("3");  
}
if(IR.decodedIRData.decodedRawData==0xEB14BF00)
{
Serial.println("4");  
}
if(IR.decodedIRData.decodedRawData==0xEA15BF00)
{
Serial.println("5");  
}
if(IR.decodedIRData.decodedRawData==0xE916BF00)
{
Serial.println("6");  
}
if(IR.decodedIRData.decodedRawData==0xE718BF00)
{
Serial.println("7");  
}
if(IR.decodedIRData.decodedRawData==0xE619BF00)
{
Serial.println("8");  
}
if(IR.decodedIRData.decodedRawData==0xE51ABF00)
{
Serial.println("9");  
}  
delay(t);
IR.resume();  
}  
}

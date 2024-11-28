#include <IRremote.h> // Include remote library
#include <Servo.h> // Include the Servo library  

int Tilt_Sensor = 0;


int servoPin = 3;// Declare the Servo pin  
int servo_1Pin = 4;//declare the 2nd Servo pin
int servo_2Pin = 5;


Servo servo_2;

int IRpin=0;//declare a remote control pin
IRrecv IR(IRpin);//pass the pin value to the remote IR
int t=1000;//delay variable


int LEDpin = 8;//LED pin
int tiltPin = 2;


void setup(){
  
Serial.begin(9600);


servo_2.attach(servo_2Pin);
pinMode(2, INPUT);  
  //end servo motor code
  
//code for remote  
pinMode(IRpin,INPUT);
IR.enableIRIn();
pinMode(0, OUTPUT);
//end code for remote
}

void loop(){
  
   Tilt_Sensor = digitalRead(tiltPin);
  if (Tilt_Sensor == LOW) 
{
    servo_2.write(180);//tilt the Servo motor
  } 
else 
{
    servo_2.write(0);
  }
 
  

while(IR.decode()){
//Serial.println(IR.decodedIRData.decodedRawData,HEX);
if(IR.decodedIRData.decodedRawData==0xFF00BF00)
{
Serial.println("Power On");
digitalWrite(8, HIGH);
Serial.println("LED On");
delay(t/10);
Serial.println("Power Off");
digitalWrite(8, LOW);
Serial.println("LED Off");  
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFE01BF00){
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

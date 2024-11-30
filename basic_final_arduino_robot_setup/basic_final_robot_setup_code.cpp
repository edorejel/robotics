/*

code is in the process of being updated
limited functionality is present, however
- servo motor works
- - distance sensor works to control the servo motor
- - remote control also controls the servo motor
- - (it is implied you understand what a Servo motor is)
*/

#include <IRremote.h> // Include remote library
#include <Servo.h> // Include the Servo library  

int Tilt_Sensor = 0;//object initialization
int servo_2Pin = 5;
Servo servo_2;

int IRpin = 10;//declare a remote control pin
IRrecv IR(IRpin);//pass the pin value to the remote IR
int t=1000;//delay variable
int LEDpin = 8;//LED pin
int tiltPin = 11;


void setup(){
  
Serial.begin(9600);

//servo motor code (you shoud know what the syntax means)  

servo_2.attach(servo_2Pin);  
  //end servo motor code
  
//code for remote  
pinMode(IRpin,INPUT);
IR.enableIRIn();

//end code for remote
}
//verified

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
 
/*

  */
  

while(IR.decode()){
//Serial.println(IR.decodedIRData.decodedRawData,HEX);
if(IR.decodedIRData.decodedRawData==0xFF00BF00){
Serial.println("Power On");
digitalWrite(LEDpin, HIGH);
Serial.println("LED On");
delay(t);
Serial.println("Power Off");
digitalWrite(LEDpin, LOW);
Serial.println("LED Off");  
}
  
  
  
if(IR.decodedIRData.decodedRawData==0xFE01BF00){
Serial.println("Vol+");
  digitalWrite(LEDpin, HIGH);
delay(t);
  digitalWrite(LEDpin, LOW); 
}
  
  
  
//stops the vehicle motors from spinning  
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
    // Make servo go to 0 degrees 
   servo_2.write(0); 
   delay(t);
  // Make servo go to 45 degrees
  servo_2.write(45); 
   delay(t); 
  // Make servo go to 90 degrees 
   servo_2.write(90); 
   delay(t);
  // Make servo go to 90 degrees 
   servo_2.write(135); 
   delay(t);
   // Make servo go to 180 degrees 
   servo_2.write(180); 
  delay(t);
    //end #1 servo motor code
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

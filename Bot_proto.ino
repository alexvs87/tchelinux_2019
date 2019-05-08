/*
================================================================================

    File........... Bot_proto.ino
    Purpose........ To demonstrate how to interface to a buttons and a breadboard
    Author......... Alex Veloso
    E-mail......... alexvs @ gmail.com
    Started........ 16/04/2019
    Finished....... 27/04/2019
    Updated........ --/--/----
 
================================================================================
   Notes
================================================================================
 

- The order of pins for the buttons is shown in the table below:

        Bit# | Button   
        --------------
          0  |   Left  
        --------------
          1  |   Down  
        --------------
          2  |   Up    
        --------------
          3  | Right  
        --------------
          4  |   a  
        --------------
          5  |  b
        --------------
          6  |  c 
        --------------
                

================================================================================
  Updates
================================================================================
*/

//===============================================================================
//  Header Files
//===============================================================================

//===============================================================================
//  Constants
//===============================================================================
// 
 #include "Keyboard.h" //Arduino Leonardo

 
 
//===============================================================================
//  Pin Declarations
//===============================================================================
//Inputs:
 
const int left          = 0;  
const int down          = 1;
const int up            =2;   
const int right         =3;
const int button1       =4;
const int button2       =5;
const int button3       =6; 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


 
//===============================================================================
//  Initialization
//===============================================================================
void setup() 
{
  // Initialize serial port speed for the serial terminal
  Serial.begin(9600);
  
  // Set appropriate pins to inputs
  
  pinMode(left, INPUT);
  pinMode(down, INPUT);
  pinMode(right, INPUT);
  pinMode(up, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(13, OUTPUT); //test to see feedback
   // initialize control over the keyboard:
   Keyboard.begin(); //Arduino Leonardo
}
//===============================================================================
//  Main
//===============================================================================
void loop() 
{
  
  // Slight delay before we debug what was pressed so we don't spam the
  // serial monitor.
   delay(120);
  if (digitalRead(up) == HIGH){
      Serial.println("cima");
       Keyboard.write(218);
  } 
  else if (digitalRead(down) == HIGH){
      Serial.println("abaixo");
       Keyboard.write(217);
  } 
   else if (digitalRead(left) == HIGH){
      Serial.println("ixquerda");
       Keyboard.write(216);
  } 
  else if (digitalRead(right) == HIGH){
      Serial.println("direita");
       Keyboard.write(215);
  } 
  else if (digitalRead(button1) == HIGH){
      Serial.println("BotaoA");
       Keyboard.write(0x61);
  } 
  else if (digitalRead(button2) == HIGH){
      Serial.println("BotaoB");
       Keyboard.write(0x62);
  } 
   else if (digitalRead(button3) == HIGH){
      Serial.println("BotaoC");
       Keyboard.write(0x63);
  }
   else if (Serial.read() == 'a'){
      Serial.println("Liga Led");
       digitalWrite(13,HIGH);
  }
   else if (Serial.read() == 'b'){
      Serial.println("Desliga Led");
       digitalWrite(13,LOW);
  }
}

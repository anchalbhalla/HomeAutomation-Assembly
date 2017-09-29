

#define LDRpin A0 // analog pin where we connected the LDR and the resistor

int LDRValue = 0;   // result of reading the analog pin 
int pinOut = 3;   //digital pin where the relay / led is connected



void setup() {
  Serial.begin(9600); // sets serial port for communication (bits sent)
  while(!Serial)
  {}

  pinMode(3, OUTPUT);
  digitalWrite(pinOut, LOW);
  
  
}

void loop() {
  
  LDRValue = analogRead(LDRpin); // read the value from the LDR
        
  if(LDRValue>50) //there is light then print 1 (change the value of 50 as required)
    Serial.println(1); //write to the serial monitor which also be read by python
  else
    Serial.println(0);  

  
  
  delay(1000); //wait for 1 second

 if(Serial.available())
    {
      Serial.print("gonna print");
      char ch = Serial.read(); //get the value from python code
      Serial.println(ch); 
      if(ch==97) 
      { 
        digitalWrite(pinOut, HIGH);  //switch on light if 'a' is sent by python code
         
      }
       else if (ch ==98) 
        digitalWrite(pinOut, LOW); //switch off light if 'b' is sent by python code
    } 

  }


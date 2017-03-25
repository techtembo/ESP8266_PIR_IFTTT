// written by Edwin Cheung

// This is a free software protected by the creative commons license

// This is for as is use and there may be bugs and other issues.

// map variable names to pins on the microcontroller
int ledpin = 13; //D7
int pirpin = 4;  //D2
int buzzerpin = 5; //D1

// initialize variable for PIR status
int val = 0;

void setup(){
  Serial.begin(115200);
  delay(2000);
  pinMode(ledpin,OUTPUT);
  pinMode(pirpin,INPUT);
}

void loop() {
  val = digitalRead(pirpin); // check status of motion sensor
  Serial.println(val);
  if(val == HIGH){           // if motion is detected
    Serial.println("Motion Detected!");
    
    // light up the LED
    digitalWrite(ledpin,HIGH);  
    
    // play alert sound 
    tone(buzzerpin, 523, 500) ; 
    delay(500);
    tone(buzzerpin, 494, 300) ;
    delay(500);
    tone(buzzerpin, 523, 500) ;
    delay(500);
    tone(buzzerpin, 494, 300) ;
    delay(500);
    pinMode(buzzerpin, INPUT);


    // wait 10 seconds before rearming motion detector
    delay(10000);

    // turn off LED
    digitalWrite(ledpin,LOW);
  }
}


// written by Edwin Cheung

// This is a free software protected by the creative commons license

// This is for as is use and there may be bugs and other issues.

// map variable names to pins on the microcontroller
int ledpin = 13; //D7

void setup(){
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // light up the LED
  digitalWrite(ledpin,HIGH);  

  // wait 1 second
  delay(1000);

  // turn off LED
  digitalWrite(ledpin,LOW);

  // wait 1 second
  delay(1000);
}


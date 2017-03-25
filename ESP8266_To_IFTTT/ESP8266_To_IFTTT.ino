// written by Edwin Cheung

// This is a free software protected by the creative commons license

// This is for as is use and there may be bugs and other issues.

#include "DataToMaker.h"
#include <ESP8266WiFi.h>

// customize these settings
const char* ssid = "xxxx";
const char* password = "xxxx";
const char* myKey = "xxxx";

// declare new maker event with the name "HPL_Alert"
DataToMaker event(myKey, "HPL_Alert");

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
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
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
    noTone(buzzerpin);

   
    // send event to IFTTT
    Serial.println(F("Trigger IFTTT"));
    if (event.connect())
        {
          Serial.println("Connected To Maker");
          event.post();
        }
    else Serial.println("Failed To Connect To Maker!");

    // wait 10 seconds before rearming motion detector
    delay(10000);

    // turn off LED
    digitalWrite(ledpin,LOW);
  }
}


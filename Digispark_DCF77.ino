/*
 * InternalClockSync.ino 
 * example code illustrating time synced from a DCF77 receiver
 * Thijs Elenbaas, 2012-2017
 * This example code is in the public domain.
 
  This example shows how to fetch a DCF77 time and synchronize
  the internal clock. In order for this example to give clear output,
  make sure that you disable logging  from the DCF library. You can 
  do this by commenting out   #define VERBOSE_DEBUG 1   in Utils.cpp. 
  
  NOTE: If you used a package manager to download the DCF77 library, 
  make sure have also fetched these libraries:

 * Time 
  
 */

#include "DCF77.h"
#include "TimeLib.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);

#define DCF_PIN 2           // Connection pin to DCF 77 device
#define DCF_INTERRUPT 0    // Interrupt number associated with pin
#define P1_PIN 3

time_t time;
DCF77 DCF = DCF77(DCF_PIN,DCF_INTERRUPT);


void setup() {
  mySerial.begin(9600);
  pinMode(P1_PIN, OUTPUT);
  digitalWrite(P1_PIN, HIGH); 
  delay(1000); 
  digitalWrite(P1_PIN, LOW); 
  DCF.Start();
  mySerial.println("Waiting for DCF77 time ... ");
  mySerial.println("It will take at least 2 minutes until a first update can be processed.");
}

void loop() {
  delay(1000);
  time_t DCFtime = DCF.getTime(); // Check if new DCF77 time is available
  if (DCFtime!=0)
  {
    mySerial.println("Time is updated");
    setTime(DCFtime);
  } 
  digitalClockDisplay();  
}

void digitalClockDisplay(){
  // digital clock display of the time
  mySerial.print(hour());
  printDigits(minute());
  printDigits(second());
  mySerial.print(" ");
  mySerial.print(day());
  mySerial.print(" ");
  mySerial.print(month());
  mySerial.print(" ");
  mySerial.print(year()); 
  mySerial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  mySerial.print(":");
  if(digits < 10)
    mySerial.print('0');
  mySerial.print(digits);
}

/* 
 * Main Algorithm Test Code
 * 
 * Written by Michael Sidler
 * 
 */

#include <Arduino.h>
#include "boardsetup.h"
#include "binaryArraySearch.h"

void setup() {

  // Setup pins
  pinMode(LED_BUILTIN,OUTPUT);

  // Setup serial communication to PC
  SerialPC.begin(9600);
  while(!SerialPC);
  delay(SERIALDELAY);
  SerialPC.println("\r\n");
  SerialPC.println(BOARDINFO);
  SerialPC.print("f_cpu = ");
  SerialPC.print(F_CPU/1000000);
  SerialPC.println(" MHz");
  SerialPC.print("sizeof(int) = ");
  SerialPC.print(sizeof(int)*8);
  SerialPC.println( "bits");
  SerialPC.println("\r\n");
  
  // Run Individual Tests
  binaryArrSearchTester();

}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}


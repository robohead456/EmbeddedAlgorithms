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
  
  // Variables
  uint32_t startTime = 0;
  uint32_t endTime = 0;
  uint32_t sumTime = 0;
  uint32_t numIterations = 65536;

  ////   Main Test
  //      Runs many tests with each variation of the algorithm
  //      Average and record test times

  SerialPC.print("BinArrSrt (=<>): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_elg(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

  sumTime = 0;
  SerialPC.print("BinArrSrt (=><): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_egl(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

  sumTime = 0;
  SerialPC.print("BinArrSrt (>=<): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_gel(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

  sumTime = 0;
  SerialPC.print("BinArrSrt (><=): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_gle(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

  sumTime = 0;
  SerialPC.print("BinArrSrt (<>=): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_lge(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

  sumTime = 0;
  SerialPC.print("BinArrSrt (<=>): ");
  for(uint32_t i = 0; i < numIterations; i++) {
    startTime = micros();
    binaryArrSearch_leg(values, numValues, (uint32_t)4095);
    endTime = micros();
    sumTime += endTime-startTime;
  }
  SerialPC.print(sumTime/(float)numIterations);
  SerialPC.println(" us");

}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
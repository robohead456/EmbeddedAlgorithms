/* 
 * Board Setup File
 * 
 * Written by Michael Sidler
 * 
 * Uses build flags set in the platformio.ini file to change parameters in the code
 * 
 * SerialPC     = the serial port used to send data to the host computer
 * BOARDINFO    = A string to print with the details of the microcontroller
 * SERIALDELAY  = Delay after starting the serial port to allow the computer to connect
 * 
 */

#ifdef MEGA2560
  #define SerialPC Serial
  #define BOARDINFO "Arduino Mega (ATMega2560)"
  #define SERIALDELAY 5000
#endif

#ifdef SAMD21
  #define SerialPC SerialUSB
  #define BOARDINFO "Sparkfun SAMD21 Dev Breakout (ATSAMD21 / ARM Cortex M0+)"
  #define SERIALDELAY 500
#endif

#ifdef SAMD51
  #define SerialPC Serial
  #define BOARDINFO "Adafruit Grand Central (ATSAMD51 / ARM Cortex M4)"
  #define SERIALDELAY 500
#endif
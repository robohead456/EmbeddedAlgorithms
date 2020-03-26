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
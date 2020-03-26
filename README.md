# Embedded Algorithms

This repository will hold libraries for various search/sort algorithms as well as tests for optimization.

The tests will be performed on the following development boards
 - Arduino Mega 2560 (8-bit ATMEL CPU, 16MHz clock)
 - Sparkfun SAMD21 Dev Breakout (32-bit ARM Cortex M0+ CPU, 48MHz clock)
 - Adafruit Grand Central (32-bit ARM Cortex M4 CPU, 120MHz clock

## Testing and Optimization

The first algorithm tested was a binary array search, to determine if an element is contained in a sorted array. Six variations of the algorithm were written - each varying the order in which the comparisons are done. The snippet below compares `rc < 0` first, then `rc > 0`, and lastly `rc == 0`. 

```c
template<typename T>
static bool binaryArrSearch_lge(T *arr, int len, T target) {
  int low = 0;
  int high = len-1;

  while(low <= high) {
    int mid = (low+high)/2;
    int rc = arr[mid] - target;

    if(rc < 0)          low = mid+1;
    else if(rc > 0)     high = mid-1;
    else                return true;
  }
  return false;
}
```

A random set of 1024 test values were created with a range of [0, 65535] and searched for the value 4095. Each algorithm was run 65536 times and the search time was averaged. The results are as follows:

Algorithm \ Board     |ATMega2560 | SAMD21 | SAMD51
-----|-----------|--------|-------
 =<> | 22.27us   | 6.40us | 2.17us
 =>< | 21.26us   | 7.13us | 2.16us
 \>=< | 22.40us   | 6.67us | 2.07us
 \><= | 22.40us   | 6.65us | 2.07us
 <>= | 22.40us   | 6.48us | 2.10us
 <=> | 22.40us   | 6.50us | 2.10us

## Configuring for different boards

The code is set up as a PlatformIO project, to add another development board it must be added to the platformio.ini configuration file.
Some definitions must also be added to src/boardsetup.h

#ifndef PB_h // Header guard to avoid multiple inclusion of header file
#define PB_h 

#include <Arduino.h> // Include Arduino header file

class PB { // Definition of the PB class
  public:
    PB(int pin); // Constructor implementation for creating a PB instance with specified pin
    bool isPressed(); // Method implementation for checking if the button is pressed
  private:
    int _pin; 
    bool _lastState; // Record of final button state
    unsigned long _lastChangeTime; // The time when the final button state last modified
    unsigned long _debounceDelay; // The amount of time dellay needed to get rid of debounce
};

#endif // indicate the ending of the piece of code to compile

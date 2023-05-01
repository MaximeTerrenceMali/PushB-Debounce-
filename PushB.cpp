#include "PB.h" // Includes headerfile for the pushbutton

PB::PB(int pin) { // Constructor implementation for PB class
  _pin = pin;
  _lastState = false; // Sets the initial state of the pushbutton to false(0)
  _lastChangeTime = 0; // The last change time is reset to 0
  _debounceDelay = 50; // The delay for the debounce is now 50milliseconds
  pinMode(_pin, INPUT_PULLUP); //The button is set as an input and includes the pull up resistor
}

bool PB::isPressed() { // isPressed method implementation
  bool currentState = !digitalRead(_pin); // Depending on the current state of the button when pushed,it will be read(Logic reversed by pullup resistor)
  unsigned long currentTime = millis(); // Current time is set to milliseconds
  if (currentState != _lastState) { // Verifies changes made on the state of pushbutton
    _lastChangeTime = currentTime; // Record the time of state change
  }
  if ((currentTime - _lastChangeTime) > _debounceDelay) { // Verifies if sufficient time has elapsed since last change
    if (currentState != _lastState) { // Verifies if the state has been changed
      _lastState = currentState; // Record the found state
      return _lastState; // Return the found state
    }
  }
  return false; // Button is not pressed
}

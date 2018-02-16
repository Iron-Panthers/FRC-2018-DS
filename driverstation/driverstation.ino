#include <Joystick.h>

#define ELEVATOR_SLIDER A0
#define MISC_BUTTON_BOI 5  // redefine pls

Joystick_ joystick;

void setup() {
  pinMode(ELEVATOR_SLIDER, INPUT);
  pinMode(MISC_BUTTON_BOI, OUTPUT);
  joystick.begin();
}

void loop() {
  int16_t elevator = analogRead(ELEVATOR_SLIDER);
  bool buttonA = digitalRead(MISC_BUTTON_BOI);
  
  joystick.setXAxis(elevator);
  joystick.setButton(0, millis() % 1000 > 500);  // currently to test output
  joystick.setButton(1, buttonA);
}

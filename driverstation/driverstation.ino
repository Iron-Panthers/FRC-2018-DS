
#include <Joystick.h>

#define ELEVATOR_SLIDER A0

Joystick_ joystick;
int buttons[12] = {7, A1, 8, A5, A2, 12, A4, A3, 2, 13, 0, 4};

void setup() {
  pinMode(ELEVATOR_SLIDER, INPUT);

  for (int i=0; i < 12; i++) {
    pinMode(buttons[i], INPUT);
  }
  joystick.begin();
}

void loop() {
  int16_t elevator = 1024 - analogRead(ELEVATOR_SLIDER);

  for (int i=0; i < 12; i++) {
    joystick.setButton(i, !digitalRead(buttons[i]));
  }
  joystick.setXAxis(elevator);
}


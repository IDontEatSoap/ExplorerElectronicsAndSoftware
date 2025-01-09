#include <Arduino.h>
#include "FastAccelStepper.h"

#define dirPinStepper    5
#define enablePinStepper 6
#define stepPinStepper   9

// If using an AVR device use the definitons provided in AVRStepperPins
//    stepPinStepper1A
//
// or even shorter (for 2560 the correct pin on the chosen timer is selected):
//    stepPinStepperA

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;

void setup() {
   engine.init();
   stepper = engine.stepperConnectToPin(stepPinStepper);
   if (stepper) {
      stepper->setDirectionPin(dirPinStepper);
      stepper->setEnablePin(enablePinStepper);
      stepper->setAutoEnable(true);

      int rpm = 700;
      int rotations = 10;
      int reduction = 50;
      int microstep = 16;
      int accelerationIndex = 10;

      stepper->setSpeedInHz(200*microstep*rpm/60);       // 500 steps/s
      stepper->setAcceleration(accelerationIndex*200*microstep);    // 100 steps/s²      
      stepper->move(200*microstep*rotations*reduction);
   }
}

void loop() {
}
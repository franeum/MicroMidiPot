// include the ResponsiveAnalogRead library
#include <MicroMidiPot.h>

// define the pin you want to use
const int PINPOT1 = A0;
const int PINPOT2 = A1;

MicroMidiPot pot1, pot2;

void setup()
{
  // begin serial so we can see analog read values through the serial monitor
  pot1.begin(PINPOT1, 0, 50);
  pot2.begin(PINPOT2, 0, 100, "POT2");
  Serial.begin(115200);
}

void loop()
{
  // update the ResponsiveAnalogRead object every loop
  pot1.update();
  pot2.update();
  delay(1);
}
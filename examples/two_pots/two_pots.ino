#include <MicroMidiPot.h>

#define PINPOT1 A0
#define PINPOT2 A1

MicroMidiPot pot1, pot2;

void setup()
{
  pot1.begin(PINPOT1, 0, 50, "POT1");
  pot2.begin(PINPOT2, 0, 100, "POT2");
  Serial.begin(115200);
}

void loop()
{
  pot1.update();
  pot2.update();
  delay(1);
}
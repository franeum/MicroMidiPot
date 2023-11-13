#include <MicroMidiPot.h>

#define PINPOT1 A0
#define PINPOT2 A1

MicroMidiPot pot1, pot2;

void setup()
{
  pot1.begin(PINPOT1, 1, 50, "POT1");
  pot2.begin(PINPOT2, 1, 100, "POT2");
}

void loop()
{
  pot1.update();
  pot2.update();
}
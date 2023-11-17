#include <MicroMidiPot.h>

#define PINPOT1 A0

// create MicroMidiPot instance
MicroMidiPot pot1;

void setup()
{
  /*
    Initialize with these args:
      1. pin
      2. midi channel (1 - 16)
      3. midi controller number (0 - 127)
      4. a string representing the pot (optional, only for debug purpose)
    */
  pot1.begin(PINPOT1, 1, 50, "POT1");

  // reverse direction
  // pot1.set_reverse();

  // disable serial monitoring if you want
  // MicroMidiPot::set_debug(0);
}

void loop()
{
  // call update() method: it makes all (read value, smooth and send midi)
  pot1.update();
}
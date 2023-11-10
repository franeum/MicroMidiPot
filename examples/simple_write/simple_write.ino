#include <MicroMidiPot.h>

#define PINPOT1 A0

// create MicroMidiPot instance
MicroMidiPot pot1;

void setup()
{
  /*
    Initialize with these args:
      1. pin
      2. midi channel (starting from 0)
      3. midi controller number (0 - 127)
      4. a string representing the pot (optional, only for debug purpose)
    */
  pot1.begin(PINPOT1, 0, 50, "POT1");

  // Initialize serial port to read values on serial monitor
  Serial.begin(115200);
}

void loop()
{
  // call update() method: it makes all (read value, smooth and send midi)
  pot1.update();
  delay(1);
}
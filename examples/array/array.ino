#include <MicroMidiPot.h>

#define MIDI_CHANNEL 0

const int PIN_POTS[] = {A0, A1};
const int N_CONTROLLERS[] = {50, 100};

MicroMidiPot *pot[2];

void setup()
{
  for (int i = 0; i < 2; i++)
    pot[i] = new MicroMidiPot(PIN_POTS[i], MIDI_CHANNEL, N_CONTROLLERS[i], "POT " + String(i));

  Serial.begin(115200);
}

void loop()
{
  for (int i = 0; i < 2; i++)
    pot[i]->update();

  delay(1);
}
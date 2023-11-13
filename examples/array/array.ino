#include <MicroMidiPot.h>

#define MIDI_CHANNEL 1
#define NUMBER 3

const int PIN_POTS[] = {A0, A1, A2};
const int N_CONTROLLERS[] = {50, 51, 52};

MicroMidiPot *pot[NUMBER];

void setup()
{
  for (int i = 0; i < NUMBER; i++)
    pot[i] = new MicroMidiPot(PIN_POTS[i], MIDI_CHANNEL, N_CONTROLLERS[i], "POT " + String(i));
}

void loop()
{
  for (int i = 0; i < NUMBER; i++)
    pot[i]->update();
}
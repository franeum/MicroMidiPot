#include "MicroMidiPot.h"

void MicroMidiPot::begin(int pin, byte channel, byte controller)
{
    ResponsiveAnalogRead analog(pin, true);
    pot = &analog;
}

void MicroMidiPot::update()
{
    pot->update();

    if (pot->hasChanged)
    {
        /*
            1. Prendi il valore (se è cambiato)
            2. Taglia i bordi (primi n valori e ultimi n valori)
            3. Scala in MIDI value
            4. Spedisci MIDI
        */
        int value = pot->getValue();
    }
}

void MicroMidiPot::send() {}
void MicroMidiPot::scale() {}

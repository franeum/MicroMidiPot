#include <Arduino.h>
#include "MicroMidiPot.h"

void MicroMidiPot::begin(int pin, byte channel, byte controller)
{
    pot = ResponsiveAnalogRead analog(pin, true);
}

void MicroMidiPot::update()
{
    pot.update();

    if (pot.hasChange)
    {
        /*
            1. Prendi il valore (se è cambiato)
            2. Taglia i bordi (primi n valori e ultimi n valori)
            3. Scala in MIDI value
            4. Spedisci MIDI
        */
    }
}

void MicroMidiPot::send() {}
void MicroMidiPot::scale() {}

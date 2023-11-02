#ifndef MICRO_MIDI_POT_H
#define MICRO_MIDI_POT_H

#include <Arduino.h>
#include <ResponsiveAnalogRead.h>
#include <MIDIUSB.h>

void controlChange(byte channel, byte control, byte value)
{
    midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
    MidiUSB.sendMIDI(event);
}

class MicroMidiPot
{
public:
    // pin - the pin to read
    // midi channel to send
    // controller number

    MicroMidiPot(){};
    MicroMidiPot(int pin, byte channel, byte controller)
    {
        begin(pin, channel, controller);
    };

    void begin(int pin, byte channel, byte controller);
    void update();

private:
    int pin;
    ResponsiveAnalogRead pot;
    int previous_value;
    void send();
    float scale();
};

#endif

#ifndef MICRO_MIDI_POT_H
#define MICRO_MIDI_POT_H

#include <Arduino.h>
#include <ResponsiveAnalogRead.h>
#include <MicroMidiUtils.h>

#define MIDICTL_MIN 0
#define MIDICTL_MAX 127
#define BOUND_MIN 100
#define BOUND_MAX 900

class MicroMidiPot
{
public:
    MicroMidiPot(){};
    MicroMidiPot(int pin, byte channel, byte controller, String identifier = "POT")
    {
        begin(pin, channel, controller, identifier);
    };

    static void setDebug(int value);
    void begin(int pin, byte channel, byte controller, String identifier = "POT");
    void update();

private:
    static int _debug;
    int pin;
    ResponsiveAnalogRead *pot;
    int previous_value;
    byte _channel;
    byte _controller;
    void send(int value);
    // void controlChange(byte channel, byte n_controller, byte value);
    int parseValue(int v);
    String _id;
};

#endif

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

    static void set_debug(byte value);
    void begin(int pin, byte channel, byte controller, String identifier = "POT");
    void update();
    inline void set_reverse() { reverse = true; };
    inline void set_forward() { reverse = false; };

private:
    static int _debug;
    bool reverse = false;
    int pin;
    ResponsiveAnalogRead *pot;
    int previous_value;
    byte _channel;
    byte _controller;
    void send(int value);
    int parseValue(int v);
    String _id;
};

#endif

#include "MicroMidiPot.h"

int MicroMidiPot::_debug = 1; // initializing the static int

void MicroMidiPot::begin(int pin, byte channel, byte controller, String identifier)
{
    _id = identifier;
    _channel = channel;
    _controller = controller;
    pot = new ResponsiveAnalogRead(pin, true);
}

void MicroMidiPot::update()
{
    pot->update();

    // Serial.println(pot->getRawValue());

    if (pot->hasChanged())
    {
        int value = pot->getValue();
        int current_value = this->parseValue(value);

        if (previous_value != current_value)
        {
            if (_debug)
            {
                Serial.print(_id);
                Serial.print(" ");
                Serial.println(current_value);
            }

            this->send(current_value);
            previous_value = current_value;
        }
    }
}

int MicroMidiPot::parseValue(int v)
{
    int parsed = constrain(v, BOUND_MIN, BOUND_MAX) - BOUND_MIN;
    parsed = map(parsed, 0, BOUND_MAX - BOUND_MIN, MIDICTL_MIN, MIDICTL_MAX);
    return parsed;
}

void MicroMidiPot::controlChange(byte channel, byte n_controller, byte value)
{
    midiEventPacket_t event = {0x0B, 0xB0 | channel, n_controller, value};
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}

void MicroMidiPot::send(int value)
{
    this->controlChange(_channel, _controller, value);
}

void MicroMidiPot::setDebug(int value)
{
    _debug = value;
}

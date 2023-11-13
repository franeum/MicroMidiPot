#include "MicroMidiPot.h"

int MicroMidiPot::_debug = 1;

void MicroMidiPot::begin(int pin, byte channel, byte controller, String identifier)
{
    _id = identifier;
    _channel = check_channel(channel);
    _controller = controller;
    pot = new ResponsiveAnalogRead(pin, true);
}

void MicroMidiPot::update()
{
    pot->update();

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

void MicroMidiPot::send(int value)
{
    control_change(_channel, _controller, value);
}

void MicroMidiPot::set_debug(byte value)
{
    _debug = value;
}

#ifndef MICRO_MIDI_UTILS_H
#define MICRO_MIDI_UTILS_H

#include <MIDIUSB.h>

byte check_channel(byte ch);
void control_change(byte channel, byte n_controller, byte value);

#endif
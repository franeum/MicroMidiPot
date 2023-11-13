#include <MicroMidiUtils.h>

byte check_channel(byte ch)
{
    return ch > 0 && ch < 17 ? ch - 1 : 0;
}

void controlChange(byte channel, byte n_controller, byte value)
{
    midiEventPacket_t event = {0x0B, 0xB0 | channel, n_controller, value};
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}
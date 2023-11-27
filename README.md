# micromidipot
by [francesco bianchi](https://wwwfrancescobianchi.cloud)

Arduino Library to use a potentiometer as MIDI controller (via USB). It currently run only on ATmega32U4 (Micro and Leonardo).

Tha API is based on ICU paradigm: Instatiate-Configure-Update and you can use a potentiometer with only 3 lines of code:

```c++
#include <MicroMidiEnc.h>

// Instantiate
MicroMidiPot pot;

void setup() {
    // Configure (pin1, MIDI_CHANNEL (1-16), MIDI_CONTROLLER, LABEL_FOR_DEBUG)
    pot.begin(A0, 1, 70, "POT1");
}

void loop() {
    // Update
    pot.update();

    // ...all done!
}
```

Credits:
- Damien Clarke, [ResponsiveAnalogRead Library](https://github.com/dxinteractive/ResponsiveAnalogRead)



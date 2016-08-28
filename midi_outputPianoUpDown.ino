///////////////////////////////////////////////////////////
//  midi_output.ino                                      //
//  Example: MIDI Output                                 //
//  https://github.com/ddiakopoulos/hiduino              //
//  Last Updated: 17 December 2015                       //
///////////////////////////////////////////////////////////

#include <MIDI.h>

const int channel = 1;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() 
{
    MIDI.begin(MIDI_CHANNEL_OMNI);
}


void loop() {
  int note;
  for (note=20; note <= 108; note++) {
    MIDI.sendNoteOn(note, 100, channel);
    delay(75);
    MIDI.sendNoteOff(note, 100, channel);
  }

  for (note=108; note >= 20; note--) {
    MIDI.sendNoteOn(note, 100, channel);
    delay(75);
    MIDI.sendNoteOff(note, 100, channel);
  }
  delay(500);
}


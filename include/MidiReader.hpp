#ifndef MIDI_READER
#define MIDI_READER

#include "MidiFile.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using namespace std;
using namespace smf;

class MidiReader {

    public:
        vector<int> * ReadMidiFile(std::string absolute_path);

};

#endif
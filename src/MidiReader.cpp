#include "MidiReader.hpp"

using namespace smf;

vector<int> * MidiReader::ReadMidiFile(std::string absolute_path){

    MidiFile midifile;
    //"/Users/lucasaraujo/projects/CutiaEngine/sample_assets/128bpm.mid"
    midifile.read(absolute_path.c_str());

    if (!midifile.status()) {
        cerr << "Error reading MIDI file " << absolute_path.c_str() << endl;
        exit(1);
    }

    midifile.joinTracks();
    int track = 0;

    for (int i=0; i<midifile[track].size(); i++) {
        if (!midifile[track][i].isNoteOn()) {
            continue;
        }

        int track_key = abs(midifile[track][i].getKeyNumber());
        int tick = midifile[track][i].tick;
        cout << track_key << " - " << tick << endl;
    }

    return new vector<int>;
}
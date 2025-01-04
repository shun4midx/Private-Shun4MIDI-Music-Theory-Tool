/********************************************
 * Copyright (c) 2025 Shun/順海 (@shun4midx) *
 * Project: Shun4MIDI Music Theory Tool     *
 * File: ongoing_spec.cpp                   *
 ********************************************/

// DISCLAIMER: THIS IS A C++ FILE BECAUSE OTHERWISE IT IS TOO HARD TO READ WITHOUT THE AUTO-COLORING

class Manip { // Handle class for all of the possible manips
    class NoteManip { // <- All of Basic
        class Scales; // has-a
        class Intervals; // has-a
        class CircleHarmony; // has-a; Circle of 4ths/5ths

        class JapaneseManip; // is-a
        class CustomManip; // is-a
    };

    class ChordManip { // Handle class for all the chord manips
        friend class NoteManip;

        class MainChordManip; // is-a
        class QuartalManip; // is-a
        class WholeToneManip; // is-a
    };
};

class MusicalPhrase {
    class ConcertPhrase { // has-a; Handle class for WesternMain, Quartal, WholeTone, Japanese, Custom, and Jingles
        friend class Manip;
        
        class Note; // has-a
        class Chord; // has-a; Make it using the Note class instead for ease of calculation? Or store both?
        class Key; // has-a
    };
};

class UserIO { // Deal with user interaction and selecting menu and also *parsing user input* to call the other functions and classes

};
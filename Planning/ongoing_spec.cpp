/********************************************
 * Copyright (c) 2025 Shun/翔海 (@shun4midx) *
 * Project: Shun4MIDI Music Theory Tool     *
 * File Type: Planning spec file            *
 * File: ongoing_spec.cpp                   *
 ********************************************/

// DISCLAIMER: THIS IS A C++ FILE BECAUSE OTHERWISE IT IS TOO HARD TO READ WITHOUT THE AUTO-COLORING

/*
REMINDER OF FUNCTIONALITIES:
Basic:
 - Supports **Circle of 4ths/5ths lookup** beginning at any note/key
 - Supports the instant recall of the notes in the scale and its key signature in **any scale of any mode**. If unspecified which "minor" scale is used, the natural (Aeolian), harmonic, and melodic minor would all be mentioned.
 - Supports the calculation of any interval between notes, remember to specify carefully which octave the two notes are!
 - [FOR FUN]: The Lick/Rickroll/Bad Apple can be transposed to any key and can be outputed any time 😂

Chords:
 - The user can input any chord name with **any chord extensions** (e.g. `Cmaj7b13`), and the desired inversion and/or slash chord, to output the chord to be displayed. Any chord in natural text form (i.e. not staff lines) would output in the order from the lowest to highest note in the chord. The input is straightforward, resembling normal text. Extended or altered dominants are supported.
 - The user can input any chord (with any chord extensions), except with the **note names only** (e.g. `C E G Ab B`), and the program can display the chord in staff line-notation and also **analyze the chord** (e.g. deduce this is a Cmaj7b13 chord). I plan to support different forms of harmony as indicated below with this, so e.g. `C F Bb` is interpreted as "C major quartal" and not some very obscure chord naming that doesn't reflect what this chord does. Extended or altered dominants are supported.
 - The user can check if any chord is in any scale or not, and if it is, which chord in the scale is it?
 - Suggests typical chord progression suggestions/auto-completion
 - Supports to **automatically voice-lead** any given chord progression
 - Supports to display the **modulation** of any chord into the tonic chord of any scale!
 - Supports to suggest a resolution from any chord to another
 - Supports for the user to suggest which chord they may want to borrow in a modulation

Alternate Harmony:
 - Support for **quartal harmony** 😎 (Quartal chord generation based on a root note, any inversion of quartal chords, modal interchange of quartal chords, "Given a (custom) scale or short musical excerpt, how many quartal chords can I generate with notes purely diatonic to the scale excerpt?", etc)
 - Support for **whole-tone harmony** 😍 (Whole-tone chord generation based on a root note, any inversion of whole-tone chords, modal interchange from other modes by weaving in whole-tone harmony if desired, etc)
 - Support for **Japanese pentatonic scales** (Yō-sen/陽旋 or In-sen/陰旋 as selected by the user). More will be revealed when the code is done, but let's just say it blends really well with quartal harmony as a new hybrid of **"J-Pentatonic Harmony" (coined by me, 2025)**, if I can get it worked out, which I'm 90% sure I can 👀 The main idea of what I will offer is modulation between any Yō-sen and In-sen scale, and also some things that are related to hybrid and quartal harmony in these scales (which I call J-Pentatonic Harmony), that I can't yet reveal, since they are relatively new concepts that I don't doubt I may be one of the first to actually document.
 - (*) Support for the inputing of **custom scales/solfège** for analysis, although for the C++ code it will only last for one "Run" attempt and reset afterwards. As of right now, I only support the inputing into a Western-notation equivalent. It will support microtonal notation too. I'm not diving into microtonal harmony at least for the Shun4MIDI Music Theory Tool, but this would be only natural to preserve authenticity of custom scales. There will be an option to include a different rising and falling scale! Transposition of these scales to different starting keys are supported, and visiual representation is offered. When inputed a melody in solfège of a custom scale, basic suggestions with vibrato and gliding will be supported. 
*/

#include <vector>
#include <string>

using namespace std;

class Manip { // Handle class for all of the possible manips
    class NoteManip { // <- All of Basic
        class Scales; // has-a
        class Intervals; // has-a
        class CircleHarmony; // has-a; Circle of 4ths/5ths

        class JapaneseManip; // is-a
        class CustomManip; // is-a, custom solfège uses some parts of MusicalPhrase and not other parts
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
        
        class Note { // has-a
        // REMEMBER: THERE IS A NEED TO REMEMBER WHICH WAY THEY WRITE THE NOTES (with which enharmonic). Going to do so with b = -1, # = 1, bb = -2, etc, and 0 being natural

            friend class Key; // Friend class to calculate any note w.r.t solfege notation

        public:
            static string noteNumToString(double num); // Returns "Custom" if said note of the Note class is not within normal 12-TET
            static string noteStringToNum(string str);
            static string noteSolfege(Key key, Note note);

        protected:
            double note_num; // The note in number, letting 0.0 be middle C, and every half step means an increment/decrement of 1.0 (Double is to accomodate 24-TET)
            double accidental_num;
            string note_name; // E.g. "C#"
        };

        class Chord; // has-a; Make it using the Note class instead for ease of calculation? Or store both?
        class Key { // has-a; Uses the class Note for its notes or else it will be hell to actually code
            friend class Note;
            /*
            MODES: (Order from least flats to most flats is the order I like, i.e. "Lydian to Locrian")
             - Lydian: 1 2 3 #4 5 6 7 1
             - Ionian: 1 2 3 4 5 6 7 1
             - Mixolydian: 1 2 3 4 5 6 b7 1
             - Dorian: 1 2 b3 4 5 6 b7 1
             - Aeolian: 1 2 b3 4 5 b6 b7 1
             - Phrygian: 1 b2 b3 4 5 b6 b7 1
             - Locrian: 1 b2 b3 4 b5 b6 b7 1
            */

            /*
            MINOR SCALES: (Remember to account for all different kinds of minor scales)
             - Natural Minor: 1 2 b3 4 5 b6 b7 1
             - Harmonic Minor: 1 2 b3 4 5 b6 n7 1 
             - Melodic Minor: 1 2 b3 4 5 n6 n7 1
            ^ Note that "n" means "natural" instead of b or #
            */

        public: // Aim for public access, just makes more sense to write under the class Key
            static const string MODES[8]; // {"Custom", "Lydian", "Ionian", "Mixolydian", "Dorian", "Aeolian", "Phrygian", "Locrian"}; static makes it accessible without needing an instance of class Key

        protected:
            vector<Note> notes_scale; // E.g. A B C# D E F# G# A
            vector<string> solfege_scale; // E.g. "do re mi fa sol la ti do"
            bool custom_solfege; // Do we use custom solfege or not
            // Key center can be determined from the first element of the notes_scale or set to C too if custom_solfege is true
        };
    };
};

class UserIO { // Deal with user interaction and selecting menu and also *parsing user input* to call the other functions and classes

};
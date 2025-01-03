# [PRIVATE] Shun4MIDI Music Theory Tool (Shun4MIDI: Part 1)
## Copyright Statement
============================================== <br>
|| Copyright (c) 2025 Shun/順海 (@shun4midx) at Shun4MIDI || <br>
============================================== <br>

## ⚠️ DISCLAIMER ⚠️
DISCLAIMER: THIS IS NOT A TUNER, THIS IS A THEORETICAL MUSIC TOOL THAT DOES NOT HAVE A TUNER OR MICROPHONE DETECTION FUNCTION AS OF RIGHT NOW.

## Table of Contents
1. [What is the Shun4MIDI project?](#what-is-the-shun4midi-project)
2. [Program Description](#program-description)
3. [Functionalities for the C++ Version](#functionalities-for-the-c-version)<br>
    3a. [User Interface](#user-interface)<br>
    3b. [Musical Functions](#musical-functions)<br>
4. [Instructions to Run This Program](#instructions-to-run-this-program)
5. [Upcoming Features](#upcoming-features)
6. [Contact and Updates](#contact-and-updates)


## What is the Shun4MIDI project?
Shun4MIDI, not to be mistaken with my username shun4midx, is officially pronounced as "Shuna" + "MIDI" or "Tsuna" + "MIDI", a fusion of "Tsunami" and "MIDI". It is a spinoff of my name, Shun.

With my experience as a musical composer in high school, I've stumbled across a handful of musical websites, but there was always something missing in my opinion, that there is no website for everything they offer combined, plus even more. It is understandable that the overlap between programmers and musical composers is not that large, but it seems as if there is not enough of a fusion between the two, to create something musical composers would truly dream of using, and that is why I came up with the idea of making Shun4MIDI one day.

Shun4MIDI is my side project (as a busy CS student in college), based on my experience as a musical composer in high school, to create tools for musicians by a musician, or rather a programmer who does music as his side hobby. If you're interested in what music I make, [this](https://youtu.be/fNU0zx5wI3Q) is a project I fully composed in high school, called *"Dissociation"*. I'm not the best at musical composition, but it has always been a huge passion of mine.

## Program Description
The Shun4MIDI Music Theory Tool is Part 1 of the Shun4MIDI project, starting off by creating a program for music theory that musicians dream to have. It is a tool for music theorists that transcends beyond the typical functions of giving you the notes in a major or minor scale or of a chord, or requiring you to visit several websites before you get the necessary information. As of right now, the Shun4MIDI Music Theory Tool is only something **ran without graphic user interface (GUI) offline** (i.e. it is only text-based), but in the future, I will be looking forward towards making it a website. 

Here is a summary of what the Shun4MIDI Music Theory Tool includes:
 - **Explore different musical scales and modes**, including all seven modes, and Japanese Pentatonic scales
 - **Identifying, analyzing, and modulating between chords**, supporting complex Jazz extensions, quartal harmony, whole-tone harmony, and something new I coined: **J-Pentatonic harmony**
 - **Transposing music** specifically also across different instruments, e.g. Bb clarinet to Concert Piano
 - **Visualizing music via staff notation**

For non-programmers, [here](https://replit.com/@shun4midx/Shun4MIDI-Music-Theory-Tool) is a link to the Replit page for the Shun4MIDI Music Theory Tool, featuring instructions below with how to run it. (Now that this README is a preview, it is still a private link you can't access yet, it will be available for acces when the project is fully released)

Although the Shun4MIDI Music Theory Tool is still in its starting stage, I plan to be able to extend it to a more developed form of a music tool, made by not just your average coder, but tailored specifically towards musical composers, to be able to use with ease.

## Functionalities for the C++ Version
### User Interface
Since this is a non-GUI C++ program only as of right now, this program will be run in a terminal as a text-based program. **HOWEVER**, this does not stop it from looking aesthetic! I plan to include **both the note names and the staff line-notation** for every output, but as of right now, the user input can only be inline text in the form of note names and the desired language, which is English. For example, you can only type "Eb Major", but the program would output "Eb F G Ab Bb C D Eb" and also that drawn in the form of staff lines, as demonstrated here:

<pre>
[TREBLE]
No Signature Version:      
F -----------------------------------
                       bO
D -------------------O---------------
                  O
B -------------bO--------------------
            bO
G --------O--------------------------
       O
E -bO--------------------------------

Key Signature:
F -----------------------------------
        b
D -----------------------------------
                  
B --b--------------------------------
            b
G -----------------------------------
       
E -----------------------------------
</pre>

Treble, bass, and alto clef signatures will all be supported. The default is in treble clef, unless the user wants to switch, in which case there will be instructions in the program to type the command to switch to the desired clef.

Leger lines will be encoded.

### Musical Functions
Basic:
 - Supports **Circle of 4ths/5ths lookup** beginning at any note/key
 - Supports the instant recall of the notes in the scale and its key signature in **any scale of any mode**. If unspecified which "minor" scale is used, the natural (Aeolian), harmonic, and melodic minor would all be mentioned.
 - Supports the calculation of any interval between notes, remember to specify carefully which octave the two notes are!
 - [FOR FUN]: The Lick/Rickroll/Bad Apple can be transposed to any key and can be outputed any time 😂

<br> Chords:
 - The user can input any chord name with **any chord extensions** (e.g. `Cmaj7b13`), and the desired inversion and/or slash chord, to output the chord to be displayed. Any chord in natural text form (i.e. not staff lines) would output in the order from the lowest to highest note in the chord. The input is straightforward, resembling normal text. Extended or altered dominants are supported.
 - The user can input any chord (with any chord extensions), except with the **note names only** (e.g. `C E G Ab G`), and the program can display the chord in staff line-notation and also **analyze the chord** (e.g. deduce this is a Cmaj7b13 chord). I plan to support different forms of harmony as indicated below with this, so e.g. `C F Bb` is interpreted as "C major quartal" and not some very obscure chord naming that doesn't reflect what this chord does. Extended or altered dominants are supported.
 - The user can check if any chord is in any scale or not, and if it is, which chord in the scale is it?
 - Suggests typical chord progression suggestions/auto-completion
 - Supports to **automatically voice-lead** any given chord progression
 - Supports to display the **modulation** of any chord into the tonic chord of any scale!
 - Supports to suggest a resolution from any chord to another
 - Supports for the user to suggest which chord they may want to borrow in a modulation

<br> Alternate Harmony:
 - Support for **quartal harmony** 😎 (Quartal chord generation based on a root note, any inversion of quartal chords, modal interchange of quartal chords, "Given a (custom) scale or short musical excerpt, how many quartal chords can I generate with notes purely diatonic to the scale excerpt?", etc)
 - Support for **whole-tone harmony** 😍 (Whole-tone chord generation based on a root note, any inversion of whole-tone chords, modal interchange from other modes by weaving in whole-tone harmony if desired, etc)
 - Support for **Japanese pentatonic scales** (Yō-sen/陽旋 or In-sen/陰旋 as selected by the user). More will be revealed when the code is done, but let's just say it blends really well with quartal harmony as a new hybrid of **"J-Pentatonic Harmony" (coined by me, 2025)**, if I can get it worked out, which I'm 90% sure I can 👀 The main idea of what I will offer is modulation between any Yō-sen and In-sen scale, and also some things that are related to hybrid and quartal harmony in these scales (which I call J-Pentatonic Harmony), that I can't yet reveal, since they are relatively new concepts that I don't doubt I may be one of the first to actually document.
 - (*) Support for the inputing of **custom scales/solfège** for analysis, although for the C++ code it will only last for one "Run" attempt and reset afterwards. As of right now, I only support the inputing into a Western-notation equivalent. It will support microtonal notation too. I'm not diving into microtonal harmony at least for the Shun4MIDI Music Theory Tool, but this would be only natural to preserve authenticity of custom scales. There will be an option to include a different rising and falling scale! Transposition of these scales to different starting keys are supported, and visiual representation is offered. When inputed a melody in solfège of a custom scale, basic suggestions with vibrato and gliding will be supported. 
 
(*) This is because, "Western music theory" isn't the only music theory there is out there, and this is a way to say "I'm not so familiar with other music theory, but this is my way of supporting e.g. Indian ragas and Arabic maqam". There would not be harmonic analysis, since these musical genres do not center around harmony.

*Can you tell quartal harmony and whole-tone melody were a huge hyperfixation of mine in high school? :D Yō-sen and In-sen were fleeting interests of mine too so I loved to see the connections between these forms of music!*

## Instructions to Run This Program
Everything is located at `main.cpp`, you just need to run that file and all instructions will be clear in the program. If you are not familiar with programming, with the Replit link, just press "run", and you'll see the program start running in the "shell". (When the program is finished and this README is not just a preview, I will probably include more detailed instructions after figuring out how to exactly explain how Replit works to a non-programmer, so don't sweat!)

## Upcoming Features
 - Turning this C++ code into an actual website
 - Triple mode input/output with the website, staff lines, piano keys, and text drop-down menus
 - Support for immediate conversion between different instruments, more specifically, between those that are not in concert key
 - Interactive mode between user and tool, e.g. creating something whilst in real-time the tool would transpose too
 - More language versions of both the C++ code and website (I plan to do Japanese, but also some other languages I speak, such as but not limited to: Traditional Chinese, Cantonese, Korean, French, German, and Dutch)
 - Since I'm a full-time student, don't expect it to be done really fast, but I plan to hopefully make the website publishable by late August.
 - **This is just a sneak peek, not an official release yet! Stay tuned for what is about to come, and follow my socials below for more updates! :D**

## Contact and Updates
Feel free to suggest more ideas to me by emailing me at shun4midx@gmail.com or DMing me at @shun4midx on Discord if you feel like you need to have an in depth discussion! These are the <u>**only official ways**</u> to contact me. You may follow my [Twitter](https://x.com/shun4midi_en) and Instagram ([English](https://www.instagram.com/shun4midi_en/) or [Japanese](https://www.instagram.com/shun4midi_jp/)) for official updates or sneak peeks on the Shun4MIDI project (The English one would be the main account which updates the fastest though), but DMs there will not be taken with priority and will likely be ignored.

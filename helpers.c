// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return (fraction[0] - '0') * (8 / (fraction[2] - '0'));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = note[0];       // parse letter, eg. A
    int accidental = 0;          // set accidental initial value
    int octave;

    if (strlen(note) > 2)       // check if length is > 2 to accomodate for cases where accidental is given
    {
        accidental = (note[1] == '#') ? 1 : -1;      // overwrite accidental if it is given
        octave = note[2] - '0';                      // parse octave and cast to int, eg. 4
    }
    else                        // when no accidental given
    {
        octave = note[1] - '0';
    }

    //C: -9, D: -7, E: -5, F: -3, G: -1, A: 0, B: 2
    int letter_vals[7] = {0, 2, -9, -7, -5, -4, -2};
    int note_offset = letter_vals[(int)letter - 65];
    int octave_offset = octave - 4;

    int n = octave_offset * 12 + note_offset + accidental;
    return round(pow(2, n / 12.0) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strcmp("", s)) ? false : true;
}
//
// Created by uwu on 12/18/2020.
//

#ifndef SMOLUI_BITMAPS_H
#define SMOLUI_BITMAPS_H

typedef unsigned char byte;

extern const byte TEST[];


// Font bitmap 8x12
// each byteacter is combined one under another
// Mapping order: 0-9 <empty> . - + A-Z
// To get nth byteacter query for FONT[12*n+k], k \set [0,12[
extern const byte FONT[];

// dmx
// error
// info
// settings
extern const byte ICONS[];

#endif //SMOLUI_BITMAPS_H

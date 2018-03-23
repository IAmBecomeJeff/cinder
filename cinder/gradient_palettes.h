#ifndef GRADIENT_PALETTES_H
#define GRADIENT_PALETTES_H

// From ColorWavesWithPalettes by Mark Kriegsman: https://gist.github.com/kriegsman/8281905786e8b2632aeb

// Gradient Color Palette definitions for 33 different cpt-city color palettes.
//    956 bytes of PROGMEM for all of the palettes together,
//   +618 bytes of PROGMEM for gradient palette code (AVR).
//  1,494 bytes total for all 34 color palettes and associated code.

// Gradient palette "ib_jul01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/xmas/tn/ib_jul01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( ib_jul01_gp ) {
    0, 194,  1,  1,
   94,   1, 29, 18,
  132,  57,131, 28,
  255, 113,  1,  1};

// Gradient palette "es_vintage_57_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_57.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_vintage_57_gp ) {
    0,   2,  1,  1,
   53,  18,  1,  0,
  104,  69, 29,  1,
  153, 167,135, 10,
  255,  46, 56,  4};

// Gradient palette "es_vintage_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_vintage_01_gp ) {
    0,   4,  1,  1,
   51,  16,  0,  1,
   76,  97,104,  3,
  101, 255,131, 19,
  127,  67,  9,  4,
  153,  16,  0,  1,
  229,   4,  1,  1,
  255,   4,  1,  1};

// Gradient palette "es_rivendell_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/rivendell/tn/es_rivendell_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_rivendell_15_gp ) {
    0,   1, 14,  5,
  101,  16, 36, 14,
  165,  56, 68, 30,
  242, 150,156, 99,
  255, 150,156, 99};

// Gradient palette "rgi_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/rgi/tn/rgi_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( rgi_15_gp ) {
    0,   4,  1, 31,
   31,  55,  1, 16,
   63, 197,  3,  7,
   95,  59,  2, 17,
  127,   6,  2, 34,
  159,  39,  6, 33,
  191, 112, 13, 32,
  223,  56,  9, 35,
  255,  22,  6, 38};

// Gradient palette "retro2_16_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/retro2/tn/retro2_16.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE( retro2_16_gp ) {
    0, 188,135,  1,
  255,  46,  7,  1};

// Gradient palette "Analogous_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/red/tn/Analogous_1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Analogous_1_gp ) {
    0,   3,  0,255,
   63,  23,  0,255,
  127,  67,  0,255,
  191, 142,  0, 45,
  255, 255,  0,  0};

// Gradient palette "es_pinksplash_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_pinksplash_08_gp ) {
    0, 126, 11,255,
  127, 197,  1, 22,
  175, 210,157,172,
  221, 157,  3,112,
  255, 157,  3,112};

// Gradient palette "es_pinksplash_07_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_07.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_pinksplash_07_gp ) {
    0, 229,  1,  1,
   61, 242,  4, 63,
  101, 255, 12,255,
  127, 249, 81,252,
  153, 255, 11,235,
  193, 244,  5, 68,
  255, 232,  1,  5};

// Gradient palette "Coral_reef_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/other/tn/Coral_reef.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( Coral_reef_gp ) {
    0,  40,199,197,
   50,  10,152,155,
   96,   1,111,120,
   96,  43,127,162,
  139,  10, 73,111,
  255,   1, 34, 71};

// Gradient palette "es_ocean_breeze_068_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_068.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_068_gp ) {
    0, 100,156,153,
   51,   1, 99,137,
  101,   1, 68, 84,
  104,  35,142,168,
  178,   0, 63,117,
  255,   1, 10, 10};

// Gradient palette "es_ocean_breeze_036_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_036.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_036_gp ) {
    0,   1,  6,  7,
   89,   1, 99,111,
  153, 144,209,255,
  255,   0, 73, 82};

// Gradient palette "departure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/mjf/tn/departure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE( departure_gp ) {
    0,   8,  3,  0,
   42,  23,  7,  0,
   63,  75, 38,  6,
   84, 169, 99, 38,
  106, 213,169,119,
  116, 255,255,255,
  138, 135,255,138,
  148,  22,255, 24,
  170,   0,255,  0,
  191,   0,136,  0,
  212,   0, 55,  0,
  255,   0, 55,  0};

// Gradient palette "es_landscape_64_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_64.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_64_gp ) {
    0,   0,  0,  0,
   37,   2, 25,  1,
   76,  15,115,  5,
  127,  79,213,  1,
  128, 126,211, 47,
  130, 188,209,247,
  153, 144,182,205,
  204,  59,117,250,
  255,   1, 37,192};

// Gradient palette "es_landscape_33_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_33.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_33_gp ) {
    0,   1,  5,  0,
   19,  32, 23,  1,
   38, 161, 55,  1,
   63, 229,144,  1,
   66,  39,142, 74,
  255,   1,  4,  1};

// Gradient palette "rainbowsherbet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/icecream/tn/rainbowsherbet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( rainbowsherbet_gp ) {
    0, 255, 33,  4,
   43, 255, 68, 25,
   86, 255,  7, 25,
  127, 255, 82,103,
  170, 255,255,242,
  209,  42,255, 22,
  255,  87,255, 65};

// Gradient palette "gr65_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr65_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr65_hult_gp ) {
    0, 247,176,247,
   48, 255,136,255,
   89, 220, 29,226,
  160,   7, 82,178,
  216,   1,124,109,
  255,   1,124,109};

// Gradient palette "gr64_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr64_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr64_hult_gp ) {
    0,   1,124,109,
   66,   1, 93, 79,
  104,  52, 65,  1,
  130, 115,127,  1,
  150,  52, 65,  1,
  201,   1, 86, 72,
  239,   0, 55, 45,
  255,   0, 55, 45};

// Gradient palette "GMT_drywet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_drywet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( GMT_drywet_gp ) {
    0,  47, 30,  2,
   42, 213,147, 24,
   84, 103,219, 52,
  127,   3,219,207,
  170,   1, 48,214,
  212,   1,  1,111,
  255,   1,  7, 33};

// Gradient palette "ib15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/general/tn/ib15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( ib15_gp ) {
    0, 113, 91,147,
   72, 157, 88, 78,
   89, 208, 85, 33,
  107, 255, 29, 11,
  141, 137, 31, 39,
  255,  59, 33, 89};

// Gradient palette "Fuschia_7_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/fuschia/tn/Fuschia-7.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Fuschia_7_gp ) {
    0,  43,  3,153,
   63, 100,  4,103,
  127, 188,  5, 66,
  191, 161, 11,115,
  255, 135, 20,182};

// Gradient palette "es_emerald_dragon_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_emerald_dragon_08_gp ) {
    0,  97,255,  1,
  101,  47,133,  1,
  178,  13, 43,  1,
  255,   2, 10,  1};

// Gradient palette "lava_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/lava.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( lava_gp ) {
    0,   0,  0,  0,
   46,  18,  0,  0,
   96, 113,  0,  0,
  108, 142,  3,  1,
  119, 175, 17,  1,
  146, 213, 44,  2,
  174, 255, 82,  4,
  188, 255,115,  4,
  202, 255,156,  4,
  218, 255,203,  4,
  234, 255,255,  4,
  244, 255,255, 71,
  255, 255,255,255};

// Gradient palette "fire_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/fire.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( fire_gp ) {
    0,   1,  1,  0,
   76,  32,  5,  0,
  146, 192, 24,  0,
  197, 220,105,  5,
  240, 252,255, 31,
  250, 252,255,111,
  255, 255,255,255};

// Gradient palette "Colorfull_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Colorfull.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Colorfull_gp ) {
    0,  10, 85,  5,
   25,  29,109, 18,
   60,  59,138, 42,
   93,  83, 99, 52,
  106, 110, 66, 64,
  109, 123, 49, 65,
  113, 139, 35, 66,
  116, 192,117, 98,
  124, 255,255,137,
  168, 100,180,155,
  255,  22,121,174};

// Gradient palette "Magenta_Evening_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Magenta_Evening.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( Magenta_Evening_gp ) {
    0,  71, 27, 39,
   31, 130, 11, 51,
   63, 213,  2, 64,
   70, 232,  1, 66,
   76, 252,  1, 69,
  108, 123,  2, 51,
  255,  46,  9, 35};

// Gradient palette "Pink_Purple_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Pink_Purple.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Pink_Purple_gp ) {
    0,  19,  2, 39,
   25,  26,  4, 45,
   51,  33,  6, 52,
   76,  68, 62,125,
  102, 118,187,240,
  109, 163,215,247,
  114, 217,244,255,
  122, 159,149,221,
  149, 113, 78,188,
  183, 128, 57,155,
  255, 146, 40,123};

// Gradient palette "Sunset_Real_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Sunset_Real.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,  0,  0,
   22, 179, 22,  0,
   51, 255,104,  0,
   85, 167, 22, 18,
  135, 100,  0,103,
  198,  16,  0,130,
  255,   0,  0,160};

// Gradient palette "es_autumn_19_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/autumn/tn/es_autumn_19.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_autumn_19_gp ) {
    0,  26,  1,  1,
   51,  67,  4,  1,
   84, 118, 14,  1,
  104, 137,152, 52,
  112, 113, 65,  1,
  122, 133,149, 59,
  124, 137,152, 52,
  135, 113, 65,  1,
  142, 139,154, 46,
  163, 113, 13,  1,
  204,  55,  3,  1,
  249,  17,  1,  1,
  255,  17,  1,  1};

// Gradient palette "BlacK_Blue_Magenta_White_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Blue_Magenta_White.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Blue_Magenta_White_gp ) {
    0,   0,  0,  0,
   42,   0,  0, 45,
   84,   0,  0,255,
  127,  42,  0,255,
  170, 255,  0,255,
  212, 255, 55,255,
  255, 255,255,255};

// Gradient palette "BlacK_Magenta_Red_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Magenta_Red.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Magenta_Red_gp ) {
    0,   0,  0,  0,
   63,  42,  0, 45,
  127, 255,  0,255,
  191, 255,  0, 45,
  255, 255,  0,  0};

// Gradient palette "BlacK_Red_Magenta_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Red_Magenta_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Red_Magenta_Yellow_gp ) {
    0,   0,  0,  0,
   42,  42,  0,  0,
   84, 255,  0,  0,
  127, 255,  0, 45,
  170, 255,  0,255,
  212, 255, 55, 45,
  255, 255,255,  0};

// Gradient palette "Blue_Cyan_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/Blue_Cyan_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Blue_Cyan_Yellow_gp ) {
    0,   0,  0,255,
   63,   0, 55,255,
  127,   0,255,255,
  191,  42,255, 45,
  255, 255,255,  0};



// Gradient palette "bhw1_greeny_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_greeny.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_greeny_gp ) {
    0,   0,  0,  0,
   39,   7, 55,  8,
   99,  42,255, 45,
  153,   7, 55,  8,
  255,   0,  0,  0};

// Gradient palette "bhw1_26_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_26.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_26_gp ) {
    0, 107,  1,205,
   35, 255,255,255,
   73, 107,  1,205,
  107,  10,149,210,
  130, 255,255,255,
  153,  10,149,210,
  170,  27,175,119,
  198,  53,203, 56,
  207, 132,229,135,
  219, 255,255,255,
  231, 132,229,135,
  252,  53,203, 56,
  255,  53,203, 56};

// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_28_gp ) {
    0,  75,  1,221,
   30, 252, 73,255,
   48, 169,  0,242,
  119,   0,149,242,
  170,  43,  0,242,
  206, 252, 73,255,
  232,  78, 12,214,
  255,   0,149,242};

// Gradient palette "bhw2_23_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_23.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_23_gp ) {
    0,   0,  0,  0,
   66,  57,227,233,
   96, 255,255,  8,
  124, 255,255,255,
  153, 255,255,  8,
  188,  57,227,233,
  255,   0,  0,  0};

  
// Gradient palette "bhw2_22_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_22.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_22_gp ) {
    0,   0,  0,  0,
   99, 227,  1,  1,
  130, 249,199, 95,
  155, 227,  1,  1,
  255,   0,  0,  0};

// Gradient palette "bhw2_49_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_49.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_49_gp ) {
    0,   9, 15, 15,
   40,   0, 55, 45,
   86,   9, 15, 15,
  130,  29, 41, 62,
  170,   9, 15, 15,
  211,  64,  8,199,
  255,   6,  1, 22};

  // Gradient palette "bhw2_10_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_10.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_10_gp ) {
    0,   0, 12,  0,
   61, 153,239,112,
  127,   0, 12,  0,
  165, 106,239,  2,
  196, 167,229, 71,
  229, 106,239,  2,
  255,   0, 12,  0};

  // Gradient palette "bhw2_14_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_14.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw2_14_gp ) {
    0,   0,  0,  8,
   45,   0,  0, 45,
   79,   7, 12,255,
  119,  42, 55,255,
  158,   7, 12,255,
  209,   0,  0, 45,
  255,   0,  0,  8};

  // Gradient palette "bhw3_21_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_21.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw3_21_gp ) {
    0,   1, 40, 98,
   48,   1, 65, 68,
   76,   2,161, 96,
  104,   0, 81, 25,
  130,  65,182, 82,
  153,   0, 86,170,
  181,  17,207,182,
  204,  17,207,182,
  255,   1, 23, 46};

  // Gradient palette "bhw3_30_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_30.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw3_30_gp ) {
    0,   1,  4,  1,
   12,   1, 28,  2,
   28,  16, 68, 11,
   58,  18, 11, 28,
   79,  31, 27, 48,
   96,   2, 13, 34,
  117,  30, 86,123,
  135,   2, 42, 62,
  153,  74,128,155,
  181,  60, 31, 41,
  214, 167,211,223,
  237, 179, 70, 78,
  255,  57,  2,  7};

// Gradient palette "cw1_029_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/1/tn/cw1-029.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE( cw1_029_gp ) {
    0,  12, 80,210,
  127, 255,235, 19,
  255, 224, 66, 15};

// Gradient palette "alarm_p4_0_2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/dca/tn/alarm.p4.0.2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.

DEFINE_GRADIENT_PALETTE( alarm_p4_0_2_gp ) {
    0, 227,255,223,
   12, 255, 36,  4,
   25, 255,  2,  1,
   38, 255,  1, 16,
   51, 255,  1, 98,
   63, 255,  1,230,
   76, 140,  1,255,
   89,  63,  1,255,
  102,  24,  1,255,
  114,   5,  1,255,
  127,   1,  1,255,
  140,   1,  4,255,
  153,   1, 16,255,
  165,   1, 36,255,
  178,   1, 62,255,
  191,   1, 95,255,
  204,   1,131,255,
  216,   1,173,255,
  229,   1,221,255,
  242,   1,255,235,
  255,   1,255,186};

// Gradient palette "Ribbon_Colors_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Ribbon-Colors.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( Ribbon_Colors_gp ) {
    0, 227,  2,  9,
   31, 194, 51,  9,
   63, 167,175,  8,
   95,  27,209, 78,
  127,   1,248,247,
  159,   1, 78,166,
  191,   1,  5,102,
  223,  42, 79, 18,
  255, 255,255,  0};
  
// Gradient palette "Orange_to_Purple_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Orange-to-Purple.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE( Orange_to_Purple_gp ) {
    0, 208, 50,  1,
  127, 146, 27, 45,
  255,  97, 12,178};

// Gradient palette "Fire_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Fire-1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE( Fire_1_gp ) {
    0, 255,  0,  0,
  127, 255, 55,  0,
  255, 255,255,  0};

  // Gradient palette "standard_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/standard.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( standard_gp ) {
    0,   0,  0,  0,
   84,  10, 17,255,
   84,   0, 17,  0,
  169,  10,255, 12,
  169,  10,  0,  0,
  255, 255, 17, 12};

// Gradient palette "a_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/a.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( a_gp ) {
    0,   0,  0,  0,
   31,   0, 55,  0,
   63,   0,255, 45,
  127, 255,  0,255,
  163, 255,  0, 45,
  196, 255,  0,  0,
  255, 255,255,  0};

// Gradient palette "b_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/b.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( b_gp ) {
    0,   0,  0,  0,
   63,   0,  0,255,
  127, 255,  0,  0,
  191, 255,255,  0,
  255, 255,255,255};
  
// Gradient palette "es_emerald_dragon_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_emerald_dragon_01_gp ) {
    0,   1,  1,  1,
   79,   1, 19,  7,
  130,   1, 59, 25,
  229,  28,255,255,
  255,  28,255,255};
  
// Gradient palette "es_landscape_59_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_59.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_59_gp ) {
    0, 215,114,  9,
   51, 255,182, 34,
   89, 255,205, 48,
   94, 213,229,210,
  153, 106,161,145,
  204,  20,101,111,
  255,   1, 48, 75};

// Gradient palette "es_seadreams_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/sea_dreams/tn/es_seadreams_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_seadreams_09_gp ) {
    0, 121,136,125,
   58,  34, 97,166,
  101,   2, 66,212,
  119,   2, 29,182,
  153,   3,  8,153,
  255,  82,107,178};
  
 // Gradient palette "froth316_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/base/tn/froth316.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 120 bytes of program space.

DEFINE_GRADIENT_PALETTE( froth316_gp ) {
    0, 247,  0,  0,
   17, 247,  0,  0,
   17, 157,  0,  0,
   33, 157,  0,  0,
   33,  86,  0,  0,
   51,  86,  0,  0,
   51,  39,  0,  0,
   68,  39,  0,  0,
   68,  12,  0,  0,
   84,  12,  0,  0,
   84,   0,248,  0,
  102,   0,248,  0,
  102,   0,169,  0,
  119,   0,169,  0,
  119,   0,101,  0,
  135,   0,101,  0,
  135,   0, 52,  0,
  153,   0, 52,  0,
  153,   0, 19,  0,
  170,   0, 19,  0,
  170,   0,  0,247,
  186,   0,  0,247,
  186,   0,  0,160,
  204,   0,  0,160,
  204,   0,  0, 89,
  221,   0,  0, 89,
  221,   0,  0, 42,
  237,   0,  0, 42,
  237,   0,  0, 14,
  255,   0,  0, 14};

// Gradient palette "Skydye11_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/midtones/tn/Skydye11.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2016 bytes of program space.

DEFINE_GRADIENT_PALETTE( Skydye11_gp ) {
255,       4,   0,   4,
254,       4,   0,   4,
253,       0,   0,   0,
252,      12,   0,   8,
251,      20,   0,  16,
250,      24,   4,  20,
249,      32,   4,  24,
248,      36,   4,  28,
247,      44,   4,  32,
246,      48,   4,  40,
245,      56,   4,  44,
244,      60,   4,  48,
243,      68,   4,  52,
242,      72,   8,  56,
241,      80,   8,  64,
240,      84,   8,  68,
239,      92,   8,  72,
238,      96,   8,  76,
237,     108,   4,  68,
236,     116,   4,  64,
235,     128,   4,  60,
234,     136,   4,  56,
233,     148,   4,  48,
232,     156,   4,  44,
231,     168,   4,  40,
230,     176,   4,  36,
229,     184,   0,  32,
228,     196,   0,  28,
227,     204,   0,  24,
226,     216,   0,  16,
225,     224,   0,  12,
224,     236,   0,   8,
223,     244,   0,   4,
222,     252,   0,   0,
221,     252,  12,   0,
220,     252,  24,   0,
219,     252,  32,   0,
218,     252,  44,   0,
217,     252,  56,   0,
216,     252,  68,   0,
215,     252,  76,   0,
214,     252,  88,   0,
213,     252, 100,   0,
212,     252, 112,   0,
211,     252, 120,   0,
210,     252, 132,   0,
209,     252, 144,   0,
208,     252, 152,   0,
207,     252, 164,   0,
206,     252, 176,   0,
205,     252, 188,   0,
204,     252, 196,   0,
203,     252, 208,   0,
202,     252, 220,   0,
201,     252, 232,   0,
200,     252, 240,   0,
199,     252, 252,   0,
198,     252, 240,   0,
197,     252, 232,   0,
196,     252, 220,   0,
195,     252, 212,   0,
194,     252, 200,   0,
193,     252, 192,   0,
192,     252, 180,   0,
191,     252, 172,   0,
190,     252, 160,   0,
189,     252, 152,   0,
188,     252, 140,   0,
187,     252, 132,   0,
186,     252, 120,   0,
185,     252, 108,   0,
184,     252, 100,   0,
183,     252,  88,   0,
182,     252,  80,   0,
181,     252,  68,   0,
180,     252,  60,   0,
179,     252,  48,   0,
178,     252,  40,   0,
177,     252,  28,   0,
176,     252,  20,   0,
175,     252,   8,   0,
174,     252,   0,   0,
173,     240,   4,   8,
172,     232,   4,  12,
171,     220,   4,  16,
170,     212,   4,  20,
169,     200,   4,  28,
168,     192,   4,  32,
167,     180,   4,  36,
166,     172,   8,  40,
165,     164,   8,  44,
164,     152,   8,  48,
163,     144,   8,  52,
162,     132,   8,  60,
161,     124,   8,  64,
160,     112,   8,  68,
159,     104,   8,  72,
158,      96,   8,  76,
157,      96,   8,  72,
156,      92,   4,  68,
155,      88,   4,  64,
154,      84,   4,  60,
153,      80,   4,  60,
152,      80,   4,  56,
151,      76,   4,  56,
150,      72,   4,  52,
149,      68,   4,  52,
148,      68,   4,  48,
147,      64,   4,  48,
146,      60,   4,  44,
145,      56,   4,  40,
143,      56,   4,  40,
142,      52,   4,  36,
141,      48,   0,  36,
140,      44,   0,  32,
139,      40,   0,  28,
138,      36,   0,  24,
137,      32,   0,  24,
136,      32,   0,  20,
135,      28,   0,  20,
134,      24,   0,  16,
133,      20,   0,  16,
132,      20,   0,  12,
131,      16,   0,  12,
130,      12,   0,   8,
129,       8,   0,   4,
128,       4,   4,   0,
127,       4,   8,   0,
126,       4,  12,   0,
125,       4,  16,   0,
124,       4,  20,   0,
123,       4,  24,   0,
122,       4,  28,   0,
121,       4,  32,   0,
120,       0,  36,   0,
119,       0,  40,   0,
118,       0,  44,   0,
117,       0,  48,   0,
116,       0,  52,   0,
115,       0,  56,   0,
114,       0,  60,   0,
113,       0,  64,   0,
112,       0,  76,   8,
111,       0,  84,  16,
110,       0,  92,  20,
109,       0, 104,  28,
108,       0, 112,  32,
107,       0, 120,  40,
106,       0, 128,  44,
105,       0, 140,  52,
104,       0, 148,  56,
103,       0, 156,  64,
102,       0, 164,  68,
101,       0, 172,  76,
100,       0, 184,  80,
99,        0, 192,  88,
98,        0, 200,  92,
97,        0, 208,  96,
96,        0, 216, 104,
95,        0, 220, 112,
94,        0, 224, 120,
93,        0, 232, 124,
92,        0, 236, 132,
91,        0, 228, 136,
90,        0, 220, 140,
89,        0, 212, 144,
88,        0, 204, 148,
87,        0, 196, 152,
86,        0, 188, 156,
85,        0, 180, 160,
84,        0, 172, 164,
83,        0, 164, 168,
82,        0, 156, 172,
81,        0, 148, 176,
80,        0, 140, 180,
79,        0, 132, 184,
78,        0, 124, 188,
77,        0, 116, 192,
76,        0, 108, 196,
75,        0, 100, 200,
74,        0,  92, 204,
73,        0,  84, 208,
72,        0,  76, 212,
71,        0,  68, 216,
70,        0,  60, 220,
69,        0,  52, 224,
68,        0,  44, 228,
67,        0,  36, 232,
66,        0,  28, 236,
65,        0,  20, 240,
64,        0,  12, 244,
63,        0,   4, 248,
62,        0,   0, 252,
61,        4,   4, 244,
60,        8,   4, 240,
59,       12,   4, 232,
58,       12,   4, 228,
57,       16,   4, 220,
56,       20,   4, 216,
55,       24,   4, 212,
54,       24,   4, 204,
53,       28,   4, 200,
52,       32,   4, 192,
51,       36,   4, 188,
50,       36,   4, 180,
49,       40,   4, 176,
48,       44,   4, 172,
47,       48,   4, 164,
46,       48,   8, 160,
45,       52,   8, 152,
44,       56,   8, 148,
43,       60,   8, 144,
42,       60,   8, 136,
41,       64,   8, 132,
40,       68,   8, 124,
39,       72,   8, 120,
38,       72,   8, 112,
37,       76,   8, 108,
36,       80,   8, 104,
35,       84,   8,  96,
34,       84,   8,  92,
33,       88,   8,  84,
32,       92,   8,  80,
31,       96,   8,  76,
30,       96,   8,  72,
29,       92,   4,  68,
28,       88,   4,  64,
27,       84,   4,  60,
26,       80,   4,  60,
25,       76,   4,  56,
24,       76,   0,  56,
23,       72,   0,  52,
22,       68,   0,  52,
21,       64,   0,  48,
20,       60,   0,  44,
18,       60,   0,  44,
17,       56,   0,  40,
16,       52,   0,  36,
15,       48,   0,  36,
14,       44,   0,  32,
13,       40,   0,  28,
12,       36,   0,  28,
11,       36,   0,  24,
10,       32,   0,  24,
9,        28,   0,  20,
7,        28,   0,  20,
6,        24,   0,  16,
5,        20,   0,  16,
4,        20,   0,  12,
3,        16,   0,  12,
2,        12,   0,   8,
1,         8,   0,   4,
0,         8,   0,   4};

// Gradient palette "Wizzl019_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/jewelmap/tn/Wizzl019.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2040 bytes of program space.

DEFINE_GRADIENT_PALETTE( Wizzl019_gp ) {
255,     128,  24, 160,
254,     120,  24, 148,
253,     108,  28, 136,
252,     100,  28, 124,
251,      88,  32, 112,
250,      80,  32, 100,
249,      68,  32,  84,
248,      60,  36,  72,
247,      48,  36,  60,
246,      40,  40,  48,
245,      28,  40,  36,
244,      20,  44,  24,
243,       8,  44,  12,
242,       0,  44,   0,
241,      16,  40,  12,
240,      32,  40,  20,
239,      48,  36,  32,
238,      60,  36,  40,
237,      76,  36,  52,
236,      92,  32,  60,
235,     108,  32,  72,
234,     120,  32,  80,
233,     136,  28,  92,
232,     152,  28, 100,
231,     168,  24, 112,
230,     180,  24, 120,
229,     196,  24, 132,
228,     212,  20, 140,
227,     228,  20, 152,
226,     240,  20, 160,
225,     228,  24, 148,
224,     216,  24, 140,
223,     204,  24, 128,
222,     192,  24, 120,
221,     180,  28, 108,
220,     168,  28, 100,
219,     156,  28,  88,
218,     148,  28,  80,
217,     136,  32,  68,
216,     124,  32,  60,
215,     112,  32,  48,
214,     100,  32,  40,
213,      88,  36,  28,
212,      76,  36,  20,
211,      64,  36,   8,
210,      56,  36,   0,
209,      68,  44,   0,
208,      80,  48,   0,
207,      92,  56,   0,
206,     104,  60,   0,
205,     112,  68,   0,
204,     124,  72,   0,
203,     136,  80,   0,
202,     148,  88,   0,
201,     160,  92,   0,
200,     168, 100,   0,
199,     180, 104,   0,
198,     192, 112,   0,
197,     204, 116,   0,
196,     216, 124,   0,
195,     224, 128,   0,
194,     212, 120,   0,
193,     204, 112,   0,
192,     196, 104,   0,
191,     188,  96,   0,
190,     176,  88,   0,
189,     168,  80,   0,
188,     160,  72,   0,
187,     152,  64,   0,
186,     140,  56,   0,
185,     132,  48,   0,
184,     124,  40,   0,
183,     116,  32,   0,
182,     104,  24,   0,
181,      96,  16,   0,
180,      88,   8,   0,
179,      80,   0,   0,
178,      92,   0,   4,
177,     100,   0,   4,
176,     112,   0,   8,
175,     120,   0,   8,
174,     132,   0,  12,
173,     140,   0,  12,
172,     152,   0,  16,
171,     160,   0,  16,
170,     172,   0,  20,
169,     180,   0,  20,
168,     192,   0,  24,
167,     200,   0,  24,
166,     212,   0,  28,
165,     220,   0,  28,
164,     232,   0,  32,
163,     240,   0,  32,
162,     224,   0,  36,
161,     212,   0,  36,
160,     200,   0,  36,
159,     188,   0,  36,
158,     176,   0,  36,
157,     164,   0,  36,
156,     152,   0,  36,
155,     140,   0,  36,
154,     124,   0,  40,
153,     112,   0,  40,
152,     100,   0,  40,
151,      88,   0,  40,
150,      76,   0,  40,
149,      64,   0,  40,
148,      52,   0,  40,
147,      40,   0,  40,
146,      52,   0,  52,
145,      60,   0,  60,
144,      72,   0,  72,
143,      80,   0,  80,
142,      92,   0,  92,
141,     100,   0, 100,
140,     112,   0, 112,
139,     120,   0, 120,
138,     132,   0, 132,
137,     140,   0, 140,
136,     152,   0, 152,
135,     160,   0, 160,
134,     172,   0, 172,
133,     180,   0, 180,
132,     192,   0, 192,
131,     200,   0, 200,
130,     184,   0, 192,
129,     172,   0, 184,
128,     160,   0, 176,
127,     148,   0, 168,
126,     136,   0, 160,
125,     124,   0, 152,
124,     112,   0, 144,
123,     100,   0, 140,
122,      84,   0, 132,
121,      72,   0, 124,
120,      60,   0, 116,
119,      48,   0, 108,
118,      36,   0, 100,
117,      24,   0,  92,
116,      12,   0,  84,
115,       0,   0,  80,
114,       4,   0,  92,
113,       8,   0, 100,
112,       8,   0, 112,
111,      12,   0, 120,
110,      16,   0, 132,
109,      16,   0, 140,
108,      20,   0, 152,
107,      20,   0, 160,
106,      24,   0, 172,
105,      28,   0, 180,
104,      28,   0, 192,
103,      32,   0, 200,
102,      36,   0, 212,
101,      36,   0, 220,
100,      40,   0, 232,
99,       40,   0, 240,
98,       36,   4, 224,
97,       32,   8, 208,
96,       32,   8, 192,
95,       28,  12, 180,
94,       24,  16, 164,
93,       24,  16, 148,
92,       20,  20, 132,
91,       20,  20, 120,
90,       16,  24, 104,
89,       12,  28,  88,
88,       12,  28,  72,
87,        8,  32,  60,
86,        4,  36,  44,
85,        4,  36,  28,
84,        0,  40,  12,
83,        0,  40,   0,
82,        0,  52,   8,
81,        0,  60,  12,
80,        0,  72,  16,
79,        0,  80,  20,
78,        0,  92,  28,
77,        0, 100,  32,
76,        0, 112,  36,
75,        0, 120,  40,
74,        0, 132,  48,
73,        0, 140,  52,
72,        0, 152,  56,
71,        0, 160,  60,
70,        0, 172,  68,
69,        0, 180,  72,
68,        0, 192,  76,
67,        0, 200,  80,
66,        8, 188,  72,
65,       12, 180,  68,
64,       16, 168,  64,
63,       20, 160,  60,
62,       28, 148,  52,
61,       32, 140,  48,
60,       36, 128,  44,
59,       40, 120,  40,
58,       48, 108,  32,
57,       52, 100,  28,
56,       56,  88,  24,
55,       60,  80,  20,
54,       68,  68,  12,
53,       72,  60,   8,
52,       76,  48,   4,
51,       80,  40,   0,
50,       88,  48,   0,
49,       96,  52,   0,
48,      104,  56,   0,
47,      112,  60,   0,
46,      120,  68,   0,
45,      128,  72,   0,
44,      136,  76,   0,
43,      140,  80,   0,
42,      148,  88,   0,
41,      156,  92,   0,
40,      164,  96,   0,
39,      172, 100,   0,
38,      180, 108,   0,
37,      188, 112,   0,
36,      196, 116,   0,
35,      200, 120,   0,
34,      192, 112,   8,
33,      184, 104,  12,
32,      176,  96,  16,
31,      168,  88,  20,
30,      160,  80,  28,
29,      152,  72,  32,
28,      144,  64,  36,
27,      140,  60,  40,
26,      132,  52,  48,
25,      124,  44,  52,
24,      116,  36,  56,
23,      108,  28,  60,
22,      100,  20,  68,
21,       92,  12,  72,
20,       84,   4,  76,
19,       80,   0,  80,
18,       88,   4,  88,
17,       92,   4,  96,
16,       96,   4, 104,
15,      100,   4, 112,
14,      108,   8, 120,
13,      112,   8, 128,
12,      116,   8, 136,
11,      120,   8, 140,
10,      128,  12, 148,
9 ,      132,  12, 156,
8 ,      136,  12, 164,
7 ,      140,  12, 172,
6 ,      148,  16, 180,
5 ,      152,  16, 188,
4 ,      156,  16, 196,
3 ,      160,  16, 200,
2 ,      148,  20, 184,
1 ,      140,  20, 172,
0 ,      140,  20, 172};
  
// Single array of defined cpt-city color palettes.
// This will let us programmatically choose one based on
// a number, rather than having to activate each explicitly
// by name every time.
// Since it is const, this_ array could also be moved
// into PROGMEM to save SRAM, but for simplicity of illustration
// we'll keep it in a regular SRAM array.
//
// This list of color palettes acts as a "playlist"; you can
// add or delete, or re-arrange as you wish.
const TProgmemRGBGradientPalettePtr g_gradient_palettes[] = {
  Sunset_Real_gp,
  es_rivendell_15_gp,
  es_ocean_breeze_036_gp,
  rgi_15_gp,
  retro2_16_gp,
  Analogous_1_gp,
  es_pinksplash_08_gp,
  Coral_reef_gp,
  es_ocean_breeze_068_gp,
  es_pinksplash_07_gp,
  es_vintage_01_gp,
  departure_gp,
  es_landscape_64_gp,
  es_landscape_33_gp,
  rainbowsherbet_gp,
  gr65_hult_gp,
  gr64_hult_gp,
  GMT_drywet_gp,
  ib_jul01_gp,
  es_vintage_57_gp,
  ib15_gp,
  Fuschia_7_gp,
  es_emerald_dragon_08_gp,
  lava_gp,
  fire_gp,
  Colorfull_gp,
  Magenta_Evening_gp,
  Pink_Purple_gp,
  es_autumn_19_gp,
  BlacK_Blue_Magenta_White_gp,
  BlacK_Magenta_Red_gp,
  BlacK_Red_Magenta_Yellow_gp,
  Blue_Cyan_Yellow_gp,
  bhw1_greeny_gp,
  bhw1_26_gp,
  bhw1_28_gp,
  bhw2_23_gp,
  bhw2_22_gp,
  bhw2_49_gp,
  bhw2_10_gp,
  bhw2_14_gp,
  bhw3_21_gp,
  bhw3_30_gp,
  cw1_029_gp,
  alarm_p4_0_2_gp,
  Ribbon_colors_gp,
  Orange_to_Purple_gp,
  Fire_1_gp,
  standard_gp,
  a_gp,
  b_gp,
  es_emerald_dragon_01_gp,
  es_landscape_59_gp,
  es_seadreams_09_gp,
  froth316_gp,
  Skydyell_gp,
  Wizzl019_gp  };


// Count of how many cpt-city gradients are defined:
const uint8_t g_gradient_palette_count =
  sizeof( g_gradient_palettes) / sizeof( TProgmemRGBGradientPalettePtr );


#endif
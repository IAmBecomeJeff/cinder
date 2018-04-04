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

// Gradient palette "vibrant_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/4/tn/vibrant.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( vibrant_gp ) {
    0, 255,255,255,
   30,   1,144, 29,
   71, 229,246, 12,
  119, 255,  1,  8,
  165, 184,  1,203,
  214,   3, 28,250,
  255,   0,  0,  0};
  
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
0,         8,   0,   4,
1,         8,   0,   4,
2,        12,   0,   8,
3,        16,   0,  12,
4,        20,   0,  12,
5,        20,   0,  16,
6,        24,   0,  16,
7,        28,   0,  20,
9,        28,   0,  20,
10,       32,   0,  24,
11,       36,   0,  24,
12,       36,   0,  28,
13,       40,   0,  28,
14,       44,   0,  32,
15,       48,   0,  36,
16,       52,   0,  36,
17,       56,   0,  40,
18,       60,   0,  44,
20,       60,   0,  44,
21,       64,   0,  48,
22,       68,   0,  52,
23,       72,   0,  52,
24,       76,   0,  56,
25,       76,   4,  56,
26,       80,   4,  60,
27,       84,   4,  60,
28,       88,   4,  64,
29,       92,   4,  68,
30,       96,   8,  72,
31,       96,   8,  76,
32,       92,   8,  80,
33,       88,   8,  84,
34,       84,   8,  92,
35,       84,   8,  96,
36,       80,   8, 104,
37,       76,   8, 108,
38,       72,   8, 112,
39,       72,   8, 120,
40,       68,   8, 124,
41,       64,   8, 132,
42,       60,   8, 136,
43,       60,   8, 144,
44,       56,   8, 148,
45,       52,   8, 152,
46,       48,   8, 160,
47,       48,   4, 164,
48,       44,   4, 172,
49,       40,   4, 176,
50,       36,   4, 180,
51,       36,   4, 188,
52,       32,   4, 192,
53,       28,   4, 200,
54,       24,   4, 204,
55,       24,   4, 212,
56,       20,   4, 216,
57,       16,   4, 220,
58,       12,   4, 228,
59,       12,   4, 232,
60,        8,   4, 240,
61,        4,   4, 244,
62,        0,   0, 252,
63,        0,   4, 248,
64,        0,  12, 244,
65,        0,  20, 240,
66,        0,  28, 236,
67,        0,  36, 232,
68,        0,  44, 228,
69,        0,  52, 224,
70,        0,  60, 220,
71,        0,  68, 216,
72,        0,  76, 212,
73,        0,  84, 208,
74,        0,  92, 204,
75,        0, 100, 200,
76,        0, 108, 196,
77,        0, 116, 192,
78,        0, 124, 188,
79,        0, 132, 184,
80,        0, 140, 180,
81,        0, 148, 176,
82,        0, 156, 172,
83,        0, 164, 168,
84,        0, 172, 164,
85,        0, 180, 160,
86,        0, 188, 156,
87,        0, 196, 152,
88,        0, 204, 148,
89,        0, 212, 144,
90,        0, 220, 140,
91,        0, 228, 136,
92,        0, 236, 132,
93,        0, 232, 124,
94,        0, 224, 120,
95,        0, 220, 112,
96,        0, 216, 104,
97,        0, 208,  96,
98,        0, 200,  92,
99,        0, 192,  88,
100,       0, 184,  80,
101,       0, 172,  76,
102,       0, 164,  68,
103,       0, 156,  64,
104,       0, 148,  56,
105,       0, 140,  52,
106,       0, 128,  44,
107,       0, 120,  40,
108,       0, 112,  32,
109,       0, 104,  28,
110,       0,  92,  20,
111,       0,  84,  16,
112,       0,  76,   8,
113,       0,  64,   0,
114,       0,  60,   0,
115,       0,  56,   0,
116,       0,  52,   0,
117,       0,  48,   0,
118,       0,  44,   0,
119,       0,  40,   0,
120,       0,  36,   0,
121,       4,  32,   0,
122,       4,  28,   0,
123,       4,  24,   0,
124,       4,  20,   0,
125,       4,  16,   0,
126,       4,  12,   0,
127,       4,   8,   0,
128,       4,   4,   0,
129,       8,   0,   4,
130,      12,   0,   8,
131,      16,   0,  12,
132,      20,   0,  12,
133,      20,   0,  16,
134,      24,   0,  16,
135,      28,   0,  20,
136,      32,   0,  20,
137,      32,   0,  24,
138,      36,   0,  24,
139,      40,   0,  28,
140,      44,   0,  32,
141,      48,   0,  36,
142,      52,   4,  36,
143,      56,   4,  40,
145,      56,   4,  40,
146,      60,   4,  44,
147,      64,   4,  48,
148,      68,   4,  48,
149,      68,   4,  52,
150,      72,   4,  52,
151,      76,   4,  56,
152,      80,   4,  56,
153,      80,   4,  60,
154,      84,   4,  60,
155,      88,   4,  64,
156,      92,   4,  68,
157,      96,   8,  72,
158,      96,   8,  76,
159,     104,   8,  72,
160,     112,   8,  68,
161,     124,   8,  64,
162,     132,   8,  60,
163,     144,   8,  52,
164,     152,   8,  48,
165,     164,   8,  44,
166,     172,   8,  40,
167,     180,   4,  36,
168,     192,   4,  32,
169,     200,   4,  28,
170,     212,   4,  20,
171,     220,   4,  16,
172,     232,   4,  12,
173,     240,   4,   8,
174,     252,   0,   0,
175,     252,   8,   0,
176,     252,  20,   0,
177,     252,  28,   0,
178,     252,  40,   0,
179,     252,  48,   0,
180,     252,  60,   0,
181,     252,  68,   0,
182,     252,  80,   0,
183,     252,  88,   0,
184,     252, 100,   0,
185,     252, 108,   0,
186,     252, 120,   0,
187,     252, 132,   0,
188,     252, 140,   0,
189,     252, 152,   0,
190,     252, 160,   0,
191,     252, 172,   0,
192,     252, 180,   0,
193,     252, 192,   0,
194,     252, 200,   0,
195,     252, 212,   0,
196,     252, 220,   0,
197,     252, 232,   0,
198,     252, 240,   0,
199,     252, 252,   0,
200,     252, 240,   0,
201,     252, 232,   0,
202,     252, 220,   0,
203,     252, 208,   0,
204,     252, 196,   0,
205,     252, 188,   0,
206,     252, 176,   0,
207,     252, 164,   0,
208,     252, 152,   0,
209,     252, 144,   0,
210,     252, 132,   0,
211,     252, 120,   0,
212,     252, 112,   0,
213,     252, 100,   0,
214,     252,  88,   0,
215,     252,  76,   0,
216,     252,  68,   0,
217,     252,  56,   0,
218,     252,  44,   0,
219,     252,  32,   0,
220,     252,  24,   0,
221,     252,  12,   0,
222,     252,   0,   0,
223,     244,   0,   4,
224,     236,   0,   8,
225,     224,   0,  12,
226,     216,   0,  16,
227,     204,   0,  24,
228,     196,   0,  28,
229,     184,   0,  32,
230,     176,   4,  36,
231,     168,   4,  40,
232,     156,   4,  44,
233,     148,   4,  48,
234,     136,   4,  56,
235,     128,   4,  60,
236,     116,   4,  64,
237,     108,   4,  68,
238,      96,   8,  76,
239,      92,   8,  72,
240,      84,   8,  68,
241,      80,   8,  64,
242,      72,   8,  56,
243,      68,   4,  52,
244,      60,   4,  48,
245,      56,   4,  44,
246,      48,   4,  40,
247,      44,   4,  32,
248,      36,   4,  28,
249,      32,   4,  24,
250,      24,   4,  20,
251,      20,   0,  16,
252,      12,   0,   8,
253,       0,   0,   0,
254,       4,   0,   4,
255,       4,   0,   4};

// Gradient palette "Wizzl019_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/jewelmap/tn/Wizzl019.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2040 bytes of program space.

DEFINE_GRADIENT_PALETTE( Wizzl019_gp ) {
0 ,      140,  20, 172,
1 ,      140,  20, 172,
2 ,      148,  20, 184,
3 ,      160,  16, 200,
4 ,      156,  16, 196,
5 ,      152,  16, 188,
6 ,      148,  16, 180,
7 ,      140,  12, 172,
8 ,      136,  12, 164,
9 ,      132,  12, 156,
10,      128,  12, 148,
11,      120,   8, 140,
12,      116,   8, 136,
13,      112,   8, 128,
14,      108,   8, 120,
15,      100,   4, 112,
16,       96,   4, 104,
17,       92,   4,  96,
18,       88,   4,  88,
19,       80,   0,  80,
20,       84,   4,  76,
21,       92,  12,  72,
22,      100,  20,  68,
23,      108,  28,  60,
24,      116,  36,  56,
25,      124,  44,  52,
26,      132,  52,  48,
27,      140,  60,  40,
28,      144,  64,  36,
29,      152,  72,  32,
30,      160,  80,  28,
31,      168,  88,  20,
32,      176,  96,  16,
33,      184, 104,  12,
34,      192, 112,   8,
35,      200, 120,   0,
36,      196, 116,   0,
37,      188, 112,   0,
38,      180, 108,   0,
39,      172, 100,   0,
40,      164,  96,   0,
41,      156,  92,   0,
42,      148,  88,   0,
43,      140,  80,   0,
44,      136,  76,   0,
45,      128,  72,   0,
46,      120,  68,   0,
47,      112,  60,   0,
48,      104,  56,   0,
49,       96,  52,   0,
50,       88,  48,   0,
51,       80,  40,   0,
52,       76,  48,   4,
53,       72,  60,   8,
54,       68,  68,  12,
55,       60,  80,  20,
56,       56,  88,  24,
57,       52, 100,  28,
58,       48, 108,  32,
59,       40, 120,  40,
60,       36, 128,  44,
61,       32, 140,  48,
62,       28, 148,  52,
63,       20, 160,  60,
64,       16, 168,  64,
65,       12, 180,  68,
66,        8, 188,  72,
67,        0, 200,  80,
68,        0, 192,  76,
69,        0, 180,  72,
70,        0, 172,  68,
71,        0, 160,  60,
72,        0, 152,  56,
73,        0, 140,  52,
74,        0, 132,  48,
75,        0, 120,  40,
76,        0, 112,  36,
77,        0, 100,  32,
78,        0,  92,  28,
79,        0,  80,  20,
80,        0,  72,  16,
81,        0,  60,  12,
82,        0,  52,   8,
83,        0,  40,   0,
84,        0,  40,  12,
85,        4,  36,  28,
86,        4,  36,  44,
87,        8,  32,  60,
88,       12,  28,  72,
89,       12,  28,  88,
90,       16,  24, 104,
91,       20,  20, 120,
92,       20,  20, 132,
93,       24,  16, 148,
94,       24,  16, 164,
95,       28,  12, 180,
96,       32,   8, 192,
97,       32,   8, 208,
98,       36,   4, 224,
99,       40,   0, 240,
100,      40,   0, 232,
101,      36,   0, 220,
102,      36,   0, 212,
103,      32,   0, 200,
104,      28,   0, 192,
105,      28,   0, 180,
106,      24,   0, 172,
107,      20,   0, 160,
108,      20,   0, 152,
109,      16,   0, 140,
110,      16,   0, 132,
111,      12,   0, 120,
112,       8,   0, 112,
113,       8,   0, 100,
114,       4,   0,  92,
115,       0,   0,  80,
116,      12,   0,  84,
117,      24,   0,  92,
118,      36,   0, 100,
119,      48,   0, 108,
120,      60,   0, 116,
121,      72,   0, 124,
122,      84,   0, 132,
123,     100,   0, 140,
124,     112,   0, 144,
125,     124,   0, 152,
126,     136,   0, 160,
127,     148,   0, 168,
128,     160,   0, 176,
129,     172,   0, 184,
130,     184,   0, 192,
131,     200,   0, 200,
132,     192,   0, 192,
133,     180,   0, 180,
134,     172,   0, 172,
135,     160,   0, 160,
136,     152,   0, 152,
137,     140,   0, 140,
138,     132,   0, 132,
139,     120,   0, 120,
140,     112,   0, 112,
141,     100,   0, 100,
142,      92,   0,  92,
143,      80,   0,  80,
144,      72,   0,  72,
145,      60,   0,  60,
146,      52,   0,  52,
147,      40,   0,  40,
148,      52,   0,  40,
149,      64,   0,  40,
150,      76,   0,  40,
151,      88,   0,  40,
152,     100,   0,  40,
153,     112,   0,  40,
154,     124,   0,  40,
155,     140,   0,  36,
156,     152,   0,  36,
157,     164,   0,  36,
158,     176,   0,  36,
159,     188,   0,  36,
160,     200,   0,  36,
161,     212,   0,  36,
162,     224,   0,  36,
163,     240,   0,  32,
164,     232,   0,  32,
165,     220,   0,  28,
166,     212,   0,  28,
167,     200,   0,  24,
168,     192,   0,  24,
169,     180,   0,  20,
170,     172,   0,  20,
171,     160,   0,  16,
172,     152,   0,  16,
173,     140,   0,  12,
174,     132,   0,  12,
175,     120,   0,   8,
176,     112,   0,   8,
177,     100,   0,   4,
178,      92,   0,   4,
179,      80,   0,   0,
180,      88,   8,   0,
181,      96,  16,   0,
182,     104,  24,   0,
183,     116,  32,   0,
184,     124,  40,   0,
185,     132,  48,   0,
186,     140,  56,   0,
187,     152,  64,   0,
188,     160,  72,   0,
189,     168,  80,   0,
190,     176,  88,   0,
191,     188,  96,   0,
192,     196, 104,   0,
193,     204, 112,   0,
194,     212, 120,   0,
195,     224, 128,   0,
196,     216, 124,   0,
197,     204, 116,   0,
198,     192, 112,   0,
199,     180, 104,   0,
200,     168, 100,   0,
201,     160,  92,   0,
202,     148,  88,   0,
203,     136,  80,   0,
204,     124,  72,   0,
205,     112,  68,   0,
206,     104,  60,   0,
207,      92,  56,   0,
208,      80,  48,   0,
209,      68,  44,   0,
210,      56,  36,   0,
211,      64,  36,   8,
212,      76,  36,  20,
213,      88,  36,  28,
214,     100,  32,  40,
215,     112,  32,  48,
216,     124,  32,  60,
217,     136,  32,  68,
218,     148,  28,  80,
219,     156,  28,  88,
220,     168,  28, 100,
221,     180,  28, 108,
222,     192,  24, 120,
223,     204,  24, 128,
224,     216,  24, 140,
225,     228,  24, 148,
226,     240,  20, 160,
227,     228,  20, 152,
228,     212,  20, 140,
229,     196,  24, 132,
230,     180,  24, 120,
231,     168,  24, 112,
232,     152,  28, 100,
233,     136,  28,  92,
234,     120,  32,  80,
235,     108,  32,  72,
236,      92,  32,  60,
237,      76,  36,  52,
238,      60,  36,  40,
239,      48,  36,  32,
240,      32,  40,  20,
241,      16,  40,  12,
242,       0,  44,   0,
243,       8,  44,  12,
244,      20,  44,  24,
245,      28,  40,  36,
246,      40,  40,  48,
247,      48,  36,  60,
248,      60,  36,  72,
249,      68,  32,  84,
250,      80,  32, 100,
251,      88,  32, 112,
252,     100,  28, 124,
253,     108,  28, 136,
254,     120,  24, 148,
255,     128,  24, 160};

// Gradient palette "Tropical_Colors_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ggr/tn/Tropical_Colors.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 116 bytes of program space.

DEFINE_GRADIENT_PALETTE( Tropical_Colors_gp ) {
    0,   1,  4,  1,
   14,   1, 10,  1,
   21,   1, 19,  0,
   35,   1, 42,  1,
   49,   3, 75,  1,
   59,  56,103,  1,
   70, 208,135,  4,
   84, 217, 54,  2,
   98, 224, 10,  1,
  130, 117, 15,  3,
  141,  48, 20,  6,
  155,  42, 18, 77,
  170,  36, 17,255,
  197,  55, 97,242,
  210,  80,255,228,
  220,  47,219, 77,
  225,  24,187, 10,
  228,  24,180,  9,
  230,  24,171,  8,
  232,  23,161,  6,
  235,  23,149,  5,
  237,  22,136,  4,
  240,  22,124,  2,
  242,  21,112,  1,
  245,  21,100,  1,
  247,  20, 88,  1,
  250,  19, 77,  1,
  252,  19, 66,  1,
  255,  18, 55,  0};

// Gradient palette "GMT_seafloor_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_seafloor.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE( GMT_seafloor_gp ) {
    0,  25,  0,109,
   10,  28,  0,119,
   21,  32,  0,127,
   31,  35,  0,140,
   42,  27,  1,145,
   53,  20,  1,151,
   74,  14,  4,156,
   84,   9,  9,164,
   95,   5, 15,170,
  106,   2, 24,176,
  116,   1, 35,182,
  138,   1, 49,188,
  148,   0, 66,197,
  159,   1, 79,203,
  170,   3, 93,210,
  180,  10,109,216,
  191,  24,128,223,
  212,  43,149,230,
  223,  72,173,240,
  233, 112,197,247,
  244, 163,225,255,
  255, 220,248,255};

  // Gradient palette "slope_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/grass/tn/slope.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( slope_gp ) {
    0, 255,255,255,
    5, 255,255,  0,
   14,   0,255,  0,
   28,   0,255,255,
   42,   0,  0,255,
   84, 255,  0,255,
  141, 255,  0,  0,
  255,   0,  0,  0};

// Gradient palette "ofaurora_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/2/tn/ofaurora.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 124 bytes of program space.

DEFINE_GRADIENT_PALETTE( ofaurora_gp ) {
    0, 255,241,242,
   10, 237,  1,  9,
   15,  42,  1,  2,
   22,   1,  1,  1,
   35, 237,  1,  9,
   48, 255,241,242,
   58, 239, 57,  1,
   66,   1,  1,  1,
   76, 239, 57,  1,
   84, 255,241,242,
   94, 242,217,  1,
  101,   1,  1,  1,
  109, 242,217,  1,
  119, 255,241,242,
  127,   9,144, 36,
  132,   1,  1,  1,
  140,   9,144, 36,
  147, 255,241,242,
  158,   1,156,186,
  168,   1,  1,  1,
  178,   1,156,186,
  186, 255,241,242,
  198,  16, 13,255,
  206,   1,  1,  1,
  216,  16, 13,255,
  224, 255,241,242,
  234,  78,  1,156,
  237,  14,  1, 30,
  239,   1,  1,  1,
  244,  78,  1,156,
  255, 255,241,242};

  // Gradient palette "hallows_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/3/tn/hallows.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE( hallows_gp ) {
    0,   1,  1,  1,
   20, 247, 28,  1,
   25, 234,136,  3,
   35,   1,  1,  1,
   48, 247, 28,  1,
   51, 234,136,  3,
   61,   1,  1,  1,
   76, 247, 28,  1,
   91, 244,176,  1,
  107, 234,136,  3,
  122,   1,  1,  1,
  140, 234,136,  3,
  153, 244,176,  1,
  168, 247, 28,  1,
  186,   1,  1,  1,
  196, 247, 28,  1,
  204, 234,136,  3,
  216,   1,  1,  1,
  229, 234,136,  3,
  239, 247, 28,  1,
  249,   1,  1,  1,
  255,   1,  1,  1};

// Gradient palette "sea_treasure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/3/tn/sea-treasure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.

DEFINE_GRADIENT_PALETTE( sea_treasure_gp ) {
    0,   1, 13,  5,
   25,   3, 57, 25,
   45,  18,191,172,
   61,   2, 29, 12,
   76,   3, 57, 25,
  101,  18,191,172,
  124,  10, 54, 20,
  153,   1, 30, 12,
  178,  10, 14, 22,
  209,   9, 93, 47,
  232,   8, 55, 22,
  255,   1, 13,  5};


// Gradient palette "Secondary_01a_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/turanj/tn/Secondary_01a.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Secondary_01a_gp ) {
    0,   3,  0,255,
   63,  67,  7, 45,
  127, 255, 33,  0,
  191,  42,115,  1,
  255,   0,255,  1};

// Gradient palette "Split_03_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/vermillion/tn/Split_03.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Split_03_gp ) {
    0,   0, 18,123,
   63,   0, 75, 29,
  127,   0,178,  1,
  191,  27, 48,  1,
  255, 167,  1,  2};

DEFINE_GRADIENT_PALETTE( rainbow_gp ) {
      0,  255,  0,  0, // Red
     32,  171, 85,  0, // Orange
     64,  171,171,  0, // Yellow
     96,    0,255,  0, // Green
    128,    0,171, 85, // Aqua
    160,    0,  0,255, // Blue
    192,   85,  0,171, // Purple
    224,  171,  0, 85, // Pink
    255,  255,  0,  0};// and back to Red

DEFINE_GRADIENT_PALETTE(cloudcolors_gp ) {
    0,   0, 0, 255,
	15, 0, 0, 139,
	111, 0, 0, 139,
	127, 0, 0, 255,
	143, 0, 0, 139,
	159, 135, 206, 250,
	175, 135, 206, 250,
	191, 173, 216, 230,
	207, 200, 200, 200,
	223, 173, 216, 230,
	239, 135, 206, 235,
	255, 0, 191, 255
	};
	
//const TProgmemPalette16 cloudcolors_p FL_PROGMEM =
//{
//    CRGB::Blue,
//    CRGB::DarkBlue,
//    CRGB::DarkBlue,
//    CRGB::DarkBlue,
//
//    CRGB::DarkBlue,
//    CRGB::DarkBlue,
//    CRGB::DarkBlue,
//    CRGB::DarkBlue,
//
//    CRGB::Blue,
//    CRGB::DarkBlue,
//    CRGB::SkyBlue,
//    CRGB::SkyBlue,
//
//    CRGB::LightBlue,
//    CRGB::White,
//    CRGB::LightBlue,
//    CRGB::SkyBlue
//};
//
//const TProgmemPalette16 lavacolors_p FL_PROGMEM =
//{
//    CRGB::Black,
//    CRGB::Maroon,
//    CRGB::Black,
//    CRGB::Maroon,
//
//    CRGB::DarkRed,
//    CRGB::Maroon,
//    CRGB::DarkRed,
//
//    CRGB::DarkRed,
//    CRGB::DarkRed,
//    CRGB::Red,
//    CRGB::Orange,
//
//    CRGB::White,
//    CRGB::Orange,
//    CRGB::Red,
//    CRGB::DarkRed
//};
//
//
//const TProgmemPalette16 oceancolors_p FL_PROGMEM =
//{
//    CRGB::MidnightBlue,
//    CRGB::DarkBlue,
//    CRGB::MidnightBlue,
//    CRGB::Navy,
//
//    CRGB::DarkBlue,
//    CRGB::MediumBlue,
//    CRGB::SeaGreen,
//    CRGB::Teal,
//
//    CRGB::CadetBlue,
//    CRGB::Blue,
//    CRGB::DarkCyan,
//    CRGB::CornflowerBlue,
//
//    CRGB::Aquamarine,
//    CRGB::SeaGreen,
//    CRGB::Aqua,
//    CRGB::LightSkyBlue
//};
//
//const TProgmemPalette16 forestcolors_p FL_PROGMEM =
//{
//    CRGB::DarkGreen,
//    CRGB::DarkGreen,
//    CRGB::DarkOliveGreen,
//    CRGB::DarkGreen,
//
//    CRGB::Green,
//    CRGB::ForestGreen,
//    CRGB::OliveDrab,
//    CRGB::Green,
//
//    CRGB::SeaGreen,
//    CRGB::MediumAquamarine,
//    CRGB::LimeGreen,
//    CRGB::YellowGreen,
//
//    CRGB::LightGreen,
//    CRGB::LawnGreen,
//    CRGB::MediumAquamarine,
//    CRGB::ForestGreen
//};
//
///// HSV Rainbow
//const TProgmemPalette16 rainbowcolors_p FL_PROGMEM =
//{
//    0xFF0000, 0xD52A00, 0xAB5500, 0xAB7F00,
//    0xABAB00, 0x56D500, 0x00FF00, 0x00D52A,
//    0x00AB55, 0x0056AA, 0x0000FF, 0x2A00D5,
//    0x5500AB, 0x7F0081, 0xAB0055, 0xD5002B
//};
//
//#define rainbowstripescolors_p rainbowstripecolors_p
//const TProgmemPalette16 rainbowstripecolors_p FL_PROGMEM =
//{
//    0xFF0000, 0x000000, 0xAB5500, 0x000000,
//    0xABAB00, 0x000000, 0x00FF00, 0x000000,
//    0x00AB55, 0x000000, 0x0000FF, 0x000000,
//    0x5500AB, 0x000000, 0xAB0055, 0x000000
//};
//
//
//const TProgmemPalette16 partycolors_p FL_PROGMEM =
//{
//    0x5500AB, 0x84007C, 0xB5004B, 0xE5001B,
//    0xE81700, 0xB84700, 0xAB7700, 0xABAB00,
//    0xAB5500, 0xDD2200, 0xF2000E, 0xC2003E,
//    0x8F0071, 0x5F00A1, 0x2F00D0, 0x0007F9
//};
//
//
//const TProgmemPalette16 heatcolors_p FL_PROGMEM =
//{
//    0x000000,
//    0x330000, 0x660000, 0x990000, 0xCC0000, 0xFF0000,
//    0xFF3300, 0xFF6600, 0xFF9900, 0xFFCC00, 0xFFFF00,
//    0xFFFF33, 0xFFFF66, 0xFFFF99, 0xFFFFCC, 0xFFFFFF
//};

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
  vibrant_gp,
  cw1_029_gp,
  alarm_p4_0_2_gp,
  Ribbon_Colors_gp,
  Orange_to_Purple_gp,
  Fire_1_gp,
  standard_gp,
  a_gp,
  b_gp,
  es_emerald_dragon_01_gp,
  es_landscape_59_gp,
  es_seadreams_09_gp,
  froth316_gp,
  Skydye11_gp,
  Wizzl019_gp,
  Tropical_Colors_gp,
  slope_gp,
  ofaurora_gp,
  hallows_gp,
  sea_treasure_gp,
  Secondary_01a_gp,
  Split_03_gp,
//  rainbowcolors_p,
//  partycolors_p,
//  lavacolors_p,
//  forestcolors_p,
//  oceancolors_p,
//  cloudcolors_p,
//  rainbowstripecolors_p,
//  heatcolors_p,
  rainbow_gp,
  cloudcolors_gp 
  };


// Count of how many cpt-city gradients are defined:
const uint8_t g_gradient_palette_count =
  sizeof( g_gradient_palettes) / sizeof( TProgmemRGBGradientPalettePtr );

// Find index of current (target) palette
void updatePaletteIndex(CRGBPalette16 pal){
	for (int i = 0; i < g_gradient_palette_count; i++){
		if (pal == g_gradient_palettes[i]){
			palette_index = i;
			break;
		}
	}
}
  
#endif

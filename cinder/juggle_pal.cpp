#include "juggle_pal.h"

uint8_t numdots;

void juggle_pal() {                                            // Several colored dots, weaving in and out of sync with each other
	this_index = 0;                                           // Reset the hue values.
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	for (int i = 0; i < numdots; i++) {
		leds[beatsin16(this_beat + i + numdots, 0, NUM_LEDS)] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);    // Munge the values and pick a colour from the palette
		this_index += this_diff;
	}
} // juggle_pal()


void juggle_pal_ring() {                                            // Several colored dots, weaving in and out of sync with each other
	this_index = 0;                                           // Reset the hue values.
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	for (int i = 0; i < numdots_ring; i++) {
		ringPaletteAdd(beatsin16(this_beat + i + numdots_ring, 0, STRIP_LENGTH - 1), current_palette, this_index, this_bright, current_blending);
		// Munge the values and pick a colour from the palette
		this_index += this_diff;
	}
} // juggle_pal_ring()


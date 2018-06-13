#ifndef JUGGLE_H
#define JUGGLE_H

/* This is adapted from a routine created by Mark Kriegsman */

/*  Usage - juggle_pal();
 *  
 *  this_hue
 *  this_fade
 *  numdots
 *  this_beat
 *  this_bright
 *  this_diff
 */
// use beatsin16_halfup and beatsin16_halfdown to make it go one way

void juggle_pal(bool old) {                                            // Several colored dots, weaving in and out of sync with each other
	if (old) {
		old_this_index = 0;                                           // Reset the hue values.
		fadeToBlackBy(old_leds, NUM_LEDS, old_this_fade);
		for (int i = 0; i < old_numdots; i++) {
			old_leds[beatsin16(old_this_beat + i + old_numdots, 0, NUM_LEDS)] += ColorFromPalette(old_palette, old_this_index, old_this_bright, current_blending);    // Munge the values and pick a colour from the palette
			old_this_index += old_this_diff;
		}
	}
	else {
		this_index = 0;                                           // Reset the hue values.
		fadeToBlackBy(leds, NUM_LEDS, this_fade);
		for (int i = 0; i < numdots; i++) {
			cur_leds[beatsin16(this_beat + i + numdots, 0, NUM_LEDS)] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);    // Munge the values and pick a colour from the palette
			this_index += this_diff;
		}
	}
} // juggle_pal()

void juggle_pal_ring(bool old) {                                            // Several colored dots, weaving in and out of sync with each other
	if (old) {
		old_this_index = 0;                                           // Reset the hue values.
		fadeToBlackBy(old_leds, NUM_LEDS, old_this_fade);
		for (int i = 0; i < old_numdots_ring; i++) {
			ringPaletteAdd(1, beatsin16(old_this_beat + i + old_numdots_ring, 0, STRIP_LENGTH - 1), old_palette, old_this_index, old_this_bright, current_blending);
			// Munge the values and pick a colour from the palette
			old_this_index += old_this_diff;
		}
	}
	else {
		this_index = 0;                                           // Reset the hue values.
		fadeToBlackBy(cur_leds, NUM_LEDS, this_fade);
		for (int i = 0; i < numdots_ring; i++) {
			ringPaletteAdd(0, beatsin16(this_beat + i + numdots_ring, 0, STRIP_LENGTH - 1), current_palette, this_index, this_bright, current_blending);
			// Munge the values and pick a colour from the palette
			this_index += this_diff;
		}
	}
} // juggle_pal_ring()

#endif

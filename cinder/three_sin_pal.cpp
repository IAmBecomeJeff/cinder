#include "three_sin_pal.h"


void three_sin_pal() {
	wave1 += beatsin8(10, -4, 4);
	wave2 += beatsin8(15, -2, 2);
	wave3 += beatsin8(12, -3, 3);

	for (int k = 0; k<NUM_LEDS; k++) {
		uint8_t tmp = sin8(mul1*k + wave1) + sin8(mul1*k + wave2) + sin8(mul1*k + wave3);
		leds[k] = ColorFromPalette(current_palette, tmp, 255);
	}
} // three_sin_pal()



void three_sin_pal_ring() {
	wave1r += beatsin8(10, -4, 4);
	wave2r += beatsin8(15, -2, 2);
	wave3r += beatsin8(12, -3, 3);

	for (int k = 0; k<144; k++) {
		uint8_t tmp = sin8(mul1r*k + wave1r) + sin8(mul1r*k + wave2r) + sin8(mul1r*k + wave3r);
		ringPalette(k, current_palette, tmp, 255);
	}
} // three_sin_pal_ring()
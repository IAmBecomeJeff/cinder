#include "spiral.h"

// spiral()
// spiral_start = 0
// spiral_inc = 4
// spiral_width = 1
// this_hue

void spiral() {
	fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	for (int r_index = 0; r_index < 4; r_index++) {
		for (int i = spiral_start + r_index * spiral_width; i < STRIP_LENGTH; i += spiral_inc * spiral_width) {
			for (int w = i; w < i + spiral_width; w++) {
				leds[ringArray[w%STRIP_LENGTH][r_index]] = CHSV(this_hue, this_sat, this_bright);
			}
		}
	}
	spiral_start += spiral_width;
	if (spiral_start > 3 * spiral_width) {
		spiral_start = 0;
	}
}

// spiral_pal()
// spiral_start = 0
// spiral_inc = 4
// spiral_width = 1
// this_inc
// start_index = 0

void spiral_pal() {
	fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	start_index += this_inc;
	this_index = start_index;
	for (int r_index = 0; r_index < 4; r_index++) {
		for (int i = spiral_start + r_index * spiral_width; i < STRIP_LENGTH; i += spiral_inc * spiral_width) {
			for (int w = i; w < i + spiral_width; w++) {
				leds[ringArray[w%STRIP_LENGTH][r_index]] = ColorFromPalette(current_palette, this_index + w * this_inc, this_bright, current_blending);
			}
		}
	}
	spiral_start += spiral_width;
	if (spiral_start > 3 * spiral_width) {
		spiral_start = 0;
	}
}


// spiral_sin()
// start_index = 0
// this_inc = 1
// freq = 6
// this_rot = 1

void spiral_sin() {
	fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	start_index += this_inc;
	this_index = start_index;
	this_phase += this_speed;
	for (int k = 0; k < STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		for (int r = 0; r < 4; r++) {
			int spiral_bri = qsuba(scale8(cubicwave8((k*all_freq) + r * 64 + this_phase), 120), 85);
			leds[ringArray[k][r]] = ColorFromPalette(current_palette, this_index + k * this_inc, spiral_bri, current_blending);
		}
		this_index += this_rot;
	}
}

void spiral_sin_sub() {
	fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	start_index += this_inc;
	this_index = start_index;
	this_phase += this_speed;
	for (int k = 0; k < STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		for (int r = 0; r < 4; r++) {
			int spiral_bri = qsuba(cubicwave8((k*all_freq) + r * 64 + this_phase) - 192, 0);
			leds[ringArray[k][r]] = ColorFromPalette(current_palette, this_index + k * this_inc, spiral_bri, current_blending);
		}
		this_index += this_rot;
	}
}


void one_sin_spiral() {
	start_index += this_inc;
	this_index = start_index;
	if (this_dir) {
		this_phase += this_speed;                                                                     // You can change direction and speed individually.
	}
	else { this_phase -= this_speed; }

	for (int k = 0; k<STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);                    // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[spiralArray[0][k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[spiralArray[0][k]] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
		this_index += this_rot;
	}
} // one_sin_spiral()

void helix_spiral() {
	start_index += this_inc;
	this_index = start_index;

	if (this_dir) {
		this_phase += this_speed; // You can change direction and speed individually.
		that_phase -= that_speed;
	}
	else {
		this_phase -= this_speed;
		that_phase += that_speed;
	}

	//  for (int k = 0; k<STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
	//    int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);                    // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
	//    leds[spiralArray[0][k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
	//    leds[spiralArray[0][k]] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
	//    this_index += this_rot;
	//  }

	for (int k = 0; k<STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int that_bright = qsubd(cubicwave8((k*all_freq) + that_phase), this_cutoff);                    // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[spiralArrayRev[2][k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[spiralArrayRev[2][k]] += ColorFromPalette(current_palette, this_index + 64 + k * this_inc, that_bright, current_blending);
		this_index += this_rot;
	}

} // helix_spiral()



void plasma_spiral() {
	plasma_phase1 = beatsin8(6, -64, 64);
	plasma_phase2 = beatsin8(7, -64, 64);

	for (int k = 0; k < STRIP_LENGTH; k++) {
		plasmaIndex = cubicwave8((k * 23) + plasma_phase1) / 2 + cos8((k * 15) + plasma_phase2) / 2;
		plasmaBright = qsuba(plasmaIndex, beatsin8(7, 0, 96));

		leds[spiralArray[0][k]] = ColorFromPalette(current_palette, plasmaIndex, plasmaBright, current_blending);
	}
} // plasma_spiral()


void plasma_spiral2() {
	plasma_phase1 = beatsin8(6, -64, 64);
	plasma_phase2 = beatsin8(7, -64, 64);

	for (int k = 0; k < STRIP_LENGTH; k++) {
		plasmaIndex = cubicwave8((k * 23) + plasma_phase1) / 2 + cos8((k * 15) + plasma_phase2) / 2;
		plasmaBright = qsuba(plasmaIndex, beatsin8(7, 0, 96));

		leds[spiralArray[0][k]] = ColorFromPalette(current_palette, plasmaIndex, plasmaBright, current_blending);
		//leds[spiralArray[1][k]] = ColorFromPalette(current_palette, plasmaIndex, plasmaBright, current_blending);
		leds[spiralArray[2][k]] = ColorFromPalette(LavaColors_p, plasmaIndex, plasmaBright, current_blending);
		//leds[spiralArray[3][k]] = ColorFromPalette(current_palette, plasmaIndex, plasmaBright, current_blending);
	}
} // plasma_spiral()

void spiral_fill_palette(uint8_t spine, uint8_t startIndex, uint8_t incIndex, CRGBPalette16 pal = current_palette, uint8_t bri = this_bright, TBlendType blending = current_blending) {
	uint8_t colorIndex = startIndex;
	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {
		leds[spiralArray[spine][i]] = ColorFromPalette(pal, colorIndex, bri, blending);
		colorIndex += incIndex;
	}
}


void palette_spiral() {

	if (this_dir) {
		color_index += color_speed;
	}
	else { color_index -= color_speed; }

	spiral_fill_palette(0, color_index, color_inc, current_palette, this_bright, current_blending);
	spiral_fill_palette(1, color_index + 64, color_inc, current_palette, this_bright, current_blending);
	spiral_fill_palette(2, color_index + 128, color_inc, current_palette, this_bright, current_blending);
	spiral_fill_palette(3, color_index + 192, color_inc, current_palette, this_bright, current_blending);
}
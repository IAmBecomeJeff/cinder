#ifndef SPIRAL_H
#define SPIRAL_H

// spiral()
// spiral_start = 0
// spiral_inc = 4
// spiral_width = 1
// this_hue

void spiral(){
	fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
	for (int r_index = 0; r_index < 4; r_index ++){
		for (int i = spiral_start + r_index*spiral_width; i < STRIP_LENGTH; i += spiral_inc*spiral_width){
			for (int w = i; w < i + spiral_width; w++){
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

void spiral_pal(){
	fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
	start_index+=this_inc;
	this_index = start_index;
	for (int r_index = 0; r_index < 4; r_index ++){
		for (int i = spiral_start + r_index*spiral_width; i < STRIP_LENGTH; i += spiral_inc*spiral_width){
			for (int w = i; w < i + spiral_width; w++){
				leds[ringArray[w%STRIP_LENGTH][r_index]] = ColorFromPalette(current_palette, this_index + w*this_inc, this_bright, current_blending);
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
  fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
	start_index += this_inc;
	this_index = start_index;
  this_phase += this_speed;
	for (int k = 0; k < STRIP_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		for (int r = 0; r < 4; r++) {
			int spiral_bri = qsuba(scale8(cubicwave8((k*all_freq) + r*64 + this_phase), 120),85);
			leds[ringArray[k][r]] = ColorFromPalette(current_palette, this_index + k * this_inc, spiral_bri, current_blending);
		}
		this_index += this_rot;
	}
}

void spiral_sin_sub() {
  fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
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


#endif

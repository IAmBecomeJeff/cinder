#ifndef SPIRAL_H
#define SPIRAL_h

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
}






#endif
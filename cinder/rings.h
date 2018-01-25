#ifndef RINGS_H
#define RINGS_H

// Use CHSV
void ringCHSV(uint8_t pos, uint8_t hue, uint8_t sat = this_sat, uint8_t bri = this_bright) {
	for (j=0;j<4;j++){
		leds[ringArray[pos][j]]=CHSV(hue,sat,bri);
	}
}

// Use CRGB
void ringCRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b){
	for (j=0;j<4;j++){
		leds[ringArray[pos][j]]=CRGB(r,g,b);
	}
}

// Use ColorFromPalette
void ringPalette(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blend = current_blending){
	for (j=0;j<4;j++){
		leds[ringArray[pos][j]] = ColorFromPalette(pal, index, bri, blend )
	}
}

#endif

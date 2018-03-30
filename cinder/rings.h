#ifndef RINGS_H
#define RINGS_H

// Use CHSV
void ringCHSV(uint8_t pos, uint8_t hue, uint8_t sat = this_sat, uint8_t bri = this_bright) {
	for (byte j=0;j<4;j++){
		leds[ringArray[pos][j]]=CHSV(hue,sat,bri);
	}
}

// Add CHSV
void ringCHSVAdd(uint8_t pos, uint8_t hue, uint8_t sat = this_sat, uint8_t bri = this_bright) {
	for (byte j=0;j<4;j++){
		leds[ringArray[pos][j]]+=CHSV(hue,sat,bri);
	}
}

// Use CRGB
void ringCRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b){
	for (byte j=0;j<4;j++){
		leds[ringArray[pos][j]]=CRGB(r,g,b);
	}
}

// Add CRGB
void ringCRGBAdd(uint8_t pos, uint8_t r, uint8_t g, uint8_t b){
	for (byte j=0;j<4;j++){
		leds[ringArray[pos][j]]+=CRGB(r,g,b);
	}
}

// Use ColorFromPalette
void ringPalette(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blending = current_blending){
	for (byte j=0;j<4;j++){
		leds[ringArray[pos][j]] = ColorFromPalette(pal, index, bri, blending);
	}
}

// Use ColorFromPalette
void ringPaletteAdd(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blending = current_blending){
  for (byte j=0;j<4;j++){
    leds[ringArray[pos][j]] += ColorFromPalette(pal, index, bri, blending);
  }
}

// Use nblend
void ring_nblend(uint16_t pix, CRGB new_color, fract8 blend_amount){
	for (byte j=0;j<4;j++){
		nblend(leds[ringArray[pix][j]], new_color, blend_amount);
	}
}

// Ring version of fill_palette
 void ring_fill_palette(uint8_t startIndex, uint8_t incIndex, CRGBPalette16 pal=current_palette, uint8_t bri = this_bright, TBlendType blending=current_blending){
    uint8_t colorIndex = startIndex;
    for( uint16_t i = 0; i < STRIP_LENGTH; i++) {
        ringPalette(i, pal, colorIndex, bri, blending);
        colorIndex += incIndex;
    }
 }

 // Ring version of fill_rainbow
 void ring_fill_rainbow(uint8_t initialhue, uint8_t deltahue){
	 byte hsv_hue;
	 hsv_hue = initialhue;
	 for( int i = 0; i < STRIP_LENGTH; i++){
		 ringCHSV(i, hsv_hue, 255, 240);
		 hsv_hue += deltahue;
	 }
 }

void ring_fill_static_palette(CRGBPalette16 pal=current_palette, uint8_t bri = this_bright, TBlendType blending=current_blending){
	for (uint8_t i = 0; i< STRIP_LENGTH; i++){
		ringPalette(i, pal, i*255/STRIP_LENGTH, bri, blending);
	}
} 
#endif

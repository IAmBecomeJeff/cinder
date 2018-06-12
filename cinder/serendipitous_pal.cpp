#include "serendipitous_pal.h"


void serendipitous_pal() {

	EVERY_N_SECONDS(5) {
		X = Xorig;
		Y = Yorig;
	}

	Xn = X - (Y / 2); Yn = Y + (Xn / 2);
	//  Xn = X-Y/2;   Yn = Y+Xn/2;
	//  Xn = X-(Y/2); Yn = Y+(X/2.1);
	//  Xn = X-(Y/3); Yn = Y+(X/1.5);
	//  Xn = X-(2*Y); Yn = Y+(X/1.1);

	X = Xn;
	Y = Yn;
	this_index = (sin8(X) + cos8(Y)) / 2;
	leds[X % (NUM_LEDS - 1)] = ColorFromPalette(current_palette, this_index, 255, LINEARBLEND);
	fadeToBlackBy(leds, NUM_LEDS, 16);                     // 8 bit, 1 = slow, 255 = fast

} // serendipitous_pal()


void serendipitous_pal_ring() {

	EVERY_N_SECONDS(5) {
		X2 = Xorig2;
		Y2 = Yorig2;
	}

	Xn2 = X2 - (Y2 / 2); Yn2 = Y2 + (Xn2 / 2);
	//  Xn = X-Y/2;   Yn = Y+Xn/2;
	//  Xn = X-(Y/2); Yn = Y+(X/2.1);
	//  Xn = X-(Y/3); Yn = Y+(X/1.5);
	//  Xn = X-(2*Y); Yn = Y+(X/1.1);

	X2 = Xn2;
	Y2 = Yn2;
	this_index = (sin8(X2) + cos8(Y2)) / 2;
	ringPalette(X2 % 143, current_palette, this_index, 255, LINEARBLEND);
	fadeToBlackBy(leds, NUM_LEDS, 16);                     // 8 bit, 1 = slow, 255 = fast

} // serendipitous_pal_ring()
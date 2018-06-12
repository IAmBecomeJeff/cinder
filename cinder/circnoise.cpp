#include "circnoise.h"

void circnoise_pal_1() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < NUM_LEDS; i++) {

		uint16_t shift_x = beatsin8(17);                  // the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = millis() / 100;                // the y position becomes slowly incremented

		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		leds[i] = ColorFromPalette(current_palette, index, bri, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
	}
} // circnoise_pal_1()



void circnoise_pal_2() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < NUM_LEDS; i++) {

		uint16_t shift_x = millis() / 10;                 // x as a function of time
		uint16_t shift_y = 0;

		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		leds[i] = ColorFromPalette(current_palette, index, bri, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
} // circnoise_pal_2()



void circnoise_pal_3() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < NUM_LEDS; i++) {

		uint16_t shift_x = 0;                             // no movement along x and y
		uint16_t shift_y = 0;


		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint32_t real_z = millis() * 20;                  // increment z linear

		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		leds[i] = ColorFromPalette(current_palette, index, bri, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
} // circnoise_pal_3()


void circnoise_pal_4() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < NUM_LEDS; i++) {

		uint16_t shift_x = beatsin8(15);                          // x as a function of time
		uint16_t shift_y = beatsin8(17);                          // y as a function of time
		uint32_t real_z = millis() / 11;                          // z is also a function of time


		uint32_t real_x = (cos8(i) + beatsin8(5, 0, 32) + shift_x) * scale;             // calculate the coordinates within the noise field
		uint32_t real_y = (sin8(i) + beatsin8(3, 0, 32) + shift_y) * scale;             // based on the precalculated positions


		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		leds[i] = ColorFromPalette(current_palette, index, bri, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
} // circnoise_pal_4()



void circnoise_pal_1_ring() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {

		uint16_t shift_x = beatsin8(17);                  // the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = millis() / 100;                // the y position becomes slowly incremented

		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		ringPalette(i, current_palette, index, bri, LINEARBLEND);
	}
}  //circnoise_pal_1_ring()


void circnoise_pal_2_ring() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {

		uint16_t shift_x = millis() / 10;                 // x as a function of time
		uint16_t shift_y = 0;

		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		ringPalette(i, current_palette, index, bri, LINEARBLEND);				// With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
}  //circnoise_pal_2_ring()


void circnoise_pal_3_ring() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {

		uint16_t shift_x = 0;                             // no movement along x and y
		uint16_t shift_y = 0;


		uint32_t real_x = (xd[i] + shift_x) * scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * scale;       // based on the precalculated positions

		uint32_t real_z = millis() * 20;                  // increment z linear

		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		ringPalette(i, current_palette, index, bri, LINEARBLEND);
		// With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
} // circnoise_pal_3_ring()



void circnoise_pal_4_ring() {

	int scale = 1000;                               // the "zoom factor" for the noise

	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {

		uint16_t shift_x = beatsin8(15);                          // x as a function of time
		uint16_t shift_y = beatsin8(17);                          // y as a function of time
		uint32_t real_z = millis() / 11;                          // z is also a function of time


		uint32_t real_x = (cos8(i) + beatsin8(5, 0, 32) + shift_x) * scale;             // calculate the coordinates within the noise field
		uint32_t real_y = (sin8(i) + beatsin8(3, 0, 32) + shift_y) * scale;             // based on the precalculated positions


		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;           // get the noise data and scale it down

		uint8_t index = noise * 3;                        // map led color based on noise data
		uint8_t bri = noise;

		ringPalette(i, current_palette, index, bri, LINEARBLEND);
		// With that value, look up the 8 bit colour palette value and assign it to the current LED.

	}
} // circnoise_pal_4_ring()

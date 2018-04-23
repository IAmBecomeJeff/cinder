#ifndef METEORRAIN_H
#define METEORRAIN_H

void meteorRain() {
	// set all to black first, but outside of loop, mc change should cover that
	for (int i = 0; i < STRIP_LENGTH + STRIP_LENGTH; i++) {
		for (int j = 0; j < NUM_LEDS; j++) {
			if ((!meteorRandomDecay) || (random(10),5)) {
				leds[j].fadeToBlackBy(meteorTrailDecay);
			}
		}

		for (int j = 0; j < meteorSize; j++) {
			if ((i - j < STRIP_LENGTH) && (i - j >= 0)) {
				ringCRGB(i - j, r, g, b);
			}
		}
	} // move this for loop outside of the function.  meteor_count & meteor_limit or something.
}












#endif
#include "ripple.h"

int wrap(int step) {
	if (step < 0) return STRIP_LENGTH + step;
	if (step > STRIP_LENGTH - 1) return step - STRIP_LENGTH;
	return step;
}

void ripple() {

	if (rip_currentBg == rip_nextBg) {
		rip_nextBg = random(256);
	}
	else if (rip_nextBg > rip_currentBg) {
		rip_currentBg++;
	}
	else {
		rip_currentBg--;
	}

	for (uint8_t l = 0; l < NUM_LEDS; l++) {
		leds[l] = CHSV(rip_currentBg, 255, 50);
	}

	if (rip_step == -1) {
		rip_center = random(STRIP_LENGTH);
		rip_color = random(256);
		rip_step = 0;
	}

	if (rip_step == 0) {
		ringCHSV(rip_center, rip_color, 255, 255);
		rip_step++;
	}
	else {
		if (rip_step < rip_maxSteps) {
			//Serial.println(pow(fadeRate, step));
			ringCHSV(wrap(rip_center + rip_step), rip_color, 255, pow(rip_fadeRate, rip_step) * 255);
			ringCHSV(wrap(rip_center - rip_step), rip_color, 255, pow(rip_fadeRate, rip_step) * 255);
			if (rip_step > 3) {
				ringCHSV(wrap(rip_center + rip_step - 3), rip_color, 255, pow(rip_fadeRate, rip_step - 2) * 255);
				ringCHSV(wrap(rip_center - rip_step + 3), rip_color, 255, pow(rip_fadeRate, rip_step - 2) * 255);
			}
			rip_step++;
		}
		else {
			rip_step = -1;
		}
	}
} // ripple()

void ripple2() {

	fadeToBlackBy(leds, NUM_LEDS, fadeval);                             // 8 bit, 1 = slow, 255 = fast

	switch (rip_step) {

	case -1:                                                          // Initialize ripple variables.
		rip_center = random(STRIP_LENGTH);
		rip_color = random8();
		rip_step = 0;
		break;

	case 0:
		leds[rip_center] = ColorFromPalette(current_palette, rip_color, myfade, current_blending);
		rip_step++;
		break;

	case rip_maxSteps:                                                    // At the end of the ripples.
		rip_step = -1;
		break;

	default:                                                          // Middle of the ripples.
		ringPaletteAdd((rip_center + rip_step + STRIP_LENGTH) % STRIP_LENGTH, current_palette, rip_color, myfade / rip_step * 2, current_blending);       // Simple wrap from Marc Miller
		ringPaletteAdd((rip_center - rip_step + STRIP_LENGTH) % STRIP_LENGTH, current_palette, rip_color, myfade / rip_step * 2, current_blending);
		rip_step++;                                                         // Next step.
		break;
	} // switch step

} // ripple2()
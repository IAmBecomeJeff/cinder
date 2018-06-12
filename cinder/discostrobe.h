#ifndef DISCOSTROBE_H
#define DISCOSTROBE_H

static void drawRainbowDashes(
	uint8_t startpos, uint16_t lastpos, uint8_t period, uint8_t width,
	uint8_t huestart, uint8_t huedelta, uint8_t saturation, uint8_t value);

void discoWorker(
	uint8_t dashperiod, uint8_t dashwidth, int  dashmotionspeed,
	uint8_t stroberepeats,
	uint8_t huedelta);

void discostrobe(void);

static void delayToSyncFrameRate(uint8_t framesPerSecond);

#endif

#ifndef TWINKLE_H
#define TWINKLE_H

uint8_t attackDecayWave8(uint8_t i);

void coolLikeIncandescent(CRGB& c, uint8_t phase);

CRGB computeOneTwinkle(uint32_t ms, uint8_t salt);

void twinkle(void);

#endif

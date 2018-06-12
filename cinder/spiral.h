#ifndef SPIRAL_H
#define SPIRAL_H

void spiral(void);

void spiral_pal(void);

void spiral_sin(void);

void spiral_sin_sub(void);

void one_sin_spiral(void);

void helix_spiral(void);

void plasma_spiral(void);

void plasma_spiral2(void);

void spiral_fill_palette(uint8_t spine, uint8_t startIndex, uint8_t incIndex, CRGBPalette16 pal = current_palette, uint8_t bri = this_bright, TBlendType blending = current_blending);

void palette_spiral(void);

#endif

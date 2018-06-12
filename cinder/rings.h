#ifndef RINGS_H
#define RINGS_H

void ringCHSV(uint8_t pos, uint8_t hue, uint8_t sat = this_sat, uint8_t bri = this_bright);

void ringCHSVAdd(uint8_t pos, uint8_t hue, uint8_t sat = this_sat, uint8_t bri = this_bright);

void ringCRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b);

void ringCRGBAdd(uint8_t pos, uint8_t r, uint8_t g, uint8_t b);

void ringPalette(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blending = current_blending);

void ringPaletteAdd(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blending = current_blending);

void ring_nblend(uint16_t pix, CRGB new_color, fract8 blend_amount);

void ring_fill_palette(uint8_t startIndex, uint8_t incIndex, CRGBPalette16 pal = current_palette, uint8_t bri = this_bright, TBlendType blending = current_blending);

void ring_fill_rainbow(uint8_t initialhue, uint8_t deltahue);

void ring_fill_static_palette(CRGBPalette16 pal = current_palette, uint8_t bri = this_bright, TBlendType blending = current_blending);

#endif

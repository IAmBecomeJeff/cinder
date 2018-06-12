#ifndef NOISE8_PAL_H
#define NOISE8_PAL_H


uint16_t dist = 12345;         // A random number for our noise generator.
uint16_t scale = 30;          // Wouldn't recommend changing this_ on the fly, or the animation will be really blocky.

void noise8_pal(void);           

void noise8_pal_ring(void);

#endif

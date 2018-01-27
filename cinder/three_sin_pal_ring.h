#ifndef THREE_SIN_PAL_RING_H
#define THREE_SIN_PAL_RING_H



// three_sin_pal_ring variables ---------------------------------------------------------------------

int wave1;
int wave2;
int wave3;
uint8_t mul1;
uint8_t mul2;
uint8_t mul3;


void three_sin_pal_ring() {
  wave1 += beatsin8(10,-4,4);
  wave2 += beatsin8(15,-2,2);
  wave3 += beatsin8(12,-3, 3);

  for (int k=0; k<144; k++) {
    uint8_t tmp = sin8(mul1*k + wave1) + sin8(mul1*k + wave2) + sin8(mul1*k + wave3);
    ringPalette(k, current_palette, tmp, 255);
  }
} // three_sin_pal_ring()


#endif

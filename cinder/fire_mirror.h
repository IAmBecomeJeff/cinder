#ifndef FIRE_MIRROR_H
#define FIRE_MIRROR_H



CRGB leds_temp[STRIP_LENGTH/2];  // half the total number of pixels



bool this_dir = false;  //false = center outward, true = from ends inward


//---------------------------------------------------------------
void loop()
{
  // Add entropy to random number generator; we use a lot of it.
  // random16_add_entropy( random());

  Fire2012_halfStrip(); // draw fire data to leds_temp

  mirror2ndHalf();  // copy and mirror data from leds_temp to leds

  FastLED.show(); // display leds
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}



void Fire2012_halfStrip() {
  // Fuction only operates on half the number of pixels (NUM_LEDS/2)
  
  // Array of temperature readings at each simulation cell
  static byte heat[STRIP_LENGTH/2];

  // Step 1.  Cool down every cell a little
  for( int i = 0; i < STRIP_LENGTH/2; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / (STRIP_LENGTH/2)) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= (STRIP_LENGTH/2) - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  
  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if( random8() < sparking ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for( int j = 0; j < STRIP_LENGTH/2; j++) {
    ringCRGB(j, HeatColor(heat[j]).r, HeatColor(heat[j]).g, HeatColor(heat[j]).b);
	//CRGB color = HeatColor( heat[j]);
    leds_temp[j] = color;
  }

}//end_Fire2012_halfStrip


//---------------------------------------------------------------
void mirror2ndHalf() {
  //copy and mirror pixel data from leds_temp to leds array.

  if (!this_dir) {  //false is center outward
    for (uint8_t i=0; i<STRIP_LENGTH/2; i++) {
      leds[(STRIP_LENGTH/2)-1-i] = leds_temp[i];
      leds[(STRIP_LENGTH/2)+i] = leds_temp[i];
    }

  } else {  //true is from ends inward
    for (uint8_t i=0; i<STRIP_LENGTH/2; i++) {
      leds[i] = leds_temp[i];
      leds[(STRIP_LENGTH-1)-i] = leds_temp[i];
    }
  }
  
}//end_mirror2ndHalf
#endif
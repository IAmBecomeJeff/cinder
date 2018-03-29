#ifndef FIRE_H
#define FIRE_H

void fire()
{
// Array of temperature readings at each simulation cell
  static byte heat[STRIP_LENGTH];
 
  // Step 1.  Cool down every cell a little
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
 
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k = STRIP_LENGTH - 3; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
   
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
 
    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < STRIP_LENGTH; j++) {
		 CRGB hcolor = HeatColor(heat[j]);
		 ringCRGB(j, hcolor.r, hcolor.g, hcolor.b);
    //  ringCRGB(j, HeatColor(heat[j]).r, HeatColor(heat[j]).g, HeatColor(heat[j]).b);
		//leds[j] = HeatColor( heat[j]);
    }
}

#endif

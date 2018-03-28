#ifndef FIRE_RINGS_H
#define FIRE_RINGS_H

// Call with a call to fire1(), fire2(), fire3(), fire4()

void fire1()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
		 CRGB hcolor = HeatColor(heat[j]);
		leds[ringArray[j][0]] = HeatColor( heat[j]);
    }
}

void fire2()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
		 CRGB hcolor = HeatColor(heat[j]);
		leds[ringArray[j][1]] = HeatColor( heat[j]);
    }
}

void fire3()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
		 CRGB hcolor = HeatColor(heat[j]);
		leds[ringArray[j][2]] = HeatColor( heat[j]);
    }
}

void fire4()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
		 CRGB hcolor = HeatColor(heat[j]);
		leds[ringArray[j][3]] = HeatColor( heat[j]);
    }
}
#endif
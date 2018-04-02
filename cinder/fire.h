#ifndef FIRE_H
#define FIRE_H

// Functions:
	// fire()			
		// Moves a fire along the strip, with the rings all the same

	// fire_pal()
		// Moves a fire along the strip with a palette, with the rings all the same

	// fire_mirror()
		// Fire from middle or ends, rings all the same

	// fire_mirror_pal()
		// Fire mirrored, with palette, rings all the same
		
	// fire_rings()
		// Fire with each strip a different flame

	// fire_pal_rings()
		// Fire with each strip a different flame, using palettes

	// fire_mirror_rings()
		// Mirrored fire, with each strip different flame
		
	// fire_mirror_pal_rings()
		// Mirrored fire, with palettes, each strip different
	


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


// fire with a palette
void fire_pal()
{
// Array of temperature readings at each simulation cell
  static byte heat[STRIP_LENGTH];

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / STRIP_LENGTH) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= STRIP_LENGTH - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < STRIP_LENGTH; j++) {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      byte colorindex = scale8( heat[j], 240);
      //CRGB color = ColorFromPalette( current_palette, colorindex);
      int pixelnumber;
      if( this_dir ) {
        pixelnumber = (STRIP_LENGTH-1) - j;
      } else {
        pixelnumber = j;
      }
      ringPalette(pixelnumber, current_palette, colorindex);
	  //leds[pixelnumber] = color;
    }
}



// fire mirrored from ends or center
void fire_mirror() {
  static byte heat[STRIP_LENGTH/2];
  for( int i = 0; i < STRIP_LENGTH/2; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / (STRIP_LENGTH/2)) + 2));
  }
  for( int k= (STRIP_LENGTH/2) - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < sparking ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  if (this_dir){
    for( int j = 0; j < STRIP_LENGTH/2; j++) {
       CRGB hcolor = HeatColor(heat[j]);
       ringCRGB(j, hcolor.r, hcolor.g, hcolor.b);
       ringCRGB(STRIP_LENGTH-1-j, hcolor.r, hcolor.g, hcolor.b);
    }
  } else {
    for (int j = 0; j < STRIP_LENGTH/2; j++) {
      CRGB hcolor = HeatColor(heat[j]);
      ringCRGB((STRIP_LENGTH/2) - 1 - j, hcolor.r, hcolor.g, hcolor.b);
      ringCRGB((STRIP_LENGTH/2) + j, hcolor.r, hcolor.g, hcolor.b);
    }
  }
  
}//end fire_mirror



// fire mirrored from ends or center using palette
void fire_mirror_pal() {
  static byte heat[STRIP_LENGTH/2];
  for( int i = 0; i < STRIP_LENGTH/2; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / (STRIP_LENGTH/2)) + 2));
  }
  for( int k= (STRIP_LENGTH/2) - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < sparking ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < STRIP_LENGTH/2; j++){
	  byte colorindex = scale8(heat[j],240);
	  CRGB color = ColorFromPalette( current_palette, colorindex);
	  if (this_dir){
		  ringPalette(j, current_palette, colorindex);
		  ringPalette(STRIP_LENGTH-1-j, current_palette, colorindex);
	  } else {
			ringPalette((STRIP_LENGTH/2) - 1 - j, current_palette, colorindex);
			ringPalette((STRIP_LENGTH/2) + j, current_palette, colorindex);  
	  }
  }
} // end fire_mirror_pal()




// fire with each strip doing a seperate flame
void fire_rings1()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling1 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking1 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
     if (!this_dir){
      leds[ringArray[STRIP_LENGTH-1-j][0]] = HeatColor( heat[j]);
     } else {
		leds[ringArray[j][0]] = HeatColor( heat[j]);
     }
    }
}

void fire_rings2()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling2 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking2 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
     if (!this_dir){
      leds[ringArray[STRIP_LENGTH-1-j][1]] = HeatColor( heat[j]);
     } else {
		leds[ringArray[j][1]] = HeatColor( heat[j]);
     }
    }
}

void fire_rings3()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling3 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking3 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
     if (!this_dir){
      leds[ringArray[STRIP_LENGTH-1-j][2]] = HeatColor( heat[j]);
     } else {
		   leds[ringArray[j][2]] = HeatColor( heat[j]);
     }
    }
}

void fire_rings4()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling4 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking4 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
     if (!this_dir){
      leds[ringArray[STRIP_LENGTH-1-j][3]] = HeatColor( heat[j]);
     } else {
		 leds[ringArray[j][3]] = HeatColor( heat[j]);
     }
    }
}

void fire_rings(){
	fire_rings1();
	fire_rings2();
	fire_rings3();
	fire_rings4();
}




// fire rings using current_palette
void fire_pal_rings1()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling1 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking1 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
      byte colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( current_palette, colorindex);
      int pixelnumber;
      if( this_dir ) {
        pixelnumber = (STRIP_LENGTH-1) - j;
      } else {
        pixelnumber = j;
      }
	  leds[ringArray[pixelnumber][0]] = color;
    }
}

void fire_pal_rings2()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling2 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking2 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
      byte colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( current_palette, colorindex);
      int pixelnumber;
      if( this_dir ) {
        pixelnumber = (STRIP_LENGTH-1) - j;
      } else {
        pixelnumber = j;
      }
      //ringPalette(pixelnumber, current_palette, colorindex);
	  leds[ringArray[pixelnumber][1]] = color;
    }
}

void fire_pal_rings3()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling3 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking3 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
      byte colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( current_palette, colorindex);
      int pixelnumber;
      if( this_dir ) {
        pixelnumber = (STRIP_LENGTH-1) - j;
      } else {
        pixelnumber = j;
      }
      //ringPalette(pixelnumber, current_palette, colorindex);
	  leds[ringArray[pixelnumber][2]] = color;
    }
}

void fire_pal_rings4()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling4 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking4 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
    for( int j = 0; j < STRIP_LENGTH; j++) {
      byte colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( current_palette, colorindex);
      int pixelnumber;
      if( this_dir ) {
        pixelnumber = (STRIP_LENGTH-1) - j;
      } else {
        pixelnumber = j;
      }
      //ringPalette(pixelnumber, current_palette, colorindex);
	  leds[ringArray[pixelnumber][3]] = color;
    }
}

void fire_pal_rings(){
	fire_pal_rings1();
	fire_pal_rings2();
	fire_pal_rings3();
	fire_pal_rings4();
}




// fire mirror using seperate fires for each strip
void fire_mirror_rings1(){
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling1 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking1 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		CRGB hcolor = HeatColor(heat[j]);	
		if(this_dir){
			leds[ringArray[j][0]] = hcolor;
			leds[ringArray[STRIP_LENGTH-1-j][0]] = hcolor;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][0]] = hcolor;
			leds[ringArray[(STRIP_LENGTH/2) + j][0]] = hcolor;
		}
	}
}	

void fire_mirror_rings2(){
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling2 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking2 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		CRGB hcolor = HeatColor(heat[j]);	
		if(this_dir){
			leds[ringArray[j][1]] = hcolor;
			leds[ringArray[STRIP_LENGTH-1-j][1]] = hcolor;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][1]] = hcolor;
			leds[ringArray[(STRIP_LENGTH/2) + j][1]] = hcolor;
		}
	}
}	

void fire_mirror_rings3(){
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling3 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking3 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		CRGB hcolor = HeatColor(heat[j]);	
		if(this_dir){
			leds[ringArray[j][2]] = hcolor;
			leds[ringArray[STRIP_LENGTH-1-j][2]] = hcolor;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][2]] = hcolor;
			leds[ringArray[(STRIP_LENGTH/2) + j][2]] = hcolor;
		}
	}
}	

void fire_mirror_rings4(){
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling4 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking4 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		CRGB hcolor = HeatColor(heat[j]);	
		if(this_dir){
			leds[ringArray[j][3]] = hcolor;
			leds[ringArray[STRIP_LENGTH-1-j][3]] = hcolor;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][3]] = hcolor;
			leds[ringArray[(STRIP_LENGTH/2) + j][3]] = hcolor;
		}
	}
}	

void fire_mirror_rings(){
	fire_mirror_rings1();
	fire_mirror_rings2();
	fire_mirror_rings3();
	fire_mirror_rings4();
}





// fire mirror rings with palette
void fire_mirror_pal_rings1()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling1 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking1 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		byte colorindex = scale8( heat[j], 240);
		CRGB color = ColorFromPalette( current_palette, colorindex);
		if(this_dir){
			leds[ringArray[j][0]] = color;
			leds[ringArray[STRIP_LENGTH-1-j][0]] = color;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][0]] = color;
			leds[ringArray[(STRIP_LENGTH/2) + j][0]] = color;
		}
	}
}	

void fire_mirror_pal_rings2()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling2 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking2 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		byte colorindex = scale8( heat[j], 240);
		CRGB color = ColorFromPalette( current_palette, colorindex);
		if(this_dir){
			leds[ringArray[j][1]] = color;
			leds[ringArray[STRIP_LENGTH-1-j][1]] = color;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][1]] = color;
			leds[ringArray[(STRIP_LENGTH/2) + j][1]] = color;
		}
	}
}	

void fire_mirror_pal_rings3()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling3 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking3 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		byte colorindex = scale8( heat[j], 240);
		CRGB color = ColorFromPalette( current_palette, colorindex);
		if(this_dir){
			leds[ringArray[j][2]] = color;
			leds[ringArray[STRIP_LENGTH-1-j][2]] = color;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][2]] = color;
			leds[ringArray[(STRIP_LENGTH/2) + j][2]] = color;
		}
	}
}	

void fire_mirror_pal_rings4()
{
  static byte heat[STRIP_LENGTH];
    for( int i = 0; i < STRIP_LENGTH; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling4 * 10) / STRIP_LENGTH) + 2));
    }
    for( int k= STRIP_LENGTH - 3; k > 0; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if( random8() < sparking4 ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }
	for ( int j = 0; j < STRIP_LENGTH/2; j++) {
		byte colorindex = scale8( heat[j], 240);
		CRGB color = ColorFromPalette( current_palette, colorindex);
		if(this_dir){
			leds[ringArray[j][3]] = color;
			leds[ringArray[STRIP_LENGTH-1-j][3]] = color;
		} else {
			leds[ringArray[(STRIP_LENGTH/2) - 1- j][3]] = color;
			leds[ringArray[(STRIP_LENGTH/2) + j][3]] = color;
		}
	}
}	

void fire_mirror_pal_rings(){
	fire_mirror_pal_rings1();
	fire_mirror_pal_rings2();
	fire_mirror_pal_rings3();
	fire_mirror_pal_rings4();
}

#endif
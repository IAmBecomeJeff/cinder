#ifndef GRAVITY_H
#define GRAVITY_H

/* Usage - gravity();
 *
 * 
 */

uint8_t x_grav;
//uint8_t x_prev;
//uint8_t x0 = 143;
//uint8_t accel = -9.8;
//uint8_t v0 = 0;
uint8_t atBottom = 0;
uint8_t timer = 0;
//uint8_t pause = 100;
uint8_t palette_index;

void gravity() {                                                              // This is the heart of this_ program. Sure is short.

  if (timer == 0) {x = x0;}
  
  x_prev = x_grav;
  x_grav = x0 + v0 * timer + 0.5 * accel * timer * timer;
  timer += this_delay / 1000;
  
  if (x <= 0) {		// Handle x going below 0
	  count +=1;	// Create a delay before resetting
	  x = 0;
  }
  if (count == pause) { // Once we reach the time for pause, reset
	  timer = 0;
  }
  palette_index = x * 255 / 143;
  
  ringCRGB(x_prev,0,0,0); // maybe use fadeToBlackBy?
  //ringCRGB(x,255,0,0);
  ringPalette(x, current_palette, palette_index, this_bright, current_blending);

  }
} // gravity()

#endif



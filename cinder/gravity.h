#ifndef GRAVITY_H
#define GRAVITY_H

/* Usage - gravity();
 *	set x0, v0, accel, pause, 
 * 
 */

//uint8_t x_grav;
//uint8_t x_prev;
//uint8_t x0 = 143;
//uint8_t accel = -9.8;
//uint8_t v0 = 0;
//uint8_t atBottom = 0;
//uint8_t timer = 0;
//uint8_t pause = 100;
//uint8_t paletteindex;
//uint8_t count = 0;

void gravity() {   
  Serial.print("timer: ");
  Serial.println(timer);
  if (timer == 0) {x_grav = x0;}

  Serial.print("atBottom: ");
  Serial.println(atBottom);
  if (!atBottom) {
	  x_prev = x_grav;
	  x_grav = x0 + v0 * timer + 0.5 * accel * timer * timer;
	  timer += this_delay / 100;
    Serial.print("x_prev: "); 
    Serial.println(x_prev);
    Serial.print("x_grav: ");
    Serial.println(x_grav);
    Serial.print("timer: ");
    Serial.println(timer);
  } else {
	  grav_count++;
  }

  if (x_grav <= 0) {atBottom = 1;}

  if (grav_count >= pause) { // Once we reach the time for pause, reset
	  timer = 0;
	  grav_count = 0;
	  atBottom = 0;
  }

  palette_index = x_grav * 255 / 143;
  
  ringCRGB(x_prev,0,0,0); // maybe use fadeToBlackBy?
  ringPalette(x_grav, current_palette, palette_index, this_bright, current_blending);

} // gravity()

#endif



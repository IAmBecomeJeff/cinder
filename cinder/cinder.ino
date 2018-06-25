#include "includes.h"
// Modified from Caleb's modified version of seirlight

void setup() {
  // Set up serial connection
  Serial.begin(SERIAL_BAUDRATE);
  Serial.setTimeout(SERIAL_TIMEOUT);

  delay(2000);

  // Set up LEDS
  LEDS.setBrightness(max_bright);

  // -- Single strip of 576 LEDS ------------------------------- //

  LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  // --------------------------------------------------------------------------------------- //

  set_max_power_in_volts_and_milliamps(5, 1750); // TODO: increase power?

  // Set up variables
  random16_set_seed(4832);
  random16_add_entropy(analogRead(2));

  Serial.println("---SETUP COMPLETE---");

  // Load starting mode and number of leds
  led_mode = EEPROM.read(STARTMODE);

  // Set up palettes
  current_palette  = CRGBPalette16(CRGB::Black);
  target_palette   = RainbowColors_p;
  current_blending = LINEARBLEND;

  // Set up circ_noise variables
  for (long i = 0; i < NUM_LEDS; i++) {
    uint8_t angle = (i * 256) / NUM_LEDS;
    xd[i] = cos8( angle );
    yd[i] = sin8( angle );
  }

  // Set up rotary encoder
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
  pinMode(pinSW,INPUT_PULLUP); // or pinMode(pinSW,INPUT); if I use the 10k resistor
  pinALast = digitalRead(pinA);
  debouncer.attach(pinSW);
  debouncer.interval(100);

  // Set up switches
  pinMode(switchA, INPUT_PULLUP);
  pinMode(switchB, INPUT_PULLUP);

  // Init ring array
  for (uint8_t i=0;i<144;i++){
	ringArray[i][0]=i;
	ringArray[i][1]=287-i;
	ringArray[i][2]=288+i;
	ringArray[i][3]=575-i;
  }

  // Init spiral array

	for(int i=0; i<STRIP_LENGTH; i+=4*w){
		for(int j=0; j<w; j++){
			spiralArray[0][i+j]     = i + j;
			spiralArray[0][i+j+w]   = 287 - w - i - j;
			spiralArray[0][i+j+2*w] = 288 + 2*w + i + j;
			spiralArray[0][i+j+3*w] = 575 - 3*w - i - j;
			spiralArray[1][i+j]     = 287 - i - j;
			spiralArray[1][i+j+w]   = 288 + w + i + j;
			spiralArray[1][i+j+2*w] = 575 - 2*w - i - j;
			spiralArray[1][i+j+3*w] = 3*w + i + j;
			spiralArray[2][i+j]     = 288 + i + j;
			spiralArray[2][i+j+w]   = 575 - w - i - j;
			spiralArray[2][i+j+2*w] = 2*w + i + j;
			spiralArray[2][i+j+3*w] = 287 - 3*w - i - j;
			spiralArray[3][i+j]     = 575 - i - j;
			spiralArray[3][i+j+w]   = w + i + j;
			spiralArray[3][i+j+2*w] = 287 - 2*w - i - j;
			spiralArray[3][i+j+3*w] = 288 + 3*w + i + j;
		}
	}

	for (int i = 0; i<STRIP_LENGTH; i += 4 * w) {
		for (int j = 0; j<w; j++) {
			spiralArrayRev[0][i + j] = i + j;
			spiralArrayRev[0][i + j + w] = 575 - w - i - j;
			spiralArrayRev[0][i + j + 2 * w] = 288 + 2 * w + i + j;
			spiralArrayRev[0][i + j + 3 * w] = 287 - 3 * w - i - j;

			spiralArrayRev[1][i + j] = 287 - i - j;
			spiralArrayRev[1][i + j + w] = w + i + j;
			spiralArrayRev[1][i + j + 2 * w] = 575 - 2 * w - i - j;
			spiralArrayRev[1][i + j + 3 * w] = 288 + 3 * w + i + j;

			spiralArrayRev[2][i + j] = 288 + i + j;
			spiralArrayRev[2][i + j + w] = 287 - w - i - j;
			spiralArrayRev[2][i + j + 2 * w] = 2 * w + i + j;
			spiralArrayRev[2][i + j + 3 * w] = 575 - 3 * w - i - j;

			spiralArrayRev[3][i + j] = 575 - i - j;
			spiralArrayRev[3][i + j + w] = 288 + w + i + j;
			spiralArrayRev[3][i + j + 2 * w] = 287 - 2 * w - i - j;
			spiralArrayRev[3][i + j + 3 * w] = 3 * w + i + j;
		}
	}

  // Init first mode
  strobe_mode(led_mode, 1, 0);
}

void loop() {
  // Get keyboard input
  readkeyboard();

  // Check rotary dial
  checkDial();

  // Check switchA for direction
  if (digitalRead(switchA)) {
	  this_dir = 0;
  }
  else {
	  this_dir = 1;
  }

  // Check switchB for demo
  EVERY_N_SECONDS(30) {
	  if (!digitalRead(switchB)) {
      if (rotary_function==1){
        updatePaletteIndex(target_palette);
        palette_index++;
        if (palette_index > g_gradient_palette_count -1){palette_index= 0;}
        target_palette = g_gradient_palettes[palette_index];  
        Serial.print("Palette number: ");
        Serial.println(palette_index);
      }else{
  		  old_mode = led_mode;
  		  led_mode++;
  		  if (led_mode > max_mode) {
  			  led_mode = 2;
  		  }
  		  update_old_variables();
  		  transitioning = 1;
  		  strobe_mode(led_mode,1,0);
        }
	  }
  }

  // Palette transitions - always running
  EVERY_N_MILLISECONDS(50) {
    uint8_t maxChanges = 24;
    nblendPaletteTowardPalette(current_palette, target_palette, maxChanges);
  }

  // Dynamically change delay
  EVERY_N_MILLIS_I(this_timer, this_delay) {
    this_timer.setPeriod(this_delay);
	  strobe_mode(led_mode, 0, 0);
	  if (transitioning) {
		  strobe_mode(old_mode, 0, 1);
	  }
  }

  if (transitioning) {
	  glitter = 1;
    if (transition_wait){
  	   blending_ratio += 1;
     }
	  for (int i = 0; i < NUM_LEDS; i++) {
		  leds[i] = blend(old_leds[i], cur_leds[i], blending_ratio);
	  }
	  if (blending_ratio >= 255) {
		  transitioning = 0;
		  blending_ratio = 0;
		  glitter = 0;
      fill_solid(old_leds, NUM_LEDS, CRGB(0, 0, 0)); // TODO update old_pal to be cur_pal before cur_pal gets updated.
	  }
    transition_wait = !transition_wait;
  }
  else {
	  for (int i = 0; i < NUM_LEDS; i++) {
		  leds[i] = cur_leds[i];
	  }
  }


  // Optionally add glitter
  if(glitter) addglitter(10);

  show_at_max_brightness_for_power();
  //FastLED.show();
}

/*
 * Sets the mode/routine for the LEDs.
 *
 * @param newMode : the mode to set the leds to
 * @param mc      : signifies if we're changing modes or not
 */
void strobe_mode(uint8_t newMode, bool mc, bool old){
	// void strobe_mode(uint8_t newMode, bool mc){
  // If this_ is a *new* mode, clear out LED array.
  if(mc) {
    //fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0)); // comment out for transitioning
	fill_solid(cur_leds, NUM_LEDS, CRGB(0, 0, 0));
	Serial.print("Mode: ");
    Serial.println(led_mode);
	// transitioning = 1;
  }

  switch (newMode) {

    // 0 - all off TODO REMOVE
    case  0:
			//if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0 )); }
			if (mc) { fill_solid(cur_leds, NUM_LEDS, CRGB(0, 0, 0)); }
			break;

    // 1 - all on TODO REMOVE
    case  1:
			//if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 255, 255, 255 )); }
			if (mc) { fill_solid(cur_leds, NUM_LEDS, CRGB(255, 255, 255)); }
			break;

    // 2 - two-sin TODO COMBINE with others or remove
    case  2:
			if(mc) { this_delay = 10; all_freq = 2; this_speed = 1; thatspeed = 1; this_hue = 0; thathue = 128; this_rot = 1; thatrot = 1; this_cutoff = 128; thatcutoff = 192; }
			two_sin(old);
			break;

    // 3 - one-sin with rainbow palette TODO REMOVE
    case  3:
			if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 4 - noise8 with party palette TODO REMOVE
    case  4:
			if(mc) { this_delay = 10; target_palette = PartyColors_p; palette_change = 2; }
			noise8_pal(old);
			break;

    // 5 - two-sin TODO combine with others or remove
    case  5:
			if(mc) { this_delay = 10; all_freq = 4; this_speed = -1; thatspeed = 0; this_hue = 64; thathue = 192; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 192; }
			two_sin(old);
			break;

    // 6 - one-sin with rainbow palette //TODO REMOVE
    case  6:
			if(mc) { this_delay = 8; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 7 - juggle mode TODO REMOVE
    case  7:
			if(mc) { this_delay = 10; numdots = 6; target_palette = PartyColors_p; this_fade = 16; this_beat = 8; this_bright = 255; this_diff = 64; } // if ring, use numdots_ring
			juggle_pal(old);
			break;

    // 8 - matrix with palette // TODO REMOVE
    case  8:
			if(mc) { this_delay = 15; target_palette = LavaColors_p; this_index = 128; this_rot = 0; this_bright = 255; bg_clr = 200; bg_bri = 6; }
			matrix_pal(old);
			break;

    // 9 - two-sin // TODO combine with others or REMOVE
    case  9:
			if(mc) { this_delay = 10; all_freq = 6; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 64; }
			two_sin(old);
			break;

    // 10 - one-sin with rainbow palette // TODO REMOVE
    case 10:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 11 - three-sin with palette // TODO change to ring
    case 11:
			if(mc) { this_delay = 20; mul1 = 5; mul2 = 8; mul3 = 7; }
			three_sin_pal(old);
			break;

    // 12 - serendipitous with palette TODO combine with twinkle or confetti
    case 12:
			if(mc) { this_delay = 10; target_palette = ForestColors_p; }
			serendipitous_pal(old);
			break;

    // 13 - one-sine with lava palette // TODO REMOVE
    case 13:
			if(mc) { this_delay = 8; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 14 - two-sin TODO this looks really cool... find out why
    case 14:
			if(mc) { this_delay = 10; all_freq = 20; this_speed = 2; thatspeed = -1; this_hue = 24; thathue = 180; this_rot = 0; thatrot = 1; this_cutoff = 64; thatcutoff = 128; }
			two_sin(old);
			break;

    // 15 - matrix with party palette // TODO REMOVE
    case 15:
			if(mc) { this_delay = 20; target_palette = PartyColors_p; this_index = 64; this_rot = 1; this_bright = 255; bg_clr = 100; bg_bri = 10; }
			matrix_pal(old);
			break;

    // 16 - noise8 with palette TODO REMOVE
    case 16:
			if(mc) { this_delay = 10; target_palette = OceanColors_p; palette_change = 1; }
			noise8_pal(old);
			break;

    // 17 - circular noise with party palette TODO REMOVE
    case 17:
   			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_2(old);
			break;

    // 18 - two-sin TODO combine with other two sins or remove
    case 18:
 			if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 48; thathue = 160; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
			two_sin(old);
			break;

    // 19 - three-sin with palette TODO REMOVE, only keep 3sin rings
    case 19:
 			if(mc) { this_delay = 50; mul1 = 6; mul2 = 9; mul3 = 11; }
			three_sin_pal(old);
			break;

    // 20 - rainbow march with wide waves TODO same as 37, REMOVE one at least
    case 20:
 			if(mc) { this_delay = 10; this_rot = 1; this_diff = 1; }
			rainbow_march(old);
			break;

    // 21 - rainbow march with narrow waves TODO combine with other rainbows or remove
    case 21:
 			if(mc) { this_delay = 10; this_rot = 2; this_diff = 10; }
			rainbow_march(old);
			break;

    // 22 - one-sine with ocean palette // increase delay from 20 to 8 to fix jerkinessTODO REMOVE
    case 22: 
 			if(mc) { this_delay = 8; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 23 - circular noise with ocean palette TODO REMOVE
    case 23:
 			if(mc) { this_delay = 10; target_palette = OceanColors_p; }
			circnoise_pal_4(old);
			break;

    // 24 - two-sin TODO REMOVE or combine in transitions
    case 24:
 			if(mc) { this_delay = 10; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_rot = 1; thatrot = 2; this_cutoff = 128; thatcutoff = 64; }
			two_sin(old);
			break;

    // 25 - matrix with forest palette //TODO REMOVE
    case 25:
 			if(mc) { this_delay = 25; target_palette = ForestColors_p; this_index = 192; this_rot = 0; this_bright = 255; bg_clr = 50; bg_bri = 0; }
			matrix_pal(old);
			break;

    // 26 - one-sin with party palette // TODO find something good to transition with, or REMOVE
    case 26:
 			if(mc) { this_delay = 6; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 27 - circular noise with party palette // TODO REMOVE, keep circnoise to rings 
    case 27:
 			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_3(old);
			break;

    // 28 - juggle mode with ocean palette TODO REMOVE
    case 28:
 			if(mc) { this_delay = 10; numdots = 4; target_palette = OceanColors_p; this_fade = 32; this_beat = 12; this_bright = 255; this_diff = 20; } // if ring, use numdots_ring
			juggle_pal(old);
			break;

    // 29 - one-sin with palette TODO REMOVE
    case 29:
 			if(mc) { this_delay = 30; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 30 - three-sin with palette // looks cool with ofaurora_gp palette TODO find more palettes
    case 30:
 			if(mc) { this_delay = 20; mul1r = 3; mul2r = 4; mul3r = 5; target_palette = ofaurora_gp; }
			three_sin_pal_ring(old);
			break;

    // 31 - rainbow march with slow, long waves
    case 31:
 			if(mc) { this_delay = 25; this_rot = 1; this_diff = 1;}
			rainbow_march(old);
			break;

    // 32 - circular noise with party palette TODO REMOVE
    case 32:
 			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_1(old);
			break;

    // 33 - noise8 with lava palette TODO find palette or remove
    case 33:
 			if(mc) { this_delay = 10; target_palette = LavaColors_p; palette_change = 0; }
			noise8_pal(old);
			break;

    // 34 - two-sin ring, TODO mix with other twosins or m2
    case 34:
			if(mc) { this_delay = 10; all_freq = 2; this_speed = 1; thatspeed = 1; this_hue = 0; thathue = 128; this_rot = 1; thatrot = 1; this_cutoff = 128; thatcutoff = 192; }
			two_sin_ring(old);
			break;

    // 35 - one-sin with rainbow palette ring TODO REMOVE
    case 35:
			if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 36 - noise8 with party palette ring TODO REMOVE
    case 36:
			if(mc) { this_delay = 10; target_palette = PartyColors_p; palette_change = 2; }
			noise8_pal_ring(old);
			break;

    // 37 - two-sin ring TODO REMOVE
    case 37:
			if(mc) { this_delay = 10; all_freq = 4; this_speed = -1; thatspeed = 0; this_hue = 64; thathue = 192; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 192; }
			two_sin_ring(old);
			break;

    // 38 - one-sin with rainbow palette ring // TODO REMOVE
    case 38:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 39 - two-sin_ring TODO REMOVE
    case 39:
			if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 28; thathue = 180; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
			two_sin_ring(old);
			break;

    // 40 - two-sin ring, transition with other two-sins, 44, 48, 52, especially 52
    case 40:
			if(mc) { this_delay = 10; all_freq = 6; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 64; }
			two_sin_ring(old);
			break;

    // 41 - one-sin with rainbow palette_ring //TODO find palette... f2 is kinda cool
    case 41:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 42 - serendipitous with palette_ring,essentially confetti TODO REMOVE
    case 42:
			if(mc) { this_delay = 10; target_palette = ForestColors_p; }
			serendipitous_pal_ring(old);
			break;

    // 43 - one-sine with lava palette_ring TODO REMOVE
    case 43:
			if(mc) { this_delay = 16; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 44 - two-sin_ring TODO tranisition with 48 and 52, maybe some back and forths
    case 44:
			if(mc) { this_delay = 10; all_freq = 20; this_speed = 2; thatspeed = -1; this_hue = 24; thathue = 180; this_rot = 0; thatrot = 1; this_cutoff = 64; thatcutoff = 128; }
			two_sin_ring(old);
			break;

    // 45 - matrix with party palette_ring TODO REMOVE
    case 45:
			if(mc) { this_delay = 20; target_palette = PartyColors_p; this_index = 64; this_rot = 1; this_bright = 255; bg_clr = 100; bg_bri = 10; }
			matrix_pal_ring(old);
			break;

    // 46 - noise8 with palette_ring TODO maybe find palette, or remove
    case 46:
			if(mc) { this_delay = 10; target_palette = OceanColors_p; palette_change = 1; }
			noise8_pal_ring(old);
			break;

    // 47 - circular noise with party palette_ring TODO if keep, maybe let palettes change, or find the right palette
    case 47:
			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_2_ring(old);
			break;

    // 48 - two-sin_ring TODO Transition with 52
    case 48:
			if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 48; thathue = 160; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
			two_sin_ring(old);
			break;

    // 49 - one-sine with ocean palette_ring TODO REMOVE
    case 49:
			if(mc) { this_delay = 9; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 50 - circular noise with ocean palette_ring TODO REMOVE, too chaotic
    case 50:
			if(mc) { this_delay = 10; target_palette = OceanColors_p; }
			circnoise_pal_4_ring(old);
			break;

    // 51 - confetti with party palette_ring TODO KEEP ONE CONFETTI
    case 51:
			if(mc) { this_delay = 20; target_palette = PartyColors_p; this_inc = 1; this_hue = 192; this_sat = 255; this_fade = 2; this_diff = 32; this_bright = 255; }
			confetti_pal_ring(old);
			break;

    // 52 - two-sin_ring GOOD AS IS, transition with 48
    case 52:
			if(mc) { this_delay = 10; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_rot = 1; thatrot = 2; this_cutoff = 128; thatcutoff = 64; }
			two_sin_ring(old);
			break;

    // 53 - matrix with forest palette_ring TODO Find better GREEN palette
    case 53:
			if(mc) { this_delay = 10; target_palette = ForestColors_p; this_index = 192; this_rot = 1; this_bright = 255; bg_clr = 50; bg_bri = 0; }
			matrix_pal_ring(old);
			break;

    // 54 - one-sin with rainbow palette_ring TODO find palette, check one_sin_tests
    case 54:
			if(mc) { this_delay = 4; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 55 - confetti with lava palette_ring TODO REMOVE
    case 55:
			if(mc) { this_delay = 10; target_palette = LavaColors_p; this_inc = 2; this_hue = 128; this_fade = 8; this_diff = 64; this_bright = 255; }
			confetti_pal_ring(old);
			break;

    // 56 - circular noise with party palette_ring TODO Find Palette
    case 56:
			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_3_ring(old);
			break;

    // 57 - one-sin with palette_ring // reduce from 25 to 20 TODO REMOVE
    case 57:
			if(mc) { this_delay = 20; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 58 - circular noise with party palette_ring TODO REMOVE
    case 58:
			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_1_ring(old);
			break;

    // 59 - confetti with forest palette_ring
    case 59:
			if(mc) { this_delay = 15; target_palette = ForestColors_p; this_inc = 1; this_hue = random8(255); this_fade = 1; this_bright = 255; }
			confetti_pal_ring(old);
			break;

    // 60 - noise8 with lava palette_ring 
    case 60:
			if(mc) { this_delay = 10; target_palette = LavaColors_p; palette_change = 0; }
			noise8_pal_ring(old);
			break;

  	// 61 - fire rings
  	case 61:
    		if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90;}
    		fire_rings(old);
    		break;

	// 62 - fire TODO REMOVE
  	case 62:
  			if(mc) {this_delay = 10; cooling = 100; sparking = 120; }
  			fire(old);
			break;

	// 63 - fire with palette TODO REMOVE
	case 63:
			if(mc) {this_delay = 10; cooling = 80; sparking = 120; target_palette = LavaColors_p; palette_change = 0; }
			fire_pal(old);
			break;

    // 64 - juggle mode with ocean palette_ring
    case 64:
			if(mc) { this_delay = 10; numdots_ring = 4; target_palette = OceanColors_p; this_fade = 32; this_beat = 12; this_bright = 255; this_diff = 20; } // if ring, use numdots_ring
			juggle_pal_ring(old);
			break;

	// 65 - juggle mode one direction
	case 65:
			if(mc) { this_delay = 5; numdots_ring = 5; target_palette = LavaColors_p; this_fade = 16; this_beat = 6; this_bright = 255; this_diff = 50; } // if ring, use numdots_ring
			juggle_pal_ring_onedir(old);
			break;

	// 66 - pride rainbows
	case 66:
			if(mc) { this_delay = 10; }	// maybe update delay?
			pride(old);
			break;

	// 67 - rainbow march with wide waves
    case 67:
 			if(mc) { this_delay = 10; this_rot = 1; this_diff = 1; }
			rainbow_march_ring(old);
			break;

    // 68 - rainbow march with narrow waves
    case 68:
 			if(mc) { this_delay = 10; this_rot = 2; this_diff = 10; }
			rainbow_march_ring(old);
			break;

	// 69 - juggle mode ring TODO find positino and palette
	case 69:
			if (mc) { this_delay = 10; numdots_ring = 4; target_palette = bhw2_23_gp; this_fade = 32; this_beat = 6; this_bright = 255; this_diff = 32; } // if ring, use numdots_ring
			juggle_pal_ring(old);
			break;

	// 70 - fire mirror
	case 70:
			if(mc) { this_delay = 10; cooling = 60; sparking = 90; }
			fire_mirror(old);
			break;

	// 71 - fire mirror with rings
	case 71:
			if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90;}
			fire_mirror_rings(old);
			break;

	// 72 - fire mirror with rings, from middle TODO REMOVE
	case 72:
			if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90; }
			fire_mirror_rings(old);
			break;

	// 73 - fire mirror with palette TODO REMOVE
	case 73:
			if(mc) {this_delay = 10; cooling = 75; sparking = 120; target_palette = HeatColors_p; }
			fire_mirror_pal(old);
			break;

	// 74 - fire palette with rings TODO REMOVE or find a good palette
	case 74:
			if(mc) {this_delay = 10; cooling1 = 60; sparking1 = 80; cooling2 = 95; sparking2 = 90; cooling3 = 80; sparking3 = 50; cooling4 = 90; sparking4 = 85; target_palette = hallows_gp;}
			fire_pal_rings(old);
			break;

	// 75 - fire mirror palette with rings TODO REMOVE or find a good palette
	case 75:
			if(mc) {this_delay = 10; cooling1 = 60; sparking1 = 80; cooling2 = 95; sparking2 = 150; cooling3 = 80; sparking3 = 50; cooling4 = 90; sparking4 = 90; target_palette = slope_gp;}
			fire_mirror_pal_rings(old);
			break;

	// 76 - palette motion with option 1 TODO REMOVE
	case 76:
			if(mc) { this_delay = 15; color_index = 0; color_speed = 0; color_inc = 3; target_palette = ofaurora_gp;}
			palette_motion(old);
			break;

	// 77 - palette motion with option 2 TODO REMOVE
	case 77:
			if(mc) { this_delay = 15; color_index = 0; color_speed = 1; color_inc = 3; target_palette = ofaurora_gp;}
			palette_motion(old);
			break;

	// 78 - palette viewer TODO REMOVE
	case 78:
			if(mc) {this_delay = 5; target_palette = sea_treasure_gp;}
			ring_fill_static_palette(old);
			break;


  // 79 - juggle mode one direction TODO find best palette, this_diff, this_beat
  case 79:
      if(mc) { this_delay = 5; numdots_ring = 5; target_palette = purple_flower_gp; this_fade = 16; this_beat = 6; this_bright = 255; this_diff = 50; } // if ring, use numdots_ring
      juggle_pal_ring_onedir(old);
      break;


  // 80 - juggle mode one direction TODO Remove, keep the above version
  case 80:
      if(mc) { this_delay = 5; numdots_ring = 8; target_palette = alarm_p4_0_2_gp; this_fade = 16; this_beat = 20; this_bright = 255; this_diff = 32; } // if ring, use numdots_ring
      juggle_pal_ring_onedir(old);
      break;

  // 81 - juggle mode one direction TODO Remove, keep just one version
  case 81:
      if(mc) { this_delay = 5; numdots_ring = 6; target_palette = cequal_gp; this_fade = 16; this_beat = 0; this_bright = 255; this_diff = 42; } // if ring, use numdots_ring
      juggle_pal_ring_onedir(old);
      break;

	// 82 - spiral sin 1 TODO find good palette
	case 82:
			if (mc) {this_delay = 5; start_index = 0; this_inc = 1; this_rot = 1; all_freq = 20; this_phase = 0; this_speed = 2; }
			spiral_sin(old);
			break;

	// 83 - spiral sin 2 TODO REMOVE
	case 83:
			if (mc) {this_delay = 10; start_index = 0; this_inc = 4; this_rot = 1; all_freq = 16;  this_phase = 0; this_speed = 2;}
			spiral_sin_sub(old);
			break;

	// 84 - one sin spiral TODO find good palette
	case 84:
			if (mc) { this_delay = 4; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 1; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 3; wave_brightness = 255; }
			one_sin_spiral(old);
			break;

	// 85 - twinkle TODO find best palette
	case 85:
			if (mc) {this_delay = 15; twinkle_speed = 4; twinkle_density = 2; twinkle_bg = CRGB::Black; auto_select_background_color = 0; cool_like_incandescent = 1;  }
			twinkle(old);
			break;

	// 86 - twinkle TODO REMOVE, keep above
	case 86:
			if (mc) {this_delay = 15; twinkle_speed = 3; twinkle_density = 1; twinkle_bg = CRGB::Black; auto_select_background_color = 0; cool_like_incandescent = 1;  }
			twinkle(old);
			break;

	// 87 - plasma TODO REMOVE, too slow, even at delay1... or compare with Noise
	case 87:
			if (mc) {this_delay = 10; target_palette = es_ocean_breeze_036_gp;  }
			plasma(old);
			break;

	// 88 - ripple2
	case 88:
			if (mc) {this_delay = 25; myfade = 255; fadeval = 128;  }
			ripple2(old);
			break;

	// 89 - plasma spiral TODO REMOVE
	case 89:
			if (mc) {this_delay = 10; target_palette = es_ocean_breeze_036_gp;  }
			plasma_spiral(old);
			break;

    // 90 - plasma spiral 2 TODO REMOVE
	case 90:
			if (mc) {this_delay = 10; target_palette = es_ocean_breeze_036_gp;  }
			plasma_spiral2(old);
			break;

	// 91 - helix spiral TODO REMOVE
	case 91:
			if (mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 1; this_phase = 0; that_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 3; that_speed = 3; wave_brightness = 255; }
			helix_spiral(old);
			break;

	// 92 - juggle fire rings
	case 92:
		if (mc) { this_delay = 7; target_palette = es_emerald_dragon_01_gp; numdots_ring = 3; jug_fade = 32; this_beat = 10; this_diff = 80; cooling1 = 80; sparking1 = 40; cooling2 = 80; sparking2 = 30; cooling3 = 80; sparking3 = 35; cooling4 = 75; sparking4 = 45; }
		juggle_fire(old);
		break;

	// 93 - juggle individual rings one dir fire
	case 93:
		if (mc) { this_delay = 7; target_palette = hallows_gp; numdots_ring = 4; ringBeat[0] = 12; ringBeat[1] = 5; ringBeat[2] = 10; ringBeat[3] = 6; this_diff = 32; this_fade = 16;}
		juggle_fire_individual(old);
		break;

	// 94 - juggle individual rings one dir
	case 94:
		if (mc) {this_delay = 7; target_palette = hallows_gp; numdots_ring = 4; ringBeat[0] = 12; ringBeat[1] = 5; ringBeat[2] = 12; ringBeat[3] = 6; this_diff = 32; this_fade = 16;}
		juggle_pal_individual_ring_onedir_all(old);
		break;


  // 95 - juggle individual rings one dir fire same dir
  case 95:
    if (mc) {this_delay = 7; target_palette = hallows_gp; numdots_ring = 4; ringBeat[0] = 12; ringBeat[1] = 5; ringBeat[2] = 12; ringBeat[3] = 6; this_diff = 32; this_fade = 16; cooling1 = 80; sparking1 = 20; cooling2 = 90; sparking2 = 15; cooling3 = 85; sparking3 = 20; cooling4 = 80; sparking4 = 25;}
    juggle_fire_individual_same_dir(old);
    break;
    
    
    // if more modes added, must update max_modes in variables
  }
}

/*
 * Takes in keyboard input and executes commands.
 *
 * Serial timeout value here is important.
 * We should make sure it's set high enough
 * to type the entire command within the timeout.
 */
void readkeyboard() {
  while (Serial.available() > 0) {

    in_byte = Serial.read();

    // Don't print carriage return
    if (in_byte != 10) {
      Serial.print("# ");
      Serial.print(char(in_byte));
      Serial.print(" ");
    }

    switch(in_byte) {

      // Command: a {hue} - set entire strip to {hue} (0-255)
      case 97:
        led_mode = 0;
        this_arg = Serial.parseInt();
        this_arg = constrain(this_arg, 0, 255);
        Serial.println(this_arg);
        fill_solid(leds, NUM_LEDS, CHSV(this_arg, 255, 255));
        break;

      // Command: b {brightness} - set entire strip to {brightness} (0-255)
      case 98:
        max_bright = Serial.parseInt();
        max_bright = constrain(max_bright, 0, 255);
        Serial.println(max_bright);
        LEDS.setBrightness(max_bright);
        break;

      // Command: c - clear strip
      case 99:
        Serial.println(" ");
        led_mode = 0;
        strobe_mode(led_mode, 1,0);
        break;

      // Command: d {delay} - set the delay amount to {delay} (0-255)
      case 100:
        this_arg = Serial.parseInt();
        this_delay = constrain(this_arg, 0, 255);
        Serial.println(this_delay);
        break;

      // Command: e {0/1} - increment or decrement the mode
      case 101:
        this_arg = Serial.parseInt();
        if (this_arg) {
          demo_run = 0;
          led_mode = (led_mode + 1)%(max_mode + 1);
        } else {
          demo_run = 0;
          led_mode = (led_mode - 1);
          if (led_mode == 255) led_mode = max_mode;
        }
        strobe_mode(led_mode, 1,0);
        break;

      // Command: f {palette_number} - set the current palette
      case 102:
        demo_run = 0;
        palette_change = 0;
        this_arg = Serial.parseInt();
        g_current_palette_number = this_arg % g_gradient_palette_count;
        target_palette = g_gradient_palettes[g_current_palette_number];
        Serial.println(g_current_palette_number);
        break;

      // Command: g - toggle glitter
      case 103:
        glitter = !glitter;
        Serial.println(" ");
        break;

      // Command: h {hue} - set hue variable to {hue} (0-255)
      case 104:
        this_arg = Serial.parseInt();
        this_hue = constrain(this_arg, 0, 255);
        Serial.println(this_hue);
        break;

      // Command: i {hue} - set similar palette with selected hue {hue} (0-255)
      case 105:
        palette_change = 0;
        this_arg = Serial.parseInt();
        this_hue = constrain(this_arg, 0, 255);
        Serial.println(this_hue);
        SetupMySimilar4Palette();
        break;

      // Command: m {mode} - select mode {mode} (0-255)
      case 109:
  		  old_mode = led_mode;
        led_mode = Serial.parseInt();
        led_mode = constrain(led_mode, 0, max_mode);
        Serial.println(led_mode);
        update_old_variables();
        transitioning = 1;
        strobe_mode(led_mode, 1,0);
        break;

      // Command: n - toggle direction
      case 110:
        Serial.println(" ");
        this_dir = !this_dir;
        break;

      // Command: p {0/1/2} - set demo mode (fixed/sequential/shuffle)
      case 112:
        demo_run = Serial.parseInt();
        demo_run = constrain(demo_run, 0, 2);
        Serial.println(demo_run);
        break;

      // Command: s {saturation} - set saturation to {saturation} (0-255)
      case 115:
        this_arg = Serial.parseInt();
        this_sat = constrain(this_arg, 0, 255);
        Serial.println(this_sat);
        break;

      // Command: t {0/1/2/3} - set palette mode (fixed/4similar/random4/random16)
      case 116:
        this_arg = Serial.parseInt();
        palette_change = constrain(this_arg, 0, 3);
        Serial.println(palette_change);
        break;

      // Command: w - write current mode to EEPROM
      case 119:
        EEPROM.write(STARTMODE, led_mode);
        Serial.print("Writing keyboard: ");
        Serial.println(led_mode);
        break;
    }
  }
}

void checkDial() {
  debouncer.update();
  if ( debouncer.fell() ){
    pinSWstate = 0;
  } else {
    pinSWstate =1 ;
  }

  if (!pinSWstate){
    rotary_function += 1;
    if (rotary_function > 3){
      rotary_function = 0;
    }

    Serial.print("Button Function: ");
    Serial.println(rotary_function);
  }


  aVal = digitalRead(pinA);   // Read pinA
  if ((aVal != pinALast)){//&&(aVal==LOW)){      // If pinA has changed, update things.   Added the &&
    rotateCount = !rotateCount;   // If at 0, change to 1... if at 1 change to 0 and don't update.
    if (rotateCount){    // Need to let it change twice
      switch (rotary_function) {

        case 0: // add !transitioning to let the new mode get set up
			  //if (!transitioning) {
  				old_mode = led_mode;
  				if (digitalRead(pinB) != aVal) {   // Means pin A changed first, we're rotating CW
  					led_mode++;      // Move to next pattern
  				}
  				else {            // Means pin B changed first, we're moving CCW
  					led_mode--;       // Move to previous pattern
  				}
  				if (led_mode < 0) {
  					led_mode = max_mode;
  				}
  				if (led_mode > max_mode) {
  					led_mode = 0;
  				}
  				update_old_variables();
				transitioning = 1 ;
  				strobe_mode(led_mode, 1,0);
			  //}
          break;

        case 1:
          updatePaletteIndex(target_palette);
          if (digitalRead(pinB) != aVal){
            palette_index++;
          } else {
            palette_index--;
          }
          if (palette_index > g_gradient_palette_count-1){
            palette_index = 0;
          }
          if (palette_index < 0){
            palette_index = g_gradient_palette_count-1;
          }
          target_palette = g_gradient_palettes[palette_index];
          Serial.print("Palette number: ");
          Serial.println(palette_index);
          break;

        case 2:
          if (digitalRead(pinB) != aVal){
			  if (this_delay == 1) {
				  this_delay = 1;
			  }
			  else {
				  this_delay--;
			  }
          } else {
				  this_delay++;
          }
          constrain(this_delay, 1, 255);
          Serial.print("Delay: ");
          Serial.println(this_delay);
          break;

        case 3:
          if (digitalRead(pinB) != aVal){
            this_bright++;
          } else {
            this_bright--;
          }
          constrain(this_bright,0,max_bright);
          LEDS.setBrightness(this_bright);
          Serial.print("Brightness: ");
          Serial.println(this_bright);
          break;

      }
    }
  }
  pinALast = aVal;
}

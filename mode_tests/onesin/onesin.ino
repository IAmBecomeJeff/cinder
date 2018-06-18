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

  // Palette transitions - always running
  EVERY_N_MILLISECONDS(50) {
    uint8_t maxChanges = 24;
    nblendPaletteTowardPalette(current_palette, target_palette, maxChanges);
  }

  EVERY_N_SECONDS(5) {
    if (palette_change == 1) SetupSimilar4Palette();
    if (palette_change == 2) SetupRandom4Palette();
    if (palette_change == 3) SetupRandom16Palette();
  }

  // Dynamically change delay
  EVERY_N_MILLIS_I(this_timer, this_delay) {
    this_timer.setPeriod(this_delay);
    //strobe_mode(led_mode, 0);
	strobe_mode(led_mode, 0, 0);
	if (transitioning) {
		strobe_mode(old_mode, 0, 1);
	}
  }

  if (transitioning) {
	  //glitter = 1;
    if (transition_wait){
  	   blending_ratio += 1;
     }
	  for (int i = 0; i < NUM_LEDS; i++) {
		  leds[i] = blend(old_leds[i], cur_leds[i], blending_ratio);
	  }
	  if (blending_ratio >= 255) {
		  transitioning = 0;
		  blending_ratio = 0;
		  //glitter = 0;
	  }
    transition_wait = !transition_wait;
  }
  else {
	  for (int i = 0; i < NUM_LEDS; i++) {
		  leds[i] = cur_leds[i];
	  }
  }


  // Optionally add glitter
 // if(glitter) addglitter(10);

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

    // 0 - all off
    case  0:
			//if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0 )); }
			if (mc) { fill_solid(cur_leds, NUM_LEDS, CRGB(0, 0, 0)); }
			break;

    // 1 - all on
    case  1:
			//if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 255, 255, 255 )); }
			if (mc) { fill_solid(cur_leds, NUM_LEDS, CRGB(255, 255, 255)); }
			break;

    // 2 - one-sin with rainbow palette
    case  2:
			if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 3 - one-sin with rainbow palette //increased from 20 to 8, smooths out there
    case  3:
			if(mc) { this_delay = 8; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 4 - one-sin with rainbow palette // decreased delay to 5, looks smoothest
    case 4:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 5 - one-sine with lava palette // increase delay from 20 to 18 to remove jerkiness
    case 5:
			if(mc) { this_delay = 8; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 6 - one-sine with ocean palette // increase delay from 20 to 8 to fix jerkiness
    case 6:
 			if(mc) { this_delay = 8; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 7 - one-sin with party palette // increase this_speed from 4 to 6, very jerky
    case 7:
 			if(mc) { this_delay = 6; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 8 - one-sin with palette
    case 8:
 			if(mc) { this_delay = 30; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
			one_sin_pal(old);
			break;

    // 9 - one-sin with rainbow palette ring
    case 9:
			if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 10 - one-sin with rainbow palette ring // increasing delay to 5 to avoid jerkiness
    case 10:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 11 - one-sin with rainbow palette_ring // increasing delay to 10
    case 11:
			if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 12 - one-sine with lava palette_ring // increasing speed to 16
    case 12:
			if(mc) { this_delay = 16; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 13 - one-sine with ocean palette_ring // increasing speed
    case 13:
			if(mc) { this_delay = 9; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 14 - one-sin with rainbow palette_ring
    case 14:
			if(mc) { this_delay = 4; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

    // 15 - one-sin with palette_ring // reduce from 25 to 20
    case 15:
			if(mc) { this_delay = 20; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
			one_sin_pal_ring(old);
			break;

			// 14 - one-sin // Various palettes
	case 16:
		if (mc) { this_delay = 15; target_palette = froth316_gp; all_freq = 2; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 17:
		if (mc) { this_delay =15; target_palette = Skydye11_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 18:
		if (mc) { this_delay = 15; target_palette = Wizzl019_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 19:
		if (mc) { this_delay =15; target_palette = Tropical_Colors_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 20:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 21:
		if (mc) { this_delay = 15; target_palette = hallows_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 22:
		if (mc) { this_delay = 15; target_palette = vibrant_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin **************** all_freq changes
	case 23:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 2; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 24:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 25:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 26:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 27:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 28:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 29:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin ************* this_rot changes
	case 30:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 31:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 32:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 2; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 33:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 4; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 34:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 8; this_speed = 1; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin ****** this_speed changes
	case 35:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 36:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin KEEP
	case 37:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 8; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 38:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 16; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 39:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 4; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin ************* this_rot changes, all_freq alternates, this speed changes
	case 40:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 41:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 2; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin KEEP
	case 42:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 2; this_speed = -6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 43:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 4; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 44:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 8; this_speed = 1; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

	case 45:
		if (mc) { this_delay = 15; target_palette = Orange_to_Purple_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 46:
		if (mc) { this_delay = 15; target_palette = Orange_to_Purple_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 47:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 8; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 48:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 2; this_cutoff = 100; this_rot = 1; this_speed = 16; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 49:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 4; this_phase = 4; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal_ring(old);
		break;

		// 14 - one-sin 
	case 50:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 51:
		if (mc) { this_delay = 15; target_palette = hallows_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin  KEEP
	case 52:
		if (mc) { this_delay = 5; target_palette = vibrant_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin **************** all_freq changes
	case 53:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 2; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 54:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 55:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 56:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 57:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 58:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 59:
		if (mc) { this_delay = 15; target_palette = cequal_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin ************* this_rot changes
	case 60:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 61:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 62:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 2; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 63:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 4; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 64:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 8; this_speed = 1; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin ****** this_speed changes
	case 65:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 66:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 67:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 8; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 68:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 16; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 69:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 4; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin ************* this_rot changes, all_freq alternates, this speed changes
	case 70:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 71:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 2; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 72:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 2; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 73:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 4; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 74:
		if (mc) { this_delay = 15; target_palette = slope_gp; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 8; this_speed = 1; wave_brightness = 255; }
		one_sin_pal(old);
		break;

	case 75:
		if (mc) { this_delay = 15; target_palette = Orange_to_Purple_gp; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 2; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 76:
		if (mc) { this_delay = 15; target_palette = Orange_to_Purple_gp; all_freq = 8; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 77:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 10; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 8; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 78:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 12; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_phase = 2; this_cutoff = 100; this_rot = 1; this_speed = 16; wave_brightness = 255; }
		one_sin_pal(old);
		break;

		// 14 - one-sin 
	case 79:
		if (mc) { this_delay = 15; target_palette = bhw1_28_gp; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 4; this_phase = 4; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
		one_sin_pal(old);
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
			  if (!transitioning) {
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
			  }
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

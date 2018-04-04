#include "includes.h"
// Modified from Caleb's modified version of seirlight

void setup() {
  // Set up serial connection
  Serial.begin(SERIAL_BAUDRATE); 
  Serial.setTimeout(SERIAL_TIMEOUT);
  
  delay(1000);  

  // Set up LEDS
	LEDS.setBrightness(max_bright);

  // -- Single strip of 576 LEDS set for development testing ------------------------------- //
  
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
  
  // Init rings
  for (uint8_t i=0;i<144;i++){
	ringArray[i][0]=i;
	ringArray[i][1]=287-i;
	ringArray[i][2]=288+i;
	ringArray[i][3]=575-i;
  }
	
  // Init first mode
  strobe_mode(led_mode, 1);
}

void loop() {
  // Get keyboard input
  readkeyboard();
 
  // Check rotary dial
  checkDial();
  
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
    strobe_mode(led_mode, 0);
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
void strobe_mode(uint8_t newMode, bool mc){

  // If this_ is a *new* mode, clear out LED array.
  if(mc) {
    fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
    Serial.print("Mode: "); 
    Serial.println(led_mode);
  }

  switch (newMode) {

    // 0 - all off
    case  0: 
      if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0 )); } 
      break;

    // 1 - all on
    case  1: 
      if(mc) { fill_solid(leds, NUM_LEDS, CRGB( 255, 255, 255 )); } 
      break;

    // 2 - two-sin
    case  2: 
      if(mc) { this_delay = 10; all_freq = 2; this_speed = 1; thatspeed = 1; this_hue = 0; thathue = 128; this_dir = 0; this_rot = 1; thatrot = 1; this_cutoff = 128; thatcutoff = 192; } 
      two_sin(); 
      break;

    // 3 - one-sin with rainbow palette
    case  3: 
      if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal(); 
      break;

    // 4 - noise8 with party palette
    case  4: 
      if(mc) { this_delay = 10; target_palette = PartyColors_p; palette_change = 2; } 
      noise8_pal(); 
      break;

    // 5 - two-sin
    case  5: 
      if(mc) { this_delay = 10; all_freq = 4; this_speed = -1; thatspeed = 0; this_hue = 64; thathue = 192; this_dir = 0; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 192; } 
      two_sin(); 
      break;

    // 6 - one-sin with rainbow palette //increased from 20 to 8, smooths out there
    case  6: 
      if(mc) { this_delay = 8; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal(); 
      break;

    // 7 - juggle mode
    case  7: 
      if(mc) { this_delay = 10; numdots = 2; target_palette = PartyColors_p; this_fade = 16; this_beat = 8; this_bright = 255; this_diff = 64; } // if ring, use numdots_ring
      juggle_pal(); 
      break;

    // 8 - matrix with palette // increased delay from 40 to 15
    case  8: 
      if(mc) { this_delay = 15; target_palette = LavaColors_p; this_index = 128; this_dir = 1; this_rot = 0; this_bright = 255; bg_clr = 200; bg_bri = 6; } 
      matrix_pal(); 
      break;

    // 9 - two-sin // green + pink
    case  9: 
      if(mc) { this_delay = 10; all_freq = 6; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_dir = 1; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 64; } 
      two_sin(); 
      break;

    // 10 - one-sin with rainbow palette // decreased delay to 5, looks smoothest
    case 10: 
      if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal(); 
      break;

    // 11 - three-sin with palette // good three sine // delay 20 works well
    case 11: 
      if(mc) { this_delay = 20; mul1 = 5; mul2 = 8; mul3 = 7; }
			three_sin_pal(); 
			break;
   
    // 12 - serendipitous with palette
    case 12:
      if(mc) { this_delay = 10; target_palette = ForestColors_p; }
			serendipitous_pal(); 
			break;
  
    // 13 - one-sine with lava palette // increase delay from 20 to 18 to remove jerkiness
    case 13:
      if(mc) { this_delay = 8; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(); 
			break;
 
    // 14 - two-sin
    case 14:
      if(mc) { this_delay = 10; all_freq = 20; this_speed = 2; thatspeed = -1; this_hue = 24; thathue = 180; this_dir = 1; this_rot = 0; thatrot = 1; this_cutoff = 64; thatcutoff = 128; }
			two_sin(); 
			break;

    // 15 - matrix with party palette // increase delay from 50 to 20 to speed it up
    case 15:
      if(mc) { this_delay = 20; target_palette = PartyColors_p; this_index = 64; this_dir = 0; this_rot = 1; this_bright = 255; bg_clr = 100; bg_bri = 10; }
			matrix_pal(); 
			break;

    // 16 - noise8 with palette
    case 16:
      if(mc) { this_delay = 10; target_palette = OceanColors_p; palette_change = 1; }
			noise8_pal(); 
			break;

    // 17 - circular noise with party palette
    case 17:
 			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_2(); 
			break;

    // 18 - two-sin
    case 18:
 			if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 48; thathue = 160; this_dir = 0; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
			two_sin(); 
			break;

    // 19 - three-sin with palette
    case 19:
 			if(mc) { this_delay = 50; mul1 = 6; mul2 = 9; mul3 = 11; }
			three_sin_pal(); 
			break;

    // 20 - rainbow march with wide waves
    case 20:
 			if(mc) { this_delay = 10; this_dir = 1; this_rot = 1; this_diff = 1; }
			rainbow_march(); 
			break;

    // 21 - rainbow march with narrow waves
    case 21:
 			if(mc) { this_delay = 10; this_dir = 1; this_rot = 2; this_diff = 10; }
			rainbow_march(); 
			break;

    // 22 - one-sine with ocean palette // increase delay from 20 to 8 to fix jerkiness
    case 22:
 			if(mc) { this_delay = 8; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
			one_sin_pal(); 
			break;

    // 23 - circular noise with ocean palette
    case 23:
 			if(mc) { this_delay = 10; target_palette = OceanColors_p; }
			circnoise_pal_4(); 
			break;

    // 24 - two-sin
    case 24:
 			if(mc) { this_delay = 10; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_dir = 1; this_rot = 1; thatrot = 2; this_cutoff = 128; thatcutoff = 64; }
			two_sin(); 
			break;

    // 25 - matrix with forest palette // increase delay from 30 to 25
    case 25:
 			if(mc) { this_delay = 25; target_palette = ForestColors_p; this_index = 192; this_dir = 0; this_rot = 0; this_bright = 255; bg_clr = 50; bg_bri = 0; }
			matrix_pal(); 
			break;

    // 26 - one-sin with party palette // increase this_speed from 4 to 6, very jerky
    case 26:
 			if(mc) { this_delay = 6; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
			one_sin_pal(); 
			break;

    // 27 - circular noise with party palette // maybe new palette?
    case 27:
 			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_3(); 
			break;

    // 28 - juggle mode with ocean palette
    case 28:
 			if(mc) { this_delay = 10; numdots = 4; target_palette = OceanColors_p; this_fade = 32; this_beat = 12; this_bright = 255; this_diff = 20; } // if ring, use numdots_ring
			juggle_pal(); 
			break;

    // 29 - one-sin with palette
    case 29:
 			if(mc) { this_delay = 30; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
			one_sin_pal(); 
			break;

    // 30 - three-sin with palette // looks cool with ofaurora_gp palette
    case 30:
 			if(mc) { this_delay = 50; mul1 = 3; mul2 = 4; mul3 = 5; target_palette = ofaurora_gp; }
			three_sin_pal(); 
			break;

    // 31 - rainbow march with slow, long waves
    case 31:
 			if(mc) { this_delay = 255; this_dir = -1; this_rot = 1; this_diff = 1;}
			rainbow_march(); 
			break;

    // 32 - circular noise with party palette
    case 32:
 			if(mc) { this_delay = 10; target_palette = PartyColors_p; }
			circnoise_pal_1(); 
			break;

    // 33 - noise8 with lava palette
    case 33:
 			if(mc) { this_delay = 10; target_palette = LavaColors_p; palette_change = 0; }
			noise8_pal(); 
			break;
      
    // 34 - two-sin ring
    case 34: 
      if(mc) { this_delay = 10; all_freq = 2; this_speed = 1; thatspeed = 1; this_hue = 0; thathue = 128; this_dir = 0; this_rot = 1; thatrot = 1; this_cutoff = 128; thatcutoff = 192; } 
      two_sin_ring(); 
      break;

    // 35 - one-sin with rainbow palette ring
    case 35: 
      if(mc) { this_delay = 20; target_palette = RainbowColors_p; all_freq = 4; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal_ring(); 
      break;

    // 36 - noise8 with party palette ring
    case 36: 
      if(mc) { this_delay = 10; target_palette = PartyColors_p; palette_change = 2; } 
      noise8_pal_ring(); 
      break;

    // 37 - two-sin ring
    case 37: 
      if(mc) { this_delay = 10; all_freq = 4; this_speed = -1; thatspeed = 0; this_hue = 64; thathue = 192; this_dir = 0; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 192; } 
      two_sin_ring(); 
      break;

    // 38 - one-sin with rainbow palette ring // increasing delay to 5 to avoid jerkiness
    case 38: 
      if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 10; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal_ring(); 
      break;

    // 39 - two-sin_ring
    case 39:
      if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 28; thathue = 180; this_dir = 0; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
      two_sin_ring(); 
      break;
      
    // 40 - two-sin ring
    case 40: 
      if(mc) { this_delay = 10; all_freq = 6; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_dir = 1; this_rot = 0; thatrot = 0; this_cutoff = 64; thatcutoff = 64; } 
      two_sin_ring(); 
      break;

    // 41 - one-sin with rainbow palette_ring // increasing delay to 10
    case 41: 
      if(mc) { this_delay = 5; target_palette = RainbowColors_p; all_freq = 16; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; } 
      one_sin_pal_ring(); 
      break;
   
    // 42 - serendipitous with palette_ring, really cool, try more palettes
    case 42:
      if(mc) { this_delay = 10; target_palette = ForestColors_p; }
      serendipitous_pal_ring(); 
      break;
  
    // 43 - one-sine with lava palette_ring // increasing speed to 16
    case 43:
      if(mc) { this_delay = 16; target_palette = LavaColors_p; all_freq = 8; bg_clr = 0; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
      one_sin_pal_ring(); 
      break;
 
    // 44 - two-sin_ring
    case 44:
      if(mc) { this_delay = 10; all_freq = 20; this_speed = 2; thatspeed = -1; this_hue = 24; thathue = 180; this_dir = 1; this_rot = 0; thatrot = 1; this_cutoff = 64; thatcutoff = 128; }
      two_sin_ring(); 
      break;

    // 45 - matrix with party palette_ring // has a light green background, not sure if it works with direction change
    case 45:
      if(mc) { this_delay = 20; target_palette = PartyColors_p; this_index = 64; this_dir = 0; this_rot = 1; this_bright = 255; bg_clr = 100; bg_bri = 10; }
      matrix_pal_ring(); 
      break;

    // 46 - noise8 with palette_ring
    case 46:
      if(mc) { this_delay = 10; target_palette = OceanColors_p; palette_change = 1; }
      noise8_pal_ring(); 
      break;

    // 47 - circular noise with party palette_ring
    case 47:
      if(mc) { this_delay = 10; target_palette = PartyColors_p; }
      circnoise_pal_2_ring(); 
      break;

    // 48 - two-sin_ring
    case 48:
      if(mc) { this_delay = 20; all_freq = 10; this_speed = 1; thatspeed = -2; this_hue = 48; thathue = 160; this_dir = 0; this_rot = 1; thatrot = -1; this_cutoff = 128; thatcutoff = 192; }
      two_sin_ring(); 
      break;

    // 49 - one-sine with ocean palette_ring // increasing speed
    case 49:
      if(mc) { this_delay = 9; target_palette = OceanColors_p; all_freq = 6; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 4; wave_brightness = 255; }
      one_sin_pal_ring(); 
      break;

    // 50 - circular noise with ocean palette_ring
    case 50:
      if(mc) { this_delay = 10; target_palette = OceanColors_p; }
      circnoise_pal_4_ring(); 
      break;

    // 51 - confetti with party palette_ring
    case 51:
      if(mc) { this_delay = 20; target_palette = PartyColors_p; this_inc = 1; this_hue = 192; this_sat = 255; this_fade = 2; this_diff = 32; this_bright = 255; }
      confetti_pal_ring(); 
      break;

    // 52 - two-sin_ring
    case 52:
      if(mc) { this_delay = 10; this_speed = 2; thatspeed = 3; this_hue = 96; thathue = 224; this_dir = 1; this_rot = 1; thatrot = 2; this_cutoff = 128; thatcutoff = 64; }
      two_sin_ring(); 
      break;

    // 53 - matrix with forest palette_ring
    case 53:
      if(mc) { this_delay = 10; target_palette = ForestColors_p; this_index = 192; this_dir = 0; this_rot = 0; this_bright = 255; bg_clr = 50; bg_bri = 0; }
      matrix_pal_ring(); 
      break;

    // 54 - one-sin with rainbow palette_ring
    case 54:
      if(mc) { this_delay = 4; target_palette = RainbowColors_p; all_freq = 20; bg_clr = 0; bg_bri = 0; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 224; this_rot = 0; this_speed = 6; wave_brightness = 255; }
      one_sin_pal_ring(); 
      break;

    // 55 - confetti with lava palette_ring
    case 55:
      if(mc) { this_delay = 20; target_palette = LavaColors_p; this_inc = 2; this_hue = 128; this_fade = 8; this_diff = 64; this_bright = 255; }
      confetti_pal_ring(); 
      break;

    // 56 - circular noise with party palette_ring
    case 56:
      if(mc) { this_delay = 10; target_palette = PartyColors_p; }
      circnoise_pal_3_ring(); 
      break;

    // 57 - one-sin with palette_ring // reduce from 25 to 20
    case 57:
      if(mc) { this_delay = 20; SetupSimilar4Palette(); all_freq = 4; bg_clr = 64; bg_bri = 4; this_bright = 255; start_index = 64; this_inc = 2; this_cutoff = 224; this_phase = 0; this_cutoff = 128; this_rot = 1; this_speed = 8; wave_brightness = 255; }
      one_sin_pal_ring(); 
      break;

    // 58 - circular noise with party palette_ring
    case 58:
      if(mc) { this_delay = 10; target_palette = PartyColors_p; }
      circnoise_pal_1_ring(); 
      break;

    // 59 - confetti with forest palette_ring
    case 59:
      if(mc) { this_delay = 15; target_palette = ForestColors_p; this_inc = 1; this_hue = random8(255); this_fade = 1; this_bright = 255; }
      confetti_pal_ring(); 
      break;

    // 60 - noise8 with lava palette_ring
    case 60:
      if(mc) { this_delay = 10; target_palette = LavaColors_p; palette_change = 0; }
      noise8_pal_ring(); 
      break;
	
  	// 61 - fire rings
  	case 61:
    	if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90;}
    	fire_rings();
    	break;
	
	// 62 - fire
  	case 62:
  		if(mc) {this_delay = 10; cooling = 100; sparking = 120; }
  		fire();
		break;
	
	// 63 - fire with palette
	case 63:
		if(mc) {this_delay = 10; cooling = 80; sparking = 120; target_palette = LavaColors_p; palette_change = 0; }
		fire_pal();
		break;
		
    // 64 - juggle mode with ocean palette_ring 
    case 64:
      if(mc) { this_delay = 10; numdots_ring = 4; target_palette = OceanColors_p; this_fade = 32; this_beat = 12; this_bright = 255; this_diff = 20; } // if ring, use numdots_ring
      juggle_pal_ring(); 
      break;
    
	// 65 - juggle mode ring
	case 65: 
      if(mc) { this_delay = 10; numdots_ring = 2; target_palette = PartyColors_p; this_fade = 16; this_beat = 8; this_bright = 255; this_diff = 64; } // if ring, use numdots_ring
      juggle_pal_ring(); 
      break;	  
	  
	// 66 - pride rainbows
	case 66:
		if(mc) { this_delay = 10; }	// maybe update delay?
		pride();
		break;
		
	// 67 - rainbow march with wide waves
    case 67:
 		if(mc) { this_delay = 10; this_dir = 1; this_rot = 1; this_diff = 1; }
		rainbow_march_ring(); 
		break;

    // 68 - rainbow march with narrow waves
    case 68:
 		if(mc) { this_delay = 10; this_dir = 1; this_rot = 2; this_diff = 10; }
		rainbow_march_ring(); 
		break;
	
	// 69 - disco strobe
	case 69:
		if(mc) { this_delay = 1; }
		discostrobe();
		delayToSyncFrameRate(this_delay);
		break;

	// 70 - fire mirror
	case 70:
		if(mc) { this_delay = 10; cooling = 60; sparking = 90; }
		fire_mirror();
		break;

	// 71 - fire mirror with rings
	case 71:
		if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90; this_dir = 1;}
		fire_mirror_rings();
		break;
	
	// 72 - fire mirror with rings, from middle
	case 72:
		if(mc) {this_delay = 10; cooling1 = 80; sparking1 = 90; cooling2 = 55; sparking2 = 70; cooling3 = 70; sparking3 = 70; cooling4 = 55; sparking4 = 90; this_dir = 0 ; }
		fire_mirror_rings();
		break;
	
	// 73 - fire mirror with palette
	case 73:
		if(mc) {this_delay = 10; cooling = 75; sparking = 120; target_palette = HeatColors_p; this_dir = 0;}
		fire_mirror_pal();
    break;
		
	// 74 - fire palette with rings
	case 74:
		if(mc) {this_delay = 10; cooling1 = 60; sparking1 = 80; cooling2 = 95; sparking2 = 150; cooling3 = 80; sparking3 = 50; cooling4 = 90; sparking4 = 90; target_palette = hallows_gp;}
		fire_pal_rings();
    break;
	
	// 75 - fire mirror palette with rings
	case 75:
		if(mc) {this_delay = 10; cooling1 = 60; sparking1 = 80; cooling2 = 95; sparking2 = 150; cooling3 = 80; sparking3 = 50; cooling4 = 90; sparking4 = 90; target_palette = slope_gp;}
		fire_mirror_pal_rings();
    break;
   
	// 76 - palette motion with option 1
	case 76:
		if(mc) { this_delay = 15; color_index = 0; color_speed = 0; color_inc = 3; target_palette = ofaurora_gp;}
		palette_motion();
		break;
	
	// 77 - palette motion with option 2
	case 77:
		if(mc) { this_delay = 15; color_index = 0; color_speed = 1; color_inc = 3; target_palette = ofaurora_gp;}
		palette_motion();
		break;
		
	// 78 - palette viewer
	case 78:
		if(mc) {target_palette = sea_treasure_gp;}
		ring_fill_static_palette();
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
        strobe_mode(led_mode, 1);
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
        strobe_mode(led_mode, 1);
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
        strobe_mode(led_mode, 1);
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
  int reading = digitalRead(pinSW);   // check button
  if (reading != lastPinSWstate){     // is it different from before?
    lastDebounceTime = millis();    // set time
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {  // is current time 50ms since the button was pressed?
    if (reading != pinSWstate){     // if the button state has changed
      pinSWstate = reading;
      if (!pinSWstate){
        rotary_function +=1;
        if (rotary_function > 2){
          rotary_function = 0;
        }
      }
    }
  }
  lastPinSWstate = reading;
  
  if (!(digitalRead(pinSW))){
    rotary_function += 1;
    if (rotary_function > 3){
      rotary_function = 0;
    }
    
    Serial.print("Button Function: ");
    Serial.println(rotary_function);
  }
  aVal = digitalRead(pinA);   // Read pinA
  if (aVal != pinALast){      // If pinA has changed, update things
    rotateCount = !rotateCount;   // If at 0, change to 1... if at 1 change to 0 and don't update.
    if (rotateCount){    // Need to let it change twice
      switch (rotary_function) {
        
        case 0:
          if (digitalRead(pinB) != aVal){   // Means pin A changed first, we're rotating CW
            led_mode ++;      // Move to next pattern
          } else {            // Means pin B changed first, we're moving CCW
            led_mode--;       // Move to previous pattern
          }
            if (led_mode < 0){
            led_mode = max_mode;
            }
            if (led_mode > max_mode){
            led_mode = 0;
            }
            strobe_mode(led_mode, 1);
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
            this_delay ++;
          } else {
            this_delay --;
          }
          constrain(this_delay, 0, 255);
          Serial.print("Delay: ");
          Serial.println(this_delay);
          break;
          
        case 3:
          if (digitalRead(pinB) != aVal){
            this_bright ++;
          } else {
            this_bright --;
          }
          constrain(this_bright,0,max_bright);
          LEDS.setBrightness(this_bright);
          Serial.print("Brightness: ");
          Serial.println(this_bright);
          break;
          
      }
    }
    pinALast = aVal;    
  }
}	

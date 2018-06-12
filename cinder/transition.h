
// LED Routine/Shared Variables
uint8_t old_all_freq = 32;     // Frequency (width of bars) (sine-routines)
uint8_t old_bg_clr = 0;      // Background color
uint8_t old_bg_bri = 0;      // Background brightness
uint8_t old_start_index = 0;      // Foreground hue to start with (sine-routines)
uint8_t old_this_beat;                // Beat tracker (juggle routine)
uint8_t old_this_bright = 50;      // Standard brightness
uint8_t old_that_bright = 50;     // second brightness
uint8_t old_this_cutoff = 192;    // Cutoff value; lower = longer wave
int     old_this_delay = 0;      // Standard delay
uint8_t old_this_diff = 1;      // Standard palette index jump
uint8_t old_this_dir = 0;      // Standard direction
uint8_t old_this_fade = 224;    // Standard fade rate
uint8_t old_this_hue = 0;      // Standard hue
uint8_t old_this_index = 0;      // Standard palette index
uint8_t old_this_inc = 1;      // Standard increment. Changes starting color for each pass (sine-routines)
int     old_this_phase = 0;      // Standard phase change - sines
int     old_that_phase = 0;      // second phase
uint8_t old_this_rot = 1;      // Standard hue rotation rate
uint8_t old_this_sat = 255;    // Standard saturation
uint8_t old_this_speed = 4;      // Standard speed change
uint8_t old_that_speed = 4;      // Second speed
uint8_t old_wave_brightness = 255;    // Brightness of the waves/bars


void update_old_variables() {
	old_all_freq = all_freq;
	old_bg_clr = bg_clr;
	old_bg_bri = bg_bri;
	old_start_index = start_index;
	old_this_beat = this_beat;
	old_this_bright = this_bright;
	old_that_bright = that_bright;
	old_this_cutoff = this_cutoff;
	old_this_delay = this_delay;
	old_this_diff = this_diff;
	old_this_dir = this_dir;
	old_this_fade = this_fade;
	old_this_hue = this_hue;
	old_this_index = this_index;
	old_this_inc = this_inc;
	old_this_phase = this_phase;
	old_that_phase = that_phase;
	old_this_rot = this_rot;
	old_this_sat = this_sat;
	old_this_speed = this_speed;
	old_that_speed = that_speed;
	old_wave_brightness = wave_brightness;
}
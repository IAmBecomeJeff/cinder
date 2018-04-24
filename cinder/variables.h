// ---------- COMPILE VARS ---------- //

// Disables Version "errors" on compile
#define FASTLED_INTERNAL

// Libraries
#include "FastLED.h"
#include "EEPROM.h"
#include "Bounce2.h"

// Unsigned subtraction magic
#define qsubd(x, b) ((x>b)?wave_brightness:0)		// A digital unsigned subtraction macro. if result <0, then => 0. Otherwise, take on fixed value.
#define qsuba(x, b) ((x>b)?x-b:0)					// Unsigned subtraction macro. if result <0, then => 0.

// Serial vars
#define SERIAL_BAUDRATE 57600 //57600						// TODO check on this?  seirlight options 115200
#define SERIAL_TIMEOUT 500							// TODO seirlight has it set at 5

// Arduino pin setup

// Data and clock pins defined for development testing
#define DATA_PIN 7
#define CLOCK_PIN 14

// LED Meta Defines
#define COLOR_ORDER BGR

// WS2812B used for development testing
#define LED_TYPE APA102

// 576 Length LED strip and mode start number
#define NUM_LEDS 576
#define STRIP_LENGTH 144
#define STARTMODE 0

// ---------- RUNTIME VARS ---------- //

// Serial Variables
byte in_byte;			// Serial input byte
int this_arg;			// Serial input argument

// LED Meta Variables, particularly palettes
struct CRGB leds[NUM_LEDS];
CRGBPalette16 current_palette;         // Current palette we're using
CRGBPalette16 target_palette;          // Next palette to transition to
TBlendType current_blending;           // Linear vs No-Blending
extern const TProgmemRGBGradientPalettePtr g_gradient_palettes[];   // from gradient_palettes.h
extern const uint8_t g_gradient_palette_count;                      // # of fixed palettes
uint8_t g_current_palette_number  = 0;                              // Current palette number
uint8_t current_pattern_index     = 0;                              // Index of current pattern
uint8_t default_mode              = 34;                             // Default mode to go to

// LED Overall Variables
uint8_t max_bright  = 128;		// Overall brightness, it can be changed on the fly.  TODO: Maybe lower this to 100?
uint8_t max_mode    = 90;		// maximum number of modes
uint8_t demo_run    = 0;		// 0 = regular mode, 1 = demo mode, 2 = shuffle mode
int led_mode;				// Starting mode is typically 0
uint8_t old_mode;

// LED Routine/Shared Variables
uint8_t all_freq        = 32;     // Frequency (width of bars) (sine-routines)
uint8_t bg_clr          = 0;      // Background color
uint8_t bg_bri          = 0;      // Background brightness
bool    glitter         = 0;      // Glitter flag
uint8_t palette_change;           // 1 = similar palette, 2 = random4 palette, 3 = random16 palette
uint8_t start_index     = 0;      // Foreground hue to start with (sine-routines)
uint8_t this_beat;                // Beat tracker (juggle routine)
uint8_t this_bright     = 50;      // Standard brightness
uint8_t this_cutoff     = 192;    // Cutoff value; lower = longer wave
int     this_delay      = 0;      // Standard delay
uint8_t this_diff       = 1;      // Standard palette index jump
uint8_t this_dir        = 0;      // Standard direction
uint8_t this_fade       = 224;    // Standard fade rate
uint8_t this_hue        = 0;      // Standard hue
uint8_t this_index      = 0;      // Standard palette index
uint8_t this_inc        = 1;      // Standard increment. Changes starting color for each pass (sine-routines)
int     this_phase      = 0;      // Standard phase change - sines
uint8_t this_rot        = 1;      // Standard hue rotation rate
uint8_t this_sat        = 255;    // Standard saturation
uint8_t this_speed      = 4;      // Standard speed change
uint8_t wave_brightness = 255;    // Brightness of the waves/bars
uint8_t xd[NUM_LEDS];             // X-array for 2d coordinates of leds
uint8_t yd[NUM_LEDS];             // Y-array for 2d coordinates of leds
int ringArray[144][4];      	  // Array for rings

int x_prev;						  // Variables for gravity
uint8_t x0;						  // Variables for gravity
int x_grav;	  					  // Variables for gravity
int accel;						  // Variables for gravity
uint8_t v0;					 	  // Variables for gravity
uint8_t pause;					  // Variables for gravity
uint8_t grav_count;				  // Variables for gravity
uint8_t timer;					  // Variables for gravity
bool atBottom = 0;			  // Variables for gravity
int gravity = -15;
int timeinc = 2;
int numballs = 6;

typedef struct {
	int distanceold;
	int distance;
	int velocityold;
	int velocity;
	int ballhue;
} balls;

balls myballs[numballs];

//Variables for plasma
int plasma_phase1;
int plasma_phase2;
int plasmaIndex;
int plasmaBright;


//Variables for meteor
byte meteor_r;
byte meteor_g;
byte meteor_b;
byte meteorSize;
byte meteorTrailDecay;
bool meteorRandomDecay;
int meteor_index;

//Variables for ripple 
int rip_color;
int rip_center = 0;
int rip_step = -1;
int rip_maxSteps = 16;
float rip_fadeRate = 0.8;
//Ripple background color
uint32_t rip_currentBg = random(256);
uint32_t rip_nextBg = currentBg;


//Twinkle Variables
byte twinkle_speed = 4; // 0 - 8
byte twinkle_density = 5;	// 0 - 8
CRGB twinkle_bg = CRGB::Black; // CRGB(CRGB::FairyLight).nscale8_video(16);
byte auto_select_background_color = 0;
byte cool_like_incandescent = 1;
uint8_t bglight;
uint8_t backgroundBrightness;
CRGB bg;

uint8_t numdots_ring;   			// dots for juggle_pal_ring
uint8_t cooling = 55;				// Cooling variable for fire
uint8_t cooling1;
uint8_t cooling2;
uint8_t cooling3;
uint8_t cooling4;
uint8_t sparking = 120;				// Heating variable for fire
uint8_t sparking1;
uint8_t sparking2;
uint8_t sparking3;
uint8_t sparking4;
uint8_t zooming_beats_per_minute = 122; // zooming for disco
uint8_t color_index = 0;
uint8_t color_speed = 1;
uint8_t color_inc = 3;
int col_count = 0; // column for revolutions
int rev_count = 0;
int rev_limit = 50;

// KY-040 Rotary Module variables
int pinA = 21;
int pinB = 22;
int pinSW = 23;
int lastPinSWstate = 1;
int pinSWstate;
int pinALast;
int aVal;
int rotateCount = 0;
int rotary_function = 0;
int palette_index;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


// Heartbeat variables
uint8_t bloodHue = 96;  // Blood color [hue from 0-255]
uint8_t bloodSat = 255;  // Blood staturation [0-255]
int flowDirection = -1;   // Use either 1 or -1 to set flow direction
uint16_t cycleLength = 1500;  // Lover values = continuous flow, higher values = distinct pulses.
uint16_t pulseLength = 150;  // How long the pulse takes to fade out.  Higher value is longer.
uint16_t pulseOffset = 200;  // Delay before second pulse.  Higher value is more delay.
uint8_t baseBrightness = 10;  // Brightness of LEDs when not pulsing. Set to 0 for off.

Bounce debouncer = Bounce();

int spiral_start;
int spiral_inc;
int spiral_width;

// ---------- COMPILE VARS ---------- //

// Disables Version "errors" on compile
#define FASTLED_INTERNAL

// Libraries
#include "FastLED.h"
#include "EEPROM.h"

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
uint8_t max_mode    = 71;		// maximum number of modes
uint8_t demo_run    = 0;		// 0 = regular mode, 1 = demo mode, 2 = shuffle mode
uint8_t led_mode;				// Starting mode is typically 0
uint8_t old_mode;

// LED Routine/Shared Variables
uint8_t all_freq        = 32;     // Frequency (width of bars) (sine-routines)
uint8_t bg_clr          = 0;      // Background color
uint8_t bg_bri          = 0;      // Background brightness
bool    glitter         = 0;      // Glitter flag
uint8_t palette_change;           // 1 = similar palette, 2 = random4 palette, 3 = random16 palette
uint8_t start_index     = 0;      // Foreground hue to start with (sine-routines)
uint8_t this_beat;                // Beat tracker (juggle routine)
uint8_t this_bright     = 0;      // Standard brightness
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
uint8_t x_prev;					  // Variables for gravity
uint8_t x0;						  // Variables for gravity
int accel;					  // Variables for gravity
uint8_t v0;					 	  // Variables for gravity
uint8_t pause;						// Variable for gravity
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


// KY-040 Rotary Module variables
int pinA = 21;
int pinB = 22;
int pinSW = 23;
int pinALast;
int aVal;
int rotateCount = 0;

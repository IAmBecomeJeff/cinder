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

// Switch pins
#define switchA 3
#define switchB 4

// Acellerometer pins
//#define SDA 18
//#define SCL 19

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
struct CRGB old_leds[NUM_LEDS];
struct CRGB cur_leds[NUM_LEDS];
CRGBPalette16 current_palette;         // Current palette we're using
CRGBPalette16 target_palette;          // Next palette to transition to
CRGBPalette16 old_palette;
TBlendType current_blending;           // Linear vs No-Blending
extern const TProgmemRGBGradientPalettePtr g_gradient_palettes[];   // from gradient_palettes.h
extern const uint8_t g_gradient_palette_count;                      // # of fixed palettes
uint8_t g_current_palette_number  = 0;                              // Current palette number
uint8_t current_pattern_index     = 0;                              // Index of current pattern
uint8_t default_mode              = 34;                             // Default mode to go to

// LED Overall Variables
uint8_t max_bright  = 128;		// Overall brightness, it can be changed on the fly.  TODO: Maybe lower this to 100?
uint8_t max_mode    = 91;		// maximum number of modes
uint8_t demo_run    = 0;		// 0 = regular mode, 1 = demo mode, 2 = shuffle mode
int led_mode;				// Starting mode is typically 0
uint8_t old_mode;
bool transitioning = 0;	// transitioning flag
int blending_ratio = 0;

// LED Routine/Shared Variables
uint8_t all_freq        = 32;     // Frequency (width of bars) (sine-routines)
uint8_t bg_clr          = 0;      // Background color
uint8_t bg_bri          = 0;      // Background brightness
bool    glitter         = 0;      // Glitter flag
uint8_t palette_change;           // 1 = similar palette, 2 = random4 palette, 3 = random16 palette
uint8_t start_index     = 0;      // Foreground hue to start with (sine-routines)
uint8_t this_beat;                // Beat tracker (juggle routine)
uint8_t this_bright     = 50;      // Standard brightness
uint8_t that_bright     = 50;     // second brightness
uint8_t this_cutoff     = 192;    // Cutoff value; lower = longer wave
int     this_delay      = 0;      // Standard delay
uint8_t this_diff       = 1;      // Standard palette index jump
uint8_t this_dir        = 0;      // Standard direction
uint8_t this_fade       = 224;    // Standard fade rate
uint8_t this_hue        = 0;      // Standard hue
uint8_t this_index      = 0;      // Standard palette index
uint8_t this_inc        = 1;      // Standard increment. Changes starting color for each pass (sine-routines)
int     this_phase      = 0;      // Standard phase change - sines
int     that_phase      = 0;      // second phase
uint8_t this_rot        = 1;      // Standard hue rotation rate
uint8_t this_sat        = 255;    // Standard saturation
uint8_t this_speed      = 4;      // Standard speed change
uint8_t that_speed      = 4;      // Second speed
uint8_t wave_brightness = 255;    // Brightness of the waves/bars
uint8_t xd[NUM_LEDS];             // X-array for 2d coordinates of leds
uint8_t yd[NUM_LEDS];             // Y-array for 2d coordinates of leds
int ringArray[144][4];      	  // Array for rings
int spiralArray[4][144];		  // Array for spirals
int spiralArrayRev[4][144];
int w = 3; 						  // width of spirals


typedef struct balls {
	int distanceold;
	int distance;
	int velocityold;
	int velocity;
	int ballhue;
} ;


//balls myballs[numballs];

//Variables for plasma
int plasma_phase1;
int plasma_phase2;
int plasmaIndex;
int plasmaBright;


//Variables for ripple 
int rip_color;
int rip_center = 0;
int rip_step = -1;
#define rip_maxSteps 16
float rip_fadeRate = 0.8;
//Ripple background color
uint32_t rip_currentBg = random(256);
uint32_t rip_nextBg = rip_currentBg;
uint8_t myfade = 255;
uint8_t fadeval = 128;
//uint8_t bgcol = 0;



//Twinkle Variables
byte twinkle_speed = 4; // 0 - 8
byte twinkle_density = 5;	// 0 - 8
CRGB twinkle_bg = CRGB::Black; // CRGB(CRGB::FairyLight).nscale8_video(16);
byte auto_select_background_color = 0;
byte cool_like_incandescent = 1;
uint8_t bglight;
uint8_t backgroundBrightness;
CRGB bg;


uint8_t numdots;
uint8_t numdots_ring;   			// dots for juggle_pal_ring

//Fire Variables
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

//Disco Variables
uint8_t zooming_beats_per_minute = 122; // zooming for disco
uint8_t color_index = 0;
uint8_t color_speed = 1;
uint8_t color_inc = 3;

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

Bounce debouncer = Bounce();

//Spiral Variables
int spiral_start;
int spiral_inc;
int spiral_width;

// noise8 variables

uint16_t dist = 12345;         // A random number for our noise generator.
uint16_t scale = 30;          // Wouldn't recommend changing this_ on the fly, or the animation will be really blocky.
uint16_t dist2 = 12345;         // A random number for our noise generator.
uint16_t scale2 = 30;          // Wouldn't recommend changing this_ on the fly, or the animation will be really blocky.

// serendipitous variables

uint16_t Xorig = 0x013;
uint16_t Yorig = 0x021;
uint16_t X=Xorig;
uint16_t Y=Yorig;
uint16_t Xn;
uint16_t Yn;

uint16_t Xorig2 = 0x013;
uint16_t Yorig2 = 0x021;
uint16_t X2=Xorig2;
uint16_t Y2=Yorig2;
uint16_t Xn2;
uint16_t Yn2;

// three sin variables

int wave1;
int wave2;
int wave3;
uint8_t mul1;
uint8_t mul2;
uint8_t mul3;

int wave1r;
int wave2r;
int wave3r;
uint8_t mul1r;
uint8_t mul2r;
uint8_t mul3r;


// two_sin_pal variables-------------------------------------------------------------------------

uint8_t thathue = 140;                                        // You can change the starting hue for other wave.
uint8_t thatrot = 0;                                          // You can change how quickly the hue rotates for the other wave. Currently 0.
int8_t thatspeed = 4;                                         // You can change the speed, and use negative values.
int thatphase = 0;                                            // Phase change value gets calculated.
uint8_t thatcutoff = 192;                                     // You can change the cutoff value to display that wave. Lower value = longer wave.



///////// Variables for transitioning:
// LED Routine/Shared Variables
uint8_t old_all_freq, old_bg_clr, old_bg_bri, old_start_index, old_this_beat, old_this_bright, old_that_bright, old_this_cutoff;
int     old_this_delay = 0;      // Standard delay
uint8_t old_this_diff, old_this_dir, old_this_fade, old_this_hue, old_this_index, old_this_inc;
int     old_this_phase = 0;      // Standard phase change - sines
int     old_that_phase = 0;      // second phase
uint8_t old_this_rot = 1;      // Standard hue rotation rate
uint8_t old_this_sat = 255;    // Standard saturation
uint8_t old_this_speed = 4;      // Standard speed change
uint8_t old_that_speed = 4;      // Second speed
uint8_t old_wave_brightness = 255;    // Brightness of the waves/bars
uint8_t old_xd[NUM_LEDS];             // X-array for 2d coordinates of leds
uint8_t old_yd[NUM_LEDS];

int old_plasma_phase1, old_plasma_phase2, old_plasmaIndex, old_plasmaBright;

int old_rip_color;
int old_rip_center = 0;
int old_rip_step = -1;
float old_rip_fadeRate = 0.8;
uint32_t old_rip_currentBg = random(256);
uint32_t old_rip_nextBg = rip_currentBg;
uint8_t old_myfade = 255;
uint8_t old_fadeval = 128;

byte old_twinkle_speed = 4;
byte old_twinkle_density = 5;
CRGB old_twinkle_bg = CRGB::Black;
byte old_auto_select_background_color = 0;
byte old_cool_like_incandescent = 1;
uint8_t old_bglight;
uint8_t old_backgroundBrightness;
CRGB old_bg;

uint8_t old_numdots, old_numdots_ring;

uint8_t old_cooling, old_cooling1, old_cooling2, old_cooling3, old_cooling4;
uint8_t old_sparking, old_sparking1, old_sparking2, old_sparking3, old_sparking4;

uint8_t old_zooming_beats_per_minute = 122;
uint8_t old_color_index = 0;
uint8_t old_color_speed = 1;
uint8_t old_color_inc = 3;

uint16_t old_dist = 12345;
uint16_t old_scale = 30;
uint16_t old_dist2 = 12345;
uint16_t old_scale2 = 30;

uint16_t old_Xorig = 0x013;
uint16_t old_Yorig = 0x021;
uint16_t old_X = old_Xorig;
uint16_t old_Y = old_Yorig;
uint16_t old_Xn;
uint16_t old_Yn;

uint16_t old_Xorig2 = 0x013;
uint16_t old_Yorig2 = 0x021;
uint16_t old_X2 = old_Xorig;
uint16_t old_Y2 = old_Yorig;
uint16_t old_Xn2;
uint16_t old_Yn2;

int old_wave1, old_wave2, old_wave3;
uint8_t old_mul1, old_mul2, old_mul3;
int old_wave1r, old_wave2r, old_wave3r;
uint8_t old_mul1r, old_mul2r, old_mul3r;

uint8_t old_thathue = 140;
uint8_t old_thatrot = 0;
int8_t old_thatspeed = 4;
int old_thatphase = 0;
uint8_t old_thatcutoff = 192;

int old_spiral_start;
int old_spiral_inc;
int old_spiral_width;

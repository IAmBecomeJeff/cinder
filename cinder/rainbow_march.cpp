#include "rainbow_march.h"

void rainbow_march() {                                           // The fill_rainbow call doesn't support brightness levels
	if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;  // I could use signed math, but 'this_dir' works with other routines.
	fill_rainbow(leds, NUM_LEDS, this_index, this_diff);               // I don't change deltahue on the fly as it's too fast near the end of the strip.
} // rainbow_march()


void rainbow_march_ring() {                                           // The fill_rainbow call doesn't support brightness levels
	if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;  // I could use signed math, but 'this_dir' works with other routines.
	ring_fill_rainbow(this_index, this_diff);               // I don't change deltahue on the fly as it's too fast near the end of the strip.
} // rainbow_march_ring()

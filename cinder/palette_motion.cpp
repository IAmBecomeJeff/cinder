#include "palette_motion.h"

void palette_motion() {
	if (this_dir) {
		color_index += color_speed;
	}
	else { color_index -= color_speed; }
	ring_fill_palette(color_index, color_inc, current_palette, this_bright, current_blending);
} // palette_motion()
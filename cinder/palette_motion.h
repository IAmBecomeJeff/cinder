#ifndef PALETTE_MOTION_H
#define PALETTE_MOTION_H

// uint8_t color_index  -  the index within the palette.  involves a sin function.  leave it out?
// uint8_t color_speed  -  how quickly we move the palette
// uint8_t color_inc  -  how quickly we go from the beginning to end of palette

//void fillFromPalette(){
//	color_index += color_speed;
//	for( int i = 0; i < STRIP_LENGTH; i++){
//		ringPalette(i, current_palette, color_index + sin8(8*i), this_bright, current_blending);
//		color_index += color_inc;
//	}
//}

void palette_motion(){
  if(this_dir){
	color_index += color_speed;
  }else{color_index-=color_speed;}
	ring_fill_palette(color_index, color_inc, current_palette, this_bright, current_blending);
}


#endif

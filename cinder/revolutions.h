#ifndef REVOLUTIONS_H
#define

//  revolutions()
//  this_dir
//  this_hue
//  this_sat
//  this_bright
// rev_limit

void revolutions(){
	if (rev_count == 0){
		fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0));
		for (int i = 0; i<STRIP_LENGTH; i++){
			ringArray[i][col_count] = CHSV(this_hue, this_sat, this_bright);  
		}
		if (this_dir){
			col_count++;
		}else{
			if (col_count==0){
				col_count=3;
			}else{
				col_count--;
			}
		}
	}
	rev_count++;
	if(rev_count > rev_limit){
		rev_count = 0;
	}
}



// revolutios_pal()
// start_index
// this_inc
// current_palette
// this_bright
// this_dir
// this_delay
// rev_limit

void revolutions_pal(){
	if(rev_count==0){
		fill_solid(leds, NUM_LEDS, CRGB( 0, 0, 0)); // fade to black by??
		
	    start_index+=this_inc;
	    this_index = start_index;
			
		for (int i = 0; i<STRIP_LENGTH; i++){
			ringArray[i][rev_count] = ColorFromPalette(current_palette,this_index + i*this_inc, this_bright, current_blending);
		}
		if (this_dir){
			rev_count++;
		}else{
			if (rev_count==0){
				rev_count=3;
			}else{
				rev_count--;
			}
		}
	}
	rev_count++;
	if(rev_count > rev_limit){
		rev_count = 0;
	}
}


#endif
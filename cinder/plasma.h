#ifndef PLASMA_H
#define PLASMA_H

void plasma() {
	plasma_phase1 = beatsin8(6, -64, 64);
	plasma_phase2 = beatsin8(7, -64, 64);

	for (int k = 0; k < STRIP_LENGTH; k++) {
		plasmaIndex = cubicwave8((k * 23) + plasma_phase1) / 2 + cos8((k * 15) + plasma_phase2) / 2;
		plasmaBright = qsuba(plasmaIndex, beatsin8(7, 0, 96));

		ringPalette(k, current_palette, plasmaIndex, plasmaBright, current_blending);
	}
} // plasma()

#endif

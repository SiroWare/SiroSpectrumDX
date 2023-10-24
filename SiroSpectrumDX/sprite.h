#ifndef SPRITE_H_
#define SPRITE_H_

struct Sprite {
	unsigned char width;
	unsigned char height;
	unsigned char* canvas;
};

struct Tile {
	unsigned char canvas[8 * 8];
	unsigned char colour;
};

#endif

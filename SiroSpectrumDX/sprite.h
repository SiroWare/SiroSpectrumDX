#ifndef SPRITE_H_
#define SPRITE_H_

struct Sprite {
	Sprite(unsigned char _width, unsigned char _height, unsigned char count,...);
	~Sprite();
	unsigned char width;
	unsigned char height;
	unsigned char* image;
};

struct Tile {
	unsigned char canvas[8 * 8];
	unsigned char colour;
};

#endif

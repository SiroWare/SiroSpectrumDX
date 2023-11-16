#ifndef SPRITE_H_
#define SPRITE_H_

#include <initializer_list>
#include <SiroSpectrumDX/vector.h>

struct Sprite {
	Sprite(unsigned char _width, unsigned char _height, unsigned char count,...);
	~Sprite();
	unsigned char width;
	unsigned char height;
	unsigned char* image;
};

struct AnimatedSprite {
	AnimatedSprite(std::initializer_list<Sprite*> _sprites, unsigned char _speed);
	SiroVector<Sprite*> sprites;
	unsigned char speed;
	unsigned char frame;
};

struct Tile {
	unsigned char canvas[8 * 8];
	unsigned char colour;
};

#endif

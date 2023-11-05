#include "sprite.h"
#include <cstdarg>
#include <stdio.h>

Sprite::Sprite(unsigned char _width, unsigned char _height, unsigned short grid...) {
	va_list ap;
	image = new unsigned char[_width * _height];
	width = _width;
	height = _height;
	va_start(ap, grid);
	for (int i = 0; i < _width * _height; i++) {
		image[i] = va_arg(ap, unsigned short);
	}
	va_end(ap);
}

Sprite::~Sprite() {
	delete[] image;
}

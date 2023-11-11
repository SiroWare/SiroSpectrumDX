#include "sprite.h"
#include <stdarg.h>
#include <stdio.h>

Sprite::Sprite(unsigned char _width, unsigned char _height, unsigned char count,...) {
	int result;
	va_list list;
	va_start(list, count);
	image = new unsigned char[_width * _height];
	width = _width;
	height = _height;
	image[0] = count;
	for (int i = 1; i < _width * _height; i++) {
		result = va_arg(list, unsigned char);
		image[i] = result;
	}
	va_end(list);
}

Sprite::~Sprite() {
	delete[] image;
}

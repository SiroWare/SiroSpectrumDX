#include "pencil.h"
#include <SiroSpectrumDX/Internal/renderer.h>

SiroPencil* SiroPencil::_instance = 0;

SiroPencil::SiroPencil() {
	_renderer = _renderer->GetRenderer();
}

void SiroPencil::SetSprite(Sprite* sprite, unsigned char xpos, unsigned char ypos, unsigned char colour) {
	unsigned char row = 0;

	switch (colour >> 4) {
	case 1:
		for (unsigned char y = 0; y < sprite->height; y++) {
			for (unsigned char x = sprite->width; x > 0; x--) {
				SetPixel(x + xpos - 1, y + ypos, sprite->image[row] * colour);
				row++;
			}
		}
		break;
	case 2:
		for (unsigned char y = sprite->height; y > 0; y--) {
			for (unsigned char x = 0; x < sprite->width; x++) {
				SetPixel(x + xpos, y + ypos - 1, sprite->image[row] * colour);
				row++;
			}
		}
		break;
	case 3:
		for (unsigned char y = sprite->height; y > 0; y--) {
			for (unsigned char x = sprite->width; x > 0; x--) {
				SetPixel(x + xpos - 1, y + ypos - 1, sprite->image[row] * colour);
				row++;
			}
		}
		break;
	default:
		for (unsigned char y = 0; y < sprite->height; y++) {
			for (unsigned char x = 0; x < sprite->width; x++) {
				SetPixel(x + xpos, y + ypos, sprite->image[row] * colour);
				row++;
			}
		}
		break;
	}
}

void SiroPencil::SetTile(Tile tile, unsigned char x, unsigned char y) {
	unsigned char row = 0;
	for (unsigned char ypos = 0; ypos < 8; ypos++) {
		for (unsigned char xpos = 0; xpos < 8; xpos++) {
			SetPixel((x * 8) + xpos, (y * 8) + ypos, tile.canvas[row] * tile.colour & 15);
			SetBGColour(x, y, tile.colour >> 4);
			row++;
		}
	}
}

void SiroPencil::RemoveSprite(Sprite sprite, unsigned char xpos, unsigned char ypos) {
	for (unsigned char y = 0; y < sprite.height; y++) {
		for (unsigned char x = 0; x < sprite.width; x++) {
			_renderer->pixelbuffer[y + ypos][x + xpos & 255] = 0;
		}
	}
}

void SiroPencil::ClearScreen() {
	for (int y = 0; y < WIN_HEIGHT; y++) {
		for (int x = 0; x < WIN_WIDTH; x++) {
			_renderer->pixelbuffer[y][x] = 0;
		}
	}
	for (int y = 0; y < WIN_HEIGHT / TILESIZE; y++) {
		for (int x = 0; x < WIN_WIDTH / TILESIZE; x++) {
			_renderer->backgroundcolors[y][x] = 0;
		}
	}
}

void SiroPencil::SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	if (colour) {
		_renderer->pixelbuffer[ypos][xpos] = colour & 15;
	}
}

void SiroPencil::SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	_renderer->backgroundcolors[ypos][xpos] = colour & 15;
}

void SiroPencil::PlayAnimation(AnimatedSprite* animation, unsigned char x_pos, unsigned char y_pos, unsigned char colour) {
	if (!(framecounter & (animation->speed - 1))) {
		animation->frame++;
		if (animation->frame >= animation->sprites.size()) {
			animation->frame = 0;
		}
	}
	SetSprite(animation->sprites[animation->frame], x_pos, y_pos, colour);
}

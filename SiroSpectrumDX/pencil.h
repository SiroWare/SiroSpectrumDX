#ifndef PENCIL_H_
#define PENCIL_H_

#include <SiroSpectrumDX/sprite.h>

#define OFF 0
#define BLK 1
#define DBLU 2
#define BLU 3
#define DRED 4
#define RED 5
#define DMGT 6
#define MGT 7
#define DGRN 8
#define GRN 9
#define DCYN 10
#define CYN 11
#define DYLW 12
#define YLW 13
#define GRY 14
#define WHT 15

#define MIRROR 16
#define MIRRORY 32

class SiroRenderer;

class SiroPencil {
public:
	SiroPencil(const SiroPencil&) = delete;

	static SiroPencil* SharpenPencil()
	{
		if (!_instance)
		{
			_instance = new SiroPencil();
		}
		return _instance;
	}

	void DrawSprite(Sprite* sprite, unsigned char xpos, unsigned char ypos, unsigned char colour);

	unsigned char DrawAnimatedSprite(AnimatedSprite* animation, unsigned char x_pos, unsigned char y_pos, unsigned char colour);

	void DrawTile(Tile tile, unsigned char x, unsigned char y);

	void DrawPixel(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void DrawBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void DrawTileNumber(Tile* SizeTenArray[10], unsigned char x, unsigned char y, int number, Tile* blankdigit);
	void DrawTileNumber(Tile* SizeTenArray[10], unsigned char x, unsigned char y, int number, unsigned char colour = 0);

	void ClearScreen();

	void RemoveTile(unsigned char x, unsigned char y, unsigned char colour = 0);

	void RemoveSprite(Sprite* sprite, unsigned char xpos, unsigned char ypos);

private:

	SiroPencil();

	static SiroPencil* _instance;

	SiroRenderer* _renderer;
};

#endif

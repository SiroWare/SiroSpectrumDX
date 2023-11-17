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

	void SetSprite(Sprite* sprite, unsigned char xpos, unsigned char ypos, unsigned char colour);

	void SetTile(Tile tile, unsigned char x, unsigned char y);

	void SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void RemoveSprite(Sprite* sprite, unsigned char xpos, unsigned char ypos);

	void ClearScreen();

	unsigned char SetAnimatedSprite(AnimatedSprite* animation, unsigned char x_pos, unsigned char y_pos, unsigned char colour);

private:

	SiroPencil();

	static SiroPencil* _instance;

	SiroRenderer* _renderer;
};

#endif

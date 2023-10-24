#ifndef PENCIL_H_
#define PENCIL_H_

#include <SiroSpectrumDX/sprite.h>

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

	void SetSprite(Sprite sprite, unsigned char xpos, unsigned char ypos, unsigned char colour);

	void SetTile(Tile tile, unsigned char x, unsigned char y);

	void SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour);

	void RemoveSprite(Sprite sprite, unsigned char xpos, unsigned char ypos);

	void ClearScreen();

private:
	SiroPencil();

	static SiroPencil* _instance;

	SiroRenderer* _renderer;
};

#endif

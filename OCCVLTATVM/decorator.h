#ifndef DECORATOR_H_
#define DECORATOR_H_

#include <SiroSpectrumDX/sprite.h>

class Decorator {
public:
	Decorator(const Decorator&) = delete;

	static Decorator* PayDecorator()
	{
		if (!_instance)
		{
			_instance = new Decorator();
		}
		return _instance;
	}

	unsigned char TileScreen[32 * 20];
	Tile* TileArray[16];

private:
	Decorator();

	static Decorator* _instance;
};

#endif

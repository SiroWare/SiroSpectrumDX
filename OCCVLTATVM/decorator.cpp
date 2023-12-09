#include "decorator.h"

Decorator* Decorator::_instance = 0;

Decorator::Decorator() {
	for (int i = 0; i < 32 * 20; i++) {
		TileScreen[i] = 0;
	}
	for (int j = 0; j < 16; j++) {
		TileArray[j] = nullptr;
	}
}
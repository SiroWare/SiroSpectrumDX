#ifndef SPRITE_H_
#define SPRITE_H_

#include <initializer_list>


template <typename T>
class SiroVector {
public:
	SiroVector();
	~SiroVector();
	void push_back(T newval);
	unsigned char size() { return arraySize; };
	
	T& operator[](unsigned char index) {
		return templateArray[index];
	}

private:
	T* templateArray;
	unsigned char arraySize = 0;
};

template<typename T>
SiroVector<T>::SiroVector() {
	templateArray = nullptr;
}

template<typename T>
SiroVector<T>::~SiroVector() {
	delete[] templateArray;
}

template <typename T>
void SiroVector<T>::push_back(T newval) {
	// Allocate memory for the array in the temporary array.
	T* tmpArray = new T[arraySize + 1];

	// Copy the elements of old array.
	for (unsigned char count = 0; count < arraySize; count++) {
		*(tmpArray + count) = *(templateArray + count);
	}

	// Push new value
	*(tmpArray + arraySize) = newval;

	// Delete old array
	delete[] templateArray;

	// Copy array
	templateArray = tmpArray;

	// Increase size
	arraySize++;
};

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

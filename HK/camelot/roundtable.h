#ifndef PREGO_H_
#define PREGO_H_

#include <HK/hotel.h>

class Camelot : public Hotel {

public:
	Camelot();
	//void setup() override;

private:


};

class RoundTable : public Room {
	Tile* wallup = nullptr;
	Tile* walldown = nullptr;
	void setup() override;
	void loop() override;
};

#endif
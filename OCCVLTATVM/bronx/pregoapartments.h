#ifndef PREGO_H_
#define PREGO_H_

#include <OCCVLTATVM/hotel.h>

class PregoApartments : public Hotel {

public:
	PregoApartments();
	//void setup() override;

private:


};

class Hall_1a : public Room {
	void setup() override;
	void loop() override;
};

#endif
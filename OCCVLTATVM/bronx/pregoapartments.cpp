#include "pregoapartments.h"

PregoApartments::PregoApartments(){
	AddRoomAt(new Hall_1a(), 0);
}

void Hall_1a::setup() {
	//Entity* entity = new Entity(Sprite, x,y, colour)
	Pencil->SetSprite(&Sprite(8,16,
0,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,0,
0,1,1,1,1,1,0,0,
0,1,1,1,0,1,0,0,
0,0,1,1,1,1,1,0,
0,0,1,1,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,1,1,0,1,0,0,
0,1,1,1,0,1,1,0,
0,1,1,1,0,1,1,0,
0,1,1,1,1,1,1,0,
0,1,0,0,1,0,1,0,
0,0,1,1,1,1,0,0,
0,0,1,1,0,1,0,0,
0,0,1,0,1,1,0,0,
0,0,1,1,0,1,1,0
		), 16,16,15);
}

void Hall_1a::loop() {

}

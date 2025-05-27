#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <SiroSpectrumDX/input.h>
#include <vector>
#include <stdio.h>

SiroInput* input = input->PlugInKeyboard();
SiroPencil* pencil = pencil->SharpenPencil();

struct Entity {
	Sprite* sprite;
	unsigned char x;
	unsigned char y;
};

class Maze : public Game {
public:
	void setup() override;
	void loop() override;

	bool Collision(Entity* entity1, Entity* entity2);

};


bool Maze::Collision(Entity* entity1, Entity* entity2) {
	if (entity1->x + entity1->sprite->width > entity2->x &&
		entity1->x < entity2->x + entity2->sprite->width &&
		entity1->y + entity1->sprite->height > entity2->y &&
		entity1->y < entity2->y + entity2->sprite->height
		) {
		return true;
	}
	return false;
}



void Maze::setup() {

}

void Maze::loop() {
}

int main(void) {
	SiroCore sc;

	Maze* mazegame = new Maze();

	sc.StartupConsole("Dijkstra Algorithm");
	
	while (!sc.ShutdownConsole()) {
		sc.RunGame(mazegame);
	}

	return 0;
}

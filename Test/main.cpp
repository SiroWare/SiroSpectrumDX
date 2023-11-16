#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <SiroSpectrumDX/input.h>
#include <vector>
#include <stdio.h>

#define RESETPLAYER {frog->x = 128; \
					frog->y = 168;\
}

struct Entity {
	Sprite* sprite;
	unsigned char x;
	unsigned char y;
};

class Frogger : public Game {
public:
	void setup() override;
	void loop() override;

	std::vector<Entity*>slowlane;

	Entity* frog = new Entity();

	bool Collision(Entity* entity1, Entity* entity2);

	SiroInput* input = input->GetKeyboard();
};
SiroPencil* pencil = pencil->SharpenPencil();

unsigned char posx = 0;
unsigned char posy = 0;

Sprite* frogy = new Sprite(8, 8,
		1,0,0,1,1,0,0,1,
		1,0,1,1,1,1,0,1,
		0,1,0,1,1,0,1,0,
		0,0,1,1,1,1,0,0,
		0,0,1,1,1,1,0,0,
		0,1,1,1,1,1,1,0,
		0,1,0,1,1,0,1,0,
		1,1,0,0,0,0,1,1
	);

Sprite* car = new Sprite(16, 8,
		0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,
		0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,
		0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,
		1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,
		1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,
		0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0
	);

Sprite* joedoe = new Sprite(8,16, 
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
);

Sprite* joewalk = new Sprite(8,16, 
	0,0,0,1,1,1,0,0,
	0,0,1,1,1,1,1,0,
	0,1,1,1,1,1,0,0,
	0,1,1,1,0,1,0,0,
	0,0,1,1,1,1,1,0,
	0,0,1,1,1,1,0,0,
	0,0,0,1,1,0,0,0,
	0,0,1,1,0,1,0,0,
	0,1,1,1,0,1,0,0,
	0,0,1,1,1,0,0,0,
	0,0,0,1,1,1,0,0,
	0,0,1,0,1,1,0,0,
	0,0,1,1,0,0,0,0,
	0,1,1,1,0,1,1,0,
	1,1,0,0,0,1,1,0,
	0,1,1,0,0,0,1,1);

//Sprite* frogx = new Sprite(8, 8, 
//		1,0,0,0,0,0,1,1,
//		1,1,1,0,0,1,0,0,
//		0,0,1,1,1,0,1,0,
//		0,1,1,1,1,1,1,1,
//		0,1,1,1,1,1,1,1,
//		0,0,1,1,1,0,1,0,
//		1,1,1,0,0,1,0,0,
//		1,0,0,0,0,0,1,1
//	);
bool Frogger::Collision(Entity* entity1, Entity* entity2) {
	if (entity1->x + entity1->sprite->width > entity2->x &&
		entity1->x < entity2->x + entity2->sprite->width &&
		entity1->y + entity1->sprite->height > entity2->y &&
		entity1->y < entity2->y + entity2->sprite->height
		) {
		return true;
	}
	return false;
}

AnimatedSprite* walkanimationprime = new AnimatedSprite({joedoe, joewalk}, 8);

void Frogger::setup() {
	frog->sprite = joedoe;
	RESETPLAYER;

	slowlane.resize(4);
	for (int i = 0; i < slowlane.size(); i++) {
		slowlane[i] = new Entity();
		slowlane[i]->sprite = car;
		slowlane[i]->x = i * (256 / slowlane.size());
		slowlane[i]->y = 168;
	}
}

void Frogger::loop() {
	pencil->AnimationLoop();
	pencil->ClearScreen();

	pencil->PlayAnimation(walkanimationprime, frog->x, frog->y, WHT);
	
	for (int i = 0; i < slowlane.size(); i++) {
		pencil->SetSprite(slowlane[i]->sprite, slowlane[i]->x, slowlane[i]->y, YLW);
		slowlane[i]->x--;
		if (Collision(frog, slowlane[i])) {
			RESETPLAYER;
		}
	}

	if (input->KeyPressed(KeyCode::Up)) {
		frog->y -= 8;
	}
	else if (input->KeyPressed(KeyCode::Down)) {
		frog->y += 8;
	}
	else if (input->KeyPressed(KeyCode::Left)) {
		frog->x -= 8;
	}
	else if (input->KeyPressed(KeyCode::Right)) {
		frog->x += 8;
	}
}

int main(void) {
	SiroCore sc;

	Frogger* frogger = new Frogger();

	sc.StartupConsole("Frogger");
	
	while (!sc.ShutdownConsole()) {
		sc.RunGame(frogger);
	}

	return 0;
}

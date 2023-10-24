#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	virtual void setup();
	virtual void loop();

	bool Reset = 1;
};

#endif

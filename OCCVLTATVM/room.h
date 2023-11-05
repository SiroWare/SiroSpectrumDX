#ifndef ROOM_H_
#define ROOM_H_

#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <SiroSpectrumDX/input.h>
#include <OCCVLTATVM/entity.h>

class Room : public Game {

public:

protected:
	SiroInput* Input = Input->GetKeyboard();
	SiroPencil* Pencil = Pencil->SharpenPencil();

private:

};

#endif

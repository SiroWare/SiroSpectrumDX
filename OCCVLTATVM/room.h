#ifndef ROOM_H_
#define ROOM_H_

#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <SiroSpectrumDX/input.h>
#include <OCCVLTATVM/decorator.h>
#include <OCCVLTATVM/entity.h>

class Room : public Game {

public:

protected:
	SiroInput* Input = Input->PlugInKeyboard();
	SiroPencil* Pencil = Pencil->SharpenPencil();
	Decorator* Decor = Decor->PayDecorator();

private:

};

#endif

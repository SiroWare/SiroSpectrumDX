#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <SiroSpectrumDX/input.h>
#include <stdio.h>

class FunGame : public Game {
public:
	void setup() override;
	void loop() override;
};

unsigned char stefanvas[] = {
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
0,0,1,1,0,1,1,0,
};

Sprite* Jon = new Sprite{  8,16, stefanvas };

SiroPencil* pencil = pencil->SharpenPencil();
SiroInput* input = input->GetKeyboard();

int main(void) {
	SiroCore sc;

	FunGame* fungame = new FunGame();

	sc.StartupConsole();
	
	while (!sc.ShutdownConsole()) {
		sc.RunGame(fungame);
	}

	return 0;
}

void FunGame::setup(){
	pencil->SetSprite(*Jon, 14, 14, 15);
}

void FunGame::loop() {
	if (input->KeyPressed(KeyCode::Space)) {
		pencil->SetBGColour(5, 5, 3);
	}
	if (input->KeyReleased(KeyCode::Space)) {
		pencil->SetBGColour(5, 5, 5);
	}
}

#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/input.h>
#include <SiroSpectrumDX/game.h>
#include <OCCVLTATVM/bronx/pregoapartments.h>
#include <OCCVLTATVM/city.h>

SiroInput* input = input->GetKeyboard();

//extern unsigned char* TileMap;
//extern Tile* TileArray[16];

int main(void) {
	SiroCore sc;

	sc.StartupConsole();

	Hotel* hotel = new Hotel();
	City* bronx = new City();

	//hotel->AddRoomAt({room1, room2}, 0);

	bronx->AddHotelAt(new PregoApartments(), 0);

	while (!sc.ShutdownConsole() && !input->KeyDown(KeyCode::Escape)) {

		sc.RunGame(bronx->GetHotelAt(0)->GetRoomAt(0));

	}

	return 0;
}

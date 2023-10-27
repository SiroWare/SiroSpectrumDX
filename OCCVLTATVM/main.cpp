#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/input.h>
#include <SiroSpectrumDX/game.h>
#include <OCCVLTATVM/city.h>

SiroInput* input = input->GetKeyboard();

int main(void) {
	SiroCore sc;

	sc.StartupConsole();

	Room* room = new Room();
	Hotel* hotel = new Hotel();
	City* bronx = new City();

	hotel->AddRoomAt( room , 0);

	hotel->GetRoomAt(0)->Reset = 1;

	bronx->AddHotelAt(hotel, 0);


	while (!sc.ShutdownConsole() && !input->KeyDown(KeyCode::Escape)) {

		sc.RunGame(bronx->GetHotelAt(0)->GetDynamicRoom());

	}

	return 0;
}
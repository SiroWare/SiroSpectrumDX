#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/input.h>
#include <SiroSpectrumDX/game.h>
#include <SiroSpectrumDX/pencil.h>
#include <OCCVLTATVM/city.h>

SiroInput* input = input->GetKeyboard();
SiroPencil* pencil = pencil->SharpenPencil();

int gamenumber = 0;

class Room1 : public Room {
public:
	void setup() override;
	void loop() override;
};

class Room2 : public Room {
public:
	void setup() override;
	void loop() override;
};

int main(void) {
	SiroCore sc;

	sc.StartupConsole();

	Room1* room1 = new Room1();
	Room2* room2 = new Room2();
	Hotel* hotel = new Hotel();
	City* bronx = new City();

	hotel->AddRoomAt({room1, room2}, 0);

	bronx->AddHotelAt(hotel, 0);


	while (!sc.ShutdownConsole() && !input->KeyDown(KeyCode::Escape)) {

		sc.RunGame(bronx->GetHotelAt(0)->GetRoomAt(gamenumber));

	}

	return 0;
}

void Room1::setup() {
	pencil->SetPixel(5, 5, 5);
}

void Room1::loop() {
	if (input->KeyReleased(KeyCode::LeftControl)) {
		gamenumber++;
	}
}

void Room2::setup() {
	pencil->SetPixel(6, 6, 8);
	printf("BLLLLLP!!\n");
}

void Room2::loop() {
	if (input->KeyReleased(KeyCode::LeftControl)) {
		gamenumber--;
	}
}

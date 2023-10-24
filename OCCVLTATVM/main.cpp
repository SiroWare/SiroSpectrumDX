#include <SiroSpectrumDX/core.h>
#include <SiroSpectrumDX/input.h>

SiroInput* input = input->GetKeyboard();

int main(void) {
	SiroCore sc;

	sc.StartupConsole();

	while (!sc.ShutdownConsole() && !input->KeyDown(KeyCode::Escape)) {

		//sc.RunGame()

	}

	return 0;
}
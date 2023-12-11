#ifndef CORE_H_
#define CORE_H_

class SiroCore {

public:
	SiroCore();

	/**
	 * @brief Creates a Game window.
	 *
	 * @param name:
	 * The name for the window you wish to create.
	 */
	void StartupConsole(const char* name = "SiroSpectrumDX");

	/**
	 * @brief Shuts down the Game window. Can be used as parameter in while loop. Doing so will make clicking the X mark shutdown the window.
	 */
	int ShutdownConsole();

	/**
	 * @brief Runs a Game in a *while* loop
	 *
	 * @param game:
	 * The Game you wish to run in the while loop.
	 */
	void RunGame(class Game* game);

	/**
	 * @brief Runs a Game in a *while* loop
	 *
	 * @param setup:
	 * The setup function that will be called once.
	 * 
	 * @param loop:
	 * The loop function that will be called 60 times per second.
	 */
	void RunGame(void (*setup)(), void (*loop)());

private:
	class SiroRenderer* _renderer;
	class SiroInput* _input;
	class Game* _cartridge;
	struct GLFWwindow* _window;
	double _starttime;
	void(*_keysetup)();
};

#endif

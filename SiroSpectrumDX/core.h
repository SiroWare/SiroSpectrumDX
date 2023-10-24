#ifndef CORE_H_
#define CORE_H_

class SiroRenderer;
class SiroInput;
class Game;
struct GLFWwindow;

class SiroCore {

public:
	SiroCore();

	void StartupConsole();

	int ShutdownConsole();

	void RunGame(Game* game);

private:
	SiroRenderer* _renderer;
	SiroInput* _input;
	GLFWwindow* _window;
	double _starttime;
};

#endif

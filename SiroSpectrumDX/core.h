#ifndef CORE_H_
#define CORE_H_

class SiroCore {

public:
	SiroCore();

	void StartupConsole();

	int ShutdownConsole();

	void RunGame(class Game* game);

private:
	class SiroRenderer* _renderer;
	class SiroInput* _input;
	struct GLFWwindow* _window;
	double _starttime;
};

#endif

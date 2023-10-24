#ifndef RENDERER_H_
#define RENDERER_H_

#define WIN_WIDTH 256
#define WIN_HEIGHT 192
#define TILESIZE 8

typedef unsigned int GLuint;

class SiroRenderer {
public:
	SiroRenderer(const SiroRenderer&) = delete;

	static SiroRenderer* GetRenderer()
	{
		if (!_instance)	{
			_instance = new SiroRenderer();
		}
		return _instance;
	}

	void UpdateGameScreen(void);

	void DrawGameScreen(void);

	unsigned char backgroundcolors[WIN_HEIGHT / TILESIZE][WIN_WIDTH / TILESIZE];
	unsigned char pixelbuffer[WIN_HEIGHT][WIN_WIDTH];

	friend class SiroCore;

private:
	SiroRenderer();

	static SiroRenderer* _instance;

	GLuint shaderProgram;
	GLuint vertexbuffer;
	GLuint BGtexturesampler;
	GLuint FGtexturesampler;
	GLuint PaletteSampler;
	GLuint EBO;

	void SetupRenderer();

};

#endif

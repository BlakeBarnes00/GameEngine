#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Game
{
public:
	Game(const char* title, int x, int y, int width, int height, bool fullscreen);
	~Game();

	void eventHandler();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool m_isRunning;

	SDL_Texture* playerTexture;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};


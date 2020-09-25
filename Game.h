#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
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

	static SDL_Renderer* renderer;


private:
	bool m_isRunning;

	SDL_Window* m_window;
};


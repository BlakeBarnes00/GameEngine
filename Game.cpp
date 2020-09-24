#include "Game.h"



Game::Game(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL initialized...\n";

		m_window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (m_window)
		{
			std::cout << "Window created! \n";
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer) {
			SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			std::cout << "Renderer created! \n";
		}
		m_isRunning = true;
	}
	else {
		std::cout << "SDL not initialized...\n";
		std::cout << SDL_GetError() << std::endl;
		m_isRunning = false;
	}

	int w, h;
	playerTexture = IMG_LoadTexture(m_renderer, "assets/Player.png");
	SDL_QueryTexture(playerTexture, NULL, NULL, &w, &h);

	std::cout << SDL_GetError();
}

Game::~Game()
{
}

void Game::eventHandler()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
	default:
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	
	SDL_RenderCopy(m_renderer, playerTexture, NULL, NULL);

	SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	std::cout << "Window and renderer destroyed...\n";

}

bool Game::running()
{
	return m_isRunning;
}

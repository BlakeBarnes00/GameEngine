#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Collision.h"
#include "EntityComponentSystem/Components.h"

SDL_Event Game::event;
SDL_Renderer* Game::renderer = NULL;

Map* map;
Manager manager;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

		renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created! \n";
		}
		m_isRunning = true;
	}
	else {
		std::cout << "SDL not initialized...\n";
		std::cout << SDL_GetError() << std::endl;
		m_isRunning = false;
	}

	map = new Map();
	
	tile0.addComponent<TileComponent>(100, 100, 0);
	tile1.addComponent<TileComponent>(200, 100, 1);
	tile1.addComponent<ColliderComponent>("dirt");
	tile2.addComponent<TileComponent>(300, 100, 2);
	tile1.addComponent<ColliderComponent>("grass");



	wall.addComponent<TransformComponent>(300, 300, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.addComponent<ColliderComponent>("wall");

	player.addComponent<TransformComponent>(3);
	player.addComponent<SpriteComponent>("assets/Player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	
}

Game::~Game()
{
}

void Game::eventHandler()
{
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
	// limit fps
	frameStart = SDL_GetTicks();
	if (frameDelay > frameTime)
		SDL_Delay(frameDelay - frameTime);
	
	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider)) {
		player.getComponent<TransformComponent>().velocity * -1;
		std::cout << "Wall hit\n";
	}


}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->drawMap();

	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(renderer);
	std::cout << "Window and renderer destroyed...\n";
	
	delete map; // Delete objects when exiting the game
	std::cout << "Deleted game objects...\n";
}

bool Game::running()
{
	return m_isRunning;
}

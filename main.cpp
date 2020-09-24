#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
	Game* game = nullptr;
	game = new Game("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		game->eventHandler();
		game->update();
		game->render();
	}

	game->clean();
	
	std::cin.get();
	return 0;
}
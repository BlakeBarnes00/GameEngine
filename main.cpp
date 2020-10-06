#include <iostream>
#include "Game.h"

int main(int argc, char** argv) {

	Game* game = new Game("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);;

	while (game->running()) {
		game->eventHandler();
		game->update();
		game->render();
	}

	game->clean();

	delete game;
	std::cin.get();
	return 0;
} 
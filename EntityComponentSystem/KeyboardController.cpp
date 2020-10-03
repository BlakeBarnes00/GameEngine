#include "KeyboardController.h"

void KeyboardController::init() {
	transform = &entity->getComponent<TransformComponent>();
}

void KeyboardController::update() {
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_w:
			transform->velocity.my = -1;
			break;
		case SDLK_a:
			transform->velocity.mx = -1;
			break;
		case SDLK_s:
			transform->velocity.my = 1;
			break;
		case SDLK_d:
			transform->velocity.mx = 1;
			break;

		default:
			break;
		}
	}

	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_w:
			transform->velocity.my = 0;
			break;
		case SDLK_a:
			transform->velocity.mx = 0;
			break;
		case SDLK_s:
			transform->velocity.my = 0;
			break;
		case SDLK_d:
			transform->velocity.mx = 0;
			break;

		default:
			break;
		}
	}
}
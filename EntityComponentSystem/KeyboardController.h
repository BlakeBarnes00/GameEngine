#pragma once

#include "../Game.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
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
};
#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"
#include "../TextureManager.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;
	TransformComponent* transform;

	ColliderComponent(std::string tag) {
		this->tag = tag;
	}

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		Game::colliders.push_back(this);
	}

	void update() override {
		collider.x = static_cast<int>(transform->position.mx);
		collider.y = static_cast<int>(transform->position.my);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}


};
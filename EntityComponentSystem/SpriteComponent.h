#pragma once
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	int scale;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* fileName) : scale(1){
		setTexture(fileName);
	}
	SpriteComponent(const char* fileName, int scale) {
		setTexture(fileName);
		this->scale = scale;
	}
	
	~SpriteComponent() {
		SDL_DestroyTexture(texture);
		std::cout << "Destroyed texture...\n";
		delete texture;
		delete transform;
	}

	void setTexture(const char* fileName) {
		texture = TextureManager::loadTexture(fileName);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.h = transform->height;
		srcRect.w = transform->width;
		destRect.w = destRect.h = 32 * scale;
	}

	void update() override {
		destRect.x = static_cast<int>(transform->position.mx);
		destRect.y = static_cast<int>(transform->position.my);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::draw(texture, srcRect, destRect);
	}

};

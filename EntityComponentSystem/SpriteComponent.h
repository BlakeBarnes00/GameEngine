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

		srcRect.w = srcRect.h = 32;
		srcRect.h = transform->height;
		srcRect.w = transform->width;
		destRect.w = destRect.h = 32 * scale;
	}

	void update() override {
		destRect.x = (int)transform->position.mx;
		destRect.y = (int)transform->position.my;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::draw(texture, srcRect, destRect);
	}

};

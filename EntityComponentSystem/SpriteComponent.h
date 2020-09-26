#pragma once
#include "Components.h"
#include "SDL.h"

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
	SpriteComponent(const char* fileName, int scale) : scale(scale) {
		setTexture(fileName);
	}

	void setTexture(const char* fileName) {
		texture = TextureManager::loadTexture(fileName);
	}

	void init() override {

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 32 * scale;
	}

	void update() override {
		destRect.x = (int)transform->position.mx;
		destRect.y = (int)transform->position.my;
	}

	void draw() override {
		TextureManager::draw(texture, srcRect, destRect);
	}

};

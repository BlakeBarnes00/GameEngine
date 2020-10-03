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
	SpriteComponent();
	SpriteComponent(const char* fileName);
	SpriteComponent(const char* fileName, int scale);
	~SpriteComponent();

	void setTexture(const char* fileName);
	void init() override;
	void update() override;
	void draw() override;
};

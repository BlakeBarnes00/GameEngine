#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y, float scale);
	~GameObject();

	void update();
	void render();

private:
	int m_x, m_y;
	float m_scale;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* m_renderer;

};


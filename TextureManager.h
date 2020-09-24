#pragma once
#include <SDL_image.h>
#include "Game.h"
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);
};

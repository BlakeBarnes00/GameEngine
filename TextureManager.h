#pragma once
#include <SDL_image.h>
#include "Game.h"
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};


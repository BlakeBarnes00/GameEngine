#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName, SDL_Renderer* renderer)
{
	int w, h;
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = IMG_LoadTexture(renderer, fileName);
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_FreeSurface(tempSurface);
	return texture;
}

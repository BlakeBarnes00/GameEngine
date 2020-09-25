#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = IMG_LoadTexture(renderer, fileName);
	SDL_FreeSurface(tempSurface);
	std::cout << SDL_GetError() << std::endl;
	return texture;
}

#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = IMG_LoadTexture(Game::renderer, fileName);
	SDL_FreeSurface(tempSurface);
	if (texture == NULL)
		std::cout << SDL_GetError();
	else
		std::cout << fileName << " loaded with no errors\n";
	
	return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

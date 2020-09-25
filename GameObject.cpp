#include "GameObject.h"


GameObject::GameObject(const char* textureSheet, int x, int y)
{
	m_x = x;
	m_y = y;
	m_scale = 1;
	objTexture = TextureManager::loadTexture(textureSheet);
}

GameObject::GameObject(const char* textureSheet, int x, int y, float scale)
{
	m_x = x;
	m_y = y;
	m_scale = scale;
	objTexture = TextureManager::loadTexture(textureSheet);
}

GameObject::~GameObject()
{
	
}

void GameObject::update()
{


	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	destRect.x = m_x++;
	destRect.y = m_y++;
	destRect.h = srcRect.h * m_scale;
	destRect.w = srcRect.w * m_scale;

}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
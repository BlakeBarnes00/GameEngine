#include "SpriteComponent.h"

SpriteComponent::SpriteComponent() {

}

SpriteComponent::SpriteComponent(const char* fileName) : scale(1) {
	scale = 1;
	setTexture(fileName);
}

SpriteComponent::SpriteComponent(const char* fileName, int scale) {
	setTexture(fileName);
	this->scale = scale;
}

SpriteComponent::~SpriteComponent() {
	SDL_DestroyTexture(texture);
	std::cout << "Destroyed texture...\n";
	delete texture;
	delete transform;
}

void SpriteComponent::setTexture(const char* fileName) {
	texture = TextureManager::loadTexture(fileName);
}

void SpriteComponent::init() {
	transform = &entity->getComponent<TransformComponent>();

	srcRect.x = srcRect.y = 0;
	srcRect.h = transform->height;
	srcRect.w = transform->width;
	destRect.w = destRect.h = 32 * scale;
}

void SpriteComponent::update() {
	destRect.x = static_cast<int>(transform->position.mx);
	destRect.y = static_cast<int>(transform->position.my);
	destRect.w = transform->width * transform->scale;
	destRect.h = transform->height * transform->scale;
}

void SpriteComponent::draw()  {
	TextureManager::draw(texture, srcRect, destRect);
}

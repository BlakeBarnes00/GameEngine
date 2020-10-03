#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(std::string tag) {
	this->tag = tag;
}

void ColliderComponent::init() {
	if (!entity->hasComponent<TransformComponent>()) {
		entity->addComponent<TransformComponent>();
	}
	transform = &entity->getComponent<TransformComponent>();

	Game::colliders.push_back(this);
}

void ColliderComponent::update() {
	collider.x = static_cast<int>(transform->position.mx);
	collider.y = static_cast<int>(transform->position.my);
	collider.w = transform->width * transform->scale;
	collider.h = transform->height * transform->scale;
}
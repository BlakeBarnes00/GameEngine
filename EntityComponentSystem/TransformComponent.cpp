#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	position.zero();
}

TransformComponent::TransformComponent(int sc)
{
	position.zero();
	scale = sc;
}

TransformComponent::TransformComponent(float x, float y)
{
	position.zero();
}

TransformComponent::TransformComponent(float x, float y, int scale)
{
	position.mx = x;
	position.my = y;
	this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y, int h, int w, int sc)
{
	position.mx = x;
	position.my = y;
	height = h;
	width = w;
	scale = sc;
}

void TransformComponent::init()
{
	velocity.zero();
}
void TransformComponent::update()
{
	position.mx += static_cast<int>(velocity.mx * speed);
	position.my += static_cast<int>(velocity.my * speed);
}
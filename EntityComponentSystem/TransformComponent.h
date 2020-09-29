#pragma once
#include "EntityComponentSystem.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent()
	{
		position.zero();
	}

	TransformComponent(int sc)
	{
		position.zero();
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.zero();
	}

	TransformComponent(float x, float y, int scale)
	{
		position.mx = x;
		position.my = y;
		this->scale = scale;
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.mx = x;
		position.my = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override
	{
		velocity.zero();
	}
	void update() override
	{
		position.mx += static_cast<int>(velocity.mx * speed);
		position.my += static_cast<int>(velocity.my * speed);
	}

};
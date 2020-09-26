#pragma once
#include "EntityComponentSystem.h"
#include "../Vector2D.h"
struct TransformComponent : public Component
{
	Vector2D position;
	Vector2D velocity;
	
	int speed = 3;

	TransformComponent() {
		init();
	}
	TransformComponent(float x, float y) {
		position.mx = x;
		position.my = y;
	}

	void init() override {
		velocity.mx = 0;
		velocity.my = 0;
		position.mx = 0;
		position.my = 0;
	}
	
	void update() override {
		position.mx += velocity.mx * speed;
		position.my += velocity.my * speed;
	}

	void setPosition(int x, int y) {
		position.mx = x;
		position.my = y;
	}

};

#pragma once
#include "EntityComponentSystem.h"
#include "../Vector2D.h"
struct TransformComponent : public Component
{
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;
	int speed = 3;

	TransformComponent() {
		init();
	}
	TransformComponent(float x, float y) {
		position.mx = x;
		position.my = y;
	}
	TransformComponent(float x, float y, int w, int h, int scale) {
		position.mx = x;
		position.my = y;
		height = h;
		width = w;
		this->scale = scale;
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
		std::cout << position.mx << "," << position.my << std::endl;

	}

	void setPosition(int x, int y) {
		position.mx = x;
		position.my = y;
	}

	void setPosition(int x, int y, int w, int h, int scale) {
		position.mx = x;
		position.my = y;

		width = w;
		height = h;
		this->scale = scale;

	}

};

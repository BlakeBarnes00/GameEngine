#pragma once
#include "EntityComponentSystem.h"
#include "../Vector2D.h"
struct TransformComponent : public Component
{
	Vector2D position;
	TransformComponent() {
		init();
	}
	TransformComponent(float x, float y) {
		position.mx = x;
		position.my = y;
	}

	void init() override {
		position.mx = 0;
		position.my = 0;
	}
	
	void update() override {
		
	}

	void setPosition(int x, int y) {
		position.mx = x;
		position.my = y;
	}

};

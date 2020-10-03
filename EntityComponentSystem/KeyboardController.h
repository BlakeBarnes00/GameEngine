#pragma once

#include "../Game.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;

	void init() override;
	void update() override;
};
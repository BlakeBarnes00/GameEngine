#pragma once
#include "EntityComponentSystem.h"

class PositionComponent : public Component
{
private:
	int xposition, yposition;

public:
	int x() { return xposition; }
	int y() { return yposition; }

	void init() override;
	void update() override;

	void setPosition(int x, int y);

};


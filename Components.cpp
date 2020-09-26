#include "Components.h"

void PositionComponent::init()
{
	xposition = 0;
	yposition = 0;
}

void PositionComponent::update()
{
	xposition++;
	yposition++;
}

void PositionComponent::setPosition(int x, int y)
{
	xposition = x;
	yposition = y;
}

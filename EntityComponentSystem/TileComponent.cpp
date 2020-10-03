#include "TileComponent.h"

TileComponent::TileComponent() {
}

TileComponent::TileComponent(int x, int y, int w, int h, int id) {
	tileRect.x = x;
	tileRect.y = y;
	tileRect.w = w;
	tileRect.h = h;
	tileID = id;

	switch (tileID)
	{
	case 0:
		path = "assets/water.png";
		break;
	case 1:
		path = "assets/dirt.png";
		break;
	case 2:
		path = "assets/grass.png";
		break;
	default:
		break;
	}
}

TileComponent::TileComponent(int x, int y, int id) {
	tileRect.x = x;
	tileRect.y = y;
	tileRect.w = 32;
	tileRect.h = 32;
	tileID = id;

	switch (tileID)
	{
	case 0:
		path = "assets/water.png";
		break;
	case 1:
		path = "assets/dirt.png";
		break;
	case 2:
		path = "assets/grass.png";
		break;
	default:
		break;
	}
}

void TileComponent::init() {
	entity->addComponent<TransformComponent>((int)tileRect.x, (int)tileRect.y, (int)tileRect.w, (int)tileRect.h, 1);
	transform = &entity->getComponent<TransformComponent>();

	entity->addComponent<SpriteComponent>(path);
	sprite = &entity->getComponent <SpriteComponent>();
}
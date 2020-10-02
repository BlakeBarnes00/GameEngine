#pragma once
#include "SDL.h"
#include "EntityComponentSystem/ColliderComponent.h"

class ColliderCompontent;

class Collision
{
public:
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
	static bool AABB(const ColliderComponent& a, const ColliderComponent& b);
};


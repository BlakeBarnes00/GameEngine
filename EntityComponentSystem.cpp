#include "EntityComponentSystem.h"

void Entity::update()
{
	for (auto& c : components) c->update();
	for (auto& c : components) c->draw();

}

void Entity::draw()
{
}

void Manager::update()
{
	for (auto& e : entities)
		e->update();
}

void Manager::draw()
{
	for (auto& e : entities)
		e->draw();
}

void Manager::refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity) {
		return !mEntity->isActive();
		}),
		std::end(entities));
}

Entity& Manager::addEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}

void Component::init()
{
}

void Component::update()
{
}

void Component::draw()
{
}

Component::~Component()
{
}

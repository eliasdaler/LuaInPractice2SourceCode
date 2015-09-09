#include "Entity.h"
#include "Component.h"

Entity::~Entity() {
    for (auto& c : components) {
        delete c.second;
    }
}

void Entity::addComponent(std::type_index type, Component* c) {
    components[type] = c;
}
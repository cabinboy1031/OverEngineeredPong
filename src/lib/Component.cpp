#include "Component.hpp"
#include "Actor.hpp"

void Violet::CollisionComponent::update(Actor& actor){
    Transform transform = actor.getTransform();
    collider->submit(transform);
}

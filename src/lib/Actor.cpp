#include "Actor.hpp"
using namespace Violet;
#include <iostream>

Actor::Actor() {
    m_Transform =
        {{0,0,0},
         {0,0,0,0},
         {1,1,1}};
}

/**
 * Update components and pass in arguments
 * */
void Actor::update(){
    for(std::pair<const char*, Component*> componentPair: m_ComponentList){
        componentPair.second->update(*this);
    }
}

/**
 * relative translations
 * */
void Actor::translate(Vector3 vec){
    Vector3 position = m_Transform.translation;
    position.x += vec.x;
    position.y += vec.y;
    position.z += vec.z;

    m_Transform.translation = position;
}
void Actor::rotate(Vector3 vec){
    /**
     * TODO yeahhhh not doing this until january.
     * I dont even need rotation until way later
     * */
     std::cerr << "ERROR: Not implemented yet" << std::endl;
}
void Actor::scale(Vector3 vec){
    Vector3 scale = m_Transform.scale;
    scale.x += vec.x;
    scale.y += vec.y;
    scale.z += vec.z;

    m_Transform.scale = scale;
}
/**
 * world coordinate translations
 * */
void Actor::setPosition(Vector3 vec){ m_Transform.translation = vec; }
void Actor::setRotation(Vector4 vec){m_Transform.rotation = vec; }
void Actor::setScale(Vector3 vec){ m_Transform.scale = vec; }
/**
 * position accessors
 * */
Transform& Actor::getTransform() {return m_Transform;}
Transform Actor::getTransform() const {return m_Transform;}
Vector3 Actor::getPosition() const { return getTransform().translation; }
Quaternion Actor::getRotation() const{ return getTransform().rotation; }
Vector3 Actor::getScale() const{ return getTransform().scale; }


void Actor::setComponent(const char* componentName, Component* component){
    delete m_ComponentList[componentName];
    m_ComponentList[componentName] = component;
}

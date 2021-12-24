#include "Actor.hpp"
using namespace Violet;
#include <iostream>

Actor::Actor():m_RenderComponent(new NullRenderComponent())
              ,m_PhysicsComponent(new NullPhysicsComponent())
              ,m_ColliderComponent(new NullCollisionComponent())
              ,m_ActorBehaviorComponent(new NullActorBehavior()){}

Actor::Actor(RenderComponent* mesh,
             PhysicsComponent* model,
             CollisionComponent* collider)
    :m_RenderComponent(mesh)
    ,m_PhysicsComponent(model)
    ,m_ColliderComponent(collider)
    ,m_ActorBehaviorComponent(new NullActorBehavior()){}

Actor::~Actor(){
    delete m_PhysicsComponent;
    delete m_RenderComponent;
    delete m_ColliderComponent;
    delete m_ActorBehaviorComponent;

}

/**
 * Update components and pass in arguments
 * */
void Actor::update(){
    m_PhysicsComponent->update(*this);
    m_ColliderComponent->update(*this);
    m_ActorBehaviorComponent->update(*this);
    m_RenderComponent->update(*this);
}

/**
 * relative translations
 * */
void Actor::translate(Vector3 vec){
    m_Position.x += vec.x;
    m_Position.y += vec.y;
    m_Position.z += vec.z;
}
void Actor::rotate(Vector3 vec){
    /**
     * TODO yeahhhh not doing this until january.
     * I dont even need rotation until way later
     * */
     std::cerr << "ERROR: Not implemented yet" << std::endl;
}
void Actor::scale(Vector3 vec){
    m_Scale.x += vec.x;
    m_Scale.y += vec.y;
    m_Scale.z += vec.z;
}
/**
 * world coordinate translations
 * */
void Actor::set_position(Vector3 vec){ m_Position = vec; }
void Actor::set_rotation(Vector4 vec){m_Rotation = vec; }
void Actor::set_scale(Vector3 vec){ m_Scale = vec; }
/**
 * position accessors
 * */
Vector3 Actor::get_position() const { return m_Position; }
Vector4 Actor::get_rotation() const{ return m_Rotation; }
Vector3 Actor::get_scale() const{ return m_Scale; }

/**
 * swapping out components
 * */
void Actor::setRenderComponent(RenderComponent& mesh){
    delete m_RenderComponent;
    m_RenderComponent = &mesh;
}

void Actor::setPhysicsComponent(PhysicsComponent& model){
    delete m_PhysicsComponent;
    m_PhysicsComponent = &model;
}
void Actor::setColliderComponent(CollisionComponent& collider){
    delete m_ColliderComponent;
    m_ColliderComponent = &collider;
}

void Actor::setBehaviorComponent(ActorBehavior &behavior){
    delete m_ActorBehaviorComponent;
    m_ActorBehaviorComponent = &behavior;
}

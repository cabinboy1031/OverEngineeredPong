#ifndef VIOLET_PHYSICS_HPP
#define VIOLET_PHYSICS_HPP
#include <vector>
#include <raylib.h>

namespace Violet {
    class Actor;
    struct CollisionData {
        Vector3 A;
        Vector3 B;
        Vector3 Normal;
        float Depth;
        bool hasCollision;
    };

    class Collider{
        virtual CollisionData TestCollisions(Actor* transform, Collider* targetCollider, Actor* targetTransform){
            return this->TestCollisions(transform, targetCollider, targetTransform);
        }
    };

    class PhysicsModel{
        virtual void physicsUpdate(){}
    };

    class PhysicsWorld{
        public:
            void addObject(Actor* actor);
            void removeObject(Actor* actor);
            void physicsTick(){}
            void collisionTick(){}
        private:
            std::vector<Collider*> m_ColliderList;
            std::vector<Model*> m_PhysicsModelList;
    };

    class PhysicsComponent: public PhysicsModel {
        public:
            PhysicsComponent() = default;
            PhysicsComponent(const PhysicsComponent& in) = default;
            PhysicsComponent(PhysicsComponent&& in) = default;
            virtual ~PhysicsComponent() {}

            virtual void update(Actor& actor) = 0;
    };

    class NullPhysicsComponent:public PhysicsComponent {
        public:
            virtual void update(Actor& actor) override {}
    };

    class CollisionComponent: public Collider {
        public:
            CollisionComponent() = default;
            CollisionComponent(const CollisionComponent&) = default;
            CollisionComponent(CollisionComponent&&) = default;
            virtual ~CollisionComponent(){}

            virtual void update(Actor& actor) = 0;
            bool isColliding(){return m_IsColliding;}
        protected:
            bool m_IsColliding = false;
    };

    class NullCollisionComponent:public CollisionComponent{
        public:
            virtual void update(Actor& actor) override {}
    };
}

#endif // VIOLET_PHYSICS_HPP

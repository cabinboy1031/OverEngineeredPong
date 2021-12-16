#ifndef VIOLET_ACTOR_HPP
#define VIOLET_ACTOR_HPP
/**
 * Actor interface for game objects.
 * Actors will always have a way to be positioned, rotated, and scaled.
 * TODO Actors will also store its physics state which allows for velocity and momentum to be set.
 * TODO Actors will also have the ability to carry a list of components that are accessible through tag
 * */
#include <raylib.h>

#include "util/Rendering.hpp"
#include "util/Physics.hpp"
#include "util/Collision.hpp"

namespace Violet {
        class Actor {
                public:
                        Actor();
                        Actor(RenderComponent* mesh,
                              PhysicsComponent* model,
                              CollisionComponent* collider);
                        virtual ~Actor();

                        /**
                        * Update components and pass in arguments
                        * */
                        virtual void update();

                        /**
                         * relative translations
                         * */
                        virtual void translate(Vector3 vec);
                        virtual void rotate(Vector3 vec);
                        virtual void scale(Vector3 vec);
                        /**
                         * world coordinate translations
                         * */
                        virtual void set_position(Vector3 vec);
                        virtual void set_rotation(Vector4 vec);
                        virtual void set_scale(Vector3 vec);
                        /**
                         * position accessors
                         * */
                        virtual Vector3 get_position() const;
                        virtual Vector4 get_rotation() const;
                        virtual Vector3 get_scale() const;

                        /**
                         * swapping out components
                         * */
                        virtual void setRenderComponent(RenderComponent& mesh);
                        virtual void setPhysicsComponent(PhysicsComponent& model);
                        virtual void setColliderComponent(CollisionComponent& collider);

                        /**
                         * using components in a specific object
                         * */
                        inline virtual RenderComponent& getRenderComponent() { return *m_RenderComponent; }
                        inline virtual RenderComponent& getRenderComponent() const { return *m_RenderComponent; }
                        inline virtual PhysicsComponent& getPhysicsComponent() { return *m_PhysicsComponent; }
                        inline virtual PhysicsComponent& getPhysicsComponent() const { return *m_PhysicsComponent; }
                        inline virtual CollisionComponent& getCollisionComponent() { return *m_ColliderComponent; }
                        inline virtual CollisionComponent& getCollisionComponent() const { return *m_ColliderComponent; }
                protected:
                        RenderComponent *m_RenderComponent;
                        PhysicsComponent *m_PhysicsComponent;
                        CollisionComponent *m_ColliderComponent;

                        Vector3 m_Position;
                        Vector4 m_Rotation;
                        Vector3 m_Scale;
        };
}

#endif // VIOLET_ACTOR_HPP

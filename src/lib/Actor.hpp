#ifndef VIOLET_ACTOR_HPP
#define VIOLET_ACTOR_HPP
/**
 * Actor interface for game objects.
 * Actors will always have a way to be positioned, rotated, and scaled.
 * TODO Actors will also store its physics state which allows for velocity and momentum to be set.
 * TODO Actors will also have the ability to carry a list of components that are accessible through tag
 * */
#include <map>
#include <raylib.h>

#include "Rendering/Rendering.hpp"
#include "ActorBehavior.hpp"

namespace Violet {
        class Actor {
                public:
                        Actor();
                        ~Actor();

                        /**
                        * Update components and pass in arguments
                        * */
                        void update();

                        /**
                         * relative translations
                         * */
                        void translate(Vector3 vec);
                        void rotate(Vector3 vec);
                        void scale(Vector3 vec);
                        /**
                         * world coordinate translations
                         * */
                        void setPosition(Vector3 vec);
                        void setRotation(Vector4 vec);
                        void setScale(Vector3 vec);
                        /**
                         * position accessors
                         * */
                        Transform& getTransform();
                        Transform getTransform() const;
                        Vector3 getPosition() const;
                        Quaternion getRotation() const;
                        Vector3 getScale() const;

                        /**
                         * Sets and resets components.
                         * If component exists at that name, deletes the old component.
                         * */
                        void setComponent(const char* componentName, Component* component);
                        Component& getComponent(const char* componentName){ return *m_ComponentList[componentName];}


                        Actor* create(){
                                Actor* newActor = new Actor();
                                return newActor;
                        };
                protected:
                        std::map<const char*,Component*> m_ComponentList;

                        Transform m_Transform;

        };
}

#endif // VIOLET_ACTOR_HPP

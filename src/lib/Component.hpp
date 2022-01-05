#ifndef VIOLET_COMPONENT_HPP
#define VIOLET_COMPONENT_HPP
/**
 * ActorComponent class.
 * Components are the behavior and lifeblood of the engine.
 * An actor gives data directly to the component.
 * The component updates its own state or whatever state the component is responsible for.
 *
 * the collision component shows an example of how the class is used.
 * Components can hold their own state, or contain a pointer to an object to allow for
 * more separation between game objects and states between render/physics threads
 *
 * Programming design should allow for generic component updating.
 * rather than explicitly calling methods of children objects.
 *
 * If a child object needs to be read from, use a dynamic_cast to the object
 * and allow Accessors to the required state.
 **/

namespace Violet {
    class Actor;
    class Component {
        public:
            /**
             * Update Component state based on actor data.
             **/
            virtual void update(Actor& actor) = 0;
            virtual ~Component() {}
    };

    /** NullObject to prevent the need to check for null */
    class NullComponent: public Component {
            virtual void update(Actor& actor) override {}
    };

    /*
    /**
     * CollisionComponent holds a pointer to a collider object to allow for
     * Colliders to automatically change state based on actor position.
     * Implementations may be allowed to wait for a small time if data is being read by somewhere else.
     * *\/
    class CollisionComponent: public Component {
        public:
            virtual ~CollisionComponent(){}

            // Should submit data to collider, updating actor may be allowed if collider provides
            // specific data
            virtual void update(Actor& actor) override;
            bool isColliding(){return m_IsColliding;}
        protected:
            Collider* collider;
            bool m_IsColliding = false;
    };

    class NullCollisionComponent:public CollisionComponent{
        public:
            virtual void update(Actor& actor) override {}
    };
    */
}


#endif // VIOLET_COMPONENT_HPP

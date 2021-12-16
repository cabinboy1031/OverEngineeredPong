#ifndef VIOLET_PHYSICS_HPP
#define VIOLET_PHYSICS_HPP

namespace Violet {
    class Actor;
    class PhysicsComponent {
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
}

#endif // VIOLET_PHYSICS_HPP

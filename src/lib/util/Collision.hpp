#ifndef VIOLET_COLLISION_HPP
#define VIOLET_COLLISION_HPP

namespace Violet {
    class Actor;
    class CollisionComponent {
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

#endif // VIOLET_COLLISION_HPP

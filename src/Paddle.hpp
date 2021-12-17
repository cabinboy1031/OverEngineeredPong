#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "lib/Actor.hpp"

class PaddleRenderComponent: public Violet::RenderComponent{
    public:
        PaddleRenderComponent(){}
        virtual void update(Violet::Actor& actor) override {
            m_PosX = actor.get_position().x;
            m_PosY = actor.get_position().y;
        }

        virtual void draw() override{
            DrawRectangle(m_PosX, m_PosY, m_PaddleWidth, m_PaddleHeight, MAROON);
        }
    private:
        int m_PaddleWidth = 20, m_PaddleHeight = 60;
        int m_PosX, m_PosY;
};

class RectangleCollisionComponent: public Violet::CollisionComponent{
    public:
        virtual void update(Violet::Actor& actor) override {

        }
    private:
};

Violet::Actor* createPaddleActor(float x, float y){
    Violet::Actor* newActor = new Violet::Actor(
        new PaddleRenderComponent(),
        new Violet::NullPhysicsComponent(),
        new RectangleCollisionComponent()
);

    Vector3 position({x, y, 0});
    newActor->set_position(position);
    return newActor;
}

#endif

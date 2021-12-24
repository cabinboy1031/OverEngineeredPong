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

class Paddle: public Violet::ActorBehavior {
        public:
        void setup(){

        }

        void update(Violet::Actor& object){
            if(IsKeyDown('W')){
                object.translate(Vector3({0,-5,0}));
            }
            if(IsKeyDown('S')){
                object.translate(Vector3({0,5,0}));
            }

            Vector3 position = object.get_position();
            float screenHeight = GetScreenHeight();
            if((position.y > GetScreenHeight() - 60)){
                object.set_position({position.x, screenHeight - 60, position.z });
            }
            if((position.y < 0)){
                object.set_position({position.x, 0, position.z });
            }

            if(object.getCollisionComponent().isColliding()){

            }
        }


        //void setInputHandler(InputHandler* handler){
        //}
};

Violet::Actor* createPaddleActor(float x, float y, Violet::ActorBehavior* behavior = new Violet::NullActorBehavior()){
    Violet::Actor* newActor = new Violet::Actor(
        new PaddleRenderComponent(),
        new Violet::NullPhysicsComponent(),
        new RectangleCollisionComponent()
);
    newActor->setBehaviorComponent(*behavior);

    Vector3 position({x, y, 0});
    newActor->set_position(position);
    return newActor;
}

#endif

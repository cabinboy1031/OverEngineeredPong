#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "lib/Actor.hpp"
#include "lib/Rendering/RenderComponent.hpp"

class PaddleDrawable: public Violet::Drawable{
    public:
        PaddleDrawable(){}
        virtual void submit(Transform& transform) override {
            m_PosX = transform.translation.x;
            m_PosY = transform.translation.y;

        }

        virtual void draw() override{
            DrawRectangle(m_PosX, m_PosY, m_PaddleWidth, m_PaddleHeight, m_Color);
        }
    private:
        int m_PaddleWidth = 20, m_PaddleHeight = 60;
        int m_PosX, m_PosY;
        Color m_Color = MAROON;
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

            Vector3 position = object.getPosition();
            float screenHeight = GetScreenHeight();
            if((position.y > GetScreenHeight() - 60)){
                object.setPosition({position.x, screenHeight - 60, position.z });
            }
            if((position.y < 0)){
                object.setPosition({position.x, 0, position.z });
            }
        }


        //void setInputHandler(InputHandler* handler){
        //}
};

Violet::Actor* createPaddleActor(float x, float y, Violet::ActorBehavior* behavior = new Violet::NullActorBehavior()){
    Violet::Actor* newActor = new Violet::Actor();
    newActor->setComponent("renderComponent", new Violet::RenderComponent(new PaddleDrawable()));
    newActor->setComponent("behaviorComponent",behavior);

    Vector3 position({x, y, 0});
    newActor->setPosition(position);
    return newActor;
}

#endif

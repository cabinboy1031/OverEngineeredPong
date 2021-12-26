#ifndef BALL_H_
#define BALL_H_
#include "lib/Actor.hpp"

class BallRenderComponent: public Violet::RenderComponent{
    public:
    BallRenderComponent() {}
    virtual void update(Violet::Actor& actor) override{
      m_PosX = actor.get_position().x;
      m_PosY = actor.get_position().y;
    }

    virtual void draw(){
      DrawCircle(m_PosX, m_PosY, m_Radius, WHITE);
    }
    private:
    int m_Radius = 5;
    int m_PosX, m_PosY;
};

class CircleCollisionComponent: public Violet::CollisionComponent{
    virtual void update(Violet::Actor& actor) override {

    }
};

class Ball: public Violet::ActorBehavior{
    public:
    void setup(){
      m_XVel = 200.0f;
      m_YVel = 200.0f;
    }
    void update(Violet::Actor& actor){
      Vector3 position = actor.get_position();

      if(position.x + 5>= GetScreenWidth() || position.x - 5 <= 0){
        m_XVel = -m_XVel;
      }
      if(position.y + 5 >= GetScreenHeight() || position.y - 5  <= 0){
        m_YVel = -m_YVel;
      }
      actor.set_position({position.x + (m_XVel * GetFrameTime()),position.y + (m_YVel * GetFrameTime()), 0});

    if(actor.getCollisionComponent().isColliding()){
      m_XVel = -m_XVel;
    }
    }
    private:
    float m_XVel, m_YVel;
};

Violet::Actor* createBallActor(float x, float y, Violet::ActorBehavior* behavior = new Ball()){
  Violet::Actor* newActor = new Violet::Actor(
    new BallRenderComponent(),
    new Violet::NullPhysicsComponent(),
    new CircleCollisionComponent()
    );
  newActor->setBehaviorComponent(*behavior);

  newActor->set_position({x, y, 0});
  return newActor;
};


#endif // BALL_H_

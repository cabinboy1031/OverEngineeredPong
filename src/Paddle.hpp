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
        int m_PaddleWidth = 20, m_PaddleHeight = 30;
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
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

#endif

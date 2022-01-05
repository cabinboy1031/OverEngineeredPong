#include <iostream>
#include <vector>
#include <raylib.h>
#include "Paddle.hpp"
#include "Ball.hpp"

using namespace std;
int main(int argc, char *argv[]) {

// Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    std::vector<Violet::Actor*> levelObjects = {
    createPaddleActor(40, 40, new Paddle),
    createPaddleActor(screenWidth - 60, 40),
    createBallActor(screenWidth/2,screenHeight/2)
};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    //
    // Actor and game setup
    for(Violet::Actor* object: levelObjects){
        dynamic_cast<Violet::ActorBehavior&>(object->getComponent("behaviorComponent")).setup();
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        for(Violet::Actor* object: levelObjects){
            object->update();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            for(Violet::Actor* object: levelObjects){
                dynamic_cast<Violet::RenderComponent&>(object->getComponent("renderComponent")).draw();
            }

            DrawText("11", (screenWidth/2) - 40, 10, 20, RAYWHITE);
            DrawText("12", (screenWidth/2) + 20, 10, 20, RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

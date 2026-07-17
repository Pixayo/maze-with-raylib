#include "raylib.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "example");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        
        // Update

        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}

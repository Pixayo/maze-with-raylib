#include "maze.hpp"

int main()
{
    const int screenWidth = WIDTH * CELL_SIZE + (2 * MARGIN);
    const int screenHeight = HEIGHT * CELL_SIZE + (2 * MARGIN);
    
    InitWindow(screenWidth, screenHeight, "maze-with-raylib");
    SetTargetFPS(60);

    Cell grid[HEIGHT][WIDTH];
    initialize_grid(grid);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_maze(grid);
        draw_cell_inspector(grid);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

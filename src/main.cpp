#include "maze.hpp"

#define RAYGUI_IMPLEMENTATION

int main()
{
    const int screenWidth  = (WIDTH * CELL_SIZE) + (2 * MARGIN);
    const int screenHeight = (HEIGHT * CELL_SIZE) + (2 * MARGIN);
    
    // NOTE: Height and Width are inverted here
    InitWindow(screenHeight, screenWidth, "maze-with-raylib");
    
    SetTargetFPS(60);

    Cell grid[HEIGHT][WIDTH];
    initialize_grid(grid);

    while (!WindowShouldClose()) 
    {
        if (IsKeyPressed(KEY_R)) 
        {
            generate_maze_dfs(grid, 1, 1);
        }
        
        BeginDrawing();

            ClearBackground(BLACK);
            draw_maze(grid);
            draw_cell_inspector(grid);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

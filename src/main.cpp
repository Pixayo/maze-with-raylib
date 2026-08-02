#define RAYGUI_IMPLEMENTATION

#include "maze.hpp"

int main()
{
    const int screenHeight = (HEIGHT * CELL_SIZE) + (2 * MARGIN);
    const int screenWidth  = (WIDTH * CELL_SIZE) + (2 * MARGIN);
    
    // NOTE: Height and Width are inverted here
    InitWindow(screenHeight, screenWidth, "maze-with-raylib");
    
    SetTargetFPS(60);

    Cell grid[HEIGHT][WIDTH];
    initialize_grid(grid);
    generate_maze_dfs(grid, 1, 1);

    Point start = {1, 0};
    Point end   = {WIDTH - 2, HEIGHT - 1};

    while (!WindowShouldClose()) 
    {
        if (IsKeyPressed(KEY_R)) 
        {
            restart_grid(grid);
            generate_maze_dfs(grid, 1, 1);
        }
        if (IsKeyPressed(KEY_S))
        {
            solve_maze_bfs(grid, start, end);
        }
        
        BeginDrawing();

            ClearBackground(BLACK);
            draw_instructions();
            draw_maze(grid);
            draw_cell_inspector(grid);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

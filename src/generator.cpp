#include "raylib.h" // GetRandomValue()
#include "generator.hpp"

static void shuffle_directions(int dirs[4][2]) {
    for (int i = 3; i > 0; i--)
    {
        int j = GetRandomValue(0, i) % (i + 1);
        
        int tempX = dirs[i][0];
        dirs[i][0] = dirs[j][0];
        dirs[j][0] = tempX;

        int tempY = dirs[i][1];
        dirs[i][1] = dirs[j][1];
        dirs[j][1] = tempY;
    }
}

static void dfs_step(Cell grid[HEIGHT][WIDTH], int currentX, int currentY) {
    grid[currentY][currentX].wasVisited = true;
    grid[currentY][currentX].isWall = false;

    int dirs[4][2] = {
        {0, -2},  // Norte
        {0, 2},   // Sul
        {2, 0},   // Leste
        {-2, 0}   // Oeste
    };

    shuffle_directions(dirs);

    for (int i = 0; i < 4; i++) 
    {
        int nextX = currentX + dirs[i][0];
        int nextY = currentY + dirs[i][1];

        if ((nextX > 0 && nextX < WIDTH - 1) && (nextY > 0 && nextY < HEIGHT - 1))
        {
            if (!grid[nextY][nextX].wasVisited)
            {
                
                int wallX = currentX + (dirs[i][0] / 2);
                int wallY = currentY + (dirs[i][1] / 2);
                grid[wallY][wallX].isWall = false;

                dfs_step(grid, nextX, nextY);
            }
        }
    }
}

void set_entrance_and_exit(Cell grid[HEIGHT][WIDTH]) {
    grid[0][1].isWall = false;
    grid[0][1].type = START;

    grid[HEIGHT - 1][WIDTH - 2].isWall = false;
    grid[HEIGHT - 1][WIDTH - 2].type = END;
}

void generate_maze_dfs(Cell grid[HEIGHT][WIDTH], int startX, int startY)
{
    for (int y = 0; y < HEIGHT; y++) 
    {
        for (int x = 0; x < WIDTH; x++) 
        {
            grid[y][x].isWall = true;
            grid[y][x].wasVisited = false;
        }
    }
    
    set_entrance_and_exit(grid);

    if (startX % 2 == 0) startX++;
    if (startY % 2 == 0) startY++;

    dfs_step(grid, startX, startY);
}
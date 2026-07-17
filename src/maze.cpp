#include "maze.hpp"

void initialize_grid(Cell grid[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++) 
    {
        for(int j = 0; j < WIDTH; j++)
        {
            Cell cell = Cell(i, j);

            cell.isWall = isMazeBorder(cell);

            grid[i][j] = cell;
        }
    }
}

void draw_maze(Cell grid[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++) 
    {
        for(int j = 0; j < WIDTH; j++)
        {
            Color color = grid[i][j].isWall ? GRAY : BLACK;

            int posX = MARGIN + i * CELL_SIZE;
            int posY = MARGIN + j * CELL_SIZE;

            DrawRectangle(
                posX, 
                posY, 
                CELL_SIZE, 
                CELL_SIZE, 
                color
            );
            DrawRectangleLines(
                posX, 
                posY, 
                CELL_SIZE, 
                CELL_SIZE, 
                GRAY
            );
        }
    }
} 

bool isMazeBorder(Cell cell)
{
    return ((cell.x == 0 || cell.x == HEIGHT - 1) || (cell.y == 0 || cell.y == WIDTH - 1));
}
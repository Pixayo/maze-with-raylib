#include "grid.hpp"

void initialize_grid(Cell grid[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++) 
    {
        for(int j = 0; j < WIDTH; j++)
        {
            Cell cell = Cell(i, j);

            // cell.isWall = isMazeBorder(cell);

            grid[i][j] = cell;
        }
    }
}

bool isMazeBorder(Cell cell)
{
    return ((cell.x == 0 || cell.x == HEIGHT - 1) || (cell.y == 0 || cell.y == WIDTH - 1));
}
// if not defined
#ifndef MAZE_HPP
#define MAZE_HPP

#include "raylib.h"

#define HEIGHT    30
#define WIDTH     30
#define CELL_SIZE 16
#define MARGIN    (CELL_SIZE * 2)


class Cell 
{
public:
    int x;
    int y;
    bool isWall = false;
    bool wasVisited = false; 

    Cell() = default;
    Cell(int x, int y) : x(x), y(y) {}
};

void initialize_grid(Cell grid[HEIGHT][WIDTH]);
void draw_maze(Cell grid[HEIGHT][WIDTH]);
bool isMazeBorder(Cell cell);

#endif


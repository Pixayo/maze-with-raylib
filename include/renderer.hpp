#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "raygui.h"
#include "raymath.h"

#include "cell.hpp"
#include "grid.hpp"

const int CELL_SIZE = 16;
const int MARGIN    = (CELL_SIZE * 3);

void draw_cell(Cell& cell);
void draw_cell_inspector(Cell grid[HEIGHT][WIDTH]);
void draw_maze(Cell grid[HEIGHT][WIDTH]);

#endif
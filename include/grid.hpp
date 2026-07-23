#ifndef GRID_HPP
#define GRID_HPP

#include "cell.hpp"

const int HEIGHT = 30;
const int WIDTH  = 30;

void initialize_grid(Cell grid[HEIGHT][WIDTH]);
bool isMazeBorder(Cell cell);

#endif
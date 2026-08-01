#ifndef GRID_HPP
#define GRID_HPP

#include "cell.hpp"

const int HEIGHT = 31;
const int WIDTH  = 31;

void initialize_grid(Cell grid[HEIGHT][WIDTH]);
bool isMazeBorder(Cell cell);

#endif // GRID_HPP
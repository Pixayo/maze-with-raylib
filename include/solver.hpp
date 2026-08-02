#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "grid.hpp"

bool solve_maze_bfs(Cell grid[HEIGHT][WIDTH], Point start, Point end);

#endif // SOLVER_HPP
#include "solver.hpp"
#include <queue>

bool solve_maze_bfs(Cell grid[HEIGHT][WIDTH], Point start, Point end) {
    bool visited[HEIGHT][WIDTH] = {false};
    Point parent[HEIGHT][WIDTH];

    int dirs[4][2] = {
        {0, -1}, // Norte
        {0, 1},  // Sul
        {1, 0},  // Leste
        {-1, 0}  // Oeste
    };

    std::queue<Point> q;

    q.push(start);
    visited[start.y][start.x] = true;
    parent[start.y][start.x] = {-1, -1}; // O início não tem pai

    bool found = false;

    // BFS
    while (!q.empty()) 
    {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) 
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) 
        {
            int nextX = curr.x + dirs[i][0];
            int nextY = curr.y + dirs[i][1];

            if (nextX >= 0 && nextX < WIDTH && nextY >= 0 && nextY < HEIGHT) 
            {
                if (!grid[nextY][nextX].isWall && !visited[nextY][nextX]) 
                {
                    visited[nextY][nextX] = true;
                    parent[nextY][nextX] = curr;
                    q.push({nextX, nextY});
                }
            }
        }
    }

    if (found) 
    {
        Point curr = end;
        
        while (curr.x != -1 && curr.y != -1) 
        {
            grid[curr.y][curr.x].inPath = true;
            curr = parent[curr.y][curr.x];
        }
        return true;
    }

    return false;
}
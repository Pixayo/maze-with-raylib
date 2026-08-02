#ifndef CELL_HPP
#define CELL_HPP

enum CellType {
    PATH, WALL, START, END
};

class Cell 
{
public:
    int x;
    int y;
    bool isWall = false;
    bool wasVisited = false; 
    CellType type;

    Cell() {};
    Cell(int x, int y) : x(x), y(y) {};
};

#endif // CELL_HPP
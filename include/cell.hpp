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
    bool inPath = false;
    CellType type;

    Cell() {};
    Cell(int x, int y) : x(x), y(y) {};

    void restart(int _x, int _y)
    {
        x = _x;
        y = _y;
        isWall = false;
        wasVisited = false;
        inPath = false;
        type = PATH;
    }
};

class Point
{
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

#endif // CELL_HPP
#ifndef CELL_HPP
#define CELL_HPP

// TODO: use vector2 instead of int variables

class Cell 
{
public:
    int x;
    int y;
    bool isWall = false;
    bool wasVisited = false; 

    Cell() {};
    Cell(int x, int y) : x(x), y(y) {};
};

#endif
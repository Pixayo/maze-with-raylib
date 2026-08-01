#ifndef CELL_HPP
#define CELL_HPP

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

#endif // CELL_HPP
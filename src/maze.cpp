#include "maze.hpp"

void initialize_grid(Cell grid[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++) 
    {
        for(int j = 0; j < WIDTH; j++)
        {
            Cell cell = Cell(i, j);

            cell.isWall = isMazeBorder(cell);

            grid[i][j] = cell;
        }
    }
}

bool isMazeBorder(Cell cell)
{
    return ((cell.x == 0 || cell.x == HEIGHT - 1) || (cell.y == 0 || cell.y == WIDTH - 1));
}

void draw_maze(Cell grid[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++) 
    {
        for(int j = 0; j < WIDTH; j++)
        {
            draw_cell(grid[i][j]);
        }
    }
}

void draw_cell(Cell& cell) 
{
    Color inside = cell.isWall ? GRAY : BLACK;
    Color outside = GRAY;

    int posX = MARGIN + cell.x * CELL_SIZE;
    int posY = MARGIN + cell.y * CELL_SIZE;

    int hoverX = (GetMouseX() - MARGIN) / CELL_SIZE;
    int hoverY = (GetMouseY() - MARGIN) / CELL_SIZE;

    if (GetMouseX() < MARGIN) hoverX = -1;
    if (GetMouseY() < MARGIN) hoverY = -1;

    if((cell.x == hoverX && cell.y == hoverY) && (hoverX < MARGIN && hoverY < MARGIN))
    {
        inside = GREEN;
        outside = GREEN;
    }

    DrawRectangle(
        posX, 
        posY, 
        CELL_SIZE, 
        CELL_SIZE, 
        inside
    );
    DrawRectangleLines(
        posX, 
        posY, 
        CELL_SIZE, 
        CELL_SIZE, 
        outside
    );
}

void draw_cell_inspector(Cell grid[HEIGHT][WIDTH])
{
int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    int hoverI = (mouseX - MARGIN) / CELL_SIZE;
    int hoverJ = (mouseY - MARGIN) / CELL_SIZE;

    if (mouseX < MARGIN) hoverI = -1;
    if (mouseY < MARGIN) hoverJ = -1;

    if (hoverI >= 0 && hoverI < HEIGHT && hoverJ >= 0 && hoverJ < WIDTH) 
    {
        Cell cell = grid[hoverI][hoverJ];

        int menuWidth = 140;
        int menuHeight = 75;
        
        // 1. Posição ideal do menu com um deslocamento em relação ao cursor
        int menuX = mouseX + 5;
        int menuY = mouseY + 5;

        // 2. Define a zona interna de restrição (distância mínima dos limites da janela)
        const int padding = 10; 

        // 3. Restringe o eixo X dentro do limite esquerdo e direito da zona interna
        if (menuX < padding) 
        {
            menuX = padding;
        }
        else if (menuX + menuWidth > GetScreenWidth() - padding) 
        {
            menuX = GetScreenWidth() - menuWidth - padding;
        }

        // 4. Restringe o eixo Y dentro do limite superior e inferior da zona interna
        if (menuY < padding) 
        {
            menuY = padding;
        }
        else if (menuY + menuHeight > GetScreenHeight() - padding) 
        {
            menuY = GetScreenHeight() - menuHeight - padding;
        }

        // Renderização do menu (Fundo e Textos)
        DrawRectangle(menuX, menuY, menuWidth, menuHeight, CLITERAL(Color){ 20, 20, 20, 230 });
        DrawRectangleLines(menuX, menuY, menuWidth, menuHeight, RAYWHITE);

        int textOffset = 8;
        int fontSize = 14;

        DrawText(
            TextFormat("{%d, %d}", cell.x, cell.y), 
            menuX + 10, 
            menuY + textOffset, 
            fontSize, 
            LIGHTGRAY
        );
        
        Color wallColor = cell.isWall ? RED : GREEN;
        DrawText(
            TextFormat("Wall: %s", cell.isWall ? "true" : "false"), 
            menuX + 10, 
            menuY + textOffset + 20, 
            fontSize, 
            wallColor
        );
        
        Color visitedColor = cell.wasVisited ? GOLD : LIGHTGRAY;
        DrawText(TextFormat("Visited: %s", cell.wasVisited ? "true" : "false"), menuX + 10, menuY + textOffset + 40, fontSize, visitedColor);
    }
}
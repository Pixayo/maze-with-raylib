#include "renderer.hpp"

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

        float menuWidth = 140.0f;
        float menuHeight = 85.0f;
        const float padding = 10.0f; 

        // Restringe o inspector aos limites da janela (substitui os vários 'if' manuais)
        float menuX = Clamp((float)mouseX + 10, padding, GetScreenWidth() - menuWidth - padding);
        float menuY = Clamp((float)mouseY + 10, padding, GetScreenHeight() - menuHeight - padding);

        Rectangle bounds = { menuX, menuY, menuWidth, menuHeight };

        // 1. Desenha o painel container (fundo, borda e cabeçalho estilizados pelo Raygui)
        GuiPanel(bounds, "Cell Info");

        // 2. Renderiza as informações da célula utilizando GuiLabel
        GuiLabel((Rectangle){ menuX + 10, menuY + 25, menuWidth - 20, 15 }, 
                 TextFormat("Pos: {%d, %d}", cell.x, cell.y));

        GuiLabel((Rectangle){ menuX + 10, menuY + 42, menuWidth - 20, 15 }, 
                 TextFormat("Wall: %s", cell.isWall ? "true" : "false"));

        GuiLabel((Rectangle){ menuX + 10, menuY + 59, menuWidth - 20, 15 }, 
                 TextFormat("Visited: %s", cell.wasVisited ? "true" : "false"));
    }
}

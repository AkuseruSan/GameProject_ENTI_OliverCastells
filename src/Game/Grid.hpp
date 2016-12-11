#include "GameObject.hpp"
#include "Cell.hpp"
#include "GameEngine.hpp"

class Grid
{
public:
	Grid();

	Cell* cells[GRID_WIDTH][GRID_HEIGHT];
};

Grid::Grid()
{
	Vector worldPos;
	
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; i < GRID_HEIGHT; j++)
		{
			worldPos = { SCREEN_SIZE.x / GRID_WIDTH * i, SCREEN_SIZE.y / GRID_HEIGHT * j };
			cells[i][j] = new Cell(Vector{ i, j }, worldPos);
		}

	}
}
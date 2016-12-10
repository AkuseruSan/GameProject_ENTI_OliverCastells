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
	for each (Cell* c in cells)
	{
		c = new Cell();
	}
}
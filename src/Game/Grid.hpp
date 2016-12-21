#include "System.hpp"
#include "Vector.hpp"

class Grid
{
private:
	int xSize;
	int ySize;

public:
	Grid(){}
	Grid(int xS, int yS)
	{
		xSize = xS;
		ySize = yS;
	}

	Vector GetWorldPosition(int xPosIndex, int yPosIndex)
	{
		return Vector{ (xSize - xPosIndex)*CELL_WIDTH, (ySize - yPosIndex)*CELL_HEIGHT };
	}
};

class Cell
{
private:
	int posX;
	int posY;
public:
	Cell(Grid* g)
	{

	}
};
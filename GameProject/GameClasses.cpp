#include <stdio.h>
#include <vector>

using namespace std;

enum CellContinentType {EMPTY, CANDY};
enum CellObjectType {NORMAL_CANDY, STRIPED_CANDY, WRAPED_CANDY};

struct Vector
{
	float x, y;
};

struct Vector
{
	int x, y;
};

class Grid
{
	Vector size;//Columns and rows.

	int** table;
	
	Grid() {

	}

	~Grid() {//Class Destructor

	}

	void InitTable()
	{

	}
};

class CellObject
{
	CellObjectType type;

	CellObject(CellObjectType t) {
		type = t;
	}
};

class Cell
{
	CellContinentType type;

	CellObject object;

	Cell() {

	}

	void Init()
	{

	}
};



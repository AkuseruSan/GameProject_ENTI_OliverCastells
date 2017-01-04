#include "System.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <list>

class Grid
{
private:
	int w, h;
	GameObject* gameObjectsGrid[GRID_LINES][GRID_COLUMNS];

public:
	Grid() {

	}
	Grid(int a)//Will need to ask for an XML Node
	{
		w = GRID_LINES;
		h = GRID_COLUMNS;
		
		for (int i = 0; i < GRID_LINES; i++)
		{
			for (int j = 0; j < GRID_COLUMNS; j++)
			{
				gameObjectsGrid[i][j] = new GameObject(CELL_WIDTH*i, CELL_HEIGHT*j, CELL_WIDTH, CELL_HEIGHT, R.GetTexture(ATLAS_TEXTURE.key));

			}
		}
	}

	Vector GetSize()
	{
		return Vector{ w,h };
	}
	GameObject* GetObjectFromGrid(int i, int j)
	{
		return gameObjectsGrid[i][j];
	}

	void Update()
	{
		for (int i = 0; i < GRID_LINES; i++)
		{
			for (int j = 0; j < GRID_COLUMNS; j++)
			{
				gameObjectsGrid[i][j]->Update();
			}
		}
	}

	void Draw()
	{
		for (int i = 0; i < GRID_LINES; i++)
		{
			for (int j = 0; j < GRID_COLUMNS; j++)
			{
				gameObjectsGrid[i][j]->Draw();
			}
		}
	}
};
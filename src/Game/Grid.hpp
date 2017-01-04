#include "System.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <list>

class Grid
{
private:

	GameObject* gameObjectsGrid[GRID_LINES][GRID_COLUMNS];

public:
	Grid() {

	}
	Grid(int a)//Will need to ask for an XML Node
	{
		for (int i = 0; i < GRID_LINES; i++)
		{
			for (int j = 0; j < GRID_COLUMNS; j++)
			{
				gameObjectsGrid[i][j] = new GameObject(CELL_WIDTH*i, CELL_HEIGHT*j, CELL_WIDTH, CELL_HEIGHT, R.GetTexture(ATLAS_TEXTURE.key));

			}
		}
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
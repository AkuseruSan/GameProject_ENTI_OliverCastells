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
	Grid()
	{
		w = GRID_LINES;
		h = GRID_COLUMNS;
		
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				gameObjectsGrid[i][j] = new GameObject(SCREEN_WIDTH/w*i, SCREEN_HEIGHT/h*j, SCREEN_WIDTH/w, SCREEN_HEIGHT/h, R.GetTexture(ATLAS_TEXTURE.key));

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
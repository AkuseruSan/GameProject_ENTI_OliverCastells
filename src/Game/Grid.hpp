#include "System.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <list>

class Grid
{
private:

	GameObject gameObjectsGrid[GRID_WIDTH][GRID_HEIGHT];

public:
	Grid() {

	}
	Grid(int a)//Will need to ask for an XML Node
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j] = GameObject(i, j, SCREEN_WIDTH / GRID_WIDTH, SCREEN_HEIGHT / GRID_HEIGHT, R.GetTexture(ATLAS_TEXTURE.key));
			}
		}
	}

	void Update()
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j].Update();
			}
		}
	}

	void Draw()
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j].Draw();
			}
		}
	}
};
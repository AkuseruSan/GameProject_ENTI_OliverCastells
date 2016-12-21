#include "System.hpp"
//#include "Vector.hpp"
//#include "GameObject.hpp"
#include "GameEngine.hpp"

class Grid
{
private:

	GameObject* gameObjectsGrid[GRID_WIDTH][GRID_HEIGHT];

public:
	Grid() {

	}
	Grid(int a)//Will need to ask for an XML Node
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j] = new GameObject(i, j, SCREEN_WIDTH / GRID_WIDTH, SCREEN_HEIGHT / GRID_HEIGHT, GE.GetTexture(ATLAS_TEXTURE.name));
			}
		}
	}

	void Update()
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j]->Update();
			}
		}
	}

	void Draw()
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				gameObjectsGrid[i][j]->Draw();
			}
		}
	}

	Vector GetWorldPosition(int xPosIndex, int yPosIndex)
	{
		return Vector{ (GRID_WIDTH - xPosIndex)*CELL_WIDTH, (GRID_HEIGHT - yPosIndex)*CELL_HEIGHT };
	}
};
#include "Grid.hpp"


Grid::Grid()
{
	w = GRID_LINES;
	h = GRID_COLUMNS;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			gameObjectsGrid[i][j] = new GameObject(SCREEN_WIDTH / w*i, SCREEN_HEIGHT / h*j, SCREEN_WIDTH / w, SCREEN_HEIGHT / h, R.GetTexture(ATLAS_TEXTURE.key), 0);

		}
	}
}

Vector Grid::GetSize()
{
	return Vector{ w,h };
}
GameObject* Grid::GetObjectFromGrid(int i, int j)
{
	return gameObjectsGrid[i][j];
}

void Grid::Update()
{
	for (int i = 0; i < GRID_LINES; i++)
	{
		for (int j = 0; j < GRID_COLUMNS; j++)
		{
			gameObjectsGrid[i][j]->Update();
		}
	}
}

void Grid::Draw()
{
	for (int i = 0; i < GRID_LINES; i++)
	{
		for (int j = 0; j < GRID_COLUMNS; j++)
		{
			gameObjectsGrid[i][j]->Draw();
		}
	}
}
#include "Grid.hpp"

Grid::Grid(rapidxml::xml_document<>& data)
{
	size = std::stoi(data.first_node("GameData")->first_node("GameScenes")->first_node("GameScene")->first_attribute("grid_size")->value(), nullptr, 10);

	gameObjectsGrid = new GameObject*[size];

	for (int i = 0; i < size; i++) gameObjectsGrid[i] = new GameObject[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameObjectsGrid[i][j] = GameObject(SCREEN_WIDTH / size*i, SCREEN_HEIGHT / size*j, SCREEN_WIDTH / size, SCREEN_HEIGHT / size, R.GetTexture(ATLAS_TEXTURE.key), 0);
			if (i == 0 || i == size -1 || j == 0 || j == size -1) gameObjectsGrid[i][j].SetType(BLOCK);
		}
	}
}

int Grid::GetSize()
{
	return size;
}
GameObject* Grid::GetObjectFromGrid(int i, int j)
{
	return &gameObjectsGrid[i][j];
}

void Grid::Update()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameObjectsGrid[i][j].Update();
		}
	}
}

void Grid::Draw()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameObjectsGrid[i][j].Draw();
		}
	}
}
#include "Grid.hpp"

Grid::Grid(int diff)
{
	size = std::stoi(DM.GetDifficultyData(diff)->first_attribute("grid_size")->value(), nullptr, 10);
	size *= GRID_SIZE;

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

	GenerateObstacles();
}

int Grid::GetSize()
{

	return size;
}

void Grid::GenerateApple() {
	Vector aPos{ (int)rand() % GetSize() , (int)rand() % GetSize() };
	auto aux = GetObjectFromGrid(aPos.x, aPos.y);
	if (aux->GetType() == NONE) aux->SetType(APPLE);
	else GenerateApple();
}

void Grid::GenerateObstacles() {
	int temp = (rand() % 15) + 1;
	for (int i = 0; i < temp; i++) {
		Vector aPos{ (int)rand() % GetSize() , (int)rand() % GetSize() };
		auto aux = GetObjectFromGrid(aPos.x, aPos.y);
		if (aux->GetType() == NONE) aux->SetType(BLOCK);
	}
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
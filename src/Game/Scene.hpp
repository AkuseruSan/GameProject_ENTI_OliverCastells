#pragma once
#include <iostream>
#include "Grid.hpp"
#include <list>
#include "XML\rapidxml.hpp"

class Scene
{
public:
	Scene() = default;
	Scene(int);

	Grid* GetGrid()
	{
		return &grid;
	}

	int GetDifficulty();

	void Update();
	void Draw();

private:

	Grid grid;
	SDL_Texture* background;

	int difficulty;
};
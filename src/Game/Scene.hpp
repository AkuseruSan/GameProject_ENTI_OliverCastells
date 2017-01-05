#pragma once

#include "Grid.hpp"
#include <list>

class Scene
{
public:
	Scene();
	Scene(int);

	Grid* GetGrid()
	{
		return &grid;
	}

	void Update();
	void Draw();

private:

	Grid grid;
	SDL_Texture* background;


};

//Class Definition
Scene::Scene() = default;
Scene::Scene(int a)
{
	grid = Grid(a);
}

void Scene::Update()
{
	grid.Update();
}

void Scene::Draw()
{
	grid.Draw();
}
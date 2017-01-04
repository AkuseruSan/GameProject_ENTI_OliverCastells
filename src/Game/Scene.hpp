#pragma once

#include "Grid.hpp"
#include "PlayerController.hpp"
#include <list>

class Scene
{
public:
	Scene();
	Scene(int);

	Grid GetGrid()
	{
		return grid;
	}

	void Update();
	void Draw();

private:

	Grid grid;
	SDL_Texture* background;
	PlayerController* pc;


};

//Class Definition
Scene::Scene() = default;
Scene::Scene(int a)
{
	grid = Grid(a);
	pc = new PlayerController();
}

void Scene::Update()
{
	pc->Update();
	grid.Update();
}

void Scene::Draw()
{
	grid.Draw();
}
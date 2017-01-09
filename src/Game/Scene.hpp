#pragma once
#include <iostream>
#include "Grid.hpp"
#include <list>
#include "XML\rapidxml.hpp"

class Scene
{
public:
	Scene() = default;
	Scene(rapidxml::xml_node<>& node);

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
Scene::Scene(rapidxml::xml_node<>& node)
{
	std::cout << node.name() << std::endl;
	grid = Grid();
}

void Scene::Update()
{
	grid.Update();
}

void Scene::Draw()
{
	grid.Draw();
}
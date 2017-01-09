#include "Scene.hpp"

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
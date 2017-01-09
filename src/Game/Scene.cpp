#include "Scene.hpp"

Scene::Scene(rapidxml::xml_document<>& data)
{
	std::cout << data.name() << std::endl;
	grid = Grid(data);
}

void Scene::Update()
{
	grid.Update();
}

void Scene::Draw()
{
	grid.Draw();
}
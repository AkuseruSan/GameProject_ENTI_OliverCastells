#include "GameObject.hpp"
#include "Grid.hpp"
#include <list>

class Scene
{
public:
	Scene(std::list<GameObject> members);

private:

	std::list<GameObject> gameObjects;
	Grid grid;

	void Update();
	void Draw();
};

//Class Definition

Scene::Scene(std::list<GameObject> members)
{
	gameObjects.clear();

	grid = Grid(GRID_WIDTH, GRID_HEIGHT);
	
	for each (GameObject obj in members)
	{
		gameObjects.push_back(obj);
	}
}

void Scene::Update()
{
	for each (GameObject obj in gameObjects)
	{
		obj.Update();
	}
}

void Scene::Draw()
{
	for each (GameObject obj in gameObjects)
	{
		obj.Draw();
	}
}
#include "Grid.hpp"
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

	//std::list<GameObject> gameObjects;
	Grid grid;


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
#include "GameObject.hpp"
#include <list>

class Scene : GameObject
{
public:
	Scene(std::list<GameObject> members);

private:
	std::list<GameObject> gameObjects;

	void Update();
	void Draw();
};

//Class Definition

Scene::Scene(std::list<GameObject> members)
{
	gameObjects.clear();
	
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
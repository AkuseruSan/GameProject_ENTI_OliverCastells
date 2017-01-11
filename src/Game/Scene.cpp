#include "Scene.hpp"

Scene::Scene(int diff) { grid = Grid(diff); difficulty = diff; }

void Scene::Update() { grid.Update(); }

void Scene::Draw() { grid.Draw(); }

int Scene::GetDifficulty() { return difficulty; }

Scene::~Scene()
{
	SDL_DestroyTexture(background);
	//delete(background);
}
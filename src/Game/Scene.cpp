#include "Scene.hpp"

Scene::Scene(int diff) { grid = Grid(diff); }

void Scene::Update() { grid.Update(); }

void Scene::Draw() { grid.Draw(); }

int Scene::GetDifficulty() { return difficulty; }
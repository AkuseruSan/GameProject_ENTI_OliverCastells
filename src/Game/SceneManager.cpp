#include "SceneManager.hpp"


SceneManager& SceneManager::GetInstance()
{
	static SceneManager inst = SceneManager();
	return inst;
}

void SceneManager::InitScene(int d)
{

	s_mainMenu = new Scene(d);
	currentScene = s_mainMenu;
}

Scene* SceneManager::GetCurentScene() { return currentScene; }

void SceneManager::Update() { GetCurentScene()->Update(); }

void SceneManager::Draw() { GetCurentScene()->Draw(); }

int SceneManager::GetDifficulty() { return GetCurentScene()->GetDifficulty(); }

SceneManager::SceneManager() {}


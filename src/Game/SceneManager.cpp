#include "SceneManager.hpp"


SceneManager& SceneManager::GetInstance()
{
	static SceneManager inst = SceneManager();
	return inst;
}

Scene* SceneManager::GetCurentScene()
{
	return currentScene;
}

void SceneManager::InitScene(int d)
{

	s_mainMenu = new Scene(d);
	currentScene = s_mainMenu;
}

void SceneManager::Update()
{
	GetCurentScene()->Update();
}

void SceneManager::Draw()
{
	GetCurentScene()->Draw();
}

SceneManager::SceneManager()
{

}


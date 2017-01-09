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

void SceneManager::InitScene(rapidxml::xml_document<>& data, int index)
{

	s_mainMenu = new Scene(data);
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


#pragma once
#include "Scene.hpp"
#include "XML\rapidxml.hpp"
#include "XML\rapidxml_iterators.hpp"
#include "DataManager.hpp"

#define SM SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance();

	Scene* GetCurentScene();
	void InitScene(rapidxml::xml_document<>& data, int index);

	void Update();
	void Draw();

private:
	SceneManager();

	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);

	std::map<int, Scene*> scenes;
	Scene* s_mainMenu, s_game;
	Scene* currentScene;
};


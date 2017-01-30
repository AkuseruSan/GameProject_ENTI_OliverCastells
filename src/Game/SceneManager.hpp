#pragma once
#include "Scene.hpp"
#include "XML\rapidxml.hpp"
#include "XML\rapidxml_iterators.hpp"
#include "DataManager.hpp"
#include "PlayerController.hpp"
#include "MainMenu.hpp"

#define SM SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance();

	Scene* GetCurrentScene();
	void InitScene(int);

	void Update();
	void Draw();
	int GetDifficulty();

	void ResetPlayerController();

	~SceneManager();
private:
	SceneManager();

	PlayerController* playerController;

	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);

	std::map<int, Scene*> scenes;

	bool dataAdded;

	MainMenu* mainMenu;
	Scene* currentScene;
};


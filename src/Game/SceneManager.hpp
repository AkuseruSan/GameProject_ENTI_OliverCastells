#pragma once
#include "Scene.hpp"

#define SM SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager inst = SceneManager();
		return inst;
	}

	Scene* GetCurentScene() 
	{
		return currentScene;
	}
	void InitScenes()
	{
		s_mainMenu = new Scene(0);
	}

	void Update()
	{
		GetCurentScene()->Update();
	}
	void Draw()
	{
		GetCurentScene()->Draw();
	}

private:
	SceneManager()
	{
		InitScenes();
		currentScene = s_mainMenu;
	}

	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);

	Scene* s_mainMenu, s_game;
	Scene* currentScene;
};


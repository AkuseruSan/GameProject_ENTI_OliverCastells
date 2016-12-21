#include "System.hpp"
#include "GameEngine.hpp"
#include "Scene.hpp"

#define SM SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager inst;
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

	void Run()
	{
		GetCurentScene()->Update();
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


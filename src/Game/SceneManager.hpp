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

	Scene& GetCurentScene() 
	{
		return currentScene;
	}
	void InitScenes()
	{
		s_mainMenu = new Scene({GameObject(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, 10, GE.GetTexture(ATLAS_TEXTURE.name))});
	}

private:
	SceneManager()
	{
		InitScenes();
		currentScene = *s_mainMenu;
	}

	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);

	Scene* s_mainMenu, s_game;
	Scene& currentScene;
};


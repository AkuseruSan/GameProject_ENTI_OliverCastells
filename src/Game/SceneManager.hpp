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

	Scene GetCurentScene();

private:
	SceneManager();
	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);

	Scene s_mainMenu, s_game;
};


#include "SceneManager.hpp"


SceneManager& SceneManager::GetInstance()
{
	static SceneManager inst = SceneManager();
	return inst;
}

void SceneManager::InitScene(int d)
{
	currentScene = new Scene(d);
	ResetPlayerController();
}

Scene* SceneManager::GetCurrentScene() { return currentScene; }

void SceneManager::Update() 
{ 
	switch (DM.GetState())
	{
		case GameState::MAIN_MENU:
		{
			if (IM.GetDirction() == DIR_UP)
			{
				DM.SetState(GameState::GAME);
				InitScene(1);
			}
		}break;
		case GameState::GAME:
		{
			playerController->Update();
			GetCurrentScene()->Update();
		}break;
		case GameState::GAME_OVER:
		{
			InitScene(0);
			DM.SetState(GameState::MAIN_MENU);
			ResetPlayerController();
		}break;
	}
}

void SceneManager::Draw() { GetCurrentScene()->Draw(); }

int SceneManager::GetDifficulty() { return GetCurrentScene()->GetDifficulty(); }

SceneManager::SceneManager() 
{
	InitScene(0);
	ResetPlayerController();
}

void SceneManager::ResetPlayerController()
{
	playerController = new PlayerController(GetCurrentScene());
}

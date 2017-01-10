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
			if (mainMenu->easyButton.Clicked())
			{
				DM.SetState(GameState::GAME);
				SM.InitScene(0);
			}
			else if (mainMenu->mediumButton.Clicked()) 
			{ 
				DM.SetState(GameState::GAME);
				SM.InitScene(1); 
			}
			else if (mainMenu->hardButton.Clicked()) 
			{ 
				DM.SetState(GameState::GAME);
				SM.InitScene(2); 
			}
			
			if (IM.GetDirction() == DIR_UP)
			{
				DM.SetState(GameState::GAME);
				InitScene(0);
			}
		}break;
		case GameState::GAME:
		{
			playerController->Update();
			GetCurrentScene()->Update();
		}break;
		case GameState::GAME_OVER:
		{
			DM.SetState(GameState::MAIN_MENU);
			ResetPlayerController();
		}break;
	}
}

void SceneManager::Draw() 
{ 
	switch (DM.GetState())
	{
		case GameState::MAIN_MENU:
		{
			mainMenu->Draw();
		}break;
		case GameState::GAME:
		{
			GetCurrentScene()->Draw();
		}break;
		case GameState::GAME_OVER:
		{

		}break;
	}

}

int SceneManager::GetDifficulty() { return GetCurrentScene()->GetDifficulty(); }

SceneManager::SceneManager() 
{
	mainMenu = new MainMenu();
	InitScene(0);
	ResetPlayerController();
}

SceneManager::~SceneManager()
{
	delete(mainMenu);
	delete(currentScene);
}

void SceneManager::ResetPlayerController()
{
	playerController = new PlayerController(GetCurrentScene());
}

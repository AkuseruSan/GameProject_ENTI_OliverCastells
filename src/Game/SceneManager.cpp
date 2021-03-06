#include "SceneManager.hpp"


SceneManager& SceneManager::GetInstance()
{
	static SceneManager inst = SceneManager();
	return inst;
}

void SceneManager::InitScene(int d)
{
	dataAdded = false;
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
			if (IM.MouseClicked())
			{
				DM.SetState(GameState::MAIN_MENU);
				ResetPlayerController();
			}

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
			R.RenderText((char*)std::string("Lives: " + std::to_string(playerController->lives)).c_str(), SDL_Color{ 255,255,60,45 }, SDL_Rect{ 20, 20, 50, 20 });

		}break;
		case GameState::GAME_OVER:
		{
			if (!dataAdded) {
				GetCurrentScene()->Draw();
				PlayerData newData;
				newData.score = playerController->score;
				R.RenderText("Enter your name on the console", SDL_Color{ 255, 0, 0, 50 }, SDL_Rect{ SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 15, 200, 30 });
				std::cout << "Enter your name to continue" << std::endl;
				std::cin >> newData.name;
				DM.InsertScore(newData);
				dataAdded = true;
			}
			GetCurrentScene()->Draw();
			R.RenderText("TOP 10", SDL_Color{ 50,255,50,45 }, SDL_Rect{ SCREEN_WIDTH / 2 - 40, 30, 80, 30 });
			for (int i = 0; i < 10; i++) {
				R.RenderText(const_cast<char*>(DM.GetRanking()[i].name.c_str()), SDL_Color{ 50,255,50,45 }, SDL_Rect{ SCREEN_WIDTH / 2 - 200, 100 + (40 * i), 15 *(int)DM.GetRanking()[i].name.size(), 20 });
				R.RenderText(const_cast<char*>(std::to_string(DM.GetRanking()[i].score).c_str()), SDL_Color{ 50,255,50,45 }, SDL_Rect{ SCREEN_WIDTH / 2 + 50, 100 + (40 * i), 15 * (int)std::to_string(DM.GetRanking()[i].score).size() , 20 });
			}
			R.RenderText("[CLICK TO GO TO MAIN MENU]", SDL_Color{ 255,255,60,45 }, SDL_Rect{ SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 3 + 50, 200, 20 });
			R.RenderText((char*)std::string("Score: "+ std::to_string(playerController->score)).c_str(), SDL_Color{ 255,255,60,45 }, SDL_Rect{ SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 4, 100, 20 });
			R.RenderText((char*)std::string("Level: " + std::to_string(playerController->level)).c_str(), SDL_Color{ 255,255,60,45 }, SDL_Rect{ SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 4 + 50, 100, 20 });

		}break;
	}

}

int SceneManager::GetDifficulty() { return GetCurrentScene()->GetDifficulty(); }

SceneManager::SceneManager() 
{
	mainMenu = new MainMenu();
	//InitScene(0);
	//ResetPlayerController();
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

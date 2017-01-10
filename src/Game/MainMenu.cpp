#include "MainMenu.hpp"

MainMenu::MainMenu()
{

}

void MainMenu::Update()
{
	
}

void MainMenu::Draw()
{
	R.RenderText("Easy", textCol, SDL_Rect{ (SCREEN_WIDTH/2) - 50, 50 ,100, 100 });
	R.RenderText("Medium", textCol, SDL_Rect{ (SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT/2 - 50, 100, 100 });
	R.RenderText("Hard", textCol, SDL_Rect{ (SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT - 200, 100, 100 });
}
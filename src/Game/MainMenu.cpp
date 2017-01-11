#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	easyButton = Button(SDL_Rect{ (SCREEN_WIDTH / 2) - 50, 50 ,100, 100 }, "Easy");
	mediumButton = Button(SDL_Rect{ (SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT / 2 - 50, 100, 100 }, "Medium");
	hardButton = Button(SDL_Rect{ (SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT - 200, 100, 100 }, "Hard");
}

void MainMenu::Draw()
{
	easyButton.Draw();
	mediumButton.Draw();
	hardButton.Draw();
}
#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Window.hpp"
#include "Renderer.hpp"

class MainMenu
{
private:

public:
	MainMenu();
	void Update();
	void Draw();
	void ShowMenu(TTF_Font* font);
};
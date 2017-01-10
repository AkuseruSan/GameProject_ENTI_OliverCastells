#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Window.hpp"
#include "Renderer.hpp"
#include "InputManager.hpp"

class MainMenu
{
private:
	SDL_Color textCol{ 255, 100, 100, 100 };
public:
	MainMenu();
	void Update();
	void Draw();
};
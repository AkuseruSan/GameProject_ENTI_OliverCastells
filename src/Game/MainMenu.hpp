#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Window.hpp"
#include "Renderer.hpp"
#include "InputManager.hpp"
#include "Button.hpp"

class MainMenu
{
private:


public:
	Button easyButton;
	Button mediumButton;
	Button hardButton;
	MainMenu();

	void Draw();
};
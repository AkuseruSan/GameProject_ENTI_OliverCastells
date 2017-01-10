#include "SDL\SDL.h"
#include "InputManager.hpp"
#include "Renderer.hpp"

class Button
{
private:
	SDL_Rect bounds;
	SDL_Color col{ 255, 100, 100, 100 };
	char* text;
public:
	Button() = default;
	Button(SDL_Rect, char*);
	bool Clicked();

	void Draw();
};
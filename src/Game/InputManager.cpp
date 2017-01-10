#include "InputManager.hpp"


InputManager::InputManager()
{
	click = false;
}

InputManager::~InputManager()
{

}

void InputManager::Update(bool& isRun) {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:		isRun = false;	break;
		case SDL_MOUSEMOTION:	mousePos = { evnt.motion.x, evnt.motion.y };		break;
		case SDL_MOUSEBUTTONDOWN: click = true; break;
		case SDL_MOUSEBUTTONUP: click = false; break;
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym) {
			case SDLK_UP:			if (direction != DIR_DOWN)	direction = DIR_UP;		break;
			case SDLK_DOWN:			if (direction != DIR_UP)	direction = DIR_DOWN;	break;
			case SDLK_LEFT:			if (direction != DIR_RIGHT)	direction = DIR_LEFT;	break;
			case SDLK_RIGHT:		if (direction != DIR_LEFT)	direction = DIR_RIGHT;	break;
			}
		}
	}
}

Vector InputManager::GetMousePosition()
{
	return mousePos;
}
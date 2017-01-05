#pragma once

#include <SDL/SDL.h>
#include <queue>
#include "System.hpp"

#define IM InputManager::Instance()

class InputManager {
	InputManager() {}
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

public:
	~InputManager() = default;
	inline static InputManager &Instance() {
		static InputManager inputManager;
		return inputManager;
	}
	void Update(bool& isRun) {
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_QUIT:		isRun = false;	break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_UP:		if (direction != DIR_DOWN)	direction = DIR_UP;		break;
				case SDLK_DOWN:		if (direction != DIR_UP)	direction = DIR_DOWN;	break;
				case SDLK_LEFT:		if (direction!= DIR_RIGHT)	direction = DIR_LEFT;	break;
				case SDLK_RIGHT:	if (direction != DIR_LEFT)	direction = DIR_RIGHT;	break;
				}
			}
		}
	}
	inline int GetDirction(void)  const { return direction; }
	inline int ResetDirection(void) { direction = 0; }
private:
	int direction = 0;
};
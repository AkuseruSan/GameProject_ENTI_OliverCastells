#pragma once

#include <SDL/SDL.h>
#include <queue>
#include <iostream>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

#define IM InputManager::Instance()

class InputManager {
	InputManager() = default;
	InputManager(const InputManager &rhs) = delete;
	InputManager &operator=(const InputManager &rhs) = delete;

public:
	~InputManager() = default;
	inline static InputManager &Instance() {
		static InputManager inputManager;
		return inputManager;
	}
	void Update(void) {
		SDL_Event evnt;
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_QUIT:
				m_exit = true;
				break;
			case SDL_KEYDOWN:
				if (evnt.key.keysym.sym == SDLK_UP && direction != DOWN)
				{
					direction = UP;
					break;
				}
				if (evnt.key.keysym.sym == SDLK_DOWN && direction != UP)
				{
					direction = DOWN;
					break;
				}
				if (evnt.key.keysym.sym == SDLK_LEFT && direction != RIGHT)
				{
					direction = LEFT;
					break;
				}
				if (evnt.key.keysym.sym == SDLK_RIGHT && direction != LEFT)
				{
					direction = RIGHT;
					break;
				}
			}
		}
	}
	inline bool HasQuit(void) const { return m_exit; }

	inline int getDirction() {
		return direction;
	}

private:
	bool m_exit = false;
	int direction;
};
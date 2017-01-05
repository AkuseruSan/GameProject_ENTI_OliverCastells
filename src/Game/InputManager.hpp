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
	void Update(void) {
		SDL_Event evnt;
		bool getEv = true;
		while (getEv && SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_QUIT:
				m_exit = true;
				getEv = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				direction.push(7);
				break;
			case SDL_MOUSEMOTION:
				direction.push(8);
				break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_UP: 
					if (direction.back() != DIR_DOWN && direction.back() != DIR_UP)
						direction.push(DIR_UP);
					getEv = false;
					break;
				case SDLK_DOWN:
				if (direction.back() != DIR_DOWN && direction.back() != DIR_UP)
					direction.push(DIR_DOWN);
				getEv = false;
				break;
				case SDLK_LEFT:
				if (direction.back() != DIR_RIGHT && direction.back() != DIR_LEFT)
					direction.push(DIR_LEFT);
				getEv = false;
				break;
				case SDLK_RIGHT:
				if (direction.back() != DIR_RIGHT && direction.back() != DIR_LEFT)
					direction.push(DIR_RIGHT);
				getEv = false;
				break;
				default:
					getEv = false;
					break;
				}
			default:
				getEv = false;
				break;
			}
		}
	}
	inline bool HasQuit(void) const { return m_exit; }
	inline int GetDirction(void)  const { if (!direction.empty()) return direction.front(); }
	inline void DeleteDirection(void) { if (!direction.empty()) direction.pop(); }

private:
	bool m_exit = false;
	std::queue<int> direction;
};
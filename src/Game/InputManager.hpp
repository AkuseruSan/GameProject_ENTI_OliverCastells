#pragma once

#include <SDL/SDL.h>
#include <queue>

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
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_QUIT:
				m_exit = true;
				break;
			case SDL_KEYDOWN:
				if (evnt.key.keysym.sym == SDLK_UP && direction.back() != DIR_DOWN && direction.back() != DIR_UP)
				{
					direction.push(DIR_UP);
					break;
				}
				else if (evnt.key.keysym.sym == SDLK_DOWN && direction.back() != DIR_UP && direction.back() != DIR_DOWN)
				{
					direction.push(DIR_DOWN);
					break;
				}
				else if (evnt.key.keysym.sym == SDLK_LEFT && direction.back() != DIR_RIGHT && direction.back() != DIR_LEFT)
				{
					direction.push(DIR_LEFT);
					break;
				}
				else if (evnt.key.keysym.sym == SDLK_RIGHT && direction.back() != DIR_LEFT && direction.back() != DIR_RIGHT)
				{
					direction.push(DIR_RIGHT);
					break;
				}
			default:
				break;
			}
		}
	}
	inline bool HasQuit(void) const { return m_exit; }
	inline int getDirction(void)  const { if (!direction.empty()) return direction.front(); }
	inline void deleteDirection(void) { if (!direction.empty()) direction.pop(); }

private:
	bool m_exit = false;
	std::queue<int> direction;
};
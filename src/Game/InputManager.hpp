#pragma once

#include <SDL/SDL.h>
#include <queue>
#include <iostream>

#define IM InputManager::Instance()

class InputManager {
	InputManager() = default;
	InputManager(const InputManager &rhs) = delete;
	InputManager &operator=(const InputManager &rhs) = delete;
	enum class InputValue{LEFT = SDL_SCANCODE_LEFT, RIGHT = SDL_SCANCODE_RIGHT, UP = SDL_SCANCODE_UP, DOWN = SDL_SCANCODE_DOWN};
public:
	~InputManager() = default;
	inline static InputManager &Instance() {
		static InputManager inputManager;
		return inputManager;
	}
	void Update(void) {
		SDL_Event evnt;
		if (SDL_PollEvent(&evnt) && SDL_PollEvent(&evnt) != (int)m_inputValues.back()) {
			switch (evnt.type)
			{
			case SDL_QUIT:				m_exit = true; break;
			case SDL_KEYDOWN:			m_inputValues.push.back(evnt); break;
			}
		}
	}
	inline bool HasQuit(void) const { return m_exit; }

private:
	bool m_exit = false;
	std::queue<InputValue*> m_inputValues;
};
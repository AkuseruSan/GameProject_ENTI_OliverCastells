#pragma once

#include <SDL/SDL.h>
#include <queue>
#include "System.hpp"

#define IM InputManager::Instance()

class InputManager {
	InputManager();
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

public:
	~InputManager();

	inline static InputManager& Instance()
	{
		static InputManager inputManager;
		return inputManager;
	}

	void Update(bool& isRun);

	inline int GetDirction(void)  const { return direction; }
	inline int ResetDirection(void) { direction = 0; }
private:
	int direction = 0;
};
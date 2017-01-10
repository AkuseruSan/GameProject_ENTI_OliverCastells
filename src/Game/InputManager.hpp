#pragma once

#include <SDL/SDL.h>
#include <queue>
#include "System.hpp"
#include "Vector.hpp"

#define IM InputManager::Instance()

enum InputCode {UP, DOWN, LEFT, RIGHT, CLICK, MOVE};
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

	Vector GetMousePosition();
	inline int GetDirction(void)  const { return direction; }
	inline void ResetDirection(void) { direction = NULL; }
private:
	Vector mousePos;
	bool click;
	int direction = NULL;
};
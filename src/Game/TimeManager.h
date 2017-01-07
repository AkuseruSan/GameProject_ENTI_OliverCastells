#pragma once
#include <SDL/SDL.h>
#include <functional>
#include "System.hpp"

#define TM TimeManager::Instance()

class TimeManager {
public:
	inline static TimeManager &Instance(void) {
		static TimeManager timeManager;
		return timeManager;
	}
	void FPSBegin() {
		deltaTime = float(SDL_GetTicks() - lastTime);
		lastTime = SDL_GetTicks();
	}
	void FPSEnd(std::function<void()> drawFunction) {
		if (renderTime >= SCREEN_TICKS_PER_FRAME) drawFunction(), renderTime -= SCREEN_TICKS_PER_FRAME;
		renderTime += deltaTime; // Updates the render timer
	}
	Uint32 GetCurTime() { return SDL_GetTicks(); };
	inline float GetDeltaTime() { return deltaTime; };
private:
	TimeManager() = default;
	TimeManager(const TimeManager &rhs) = delete;
	TimeManager &operator=(const TimeManager &rhs) = delete;
private:
	float deltaTime{ .0f }; // Delta time in seconds
	Uint32 lastTime{ SDL_GetTicks() }; // Last time sample in seconds
	float renderTime{ 0.0f }; // Time control for rendering
};
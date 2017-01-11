#pragma once
#include <SDL/SDL.h>
#include <string>
#include "System.hpp"

#define W Window::Instance()
#define WW Window::Instance().GetWindow()

class Window {

public:
	inline static Window& Instance() {
		static Window window("Game Window", SCREEN_WIDTH, SCREEN_HEIGHT);
		return window;
	}
	~Window();

	SDL_Surface* GetSurface();
	SDL_Window* GetWindow();

private:
	Window(const std::string &&name, int &&screenWidth, int &&screenHeight);

	SDL_Window* myWindow{ nullptr };
	SDL_Surface* surface;
};
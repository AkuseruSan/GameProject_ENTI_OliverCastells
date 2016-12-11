#pragma once
#include <SDL/SDL.h>
#include <string>

#define W Window::Instance()

class Window {
	Window(const std::string &&name, int &&screenWidth, int &&screenHeight) : w_name(name), w_width(screenWidth), w_height(screenHeight) {
		myWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 0);
	}
public:
	inline static Window &Instance() {
		static Window window("", 0, 0);
		return window;
	}
	~Window() {
		SDL_DestroyWindow(myWindow), myWindow = nullptr; //Destroy window
		SDL_Quit();
	}
	inline SDL_Window* operator() (void) { return myWindow; }

private:
	SDL_Window* myWindow{ nullptr };
	const int w_width, w_height;
	const std::string w_name;
};
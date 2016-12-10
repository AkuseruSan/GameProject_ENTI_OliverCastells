#pragma once
#include <SDL/SDL.h>
#include <string>

#define W Window::Instance()

class Window {
	Window(const std::string &&name, int &&screenWidth, int &&screenHeight) : w_name(name), w_width(screenWidth), w_height(screenHeight) {
	}
public:
	inline static Window &Instance(std::string &&name = "", int &&screenWidth = 0, int &&screenHeight = 0) {
		static Window window(std::move(name), std::move(screenWidth), std::move(screenHeight));
		return window;
	}
	~Window() {
		SDL_DestroyWindow(myWindow), myWindow = nullptr; //Destroy window
		SDL_Quit();
	}
private:
	SDL_Window* myWindow{ nullptr };
	const int w_width, w_height;
	const std::string w_name;
};
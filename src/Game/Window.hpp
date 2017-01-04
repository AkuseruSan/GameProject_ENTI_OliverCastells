#pragma once
#include <SDL/SDL.h>
#include <string>
#include "System.hpp"

#define W Window::Instance()
#define WW Window::Instance().GetWindow()

class Window {
	Window(const std::string &&name, int &&screenWidth, int &&screenHeight){
		myWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 4);
	}
public:
	inline static Window& Instance() {
		static Window window("Game Window", SCREEN_WIDTH, SCREEN_HEIGHT);
		return window;
	}
	~Window() {
		SDL_DestroyWindow(myWindow), myWindow = nullptr; //Destroy window
		SDL_Quit();
	}

	SDL_Window* GetWindow() {
		return myWindow;
	}
	//inline SDL_Window* operator() (void) { return myWindow; }

private:
	SDL_Window* myWindow{ nullptr };
};
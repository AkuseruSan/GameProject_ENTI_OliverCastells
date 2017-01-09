#include "Window.hpp"

#define W Window::Instance()
#define WW Window::Instance().GetWindow()


Window::~Window() {
	SDL_DestroyWindow(myWindow), myWindow = nullptr; //Destroy window
	SDL_Quit();
}

SDL_Window* Window::GetWindow() {
	return myWindow;
}


Window::Window(const std::string &&name, int &&screenWidth, int &&screenHeight) {
	myWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 4);
}

#pragma once
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Window.hpp"

#define R Renderer::Instance()

class Renderer
{
	SDL_Renderer *myRenderer{ nullptr };
public:
	static Renderer& Instance()
	{
		static Renderer inst;
		return inst;
	}
	SDL_Renderer* operator() (void) { return myRenderer; }

private:
	Renderer() {
		myRenderer = SDL_CreateRenderer(W(), -1, 0);
	}
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);
};
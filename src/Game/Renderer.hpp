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

	SDL_Renderer* GetRenderer()
	{
		return myRenderer;
	}
	void Render(SDL_Texture* tex, SDL_Rect* rect)
	{
		SDL_RenderCopy(myRenderer, tex, nullptr, rect);
	}
	//SDL_Renderer* operator() (void) { return myRenderer; }

private:
	Renderer() {
		myRenderer = SDL_CreateRenderer(W.GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);
};
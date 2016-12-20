#pragma once
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include "Window.hpp"

#define R Renderer::Instance()//Game Engine Renderer
#define RR Renderer::Instance().GetRenderer()//SDL Renderer

class Renderer
{
	SDL_Renderer *myRenderer{ nullptr };
public:
	inline static Renderer& Instance()
	{
		static Renderer myRenderer;
		return myRenderer;
	}

	SDL_Renderer* GetRenderer()
	{
		return myRenderer;
	}
	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect* destRect)
	{
		SDL_RenderCopy(myRenderer, tex, sourceRect, destRect);
	}



private:
	Renderer() {
		myRenderer = SDL_CreateRenderer(WW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);

};
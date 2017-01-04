#pragma once
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include "Window.hpp"

#define R Renderer::Instance()//Game Engine Renderer
#define RR Renderer::Instance().GetRenderer()//SDL Renderer

#define ATLAS_TEXTURE Texture{"ATLAS", "../../res/gfx/bg.jpg"}
#define BACKGROUND_TEXTURE Texture{"BCKG", "../../res/tex/bckg.png"}

struct Texture
{
	std::string key;
	const char* path;
};


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
	void RenderTexture(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect)
	{
		SDL_RenderCopy(myRenderer, tex, sourceRect, &destRect);
		//SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
		//SDL_RenderCopyEx(myRenderer, tex, sourceRect, &destRect, 0, new SDL_Point{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, flip);
	}

	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect, int flag)
	{

	}

	void RenderText()
	{

	}

	void LoadTexture(std::string name, const char* path)
	{
		std::pair<std::string, SDL_Texture*> aux{ name, IMG_LoadTexture(RR, path) };
		sprites.insert(aux);
	}

	SDL_Texture* GetTexture(std::string key)
	{
		if (sprites[key] == nullptr) throw "No texture stored with that key value!";
		return sprites[key];
	}

private:
	Renderer() {
		myRenderer = SDL_CreateRenderer(WW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	std::map<std::string, SDL_Texture*> sprites;
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);

};
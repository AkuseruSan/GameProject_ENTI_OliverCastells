#pragma once
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include "Window.hpp"

#define R Renderer::Instance()//Game Engine Renderer
#define RR Renderer::Instance().GetRenderer()//SDL Renderer

//Texture IDs
#define ATLAS_TEXTURE				Texture{"ATLAS", "../../res/tex/snake_spritesheet.jpg"}


//Atlas Regions
#define ATLAS_NULL_RECT				Vector{0, 0}
#define ATLAS_BLOCK_RECT			Vector{1, 0}
#define ATLAS_APPLE_RECT			Vector{2, 0}
#define ATLAS_SNAKESTART_RECT		Vector{0, 1}
#define ATLAS_SNAKE_RECT			Vector{1, 1}
#define ATLAS_SNAKEEND_RECT			Vector{2, 1}


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
	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect)
	{
		SDL_RenderCopy(myRenderer, tex, sourceRect, &destRect);
		//SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
		//SDL_RenderCopyEx(myRenderer, tex, sourceRect, &destRect, 0, new SDL_Point{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, flip);
	}

	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect, int degrees)
	{
		SDL_RenderCopyEx(myRenderer, tex, sourceRect, &destRect, degrees, nullptr, SDL_FLIP_NONE);
	}

	void RenderText()
	{

	}

	SDL_Rect* GetAtlasRegion(Vector position)
	{
		SDL_Rect* rect;
		
		int w, h;

		SDL_QueryTexture(GetTexture(ATLAS_TEXTURE.key), NULL, NULL, &w, &h);
		
		return new SDL_Rect{(w/ ATLAS_WIDTH)*position.x, (h/ ATLAS_HEIGHT)*position.y, w/ ATLAS_WIDTH, h/ ATLAS_HEIGHT};
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
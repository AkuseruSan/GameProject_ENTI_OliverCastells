#pragma once
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include "Vector.hpp"
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
	SDL_Renderer *myRenderer;
public:
	inline static Renderer& Instance()
	{
		static Renderer myRenderer;
		return myRenderer;
	}

	SDL_Renderer* GetRenderer();
	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect);

	void Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect, int degrees);

	void RenderText();

	SDL_Rect* GetAtlasRegion(Vector position);

	void LoadTexture(std::string name, const char* path);

	SDL_Texture* GetTexture(std::string key);

	Renderer();
	std::map<std::string, SDL_Texture*> sprites;

	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

};
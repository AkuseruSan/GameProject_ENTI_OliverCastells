#pragma once
#include <string>			// Needed to process error messages
#include <SDL\SDL.h>		// Always needs to be included for an SDL app
#include <SDL\SDL_ttf.h>	// Used for loading fonts and rendering text
#include <SDL\SDL_image.h>	// Used for loading and drawing sprites
#include <SDL\SDL_mixer.h>	// Used for loading and playing audio files

#include "Window.hpp"
#include "Vector.hpp"
#include "View.hpp"
#include "System.hpp"

#define GE GameEngine::Instance()

#define ATLAS_TEXTURE Texture{"ATLAS", "../../res/gfx/bg.jpg"}
#define BACKGROUND_TEXTURE Texture{"BCKG", "../../res/tex/bckg.png"}

struct Texture
{
	std::string name;
	const char* path;
};

using namespace std::string_literals;
class GameEngine
{
private:
	GameEngine() 
	{

	}
	std::map<std::string, SDL_Texture*> sprites;
public:
	inline static GameEngine &Instance() {
		static GameEngine ge;
		return ge;
	}
	~GameEngine() 
	{

	}

	void Init()
	{
		SDL_Log("Executable built in %s", SDL_GetBasePath());
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "Unable to initialize SDL subsystems"s;
		const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
		if (!(IMG_Init(imgFlags) & imgFlags)) throw "Unable to initialize SDL_image"s;
		const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
		if (!(Mix_Init(mixFlags) & mixFlags)) throw "Unable to initialize SDL_mixer"s;
		if (TTF_Init() != 0) throw "Unable to initialize SDL_ttf"s;

		
		//Window
		if (WW == nullptr) throw "Unable to initialize the SDL_Window"s;

		//Renderer
		if (RR == nullptr) throw "Unable to initialize the SDL_Renderer"s;

		//Sprites
		LoadTexture(ATLAS_TEXTURE.name, ATLAS_TEXTURE.path);

		//Init Scenes
		//SM.InitScenes();
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

	void GameLoop() {
		SDL_Event evnt;
		for (bool isRunning{ true }; isRunning;) {
			// HANDLE EVENTS
			while (SDL_PollEvent(&evnt)) {
				switch (evnt.type) {
				case SDL_QUIT:			isRunning = false; break;
				case SDL_MOUSEMOTION:	//playerTarget.x = evnt.motion.x - 50; playerTarget.y = evnt.motion.y - 50; break;
				default:;
				}
			}
			// UPDATE
			//SM.
			
			//playerRect.x += (playerTarget.x - playerRect.x) / 10;
			//playerRect.y += (playerTarget.y - playerRect.y) / 10;
			//// DRAW
			//SDL_RenderClear(RR);
			//SDL_RenderCopy(RR, bgTexture, nullptr, &bgRect);
			//SDL_RenderCopy(RR, playerTexture, nullptr, &playerRect);
			//SDL_RenderCopy(RR, textTexture, nullptr, &textRect);
			//SDL_RenderPresent(RR);
		}
	}

	void Run() {
		Init();
		GameLoop();
	}
};
#pragma once
#include <string>			// Needed to process error messages
#include <SDL\SDL.h>		// Always needs to be included for an SDL app
#include <SDL\SDL_ttf.h>	// Used for loading fonts and rendering text
#include <SDL\SDL_image.h>	// Used for loading and drawing sprites
#include <SDL\SDL_mixer.h>	// Used for loading and playing audio files

#include "Vector.hpp"
#include "View.hpp"
#include "System.hpp"
#include "SceneManager.hpp"
#include "DataManager.hpp"

#define GE GameEngine::Instance()


using namespace std::string_literals;
class GameEngine
{
private:
	GameEngine() 
	{

	}
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
		R.LoadTexture(ATLAS_TEXTURE.key, ATLAS_TEXTURE.path);

		//Load Game Data

	}

	void GameLoop() {
		SDL_Event evnt;
		for (bool isRunning{ true }; isRunning;) {
			// HANDLE EVENTS
			while (SDL_PollEvent(&evnt)) {
				switch (evnt.type) {
				case SDL_QUIT:			isRunning = false; break;
				//case SDL_MOUSEMOTION:	//playerTarget.x = evnt.motion.x - 50; playerTarget.y = evnt.motion.y - 50; break;
				default:;
				}
			}

			// UPDATE
			Update();

			// DRAW
			Draw();

		}
	}

	void Run() {
		Init();
		GameLoop();
	}
	void Draw()
	{
		SDL_RenderClear(RR);
		SM.Draw();
		SDL_RenderPresent(RR);
	}
	void Update()
	{
		//SM.Update();
	}
};
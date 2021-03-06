#pragma once
#include <string>			// Needed to process error messages
#include <SDL\SDL.h>		// Always needs to be included for an SDL app
#include <SDL\SDL_ttf.h>	// Used for loading fonts and rendering text
#include <SDL\SDL_image.h>	// Used for loading and drawing sprites
#include <SDL\SDL_mixer.h>	// Used for loading and playing audio files

#include "AuxLib.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "System.hpp"
#include "SceneManager.hpp"
#include "DataManager.hpp"
#include "InputManager.hpp"
#include "TimeManager.hpp"

#include <iostream>

#define GE GameEngine::Instance()

class GameEngine
{
private:
	GameEngine();
public:
	inline static GameEngine& Instance()
	{
		static GameEngine ge;
		return ge;
	}
	~GameEngine();

	void Init();

	void GameLoop();

	void Run();
	void Draw();
	void Update();
};
#include "GameEngine.hpp"

using namespace std::string_literals;

GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
	delete (pc);
}

PlayerController& GameEngine::GetPlayerController()
{
	return *pc;
}

void GameEngine::ResetPlayerController()
{
	//Save Binaries from DataManager
	
	//pc = new PlayerController();
}

void GameEngine::Init()
{
	//Load Game Data
	DM.LoadFileXML(GAMEDATA_PATH);

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

	//Scene Manager
	SM.InitScene(1);
	pc = new PlayerController(); // AXEL, TE ATREVES A MOVER ESTO Y TE DEPILO LAS BOLAS CON EL CORTACESPED
}

void GameEngine::GameLoop() {
	SDL_Event evnt;
	for (bool isRunning{ true }; isRunning;)
	{

		// HANDLE EVENTS
		IM.Update(isRunning);

		// UPDATE
		Update();

		// DRAW
		Draw();

	}
}

void GameEngine::Run() {
	Init();
	GameLoop();
}
void GameEngine::Draw()
{
	SDL_RenderClear(RR);
	SM.Draw();
	SDL_RenderPresent(RR);
}
void GameEngine::Update()
{
	pc->Update();
	SM.Update();


}
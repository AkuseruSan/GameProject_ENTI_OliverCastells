#include <string>			// Needed to process error messages
#include <time.h>
#include <SDL\SDL.h>		// Always needs to be included for an SDL app
#include <SDL\SDL_ttf.h>	// Used for loading fonts and rendering text
#include <SDL\SDL_image.h>	// Used for loading and drawing sprites
#include <SDL\SDL_mixer.h>	// Used for loading and playing audio files

#include "GameEngine.hpp"

int main(int, char*[]) {
	using namespace std::string_literals; // Enables to use an array of characters with an "s" at the end as an string literal
	srand(time(NULL));
	try {
		// --- INIT ---

		GE.Run();


		//SDL_Texture *playerTexture{ IMG_LoadTexture(RR, "../../res/gfx/blue.png") };
		//if (bgTexture == nullptr || playerTexture == nullptr) throw "Unable to create the SDL textures for the sprites"s;

		//SDL_Rect playerRect{ (SCREEN_WIDTH >> 1) - 50, (SCREEN_HEIGHT >> 1) - 50, 100, 100 };
		//SDL_Rect playerTarget{ 0, 0, 100, 100 };

		//SDL_QueryTexture(texturePlayer, nullptr, nullptr, &rectSrc.w, &rectSrc.h);
		//rectSrc.w >>= 1, rectSrc.h >>= 1;
		
		// --- TEXT ---

		// --- DESTROY ---
		Mix_CloseAudio();
		//SDL_DestroyTexture(bgTexture);
		//SDL_DestroyTexture(textTexture);
		//SDL_DestroyTexture(playerTexture);
		SDL_DestroyRenderer(RR);
		SDL_DestroyWindow(WW);
	}
	catch (const std::string &msg) { // Catch exceptions and print them as an error msg box
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", ("Description: " + msg + "\nSDL Error:" + SDL_GetError()).c_str(), nullptr);
	}
	// --- EXIT ---
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}
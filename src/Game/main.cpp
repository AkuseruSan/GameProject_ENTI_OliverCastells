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
		// --- INIT & RUN ---

		GE.Run();//Función de ejecución principal del juego.


		// --- DESTROY ---
		Mix_CloseAudio();

		SDL_DestroyRenderer(RR);
		SDL_DestroyWindow(WW);
	}
	catch (const std::string &msg) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", ("Description: " + msg + "\nSDL Error:" + SDL_GetError()).c_str(), nullptr);
	}
	// --- EXIT ---
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}
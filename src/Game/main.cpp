#include <string>			// Needed to process error messages
#include <SDL\SDL.h>		// Always needs to be included for an SDL app
#include <SDL\SDL_ttf.h>	// Used for loading fonts and rendering text
#include <SDL\SDL_image.h>	// Used for loading and drawing sprites
#include <SDL\SDL_mixer.h>	// Used for loading and playing audio files

#include "GameEngine.hpp"


int main(int, char*[]) {
	using namespace std::string_literals; // Enables to use an array of characters with an "s" at the end as an string literal
	try {
		// --- INIT ---

		GE.Run();

		// --- SPRITES ---
		SDL_Texture *bgTexture{ IMG_LoadTexture(RR, "../../res/gfx/bg.jpg") };
		SDL_Texture *playerTexture{ IMG_LoadTexture(RR, "../../res/gfx/blue.png") };
		if (bgTexture == nullptr || playerTexture == nullptr) throw "Unable to create the SDL textures for the sprites"s;
		SDL_Rect bgRect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
		SDL_Rect playerRect{ (SCREEN_WIDTH >> 1) - 50, (SCREEN_HEIGHT >> 1) - 50, 100, 100 };
		SDL_Rect playerTarget{ 0, 0, 100, 100 };
		//SDL_Rect rectSrc{ 0, 0, 0, 0 };
		//SDL_QueryTexture(texturePlayer, nullptr, nullptr, &rectSrc.w, &rectSrc.h);
		//rectSrc.w >>= 1, rectSrc.h >>= 1;
		
		// --- TEXT ---
		TTF_Font *font{ TTF_OpenFont("../../res/fnt/candy.ttf", 50) };
		if (font == nullptr) throw "Unable to initialize the TTF_Font"s;
		SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "DELICIOUS", SDL_Color{ 255, 0, 255, 255 }) };
		if (tmpSurf == nullptr) TTF_CloseFont(font), throw "Unable to create the SDL text surface"s;
		SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(RR, tmpSurf) };
		SDL_Rect textRect{ (SCREEN_WIDTH >> 1) - (tmpSurf->w >> 1),
			static_cast<int>(SCREEN_HEIGHT*.8f) - (tmpSurf->h >> 1),
			tmpSurf->w, tmpSurf->h };
		SDL_FreeSurface(tmpSurf);
		TTF_CloseFont(font);

		// --- AUDIO ---
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) throw "Unable to initialize SDL_mixer audio systems"s;
		Mix_Music *soundtrack{ Mix_LoadMUS("../../res/sfx/theme.wav") };
		if (!soundtrack) throw "Unable to load the Mix_Music soundtrack"s;
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(soundtrack, -1);

		// --- DESTROY ---
		Mix_CloseAudio();
		SDL_DestroyTexture(bgTexture);
		SDL_DestroyTexture(textTexture);
		SDL_DestroyTexture(playerTexture);
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
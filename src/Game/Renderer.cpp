#include "Renderer.hpp"



SDL_Renderer* Renderer::GetRenderer()
{
	return myRenderer;
}
void Renderer::Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect)
{
	SDL_RenderCopy(myRenderer, tex, sourceRect, &destRect);
}

void Renderer::RenderText(char* msg, SDL_Color col, SDL_Rect& destRect)
{
	SDL_RenderCopy(myRenderer, GetTextAsTexture(msg, col), nullptr, &destRect);
}

void Renderer::RenderRect(SDL_Rect* r, SDL_Color col)
{
	SDL_SetRenderDrawColor(myRenderer, col.r, col.g, col.b, col.a);
	SDL_RenderFillRect(myRenderer, r);
	SDL_SetRenderDrawColor(myRenderer, 0, 0, 0, 0);
	
}

void Renderer::Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect, int degrees)
{
	SDL_RenderCopyEx(myRenderer, tex, sourceRect, &destRect, degrees, nullptr, SDL_FLIP_NONE);
}

TTF_Font* Renderer::GetFont()
{
	return font;
}

SDL_Rect* Renderer::GetAtlasRegion(Vector position)
{
	int w, h;

	SDL_QueryTexture(GetTexture(ATLAS_TEXTURE.key), NULL, NULL, &w, &h);

	return new SDL_Rect{ (w / ATLAS_WIDTH)*position.x, (h / ATLAS_HEIGHT)*position.y, w / ATLAS_WIDTH, h / ATLAS_HEIGHT };
}

void Renderer::LoadTexture(std::string name, const char* path)
{
	std::pair<std::string, SDL_Texture*> aux{ name, IMG_LoadTexture(RR, path) };
	sprites.insert(aux);
}

SDL_Texture* Renderer::GetTextAsTexture(char* text, SDL_Color col)
{
	SDL_Surface* sur{ TTF_RenderText_Blended(font, text, col) };
	SDL_Texture* tex{ SDL_CreateTextureFromSurface(RR, sur) };
	
	return tex;
}

SDL_Texture* Renderer::GetTexture(std::string key)
{
	if (sprites[key] == nullptr) throw "No texture stored with that key value!";
	return sprites[key];
}


Renderer::Renderer() {
	font = { TTF_OpenFont("../../res/fnt/arial.ttf", 50) };
	myRenderer = SDL_CreateRenderer(WW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
	for (auto it = sprites.begin(); it != sprites.end(); ++it)
	{
		SDL_DestroyTexture(it->second);
		//delete(it->second);
	}

}

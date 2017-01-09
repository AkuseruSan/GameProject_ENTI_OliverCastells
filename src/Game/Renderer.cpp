#include "Renderer.hpp"



SDL_Renderer* Renderer::GetRenderer()
{
	return myRenderer;
}
void Renderer::Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect)
{
	SDL_RenderCopy(myRenderer, tex, sourceRect, &destRect);
}

void Renderer::Render(SDL_Texture* tex, SDL_Rect* sourceRect, SDL_Rect& destRect, int degrees)
{
	SDL_RenderCopyEx(myRenderer, tex, sourceRect, &destRect, degrees, nullptr, SDL_FLIP_NONE);
}

void Renderer::RenderText()
{

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

SDL_Texture* Renderer::GetTexture(std::string key)
{
	if (sprites[key] == nullptr) throw "No texture stored with that key value!";
	return sprites[key];
}


Renderer::Renderer() {
	myRenderer = SDL_CreateRenderer(WW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
std::map<std::string, SDL_Texture*> sprites;


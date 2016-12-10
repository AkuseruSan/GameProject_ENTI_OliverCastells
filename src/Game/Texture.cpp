#include <string>
#include <SDL\SDL_image.h>
#include "Vector.hpp"
#include "Renderer.hpp"

class Texture
{
public:
	
	Texture();
	~Texture();

	bool loadTexturePath(std::string path);

	void Free();

	void Render(int x, int y, SDL_Rect* clip = NULL);

	Vector GetSize();

private:
	Vector size;
	
};

void Texture::Render(int x, int y, SDL_Rect* clip = NULL)
{
	SDL_Rect quad = { x, y, size.x, size.y };

	if (clip != NULL)
	{
		quad.w = clip->w;
		quad.h = clip->h;
	}

	//SDL_RenderCopy(R
}
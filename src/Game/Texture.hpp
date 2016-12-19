#include <string>
#include <SDL\SDL_image.h>
#include "Renderer.hpp"
#include "Vector.hpp"

class Texture
{
public:
	
	Texture();
	~Texture();

	bool loadTexturePath(std::string path);

	void Free();

	void Render(int x, int y, SDL_Rect* clip = NULL);

	Vector2 GetSize();

private:
	//Vector2 size;

};
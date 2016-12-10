#include <SDL\SDL_image.h>
#include "GameObject.hpp"
#include "Vector.hpp"

enum CellType {VOID, OBSTACLE, POW, PLAYER};

class Cell : GameObject
{
public:
	Cell(CellType t, SDL_Texture& tx, int posX, int posY);
	~Cell();
	CellType type;
	SDL_Texture* tex;
	Vector position;

	void Update();
	void Draw();
};

Cell::Cell(CellType t, SDL_Texture& tx, int posX, int posY)
{
	type = t;
	tex = &tx;

	position.x = posX;
	position.y = posY;
}

Cell::~Cell()
{
	delete(tex);
}
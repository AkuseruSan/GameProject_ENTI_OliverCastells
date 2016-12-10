#include <SDL\SDL_image.h>

enum CellType {VOID, OBSTACLE, POW, PLAYER};

class Cell
{
public:
	Cell(CellType t, SDL_Texture& tx);
	~Cell();
	CellType type;
	SDL_Texture* tex;

};

Cell::Cell(CellType t, SDL_Texture& tx)
{

}

Cell::~Cell()
{
	delete(tex);
}
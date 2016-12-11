#include <SDL\SDL_image.h>
#include "GameObject.hpp"
#include "Vector.hpp"
#include "Texture.hpp"

enum CellType {VOID, OBSTACLE, POW, PLAYER};

class Cell
{
public:
	Cell(Vector gridPos, Vector worldPos);
	~Cell();
	CellType type;
	Vector gridPosition, worldPosition;

	GameObject* assignedObject;

	void Draw();
};

Cell::Cell(Vector gridPos, Vector worldPos)
{
	gridPosition.x = gridPos.x;
	gridPosition.y = gridPos.y;

	worldPosition.x = worldPos.x;
	worldPosition.y = worldPos.y;
}

Cell::~Cell()
{
	delete(assignedObject);
}

void Cell::Draw()
{
	assignedObject->Update();
}
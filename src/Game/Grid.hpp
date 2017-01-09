#include "System.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <list>

class Grid
{
private:
	int w, h;
	GameObject* gameObjectsGrid[GRID_LINES][GRID_COLUMNS];

public:
	Grid();

	Vector GetSize();
	GameObject* GetObjectFromGrid(int i, int j);

	void Update();

	void Draw();
};
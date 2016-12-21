#include "System.hpp"
//#include "Vector.hpp"
//#include "GameObject.hpp"
#include "GameEngine.hpp"

class Grid
{
private:

	GameObject* gameObjectsGrid[GRID_WIDTH][GRID_HEIGHT];

public:
	Grid();
	Grid(int);

	void Update();

	void Draw();

	Vector GetWorldPosition(int, int);
};
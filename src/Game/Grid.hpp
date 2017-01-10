#include "System.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <list>
#include "DataManager.hpp"

class Grid
{
private:
	int size;
	GameObject** gameObjectsGrid;

public:
	Grid() = default;
	Grid(int);

	int GetSize();
	GameObject* GetObjectFromGrid(int i, int j);

	void Update();

	void Draw();
};
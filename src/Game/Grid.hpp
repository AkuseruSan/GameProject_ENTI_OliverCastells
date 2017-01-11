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
	std::list<Vector> obstacles;

public:
	Grid() = default;
	Grid(int);
	~Grid();

	int GetSize();
	void GenerateApple();
	void GenerateObstacles();
	void DeleteObstacles();
	GameObject* GetObjectFromGrid(int i, int j);

	void Update();

	void Draw();
};
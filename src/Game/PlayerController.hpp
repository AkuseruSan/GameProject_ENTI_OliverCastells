#include "SceneManager.hpp"
#include "Vector.hpp"

class PlayerController
{
private:
	Grid* activeGrid;
	Vector pos;
public:
	PlayerController()
	{
		activeGrid = &SM.GetCurentScene()->GetGrid();
		pos = activeGrid->GetSize().x/2;
	}
	~PlayerController()
	{

	}
};
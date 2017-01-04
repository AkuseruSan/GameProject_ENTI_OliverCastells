#pragma once

#include "SceneManager.hpp"
#include "Grid.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"


enum Dir {UP, DOWN, LEFT, RIGHT};
class PlayerController
{
private:
	Grid* activeGrid;
	GameObject* controlledObject;
	Vector pos;

public:
	PlayerController()
	{
		activeGrid = &SM.GetCurentScene()->GetGrid();
		pos = Vector{ 0,0 };
	}
	~PlayerController()
	{

	}

	void Update()
	{
		controlledObject = activeGrid->GetObjectFromGrid(pos.x, pos.y);

		//Move(RIGHT);
	}

	void Move(Dir dir)
	{
		Vector dirVec;
		
		controlledObject->SetDefaultType();

		switch (dir)
		{
			case UP:
			{
				pos.y - 1;
			}break;
			case DOWN:
			{
				pos.y + 1;
			}break;
			case LEFT:
			{
				pos.x - 1;
			}break;
			case RIGHT:
			{
				pos.x + 1;
			}break;
			default:
				break;
		}

		controlledObject = activeGrid->GetObjectFromGrid(pos.x, pos.y);
		controlledObject->SetType(GameObjectType::SNAKE);

	}
};
#pragma once

#include "SceneManager.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <math.h>


enum Dir {UP, DOWN, LEFT, RIGHT};
class PlayerController
{
private:
	GameObject* controlledObject;
	Vector pos;

public:
	PlayerController()
	{
		pos = Vector{ 0,0 };
	}
	~PlayerController()
	{

	}

	void Update()
	{
		controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(pos.x, pos.y);

		Move(RIGHT);
	}

	void Move(Dir dir)
	{
		Vector dirVec;
		
		controlledObject->SetDefaultType();

		switch (dir)
		{
			case UP:
			{
				if(pos.y != 0) pos.y -= 1;
			}break;
			case DOWN:
			{
				if(pos.y != SM.GetCurentScene()->GetGrid()->GetSize().y - 1) pos.y += 1;
			}break;
			case LEFT:
			{
				if (pos.x != 0) pos.x -= 1;
			}break;
			case RIGHT:
			{
				if (pos.x < SM.GetCurentScene()->GetGrid()->GetSize().x - 1) pos.x += 1;
			}break;
			default:
				break;
		}


		controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(pos.x, pos.y);
		controlledObject->SetType(GameObjectType::SNAKE);

	}
};
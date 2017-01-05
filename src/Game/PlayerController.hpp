#pragma once

#include "SceneManager.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <math.h>


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

		Move();
	}

	void Die()
	{

	}

	void Move()
	{
		Vector dirVec;
		
		controlledObject->SetDefaultType();

		switch (IM.GetDirction())
		{
			case DIR_UP:
			{
				if(pos.y != 0) pos.y -= 1;
			}break;
			case DIR_DOWN:
			{
				if(pos.y != SM.GetCurentScene()->GetGrid()->GetSize().y - 1) pos.y += 1;
			}break;
			case DIR_LEFT:
			{
				if (pos.x != 0) pos.x -= 1;
			}break;
			case DIR_RIGHT:
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
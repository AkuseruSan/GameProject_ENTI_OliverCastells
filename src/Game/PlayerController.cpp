#include "PlayerController.hpp"

PlayerController::PlayerController()
{
	InitSnake();
}
PlayerController::~PlayerController()
{

}

void PlayerController::Update()
{
	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.front().x, body.front().y);

	Move();
}

void PlayerController::InitSnake()
{
	for (int i = 0; i < 5; i++)
	{
		body.push_back(Vector{ 0,0 });
	}
}

void PlayerController::Die()
{

}

void PlayerController::Move()
{
	Vector dirVec;
	Vector pos = body.front();

	switch (IM.GetDirction())
	{
	case DIR_UP:
	{
		if (pos.y != 0)
		{
			pos.y -= 1;
			
		}
	}break;
	case DIR_DOWN:
	{
		if (pos.y != SM.GetCurentScene()->GetGrid()->GetSize().y - 1) pos.y += 1;
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

	body.push_front(pos);
	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.back().x, body.back().y);
	controlledObject->SetDefaultType();
	body.pop_back();

	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.front().x, body.front().y);
	controlledObject->SetType(GameObjectType::SNAKE);

}
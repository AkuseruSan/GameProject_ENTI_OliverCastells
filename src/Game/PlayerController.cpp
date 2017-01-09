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
	rotation = 0;
	for (int i = 0; i < 5; i++)
	{
		body.push_back(Vector{ 10,10 });
	}
}

void PlayerController::Die()
{

}

void PlayerController::Move()
{
	//Vector dirVec;
	Vector pos = body.front();
	controlledObject->SetType(GameObjectType::SNAKE);

	switch (IM.GetDirction())
	{
	case DIR_UP:	if (pos.y != 0) {pos.y -= 1;rotation = 0;}	break;
	case DIR_DOWN:	if (pos.y != SM.GetCurentScene()->GetGrid()->GetSize() - 1) {pos.y += 1;rotation = 180;}break;
	case DIR_LEFT:	if (pos.x != 0) {pos.x -= 1;rotation = 270;}break;
	case DIR_RIGHT:	if (pos.x < SM.GetCurentScene()->GetGrid()->GetSize() - 1) {pos.x += 1;	rotation = 90;}	break;
	}

	body.push_front(pos);
	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.back().x, body.back().y);
	controlledObject->SetDefaultType();
	body.pop_back();

	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.back().x, body.back().y);
	controlledObject->SetType(GameObjectType::SNAKEEND);

	controlledObject = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(body.front().x, body.front().y);
	controlledObject->SetType(GameObjectType::SNAKESTART);
	controlledObject->SetRotation(rotation);

}
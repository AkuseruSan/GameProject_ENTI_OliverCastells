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
	CheckCollision();
}

void PlayerController::InitSnake()
{
	lives = INITIAL_LIVES;
	rotation = 0;
	collider = GameObjectType::NONE;
	int center = 10;//SM.GetCurentScene()->GetGrid()->GetSize() / 2;
	for (int i = 0; i < 3; i++)
		body.push_back(Vector{ center, center });
}

void PlayerController::Die()
{
	IM.ResetDirection();
	if (lives > 1) {
		lives--;
		for each (Vector v in body)
			SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(v.x, v.y)->SetDefaultType();
		body.clear();
		int center =  SM.GetCurentScene()->GetGrid()->GetSize() / 2;
		for (int i = 0; i < 3; i++)
			body.push_back(Vector{ center, center });
	}
	else {

	}
	if(collider == BLOCK) controlledObject->SetType(BLOCK);
	collider = NONE;
}

void PlayerController::CheckCollision() {
	switch (collider)
	{
	case NONE:
		break;
	case APPLE:
		break;
	default:	Die();	break;
	}
}

void PlayerController::Move()
{
	Vector pos = body.front();
	controlledObject->SetType(GameObjectType::SNAKE);

	switch (IM.GetDirction())
	{
	case DIR_UP:	if (pos.y != 0) {pos.y -= 1;rotation = 0;}	break;
	case DIR_DOWN:	if (pos.y != SM.GetCurentScene()->GetGrid()->GetSize() - 1) {pos.y += 1;rotation = 180;}break;
	case DIR_LEFT:	if (pos.x != 0) {pos.x -= 1;rotation = 270;}break;
	case DIR_RIGHT:	if (pos.x < SM.GetCurentScene()->GetGrid()->GetSize() - 1) {pos.x += 1;	rotation = 90;}	break;
	}
	
	if(IM.GetDirction() != NULL)
		collider = SM.GetCurentScene()->GetGrid()->GetObjectFromGrid(pos.x, pos.y)->GetType();

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
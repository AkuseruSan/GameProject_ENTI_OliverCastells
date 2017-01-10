#include "PlayerController.hpp"

PlayerController::PlayerController(Scene* os)
{
	ownerScene = os;
	InitSnake();
}
PlayerController::~PlayerController()
{
	delete(apple);
	delete(controlledObject);
}

void PlayerController::Update()
{
	controlledObject = ownerScene->GetGrid()->GetObjectFromGrid(body.front().x, body.front().y);

	Move();
	CheckCollision();
}

void PlayerController::InitSnake()
{
	level = 0;
	score = 0;
	eatenApples = 0;
	foodInc = 0;
	lives = INITIAL_LIVES;
	rotation = 0;
	speed = INITIAL_SPEED;
	collider = GameObjectType::NONE;
	apple = nullptr;
	int center = ownerScene->GetGrid()->GetSize() / 2;
	for (int i = 0; i < 3; i++)
		body.push_back(Vector{ center, center });
	GenerateApple();
}

void PlayerController::Die()
{
	IM.ResetDirection();
	//Pierde una vida y reinicia el nivel.
	if (lives > 1) {
		lives--;
		for each (Vector v in body)
			ownerScene->GetGrid()->GetObjectFromGrid(v.x, v.y)->SetDefaultType();
		body.clear();
		int center = ownerScene->GetGrid()->GetSize() / 2;
		for (int i = 0; i < 3; i++)
			body.push_back(Vector{ center, center });
	}
	else {
		DM.SetState(GameState::GAME_OVER);
	}
	if(collider == BLOCK) controlledObject->SetType(BLOCK);
	collider = NONE;
	eatenApples = 0;
	speed = INITIAL_SPEED;
}

void PlayerController::GenerateApple() {
	Vector aPos{ (int)rand() % ownerScene->GetGrid()->GetSize() , (int)rand() % ownerScene->GetGrid()->GetSize() };
	auto aux = ownerScene->GetGrid()->GetObjectFromGrid(aPos.x, aPos.y);
	if (aux->GetType() == NONE) aux->SetType(APPLE);
	else GenerateApple();
}

void PlayerController::LevelUp() {
	foodInc += ICREMENT_FOOD * std::stoi(DM.GetDifficultyData(ownerScene->GetDifficulty())->first_attribute("food_increment")->value(), nullptr, 10);
	eatenApples = 0;
	level++;
	speed = INITIAL_SPEED;
}

void PlayerController::CheckCollision() {
	switch (collider)
	{
	case NONE:			break;
	case APPLE: {
		eatenApples++;
		score += (eatenApples * SCORE_UP);
		//speed += score / 1000;
		body.push_back(body.back());
		if (eatenApples >= INITIAL_FOOD * (std::stoi(DM.GetDifficultyData(ownerScene->GetDifficulty())->first_attribute("food")->value()), nullptr, 1) + foodInc)
			LevelUp();
		GenerateApple();
	}	break;
	default:	Die();	break;
	}
}

void PlayerController::Move()
{
	Vector pos = body.front();
	controlledObject->SetType(GameObjectType::SNAKE);
	
	switch (IM.GetDirction())
	{
	case DIR_UP:	if (pos.y != 0) {pos.y -= speed; rotation = 0;}	break;
	case DIR_DOWN:	if (pos.y != ownerScene->GetGrid()->GetSize() - 1) {pos.y += speed; rotation = 180;}break;
	case DIR_LEFT:	if (pos.x != 0) {pos.x -= speed; rotation = 270;}break;
	case DIR_RIGHT:	if (pos.x < ownerScene->GetGrid()->GetSize() - 1) {pos.x += speed;	rotation = 90;}	break;
	}
	
	if(IM.GetDirction() != NULL)
		collider = ownerScene->GetGrid()->GetObjectFromGrid(pos.x, pos.y)->GetType();

	body.push_front(pos);
	controlledObject = ownerScene->GetGrid()->GetObjectFromGrid(body.back().x, body.back().y);
	controlledObject->SetDefaultType();
	body.pop_back();

	controlledObject = ownerScene->GetGrid()->GetObjectFromGrid(body.back().x, body.back().y);
	controlledObject->SetType(GameObjectType::SNAKEEND);

	controlledObject = ownerScene->GetGrid()->GetObjectFromGrid(body.front().x, body.front().y);
	controlledObject->SetType(GameObjectType::SNAKESTART);
	controlledObject->SetRotation(rotation);

}
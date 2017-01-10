#pragma once

#include "SceneManager.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <deque>
#include <math.h>
#include "InputManager.hpp"

#define INITIAL_LIVES 3

class PlayerController
{
private:
	GameObject* controlledObject;
	GameObject* apple;
	std::deque<Vector> body;
	GameObjectType collider;
	int rotation;
	int lives;
	long int score;
	int eateApples;

public:
	PlayerController();
	~PlayerController();

	void InitSnake();
	void Update();

	void Die();
	void Move();
	void CheckCollision();
	void GenerateApple();
};
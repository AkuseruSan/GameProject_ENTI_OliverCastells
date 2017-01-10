#pragma once

#include "SceneManager.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <deque>
#include <math.h>
#include "InputManager.hpp"
#include "TimeManager.hh"

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
	int speed;
	long int score;
	int eatenApples;

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
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
	int foodInc;
	int level;

	void Die();
	void Move();
	void CheckCollision();
	void GenerateApple();
	void InitSnake();
	void LevelUp();

public:
	PlayerController();
	~PlayerController();

	void Update();

};
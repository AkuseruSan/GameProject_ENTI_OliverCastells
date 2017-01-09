#pragma once

#include "SceneManager.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <deque>
#include <math.h>
#include "InputManager.hpp"


class PlayerController
{
private:
	GameObject* controlledObject;
	std::deque<Vector> body;
	int rotation;

public:
	PlayerController();
	~PlayerController();

	void InitSnake();
	void Update();

	void Die();

	void Move();
};
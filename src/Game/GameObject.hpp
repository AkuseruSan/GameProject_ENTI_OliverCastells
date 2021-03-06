#pragma once

#include "AuxLib.hpp"
#include "Renderer.hpp"


enum GameObjectType {NONE, BLOCK, APPLE, SNAKE, SNAKEEND, SNAKESTART};

class GameObject
{
private:
	Vector position;
	int width, height;
	int rotation;
	Vector atlasSection;


	SDL_Rect* bounds;
	SDL_Texture* texture;
	GameObjectType type;

public:	
	GameObject() = default;
	GameObject(int, int, int, int, SDL_Texture*, int);
	~GameObject();

	void SetPosition(int, int);
	Vector GetPosition();

	virtual void Draw();
	virtual void Update();

	GameObjectType GetType();
	
	void SetBounds();
	void SetType(GameObjectType type);
	void SetDefaultType();
	void SetRotation(int);
};
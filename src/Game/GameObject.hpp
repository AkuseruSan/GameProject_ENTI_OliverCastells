#pragma once
//#include "SDL\SDL.h"
#include "Vector.hpp"
#include "Renderer.hpp"
//#include "SceneManager.hpp"


enum GameObjectType {NONE, BLOCK, APPLE, SNAKE};

class GameObject
{
private:
	Vector position;
	int width, height;

	SDL_Rect* bounds;
	SDL_Texture* texture;
	GameObjectType type;

public:	
	GameObject() = default;
	GameObject(int, int, int, int, SDL_Texture*);

	void SetPosition(int, int);
	Vector GetPosition();

	virtual void Draw();
	virtual void Update();

	void SetBounds();
};

GameObject::GameObject(int posX, int posY, int w, int h, SDL_Texture* tex)
{
	type = NONE;

	width = w;
	height = h;

	SetPosition(posX, posY);

	texture = tex;

	SetBounds();
}

void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector GameObject::GetPosition()
{
	return position;
}

void GameObject::Draw()
{
	switch (type)
	{
	case NONE:
	{
		R.Render(texture, R.GetAtlasRegion(ATLAS_NULL_RECT), *bounds);
	}
		break;
	case BLOCK:
	{
		R.Render(texture, R.GetAtlasRegion(ATLAS_BLOCK_RECT), *bounds);
	}
		break;
	case APPLE:
	{
		R.Render(texture, R.GetAtlasRegion(ATLAS_APPLE_RECT), *bounds);
	}
		break;
	case SNAKE:
	{
		R.Render(texture, R.GetAtlasRegion(ATLAS_SNAKE_RECT), *bounds);
	}
		break;
	default:
		break;
	}
}

void GameObject::Update()
{
	//SetBounds();
}

void GameObject::SetBounds()
{
	bounds = new SDL_Rect{ position.x, position.y, width, height };
}
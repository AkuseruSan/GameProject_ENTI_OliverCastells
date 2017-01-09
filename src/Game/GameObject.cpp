#include "GameObject.hpp"

GameObject::GameObject(int posX, int posY, int w, int h, SDL_Texture* tex, int r)
{
	type = NONE;

	width = w;
	height = h;
	rotation = r;

	SetPosition(posX, posY);

	texture = tex;

	SetBounds();
}

void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector GameObject::GetPosition() { return position; }
void GameObject::SetType(GameObjectType t) { type = t; }
void GameObject::SetDefaultType() { type = NONE; }
void GameObject::SetRotation(int r) { rotation = r; }

void GameObject::Draw()
{
	switch (type)
	{
	case NONE:		R.Render(texture, R.GetAtlasRegion(ATLAS_NULL_RECT), *bounds, rotation);	break;
	case BLOCK:		R.Render(texture, R.GetAtlasRegion(ATLAS_BLOCK_RECT), *bounds, rotation);	break;
	case APPLE:		R.Render(texture, R.GetAtlasRegion(ATLAS_APPLE_RECT), *bounds, rotation);	break;
	case SNAKE:		R.Render(texture, R.GetAtlasRegion(ATLAS_SNAKE_RECT), *bounds, rotation);	break;
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
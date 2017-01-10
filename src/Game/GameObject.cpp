#include "GameObject.hpp"

GameObject::GameObject(int posX, int posY, int w, int h, SDL_Texture* tex, int r)
{
	type = NONE;

	width = w;
	height = h;
	rotation = r;
	
	atlasSection = ATLAS_NULL_RECT;

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
void GameObject::SetDefaultType() { type = NONE; rotation = 0; }
void GameObject::SetRotation(int r) { rotation = r; }
GameObjectType GameObject::GetType() { return type; }

void GameObject::Draw()
{
	R.Render(texture, R.GetAtlasRegion(atlasSection), *bounds, rotation);
}

void GameObject::Update()
{
	switch (type)
	{
		case NONE:			atlasSection = ATLAS_NULL_RECT;			break;
		case BLOCK:			atlasSection = ATLAS_BLOCK_RECT;		break;
		case APPLE:			atlasSection = ATLAS_APPLE_RECT;		break;
		case SNAKE:			atlasSection = ATLAS_SNAKE_RECT;		break;
		case SNAKEEND:		atlasSection = ATLAS_SNAKEEND_RECT;		break;
		case SNAKESTART:	atlasSection = ATLAS_SNAKESTART_RECT;	break;
	}
}

void GameObject::SetBounds()
{
	bounds = new SDL_Rect{ position.x, position.y, width, height };
}
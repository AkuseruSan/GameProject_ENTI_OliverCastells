#include "SDL\SDL.h"
#include "Vector.hpp"
//#include "SceneManager.hpp"

class GameObject
{
private:
	Vector position;
	int width, height;
	SDL_Rect* bounds;

public:	
	GameObject(int, int, int, int);

	void SetPosition(int, int);
	Vector GetPosition();

	virtual void Draw();
	virtual void Update();

	void UpdateBounds();
};

GameObject::GameObject(int posX, int posY, int w, int h)
{
	width = w;
	height = h;

	SetPosition(posX, posY);
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

}

void GameObject::Update()
{
	UpdateBounds();
}

void GameObject::UpdateBounds()
{
	bounds = new SDL_Rect{ position.x - width / 2, position.y - height / 2, position.x + width / 2, position.y + height / 2 };
}
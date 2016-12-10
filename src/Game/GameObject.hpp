#include "SDL\SDL.h"
#include "Vector.hpp"

class GameObject
{
public:	
	GameObject();
	
	Vector screenPosition, gridPosition;

	void SetPosition();

	virtual void Draw();
	virtual void Update();
};

void GameObject::SetPosition()
{

}

GameObject::GameObject()
{

}

void GameObject::Draw()
{

}

void GameObject::Update()
{

}
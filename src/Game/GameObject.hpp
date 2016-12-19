#include "SDL\SDL.h"
#include "Vector.hpp"
//#include "SceneManager.hpp"

class GameObject
{
public:	
	GameObject();

	Vector position;

	void SetPosition();

	virtual void Draw();
	virtual void Update();
};

void GameObject::SetPosition()
{
	//SM
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
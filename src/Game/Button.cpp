#include "Button.hpp"


Button::Button(SDL_Rect b, char* msg)
{
	bounds = b;
	text = msg;
}

void Button::Draw()
{
	R.RenderText(text, col, bounds);
}

bool Button::Clicked()
{
	if (IM.GetMousePosition().x >= bounds.x && IM.GetMousePosition().x <= bounds.x + bounds.w &&
		IM.GetMousePosition().y >= bounds.y && IM.GetMousePosition().y <= bounds.y + bounds.h &&
		IM.MouseClicked())
		return true;

	else return false;
}
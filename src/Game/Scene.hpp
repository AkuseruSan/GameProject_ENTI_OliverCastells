#pragma once
#include <iostream>
#include "Grid.hpp"
#include <list>
#include "XML\rapidxml.hpp"
#include "Renderer.hpp"

class Scene
{
public:
	Scene() = default;
	Scene(int);
	~Scene();

	Grid* GetGrid()
	{
		return &grid;
	}

	int GetDifficulty();

	void ResetTimer();

	void Update();
	void Draw();

	float lvlCounter;
	float lvlTime;
private:

	Grid grid;
	SDL_Texture* background;
	SDL_Rect* timeSlider;
	SDL_Rect* backSlider;

	void UpdateSlider();
	void DrawSlider();

	int difficulty;
};
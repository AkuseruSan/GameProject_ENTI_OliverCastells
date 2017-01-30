#include "Scene.hpp"

Scene::Scene(int diff) 
{ 
	grid = Grid(diff); 
	difficulty = diff;
	timeSlider = new SDL_Rect{ SCREEN_WIDTH/2 - SCREEN_WIDTH/8, SCREEN_HEIGHT/24, SCREEN_WIDTH/4, SCREEN_HEIGHT/50 };
	backSlider = new SDL_Rect{ SCREEN_WIDTH / 2 - SCREEN_WIDTH / 8, SCREEN_HEIGHT / 24, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 50 };

	lvlTime = strtod(DM.GetDifficultyData(diff)->first_attribute("time")->value(), NULL) * INITIAL_LEVEL_TIME;
	lvlCounter = lvlTime;
	
	DM.SetRankingData(diff);
}

void Scene::ResetTimer() {
	lvlTime = strtod(DM.GetDifficultyData(difficulty)->first_attribute("time")->value(), NULL) * INITIAL_LEVEL_TIME;
	lvlCounter = lvlTime;
}

void Scene::Update() 
{ 
	grid.Update();
	UpdateSlider();

	lvlCounter -= TM.GetDeltaTime();
	/*std::cout << lvlCounter << std::endl;*/
}

void Scene::Draw() 
{ 
	grid.Draw();
	DrawSlider();
}

int Scene::GetDifficulty() { return difficulty; }

void Scene::UpdateSlider()
{
	timeSlider->w = MAP_VALUE(lvlCounter, 0, lvlTime, 0, backSlider->w);

}

void Scene::DrawSlider()
{
	R.RenderRect(backSlider, SDL_Color{ 0,0,0,0 });
	R.RenderRect(timeSlider, SDL_Color{ 255,255,255,0 });
}

Scene::~Scene()
{
	SDL_DestroyTexture(background);
	//delete(background);
}

//CUando cambio de nivel tiene que hacer esto

/*{
//EMpezar nivel

contadorNivel = TM.GetCurTIme() + tiempoNivel;

if(TM.GetCUrrentTime()=>contadorNivel{
//Codigo de perder una vida

Al slider.set() le pasais el tiempoNivel y lo que tiene que hacer es

Slider.Imagen.w = TM.GetCurrentTIme()/tiempoNivel*100;



}

}*/
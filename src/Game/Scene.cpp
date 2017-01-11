#include "Scene.hpp"

Scene::Scene(int diff) { grid = Grid(diff); difficulty = diff; }

void Scene::Update() { grid.Update(); }

void Scene::Draw() { grid.Draw(); }

int Scene::GetDifficulty() { return difficulty; }

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
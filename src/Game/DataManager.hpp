#pragma once
#include "XML\rapidxml.hpp"
#include "XML\rapidxml_print.hpp"
#include "XML\rapidxml_utils.hpp"
#include "XML\rapidxml_iterators.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define DM DataManager::GetInstance()

enum GameState { MAIN_MENU, GAME, GAME_OVER };

struct PlayerData {
	std::string name;
	int score;
};

class DataManager
{
public:
	static DataManager& GetInstance();

	void LoadFileXML(char* path);

	void SaveFileXML(char* path);

	void ClearData();

	PlayerData ReadBinary(std::string);
	void WriteBinary(std::string, PlayerData);
	
	rapidxml::xml_document<>& GetDataRoot();
	rapidxml::xml_node<>* GetDifficultyData(int);

	GameState GetState();
	void SetState(GameState);

private:
	DataManager();

	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);

	rapidxml::xml_document<> data;
	std::ifstream readFile;
	std::ofstream writeFile;

	std::string content;
	GameState state;
};
#include "DataManager.hpp"

DataManager& DataManager::GetInstance()
{
	static DataManager inst = DataManager();
	return inst;
}

void DataManager::LoadFileXML(char* path)
{
	readFile = std::ifstream(path);

	std::stringstream buffer;
	buffer << readFile.rdbuf();
	readFile.close();

	content = buffer.str();
	data.parse<rapidxml::parse_default>(&content[0]);
}

void DataManager::SaveFileXML(char* path)
{
	writeFile = std::ofstream(path);

	writeFile << data;

	data.clear();
}

void DataManager::ClearData()
{
	data.clear();
}

rapidxml::xml_document<>& DataManager::GetDataRoot()
{
	if (data.first_node() == 0) throw "No loaded data!";
	else return data;

}

rapidxml::xml_node<>* DataManager::GetDifficultyData(int d)
{
	if (d == 0)
	{
		return GetDataRoot().first_node("GameData")->first_node("Difficulty")->first_node("Easy");
	}
	else if (d == 1)
	{
		return GetDataRoot().first_node("GameData")->first_node("Difficulty")->first_node("Medium");
	}
	else if (d == 2)
	{
		return GetDataRoot().first_node("GameData")->first_node("Difficulty")->first_node("Hard");
	}
	else throw "THAT DIFFICULTY LEVEL DOESN'T EXIST";
}

DataManager::DataManager()
{

}

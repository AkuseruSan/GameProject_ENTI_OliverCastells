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

rapidxml::xml_document<>& DataManager::GetData()
{
	if (data.first_node() == 0) throw "No loaded data!";
	else return data;

}

DataManager::DataManager()
{

}

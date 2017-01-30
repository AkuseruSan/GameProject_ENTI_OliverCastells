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
		return GetDataRoot().first_node("GameData")->first_node("Scene")->first_node("Easy");
	}
	else if (d == 1)
	{
		return GetDataRoot().first_node("GameData")->first_node("Scene")->first_node("Medium");
	}
	else if (d == 2)
	{
		return GetDataRoot().first_node("GameData")->first_node("Scene")->first_node("Hard");
	}
	else throw "THAT DIFFICULTY LEVEL DOESN'T EXIST";
}

PlayerData* DataManager::ReadBinary(std::string path) {
	std::ifstream loadfile(path, std::ios::binary);
	if (loadfile.good()) {
		PlayerData playerData;
		std::getline(loadfile, playerData.name, '\0'); // Get player name (only if null ternimated in binary)
		loadfile.read(reinterpret_cast<char*>(&playerData.score), sizeof(playerData.score)); // Read int bytes
		std::cout << "Player: { " << playerData.name << ", " << playerData.score << " }" << std::endl;
		loadfile.close();
		return &playerData;
	}
	return nullptr;
}

void DataManager::WriteBinary(std::string path, PlayerData data) {
	std::ofstream savefile(path, std::ios::binary);
	if (savefile.good()) {
		savefile.write(data.name.c_str(), data.name.size()); // Write string to binary file
		savefile.write("\0", sizeof(char)); // Add null end string for easier reading
		savefile.write(reinterpret_cast<char*>(&data.score), sizeof(data.score)); // Write int to binary file
		savefile.close();
	}
}

DataManager::DataManager()
{

}

GameState DataManager::GetState()
{
	return state;
}

void DataManager::SetState(GameState s)
{
	state = s;
}
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

void DataManager::ReadBinary(std::string path) {
	std::ifstream loadfile(path, std::ios::binary);
	if (loadfile.good()) {
		PlayerData playerData[10];
		for (int i = 0; i < 10; i++) {
			int aux = loadfile.tellg();
			if (i != 0) aux += 1;
			loadfile.seekg(aux);
			std::getline(loadfile, playerData[i].name, '\0'); // Get player name (only if null ternimated in binary)
			loadfile.read(reinterpret_cast<char*>(&playerData[i].score), sizeof(playerData[i].score)); // Read int bytes
			if (playerData[i].name == "") playerData[i].score = 0;
			ranking[i] = playerData[i];
		}
		loadfile.close();
	}
}

void DataManager::WriteBinary(std::string path, PlayerData *data) {
	std::ofstream savefile(path, std::ios::binary);
	if (savefile.good()) {
		for (int i = 0; i < 10 && data->score != 0; i++) {
			savefile.write(data->name.c_str(), data->name.size()); // Write string to binary file
			savefile.write("\0", sizeof(char)); // Add null end string for easier reading
			savefile.write(reinterpret_cast<char*>(&data->score), sizeof(data->score)); // Write int to binary file
			savefile.write("\0", sizeof(char));
			data++;
		}
		savefile.close();
	}
}

void DataManager::InsertScore(PlayerData data) {
	//insertar en el array
	if (ranking[9].score < data.score) ranking[9] = data;
	//ordenar el array, al ser solo 10 elementos no supone ningun problema
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ranking[j + 1].score > ranking[j].score)
			{
				PlayerData temp = ranking[j];
				ranking[j] = ranking[j + 1];
				ranking[j + 1] = temp;
			}
		}
	}
	WriteBinary(RANKING, ranking);
}

DataManager::DataManager()
{
	//al iniciar se cogen los datos de guardado del ranking
	ReadBinary(RANKING);
}

GameState DataManager::GetState()
{
	return state;
}

void DataManager::SetState(GameState s)
{
	state = s;
}
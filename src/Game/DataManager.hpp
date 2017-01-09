#include "XML\rapidxml.hpp"
#include <iostream>
#include <fstream>

#define DM DataManager::GetInstance()

class DataManager
{
public:
	static DataManager& GetInstance()
	{
		static DataManager inst = DataManager();
		return inst;
	}

	void WriteXML()
	{

	}

	void ReadXML()
	{

	}

	void LoadFileXML(char* path)
	{
		std::ifstream inFile(path);



	}
	void SaveFileXML(char* path)
	{
		std::ofstream outFile(path);
		
	}

	rapidxml::xml_document<>& GetOpenData()
	{
		if (loadedData.first_node != 0) return loadedData;
		else throw "No loaded data!";
	}

private:
	DataManager()
	{

	}

	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);

	rapidxml::xml_document<> loadedData;

};


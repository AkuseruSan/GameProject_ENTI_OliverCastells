#include "XML\rapidxml.hpp"
#include "XML\rapidxml_print.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define DM DataManager::GetInstance()

class DataManager
{
public:
	static DataManager& GetInstance()
	{
		static DataManager inst = DataManager();
		return inst;
	}

	void LoadFileXML(char* path)
	{
		std::ifstream file(path);
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();

		std::string content(buffer.str());
		data.parse<0>(&content[0]);

	}

	void SaveFileXML(char* path)
	{
		std::ofstream file(path);

		file << data;

		data.clear();	
	}

	void ClearData()
	{
		data.clear();
	}

	rapidxml::xml_document<>& GetData()
	{
		if (data.first_node() == 0) throw "No loaded data!";
		else return data;
		
	}

private:
	DataManager()
	{

	}

	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);

	rapidxml::xml_document<> data;

};


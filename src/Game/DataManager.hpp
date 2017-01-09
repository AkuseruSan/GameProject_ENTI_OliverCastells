#include "XML\rapidxml.hpp"
#include "XML\rapidxml_print.hpp"
#include "XML\rapidxml_utils.hpp"
#include "XML\rapidxml_iterators.hpp"

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
		readFile = std::ifstream(path);

		std::stringstream buffer;
		buffer << readFile.rdbuf();
		readFile.close();

		content = buffer.str();
		data.parse<rapidxml::parse_default>(&content[0]);

	}

	void SaveFileXML(char* path)
	{
		writeFile = std::ofstream(path);
		
		writeFile << data;

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
	std::ifstream readFile;
	std::ofstream writeFile;

	std::string content;
};


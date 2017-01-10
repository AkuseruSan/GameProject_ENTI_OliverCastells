#pragma once
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
	static DataManager& GetInstance();

	void LoadFileXML(char* path);

	void SaveFileXML(char* path);

	void ClearData();

	rapidxml::xml_document<>& GetDataRoot();
	rapidxml::xml_node<>* GetDifficultyData(int);

private:
	DataManager();

	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);

	rapidxml::xml_document<> data;
	std::ifstream readFile;
	std::ofstream writeFile;

	std::string content;
};


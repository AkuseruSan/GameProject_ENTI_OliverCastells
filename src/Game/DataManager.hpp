#include "XML\rapidxml.hpp"

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

	rapidxml::xml_document<>* GetOpenData()
	{
		if (openData != nullptr) return openData;
		else throw "No loaded data!";
	}

private:
	DataManager()
	{
		openData = nullptr;
	}

	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);

	rapidxml::xml_document<>* openData;
};


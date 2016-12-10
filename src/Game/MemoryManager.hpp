//#pragma once
//#define MM MemoryManager::GetInstance()

class MemoryManager
{
public:
	static MemoryManager& GetInstance()
	{
		static MemoryManager inst;
		return inst;
	}

private:
	MemoryManager() {}
	MemoryManager(const MemoryManager&);
	MemoryManager& operator=(const MemoryManager&);
};


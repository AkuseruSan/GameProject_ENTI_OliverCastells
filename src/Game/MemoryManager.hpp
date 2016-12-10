
class MemoryManager
{
private:
	MemoryManager()
	{

	}
public:
	~MemoryManager(){}
	MemoryManager* Instance()
	{
		return this;
	}
};

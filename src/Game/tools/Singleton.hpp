class Singleton
{
protected:
	Singleton()
	{
		instance = this;
	}
	static Singleton* instance;

public:
	static Singleton* Instance()
	{
		return instance;
	}
};

class Test : Singleton
{
private:
	Test()
	{
		instance = this;
	}

public:
	void Meow()
	{

	}
};
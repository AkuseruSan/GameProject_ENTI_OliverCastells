
#define GE GameEngine::GetInstance()

class GameEngine
{
public:
	static GameEngine& GetInstance()
	{
		static GameEngine inst;
		return inst;
	}

private:
	GameEngine() {}
	GameEngine(const GameEngine&);
	GameEngine& operator=(const GameEngine&);
};
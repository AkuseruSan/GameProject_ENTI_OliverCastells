
#define SM SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager inst;
		return inst;
	}

private:
	SceneManager() {}
	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);
};


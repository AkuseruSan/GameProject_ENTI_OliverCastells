class Renderer
{
public:
	static Renderer& GetInstance()
	{
		static Renderer inst;
		return inst;
	}

private:
	Renderer() {}
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);
};


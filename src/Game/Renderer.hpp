
#define R Renderer::Instance()

class Renderer
{
public:
	static Renderer& Instance()
	{
		static Renderer inst;
		return inst;
	}

private:
	Renderer() {}
	Renderer(const Renderer&);
	Renderer& operator=(const Renderer&);
};
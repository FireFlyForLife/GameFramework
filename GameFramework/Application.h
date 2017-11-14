#pragma once

class Application
{
public:

	Application() : m_running(false) {}
	virtual ~Application();

	bool	create(int a_argc, char* a_argv[]);
	void	run();
	void	destroy() { m_running = false; }

protected:
	//To be implemented in a child class of our application
	virtual bool	onCreate(int a_argc, char* a_argv[]) = 0;
	virtual void	onUpdate(float a_deltaTime) = 0;
	virtual void	onDraw() = 0;
	virtual void	onDestroy() = 0;

	bool			m_running;
};

//////////////////////////////////////////////////////////////////////////
#define APPLICATION_ENTRY(appClass)									\
	int main(int a_argc, char* a_argv[])							\
	{																\
		Application* app = new appClass();							\
		if (app->create(a_argc,a_argv) == true)						\
		{															\
			app->run();												\
			app->destroy();											\
		}															\
		else														\
		{															\
			/*NHTV::logError("Failed to setup application!\n");*/	\
		}															\
		delete app;													\
		return 0;													\
	}
//////////////////////////////////////////////////////////////////////////

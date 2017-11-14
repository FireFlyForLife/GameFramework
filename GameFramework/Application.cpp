#include "Application.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Input.h"
#include "Screen.h"
#include "Timing.h"


Application::~Application()
{
}

bool Application::create(int a_argc, char * a_argv[])
{
	//TODO: Load the application data from our appData.xml

	// initialise glfw systems
	if (glfwInit() != GL_TRUE)
	{
		std::cout << "Unable to initialize GLFW" << std::endl;
		return false;
	}

	//TODO: make this info load in from appdata.xml
	Screen::width = 800;
	Screen::height = 600;
	Screen::title = "Memes";

	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
	Screen::window = glfwCreateWindow(Screen::width, Screen::height, Screen::title.c_str(), nullptr, nullptr);
	if (Screen::window == nullptr)
	{
		std::cout << "Unable to create a GLFW Window" << std::endl;
		glfwTerminate();
		return false;
	}
	//glfwSetWindowPos(appWindow->glfwWindowHandle, appWindow->xPos, appWindow->yPos);
	glfwShowWindow(Screen::window);

	int major = glfwGetWindowAttrib(Screen::window, GLFW_CONTEXT_VERSION_MAJOR);
	int minor = glfwGetWindowAttrib(Screen::window, GLFW_CONTEXT_VERSION_MINOR);
	int revision = glfwGetWindowAttrib(Screen::window, GLFW_CONTEXT_REVISION);
	std::cout << "OpenGL Version " << major << "." << minor << "." << revision << std::endl;

	// make the window's context current
	glfwMakeContextCurrent(Screen::window);

	// initialise glew systems to wrangle GL extensions
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize GLEW" << std::endl;
		glfwTerminate();
		return false;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	//Create some of the components/singletons we require:

	glfwGetWindowSize(Screen::window, &Screen::width, &Screen::height);

	//TODO: load shader
	/*const char* aszInputs[] = { "Position", "Colour", "UV" };
	const char* aszOutputs[] = { "vUV", "vColour" };

	m_ShaderID = NHTV::Utility::loadShaderFromFile(3, aszInputs, 2, aszOutputs, "./shaders/default.vsh", "./shaders/default.fsh");

	// set matrix uniforms within the shaders
	GLint ProjectionID = glGetUniformLocation(m_ShaderID, "Projection");
	GLint ViewID = glGetUniformLocation(m_ShaderID, "View");

	glUniformMatrix4fv(ProjectionID, 1, false, glm::value_ptr(m_ProjectionMatrix));
	glUniformMatrix4fv(ViewID, 1, false, glm::value_ptr(m_ViewMatrix));

	// set the texture to use slot 0 in the shader
	GLuint texUniformID = glGetUniformLocation(m_ShaderID, "diffuseTexture");
	glUniform1i(texUniformID, 0);

	// set clear colour
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	*/

	//TODO: start our timer
	/*NHTV::Utility::resetTimer();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_fDeltaTime = NHTV::Utility::tickTimer();*/


	//Now call our overridden onCreate function to set up application specifics
	bool result = onCreate(a_argc, a_argv);
	if (result == false)
	{
		std::cout << "Application onCreate failure, terminating application" << std::endl;
		glfwTerminate();
	}
	return result;
}

void Application::run()
{
	using namespace Input;

	Timing::InitTime();
	m_running = true;
	do
	{
		float fDeltaTime = Timing::TickTimer();

		onUpdate(fDeltaTime);

		onDraw();

		// set active shader
		//glUseProgram(m_ShaderID);
		//glEnable(GL_BLEND);
		//glDisable(GL_DEPTH_TEST);
		// convert camera's world matrix to a view matrix
		//m_ViewMatrix = glm::inverse(m_CameraMatrix);
		// set current transforms in the shader
		//GLuint ViewID = glGetUniformLocation(m_ShaderID, "View");
		//glUniformMatrix4fv(ViewID, 1, false, glm::value_ptr(m_ViewMatrix));
		//call to draw sprites
		//SpriteManager::GetInstance()->Draw(m_ShaderID);
		//switch blending draw the font
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//FontManager::GetInstance()->Draw(m_ShaderID);
		//draw any lines that we have in the scene
		//m_pLineRenderer->draw(m_ViewMatrix, m_ProjectionMatrix);
		// clear all lines from last frame
		//m_pLineRenderer->clear();
		// bring the back-buffer to the monitor
		glfwSwapBuffers(Screen::window);
		glfwPollEvents();

	} while (m_running == true && glfwWindowShouldClose(Screen::window) == 0);

	onDestroy();
}


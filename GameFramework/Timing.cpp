#include "Timing.h"
#include <GLFW/glfw3.h>

namespace Timing
{
	double lastTotalTime = 0;
	float deltaTime;

	void InitTime()
	{
		lastTotalTime = glfwGetTime();
	}

	float TickTimer()
	{
		double now = glfwGetTime();
		deltaTime = now - lastTotalTime;
		lastTotalTime = now;

		return deltaTime;
	}

	float DeltaTime()
	{
		return deltaTime;
	}

	double TotalTime()
	{
		return lastTotalTime;
	}
}

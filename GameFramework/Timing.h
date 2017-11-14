#pragma once

//TODO: Figure out if I need to convert the namespace to a class to be able to inline them
namespace Timing
{
	void InitTime();
	float TickTimer();

	float DeltaTime();
	double TotalTime();
}

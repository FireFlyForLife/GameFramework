#pragma once
#include <Application.h>

class SampleGame : public Application
{
public:
	SampleGame();
	~SampleGame();

protected:
	bool	onCreate(int a_argc, char* a_argv[]) override;
	void	onUpdate(float a_deltaTime) override;
	void	onDraw() override;
	void	onDestroy() override;

private:
	unsigned int VAO_id;
	unsigned int vertexBuffer_id;
	unsigned int program_id;
};


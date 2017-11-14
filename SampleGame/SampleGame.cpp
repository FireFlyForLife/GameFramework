#include "SampleGame.h"

#include <GL/glew.h>
#include <iostream>

#include "Shaders.h"
#include <cassert>

APPLICATION_ENTRY(SampleGame)

using namespace std;

SampleGame::SampleGame()
{
}

SampleGame::~SampleGame()
{
}

// An array of 3 vectors which represents 3 vertices
static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};

bool SampleGame::onCreate(int a_argc, char * a_argv[])
{
	cout << "Created the ting!" << endl;

	glGenVertexArrays(1, &VAO_id);
	glBindVertexArray(VAO_id);

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexBuffer_id);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_id);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	program_id = LoadShaders("red.vertex.shader", "red.fragment.shader");
	if(program_id == 0)
	{
		throw std::exception("shaders could not compile!");
	}
	
	return true;
}

void SampleGame::onUpdate(float a_deltaTime)
{
	cout << "deltat time: " << a_deltaTime << endl;
}

void SampleGame::onDraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(program_id);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_id);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void SampleGame::onDestroy()
{
	cout << "Destroying..." << endl;
}

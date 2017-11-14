#include "Input.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Screen.h"
#include "MathFunctions.h"

//MouseMoveArgs::MouseMoveArgs() : point(0, 0), dragging(false), scan_code(-1)
//{
//}
//MouseMoveArgs::MouseMoveArgs(Point point, bool dragging, __int8 scan_code) : point(point), dragging(dragging), scan_code(scan_code)
//{
//}
//
//MouseClickArgs::MouseClickArgs() : point(0, 0), down(false), scan_code(-1)
//{
//}
//MouseClickArgs::MouseClickArgs(Point point, bool down, __int8 scan_code) : point(point), down(down), scan_code(scan_code)
//{
//}
//
//KeyClickArgs::KeyClickArgs() : down(false), scan_code(-1)
//{
//}
//KeyClickArgs::KeyClickArgs(bool down, __int16 scan_code) : down(down), scan_code(scan_code)
//{
//}

namespace Input {
	EventSource<MouseMoveArgs*, int> mouseMoveListeners;
	EventSource<MouseClickArgs*, int> mouseClickListeners;
	EventSource<MouseClickArgs*, int> mouseDownListeners;
	EventSource<MouseClickArgs*, int> mouseUpListeners;

	EventSource<KeyClickArgs*, int> keyClickListeners;
	EventSource<KeyClickArgs*, int> keyDownListeners;
	EventSource<KeyClickArgs*, int> keyUpListeners;

	bool IsKeyDown(unsigned int a_uiKey)
	{
		return (glfwGetKey(Screen::window, a_uiKey) == GLFW_PRESS);
	}

	DPoint GetMousePos()
	{
		DPoint pos;
		glfwGetCursorPos(Screen::window, &pos.x, &pos.y);
		pos.x = Math::Clampf(pos.x, 0, Screen::width);
		pos.y = Math::Clampf(pos.y, 0, Screen::height);
		return pos;
	}

	bool GetMouseButtonDown(int a_uiMouseButton)
	{
		return (glfwGetMouseButton(Screen::window, a_uiMouseButton) == GLFW_PRESS);
	}

	bool GetMouseButtonReleased(int a_uiMouseButton)
	{
		return (glfwGetMouseButton(Screen::window, a_uiMouseButton) == GLFW_RELEASE);
	}

#ifdef USE_SDL
	void handle_SDL_Event(SDL_Event* e) {
		if (e->type == SDL_EventType::SDL_KEYDOWN)
		{
			GameEngine::KeyClickArgs args(true, e->key.keysym.scancode);
			GameEngine::keyDownListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_KEYUP) {
			GameEngine::KeyClickArgs args(false, e->key.keysym.scancode);
			GameEngine::keyUpListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
			MouseClickArgs args({ e->button.x, e->button.y }, true, e->button.button);
			mouseDownListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEBUTTONUP) {
			MouseClickArgs args({ e->button.x, e->button.y }, false, e->button.button);
			mouseUpListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEMOTION) {
			MouseMoveArgs args({ e->motion.x, e->motion.y }, e->motion.state, e->button.button);
			mouseMoveListeners.call(&args, 0);
		}
	}
#endif
}
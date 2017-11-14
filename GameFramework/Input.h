#pragma once
#include "EventSource.h"
#include "Point.h"
#ifdef USE_SDL
#include <SDL.h>
#endif

namespace Input {
	bool IsKeyDown(unsigned int a_uiKey);
	DPoint GetMousePos();
	bool GetMouseButtonDown(int a_iMouseButton);
	bool GetMouseButtonReleased(int a_iMouseButton);

	extern EventSource<struct MouseMoveArgs*, int> mouseMoveListeners;
	extern EventSource<struct MouseClickArgs*, int> mouseClickListeners;
	extern EventSource<struct MouseClickArgs*, int> mouseDownListeners;
	extern EventSource<struct MouseClickArgs*, int> mouseUpListeners;

	extern EventSource<struct KeyClickArgs*, int> keyClickListeners;
	extern EventSource<struct KeyClickArgs*, int> keyDownListeners;
	extern EventSource<struct KeyClickArgs*, int> keyUpListeners;

#ifdef USE_SDL
	void handle_SDL_Event(SDL_Event* e);
#endif
}

#pragma region args
struct MouseMoveArgs {
	Point point;
	bool dragging;
	__int8 scan_code;

	MouseMoveArgs() : point(0, 0), dragging(false), scan_code(-1) {}
	MouseMoveArgs(Point point, bool dragging, __int8 scan_code) : point(point), dragging(dragging), scan_code(scan_code) {}
};

struct MouseClickArgs {
	Point point;
	bool down;
	__int8 scan_code;

	MouseClickArgs() : point(0, 0), down(false), scan_code(-1) {}
	MouseClickArgs(Point point, bool down, __int8 scan_code) : point(point), down(down), scan_code(scan_code) {}
};

struct KeyClickArgs {
	bool down;
	__int16 scan_code;

	KeyClickArgs() : down(false), scan_code(-1) {}
	KeyClickArgs(bool down, __int16 scan_code) : down(down), scan_code(scan_code) {}
};
#pragma endregion
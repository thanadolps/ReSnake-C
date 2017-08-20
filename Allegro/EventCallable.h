#include "allegro5\allegro.h"
#pragma once
//Interface To Propogatable Callable Event
//	Useful for propogating to ensure same function name
class EventCallable
{
public:
	EventCallable();
	void game() {};
	void draw() {};
	void tick() { game(); draw(); };
	void onType(ALLEGRO_KEYBOARD_EVENT kev) {};
	void onMouseMotion(ALLEGRO_MOUSE_EVENT mev) {};
	void onDown(ALLEGRO_MOUSE_EVENT mev) {};
	void onUp(ALLEGRO_MOUSE_EVENT mev) {};
	void other(ALLEGRO_EVENT ev) {};
	~EventCallable();
};


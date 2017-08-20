#include "allegro5\allegro.h"
#include "forward_list"
#include "EventCallable.h"
#include "ProgramObject.h"
//Base of Every Scence
#pragma once
class Scence:
	public EventCallable
{
public:

	std::forward_list<ProgramObject> programobjects;

	Scence();

	void onType(ALLEGRO_KEYBOARD_EVENT kev) {};
	void onMouseMotion(ALLEGRO_MOUSE_EVENT mev) {};
	void onDown(ALLEGRO_MOUSE_EVENT mev);
	void onUp(ALLEGRO_MOUSE_EVENT mev) {};
	void other(ALLEGRO_EVENT ev) {};

	~Scence();
};


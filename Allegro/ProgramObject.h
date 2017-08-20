#pragma once
#include "EventCallable.h"
//Root for all boject in this program
class ProgramObject :
	public EventCallable
{
public:
	ProgramObject();
	void onDown(ALLEGRO_MOUSE_EVENT mev);
	~ProgramObject();
};


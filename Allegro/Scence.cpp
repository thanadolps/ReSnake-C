#include "Scence.h"

ProgramObject test1;
ProgramObject test2;

Scence::Scence()
{
	programobjects = { test1, test2 };
}

//Propogation : Each Event Recive From Main Function Is Being Distribute to all programObjects (type/variable) 
//	in programobjects (forward_list containing programObject) by respective function (onDown -> onDown etc.)

void Scence::onDown(ALLEGRO_MOUSE_EVENT mev)
{
	for (auto i = programobjects.begin(); i != programobjects.end(); i++)
	{
		(*i).onDown(mev);
	}
}


Scence::~Scence()
{
	
}

#include "ProgramObject.h"
#include "stdio.h"

//Root for all boject in this program

ProgramObject::ProgramObject()
{
}

void ProgramObject::onDown(ALLEGRO_MOUSE_EVENT mev)
{
	printf("Hey! I'm Begin Called and mouse is at %d,%d \n",mev.x ,mev.y);
}


ProgramObject::~ProgramObject()
{
}

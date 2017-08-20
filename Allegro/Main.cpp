#include<stdio.h>
#include<allegro5/allegro.h>
#include "Scence.h"
#include "UIScence.h"

void initiation();
void variablize();
void destory();
void Exit();

const float FPS = 60;
const float WIDTH = 680, HEIGHT = 420;

static ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

UIScence currentScence;

bool willexit = false;

void variablize()
{
	return;
}

int main(int argc, char **argv)
{
	initiation();

	al_start_timer(timer);
	while (!willexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		bool draw = false;
		switch (ev.type)
		{
			
			case ALLEGRO_EVENT_DISPLAY_CLOSE: Exit(); break;
			case ALLEGRO_EVENT_TIMER:  draw = true; break;
			case ALLEGRO_EVENT_KEY_CHAR: currentScence.onType(ev.keyboard); break;
			case ALLEGRO_EVENT_MOUSE_AXES: currentScence.onMouseMotion(ev.mouse); break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: currentScence.onDown(ev.mouse); break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP: currentScence.onUp(ev.mouse); break;
			default: currentScence.other(ev); break;
		}

		if (draw && al_is_event_queue_empty(event_queue))
		{
			currentScence.tick();
			al_flip_display();
			draw = false;
		}
			
	}

	destory();
	return EXIT_SUCCESS;
}

void initiation()
{
	al_init();
	display = al_create_display(WIDTH, HEIGHT);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0/FPS);

	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	variablize();
}

void destory()
{
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}

void Exit()
{
	willexit = true;
}
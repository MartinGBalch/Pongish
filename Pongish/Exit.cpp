#include "Exit.h"
#include "sfwdraw.h"
#include <cstdio>

void Exit::init(int a_font)
{
	font = a_font;
}

void Exit::play()
{
	timer = 3.f;
}

void Exit::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press [ESC] of wait for the Kill timer: %f", timer);
	sfw::drawString(font, buffer, 100, 100, 16, 16);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
}

void Exit::step()
{
	timer -= sfw::getDeltaTime(); 
}

APP_STATE Exit::next()
{
	if (timer < 0 || sfw::getKey(KEY_ESCAPE))
		return TERMINATE;

	return EXIT;
}

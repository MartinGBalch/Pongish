#include "Exit.h"
#include "sfwdraw.h"
#include <cstdio>

void Exit::init(int a_font)
{
	font = a_font;
}

void Exit::play()
{
	timer = 15.f;
}

void Exit::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press [ESC] or wait for the Kill timer:\n %f", timer);
	sfw::drawString(font, buffer, 0, 300, 20, 20 );
	sfw::drawLine(100, 160, 100 + 500 * (timer / 15.f), 160);
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

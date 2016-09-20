#include "Option.h"
#include "sfwdraw.h"
#include <cstdio>

void Option::init(int a_font)
{
	font = a_font;
}

void Option::play()
{
	select = 0;
	timer = 1.f;
}

void Option::draw()
{
	
	sfw::drawString(font, "Press on your selection:", 250, 400, 32, 32, 0, 0, GREEN);

	sfw::drawString(font, "[P]lay", 380, 300, 28, 28, 0, 0, GREEN);
	sfw::drawString(font, "[Q]uit", 620, 300, 28, 28, 0, 0, GREEN);
	
	
}

void Option::step()
{
}

APP_STATE Option::next()
{
	if (sfw::getKey('P')) return ENTER_PLAY;
	if (sfw::getKey('Q')) return ENTER_EXIT;

	/*if (sfw::getKey(KEY_ENTER))
	{
		if (select == 0) return ENTER_EXIT;
		if (select == 1) return ENTER_PLAY;
	}*/
	return OPTION;
}

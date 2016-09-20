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
	sfw::drawString(font, "Press on your selection:", 80, 140, 16, 16, 0, 0, BLUE);

	sfw::drawString(font, "[P]lay!", 100, 120, 16, 16, 0, 0, select == 1 ? MAGENTA : WHITE);
	sfw::drawString(font, "[Q]uit!", 100, 100, 16, 16, 0, 0, select == 0 ? MAGENTA : WHITE);

	
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

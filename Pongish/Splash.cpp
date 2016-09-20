#include "sfwdraw.h"
#include "Splash.h"
#include <cstdio>



void Splash::init(int a_font)
{
	font = a_font;
}

void Splash::play()
{
	timer = 5.f;
}

void Splash::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press [SPACE] to skip");
	sfw::drawString(font, buffer, 100, 100, 21, 21);
}

void Splash::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Splash::next()
{
	if (timer < 0 || sfw::getKey(' '))
		return ENTER_OPTION;

		return SPLASH;
}
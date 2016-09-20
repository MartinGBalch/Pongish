#include "sfwdraw.h"
#include "Splash.h"
#include <cstdio>
#include <cstdlib>


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
	sfw::drawString(font, buffer, 10, 15, 8, 8, 0, 0, WHITE);
	unsigned u = sfw::loadTextureMap("./res/splash.png");
	sfw::drawTexture(u, 0, 600, 1200, 600, 0, false, 0, 0x88888888);
	
	

}

void Splash::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Splash::next()
{
	if (timer < 0 || sfw::getKey(' '))
		return ENTER_OPTION;
	if (sfw::getKey('Q'))
		return ENTER_PLAY;

		return SPLASH;
}
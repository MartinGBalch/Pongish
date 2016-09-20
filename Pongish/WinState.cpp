#include "WinState.h"
#include "sfwdraw.h"
#include "Player.h"
#include <cstdio>


void WinState::init(int a_font, int a_score)
{
	score = a_score;
	font = a_font;
}

void WinState::play()
{
	timer = 20.f;
}

void WinState::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Your score was: %d", score);
	sfw::drawString(font, buffer, 300, 300, 32, 32, 0, 0, GREEN);
	sfw::drawString(font, "Press [SPACE] to play again", 60, 120, 16, 16, 0, 0, GREEN);
	sfw::drawString(font, "Press [ESCAPE] to go to main menu", 640, 120, 16, 16, 0, 0, GREEN);

}

void WinState::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE WinState::next()
{
	if (sfw::getKey(' '))
	{
		score = 0;
		return ENTER_PLAY;
	}
	if (sfw::getKey(KEY_ESCAPE))
	{
		return ENTER_OPTION;
	}
		return WIN;
}

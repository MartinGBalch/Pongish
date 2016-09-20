#include "WinState.h"
#include "sfwdraw.h"
#include "Player.h"
#include <cstdio>


void WinState::init(int a_font, Paddle winner)
{
	winnerPlayer = winner;
	font = a_font;
}

void WinState::play()
{
	timer = 20.f;
}

void WinState::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Your score was: %f", &winnerPlayer.score,"\nPress [ENTER]");
	sfw::drawString(font, buffer, 100, 100, 21, 21);
}

void WinState::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE WinState::next()
{
	if (sfw::getKey(KEY_ENTER))
		return ENTER_OPTION;

		return WIN;
}

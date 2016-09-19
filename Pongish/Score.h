#pragma once
#include <cstdio>
#include "sfwdraw.h"

void drawScore(unsigned font, int score1, int score2)
{
	char buffer[80] = { 0 };
	sprintf_s(buffer, "%d", score2);
	sfw::drawString(font, buffer, 700, 500, 20, 20);

	sprintf_s(buffer, "%d", score1);
	sfw::drawString(font, buffer, 100, 500, 20, 20);
}


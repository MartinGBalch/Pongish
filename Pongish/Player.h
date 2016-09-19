#pragma once
#include"sfwdraw.h"
#include <cstdio>
#include <cstdlib>
struct Paddle
{
	float xPos = 50;
	float yPos = 300;
	float score = 0;
	unsigned color = GREEN;
};

void drawPaddle(float xPos, float yPos, unsigned color);
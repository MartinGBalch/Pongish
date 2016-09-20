#pragma once
#include"sfwdraw.h"
#include <cstdio>
#include <cstdlib>
struct Paddle
{
	float xPos = 50;
	float yPos = 300;
	float score = 0;

	float width = 30;
	float halfheight = 50;

	unsigned color = GREEN;
};

void drawPaddle(float xPos, float yPos, unsigned color);
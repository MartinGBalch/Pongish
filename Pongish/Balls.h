#pragma once
#include"sfwdraw.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

struct vec2
{
	float x;
	float y;
};

int randomDirection(int min, int max);

struct Ball
{
	float x = 300;
	float y = 300;
	float size = 10;
	float xvel;
	float yvel;
	unsigned color = YELLOW;

	int bounceCount = 0;

	vec2 direction;

	
};

Ball createball(float x, float y, float radius, unsigned int color, float xvel, float yvel);

void drawballs(const Ball &b);

void updateBalls(Ball &ball);

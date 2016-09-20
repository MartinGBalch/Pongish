#include "Balls.h"

int randomDirection(int min, int max)
{
	return rand() % (max - min) + min;
}

Ball createball(float x, float y, float radius, unsigned int color, float xvel, float yvel)
{
	Ball retval;
	retval.x = x;
	retval.y = y;
	retval.size = radius;
	retval.color = color;
	retval.xvel = randomDirection(150, 340);
	retval.yvel = randomDirection(150, 340);

	return retval;
}

void drawballs(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
}

void updateBalls(Ball &ball)
{
	ball.x += ball.xvel;
	ball.y += ball.yvel;
	if (ball.y > 585)
	{
		ball.yvel *= -1;
	}
	if (ball.y < 15)
	{
		ball.yvel *= -1;
	}
	if (ball.x > 785)
	{
		ball.xvel *= -1;
	}
	/*if (ball.x < 15)
	{
		ball.xvel *= -1;
	}*/

	// Exponential
	// Increases compound over time.
	//ball.xvel *= 1.001f;

	if (fabsf(ball.xvel) < 20)
		ball.xvel *= 1.0005f;

	// Incremental
	// Increase speed by 1 each frame.
	//ball.xvel = copysignf(ball.bounceCount*5+1, ball.xvel) * 10;	

	// clamp the velocity to 10.
	//if (fabsf(ball.xvel) > 20000000)
	//ball.xvel = copysignf(2000000, ball.xvel);
}

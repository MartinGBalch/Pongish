#include "Balls.h"
#include "GameState.h"


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
	
	//printf("x: %f y: %f \n", ball.xvel, ball.yvel);

	ball.x += ball.xvel * sfw::getDeltaTime();
	ball.y += ball.yvel * sfw::getDeltaTime();
	if (ball.y > 585)
	{
		ball.yvel *= -1;
	}
	if (ball.y < 15)
	{
		ball.yvel *= -1;
	}
	if (ball.x > 1185)
	{
		ball.xvel *= -1;
		ball.yvel = rand() % 600 - 200;
	}
	/*if (ball.x < 15)
	{
		ball.xvel *= -1;
	}*/

	// Exponential
	// Increases compound over time.
	//ball.xvel *= 1.001f;

	//if (fabsf(ball.xvel) < 20)
	//	ball.xvel *= 1.0005f;

	// Incremental
	// Increase speed by 1 each frame.

	// bouncecount is 0
	// 0 + 1 = 1
	// 1 * 100 = 100
	// copysignf(100, ball.xvel) = 100
	// 100 * 2 = 200

	// bouncecount is 1
	// 1 + 1 = 2
	// 2 * 100 = 200
	// copysignf(200, ball.xvel) = 200
	// 200 * 2 = 400
	ball.xvel = copysignf((ball.bounceCount + 1) * 100, ball.xvel) * 2;	

	// clamp the velocity to 1000.
	if (fabsf(ball.xvel) > 1000)
	{
		ball.xvel = copysignf(1000, ball.xvel);
		ball.bounceCount = 1;
	}
}

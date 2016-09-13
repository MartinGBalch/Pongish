
#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"

//1) make balls move
//2) make collision
//3) make player health
//4) make enemy health
//5) add timers
//6) add start

using namespace sfw;

int randomDirection(int min, int max)
{
	return rand() % (max - min) + min;
}

struct vec2
{
	float x;
	float y;
};

struct Paddle
{
	float xPos = 50;
	float yPos = 300;
	float shoot = 0;
};

struct Ball
{
	float x = 775;
	float y = 300;
	float size = 10;
	float xvel = 0;
	float yvel = 0;
	unsigned color = WHITE;
	
	vec2 direction;
};

struct Bounds
{
	float topWall;
	float bottomWall;
	
};

void drawPaddle(float xPos, float yPos)
{
	drawLine(xPos, yPos - 50, xPos, yPos + 50, RED);
	drawLine(xPos - 30, yPos - 50, xPos - 30, yPos + 50, GREEN);
	drawLine(xPos, yPos - 50, xPos - 30, yPos - 50, GREEN);
	drawLine(xPos, yPos + 50, xPos - 30, yPos + 50, GREEN);
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
	sfw::drawCircle(b.x, b.y, b.size, 12 , b.color);
}

int
 updateBalls()
{
	return 0;
}




void main()
{
	Paddle player;
	Ball b1;
	float xPos, yPos;
	float x, y;
	sfw::initContext(800, 600, "NSFW Draw");
	setBackgroundColor(BLACK);
	
	
	float acc = 0;
	char c = '\0';

	

	while (sfw::stepContext())
	{
		if (getKey('W'))
		{
			player.yPos += 10;
		}
		else if (getKey('S'))
		{
			player.yPos -= 10;
		}
		
		if(player.yPos >= 550)
		{
			player.yPos = 550;
		}
		else if (player.yPos <= 54)
		{
			player.yPos = 53;
		}
		drawPaddle(player.xPos,player.yPos);
		drawballs(b1);

		acc += sfw::getDeltaTime();
		

		
		
	}

	sfw::termContext();
}
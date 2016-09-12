
#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"

using namespace sfw;

void randomDirection()
{
	float direction = ((rand() % 6) + 1);
}

struct vec2
{
	float x;
	float y;
};

struct Paddle
{
	float xPos = 400;
	float yPos = 100;
	float shoot = 0;
};

struct Ball
{
	float xPos = 300;
	float yPos = 100;
	float size = 30;
	float color = WHITE;
	
	vec2 direction;
};

struct Bounds
{
	float leftwall;
	float rightwall;
	float topwall;
};

void drawPaddle(float xPos, float yPos)
{
	drawLine(xPos - 50, yPos, xPos + 50, yPos, YELLOW);
	drawLine(xPos - 50, yPos - 30, xPos + 50, yPos - 30, GREEN);
	drawLine(xPos - 50, yPos, xPos - 50, yPos - 30, GREEN);
	drawLine(xPos + 50, yPos, xPos + 50, yPos - 30, GREEN);
}

Ball createball(float xpos, float ypos, float radius, unsigned int color, float xvel, float yvel)
{
	Ball retval;
	retval.xPos = xpos;
	retval.yPos = ypos;
	retval.size = radius;
	retval.color = color;

	return retval;
}




void main()
{
	Paddle player;
	float xPos, yPos;
	sfw::initContext(800, 600, "NSFW Draw");
	setBackgroundColor(BLACK);
	
	
	float acc = 0;
	char c = '\0';

	

	while (sfw::stepContext())
	{
		if (getKey('A'))
		{
			player.xPos -= 8;
		}
		else if (getKey('D'))
		{
			player.xPos += 8;
		}
		
		if(player.xPos >= 800)
		{
			player.xPos = 0;
		}
		else if (player.xPos <= 0)
		{
			player.xPos = 800;
		}
		drawPaddle(player.xPos,player.yPos);
		

		acc += sfw::getDeltaTime();
		

		
		
	}

	sfw::termContext();
}
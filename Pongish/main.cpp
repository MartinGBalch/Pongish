
#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"

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
	float xPos = 400;
	float yPos = 100;
	float shoot = 0;
};

struct Ball
{
	float x = 400;
	float y = 300;
	float size = 10;
	float xvel = 0;
	float yvel = 0;
	unsigned color = WHITE;
	
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
	drawLine(xPos - 50, yPos, xPos + 50, yPos, RED);
	drawLine(xPos - 50, yPos - 30, xPos + 50, yPos - 30, GREEN);
	drawLine(xPos - 50, yPos, xPos - 50, yPos - 30, GREEN);
	drawLine(xPos + 50, yPos, xPos + 50, yPos - 30, GREEN);
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
		drawballs(b1);

		acc += sfw::getDeltaTime();
		

		
		
	}

	sfw::termContext();
}
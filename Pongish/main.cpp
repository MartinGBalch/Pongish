
#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"
#include <time.h>
#include <cstdio>

// ** TO DO LIST **
//3) make classes and header files
//4) make player health
//5) make enemy health
//6) add timers
//7) add start

#include <cmath>
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
	float score = 0;
	unsigned color = GREEN;
};

struct Ball
{
	float x = 775;
	float y = 300;
	float size = 10;
	float xvel = 0;
	float yvel = 0;
	unsigned color = YELLOW;
	
	int bounceCount = 0;

	vec2 direction;
};

struct Bounds
{
	float topWall;
	float bottomWall;
	
};

void drawPaddle(float xPos, float yPos, unsigned color)
{
	drawLine(xPos, yPos - 50, xPos, yPos + 50, color);
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
	if (ball.x < 15)
	{
		ball.xvel *= -1;
	}

	// Exponential
		// Increases compound over time.
	//ball.xvel *= 1.001f;

	if(fabsf(ball.xvel) < 20)
		ball.xvel *= 1.0005f;

	// Incremental
		// Increase speed by 1 each frame.
		//ball.xvel = copysignf(ball.bounceCount*5+1, ball.xvel) * 10;	

	// clamp the velocity to 10.
	//if (fabsf(ball.xvel) > 20000000)
		//ball.xvel = copysignf(2000000, ball.xvel);
}

void drawScore(unsigned font, int score1, int score2)
{
	char buffer[80] = { 0 };
	sprintf_s(buffer, "%d", score2);
	drawString(font, buffer, 700, 500, 20, 20);

	sprintf_s(buffer, "%d", score1);
	drawString(font, buffer, 100, 500, 20, 20);
}

void drawWin(unsigned font)
{
	drawString(font, "Game over Player 1 wins", 300, 500, 10, 10);
}

void drawWin2(unsigned font)
{
	drawString(font, "Game over Player 2 wins", 300, 500, 10, 10);
}


void main()
{
	Paddle player;
	Ball b1;
	b1.xvel = -5;
	b1.yvel = -1;

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

		// if the ball's y is between the top and bottom of the paddle
		// AND the x of the ball has crossed the x position of the paddle
		if (player.yPos - 50 <= b1.y
			         && b1.y <= player.yPos + 50
					 && b1.x + b1.xvel <= player.xPos  // next X position
					 && b1.x           >= player.xPos) // current X position
		{
			// reverse the ball's direction
			b1.xvel *= -1;
			// ensure the ball is in a good spot.
			b1.x = player.xPos;

			if (player.color == GREEN)
				player.color = BLUE;
			else if (player.color == BLUE)
				player.color = YELLOW;
			else if (player.color == YELLOW)
				player.color = RED;
			else if (player.color == RED)
				player.color = CYAN;
			else if (player.color == CYAN)
				player.color = MAGENTA;
			else if (player.color == MAGENTA)
				player.color = NONE;
			else if (player.color == NONE)
				player.color = WHITE;
			else
				player.color = GREEN;


			b1.bounceCount++;
			player.score++;
		}


		updateBalls(b1);

		drawPaddle(player.xPos,player.yPos, player.color);
		drawballs(b1);

		acc += sfw::getDeltaTime();
		

		
		
	}

	sfw::termContext();
}
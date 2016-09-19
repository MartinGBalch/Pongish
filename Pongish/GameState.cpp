#include "GameState.h"
#include "sfwdraw.h"
 

void GameState::init()
{
	b1.xvel = -5;
	b1.yvel = -1;
}
void GameState::update()
{
	if (sfw::getKey('W'))
	{
		player.yPos += 10;
	}
	else if (sfw::getKey('S'))
	{
		player.yPos -= 10;
	}

	if (player.yPos >= 550)
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
		&& b1.x >= player.xPos) // current X position
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
			player.color = WHITE;
		else
			player.color = GREEN;


		b1.bounceCount++;
		player.score++;
	}


	updateBalls(b1);
}

void GameState::draw()
{
	drawPaddle(player.xPos, player.yPos, player.color);
	drawballs(b1);
}

APP_STATE GameState::next()
{
	return OPTION;
}

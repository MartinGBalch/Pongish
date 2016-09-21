#include "GameState.h"
#include "sfwdraw.h"
#include "Player.h"
#include "Balls.h"
 

void GameState::init()
{
	b1.xvel = -105;
	b1.yvel = rand() % 100 + 100;
	b1.bounceCount = 0;
	player.score = 0;
}
void GameState::update()
{
	if (sfw::getKey(KEY_UP))
	{
		player.yPos += 20;
	}
	else if (sfw::getKey(KEY_DOWN))
	{
		player.yPos -= 20;
	}
	else if (sfw::getKey('W'))
	{
		player.yPos += 14;
	}
	else if (sfw::getKey('S'))
	{
		player.yPos -= 14;
	}

	if (player.yPos >= 550)
	{
		player.yPos = 550;
	}
	else if (player.yPos <= 54)
	{
		player.yPos = 53;
	}

	// a is the player
	// b is the ball

	if (player.xPos - 30 <= b1.x + b1.size && player.xPos >= b1.x - b1.size   &&
		player.yPos - 50 <= b1.y + b1.size && player.yPos + 50 >= b1.y - b1.size) 
	{
		// reverse the ball's direction
		b1.xvel *= -1;
		// ensure the ball is in a good spot.
		b1.x =  player.xPos + b1.size;

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

	//// if the ball's y is between the top and bottom of the paddle
	//// AND the x of the ball has crossed the x position of the paddle
	//if (player.yPos - 50 <= b1.y
	//	&& b1.y <= player.yPos + 50
	//	&& b1.x + b1.xvel <= player.xPos  // next X position
	//	&& b1.x >= player.xPos) // current X position
	////if ()	
	//{
	//	// reverse the ball's direction
	//	b1.xvel *= -1;
	//	// ensure the ball is in a good spot.
	//	b1.x = player.xPos;

	//	if (player.color == GREEN)
	//		player.color = BLUE;
	//	else if (player.color == BLUE)
	//		player.color = YELLOW;
	//	else if (player.color == YELLOW)
	//		player.color = RED;
	//	else if (player.color == RED)
	//		player.color = CYAN;
	//	else if (player.color == CYAN)
	//		player.color = MAGENTA;
	//	else if (player.color == MAGENTA)
	//		player.color = WHITE;
	//	else
	//		player.color = GREEN;


	//	b1.bounceCount++;
	//	player.score++;
	//}

	


	updateBalls(b1);
}

void GameState::draw()
{
	player.draw();
	drawballs(b1);
	
}

void GameState::play()
{
	
}

int GameState::getScore()
{
	return player.score;
}

APP_STATE GameState::next()
{
	if (b1.x <= 0)
	{

		b1.x = 300;
		b1.y = 300;
		b1.xvel = 0;
		b1.yvel = 0;
		player.color = GREEN;
		return ENTER_WIN;
	}

	return PLAY;
}



#pragma once
#include "Player.h"
#include "Balls.h"
#include "gameManager.h"

class GameState
{

	Paddle player;
	Ball b1;

public:
	void init();	// set up the game (load textures, sounds, etc.)
	void update();	// game logic (input, collision, movement)
	void draw();	// render the game (call all the draws!)
	void play();

	int getScore();

	APP_STATE next();
};
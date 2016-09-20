#pragma once
#include "gameManager.h"
#include "Player.h"

class WinState
{
	int font;
	float timer;
	Paddle winnerPlayer;

public:
	void init(int a_font, Paddle winner);
	void play();
	void draw();
	void step();
	
	APP_STATE next();
};
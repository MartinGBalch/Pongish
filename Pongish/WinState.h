#pragma once
#include "gameManager.h"
#include "Player.h"

class WinState
{
	int font;
	float timer;
	int score;

public:
	void init(int a_font, int a_score);
	void play();
	void draw();
	void step();
	
	APP_STATE next();
};
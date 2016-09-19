#pragma once
#include "gameManager.h"

class Exit
{
	int font;
	float timer;

public:
	void init(int a_font);

	void play();
	void draw();
	void step();

	APP_STATE next();
};


#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"
#include <time.h>
#include <cstdio>
#include "Player.h"
#include "Balls.h"
#include "Score.h"
#include "Splash.h"
#include "Exit.h"
#include "Option.h"
#include "GameState.h"
#include <cmath>
#include "gameManager.h"
#include "WinState.h"

// ** TO DO LIST **
//3) make classes
//4) make player health
//5) make enemy health*
//7) add start menu

using namespace sfw;

struct Bounds
{
	float topWall;
	float bottomWall;
	
};

void drawWin(unsigned font)
{
	sfw::drawString(font, "Game over Player 1 wins", 300, 500, 10, 10);
}

void drawWin2(unsigned font)
{
	sfw::drawString(font, "Game over Player 2 wins", 300, 500, 10, 10);
}


void main()
{
	sfw::initContext(1200, 600, "LETS PLAY SOME CALMING WALL BALL");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	//unsigned r = sfw::loadTextureMap("./res/scroll.png");
	setBackgroundColor(NONE);
	
	Splash splash;
	Exit exit;
	Option option;
	WinState win;
	GameState gamestate;

	splash.init(font);
	exit.init(font);
	option.init(font);
	
	gamestate.init();

	APP_STATE state = ENTER_SPLASH;

	bool quit = false;
	while (sfw::stepContext() && !quit)
	{
		//sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		switch(state)
		{
		case ENTER_PLAY:
			gamestate.init();
		case PLAY:
			gamestate.update();
			gamestate.draw();
			state = gamestate.next();
			break;

		case ENTER_OPTION:
			option.play();
		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case ENTER_EXIT:
			exit.play();
		case EXIT:
			exit.step();
			exit.draw();
			state = exit.next();
			break;
			
		case ENTER_WIN:
			win.play();
			win.init(font, gamestate.getScore());
		case WIN:
			win.step();
			win.draw();
			state = win.next();
			break;

		case TERMINATE: quit = true;

		}
		
	}

	sfw::termContext();
}
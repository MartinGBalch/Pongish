
#include <math.h>
#include <cstdlib>
#include "sfwdraw.h"

using namespace sfw;

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
	drawLine(xPos - 50, yPos, xPos + 50, yPos, WHITE);
	drawLine(xPos - 50, yPos - 30, xPos + 50, yPos - 30, WHITE);
	drawLine(xPos - 50, yPos, xPos - 50, yPos - 30, WHITE);
	drawLine(xPos + 50, yPos, xPos + 50, yPos - 30, WHITE);
}




void main()
{
	Paddle player;
	float xPos, yPos;
	sfw::initContext(800, 600, "NSFW Draw");
	setBackgroundColor(BLACK);
	
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	float acc = 0;
	char c = '\0';

	//sfw::setBackgroundColor(YELLOW);

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
		

		if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2.5, sfw::getTextureHeight(u) / 2.5, 45, true, 0, 0x88ffffff);
		else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);

		
	}

	sfw::termContext();
}
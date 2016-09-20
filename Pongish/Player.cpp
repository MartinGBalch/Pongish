#include "Player.h"

void drawPaddle(float xPos, float yPos, unsigned color)
{
				  // bottom left
	sfw::drawLine(xPos        , yPos - 50, xPos     , yPos + 50, color);	// right
	sfw::drawLine(xPos - 30   , yPos - 50, xPos - 30, yPos + 50, GREEN);	// left
	sfw::drawLine(xPos        , yPos - 50, xPos - 30, yPos - 50, GREEN);	// bottom
	sfw::drawLine(xPos        , yPos + 50, xPos - 30, yPos + 50, GREEN);	// top
}